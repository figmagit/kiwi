#include "kiwi.h"

#include <iostream>

#if KIWI_INDIRECT_BUFFER
#  include "FGJsBuffer.h"
#  include "FGJsGrowableBufferWriter.h"
#endif

kiwi::ByteBuffer::ByteBuffer(const uint8_t* data, size_t size) : _data(data), _size(size) {}

bool kiwi::ByteBuffer::readBool(bool& result) {
  uint8_t value;
  if (!readByte(value)) {
    result = false;
    return false;
  }

  // Fail decode if boolean is not 0 or 1.
  if (value != 0 && value != 1) {
    result = false;
    return false;
  }

  result = value;
  return true;
}

bool kiwi::ByteBuffer::readByte(uint8_t& result) {
  if (_index >= _size) {
    result = 0;
    return false;
  }

  result = _data[_index];
  _index++;
  return true;
}

// NOTE(bsmith):
// This function can be slightly optimized by optimistically reading 4 bytes
// (when possible). In my testing this makes reading a 4-byte VarFloat faster,
// but slows down 1-byte VarFloats:
//
// In the chart below readVarFloat/0 is always a 1-byte VarFloat and
// readVarFloat/1 is always a 4-byte VarFloat.
//
// ----------------------------------------------
// Benchmark                 Time      Iterations
// ----------------------------------------------
// opt/readVarFloat/0      276 ns         2542764
// opt/readVarFloat/1      265 ns         2644523
// unopt/readVarFloat/0    256 ns         2733467
// unopt/readVarFloat/1    368 ns         1891268
//
bool kiwi::ByteBuffer::readVarFloat(float& result) {
  uint8_t first;
  if (!readByte(first)) {
    return false;
  }

  // Optimization: use a single byte to store zero
  if (first == 0) {
    result = 0;
    return true;
  }

  // Endian-independent 32-bit read
  if (_index + 3 > _size) {
    result = 0;
    return false;
  }
  uint32_t bits =
      first | (_data[_index] << 8) | (_data[_index + 1] << 16) | (_data[_index + 2] << 24);
  _index += 3;

  // Move the exponent back into place
  bits = (bits << 23) | (bits >> 9);

  // Reinterpret as a floating-point number
  memcpy(&result, &bits, 4);
  return true;
}

// NOTE(bsmith):
// This function can be slightly optimized by using bit twiddling-techniques to
// determine the number of bytes in the VarUint, without having to loop. Since a
// 1-byte VarUint is the most commonly occurring VarFloat, we optimize for that
// case. If it is more than 1 byte, we can optimistically read 4 bytes. This
// yields a 32-bit integer with the following pattern (where most-significant
// bits are on the left and least-significant bits are on the right):
//
//          4        3        2        1
//   Cbbbbbbb Cbbbbbbb Cbbbbbbb Cbbbbbbb
//
// The numbers indicate the byte index, starting at 1 since we've already read
// the first byte. `b` represents the payload data, and `C` is 1 iff there is
// another byte at the next index.
//
// Given this, the 32-bit integer will have the given patterns for 2-,3-,4-, and
// 5-byte sequences:
//
//   2 bytes: XXXXXXXX XXXXXXXX XXXXXXXX 0bbbbbbb
//   3 bytes: XXXXXXXX XXXXXXXX 0bbbbbbb 1bbbbbbb
//   4 bytes: XXXXXXXX 0bbbbbbb 1bbbbbbb 1bbbbbbb
//   5 bytes: 0XXXbbbb 1bbbbbbb 1bbbbbbb 1bbbbbbb
//
// This information can be extracted with the following pseudo-code:
//
//   // Set all bits except the MSB of each byte to 1.
//   mask = x | 0x7f7f7f7fu;
//
//   // Invert, so the MSB of each byte is 1 for the last byte in the sequence,
//   // and all other bits are 0.
//   mask = ~mask;
//
//   // Special case when mask is 0, since `ctz()` is undefined for that value.
//   if (mask == 0) { ... }
//
//   // Find the index of the rightmost 0 bit. The result will be 7, 15, 24, or
//   // 31. Divide by 8 to give 0, 1, 2, or 3. Add 2 to produce the correct
//   // number of bytes.
//   numBytes = (ctz(mask) >> 3) + 2;
//
// In my testing this makes reading everything faster except 1-byte VarUints.
// Unfortunately this typically ends up being a loss, since most VarUints are 1
// byte:
//
// In the chart below readVarUint/N indicates that all VarUints are N bytes
// long.
//
// ---------------------------------------------
// Benchmark                 Time     Iterations
// ---------------------------------------------
// opt/readVarUint/1       290 ns        2408354
// opt/readVarUint/2       297 ns        2346293
// opt/readVarUint/3       301 ns        2273650
// opt/readVarUint/4       306 ns        2293593
// opt/readVarUint/5       363 ns        1932933
// unopt/readVarUint/1     277 ns        2525116
// unopt/readVarUint/2     333 ns        2143767
// unopt/readVarUint/3     413 ns        1690119
// unopt/readVarUint/4     632 ns        1108086
// unopt/readVarUint/5     760 ns         912670
//
bool kiwi::ByteBuffer::readVarUint(uint32_t& result) {
  uint8_t shift = 0;
  uint8_t byte;
  result = 0;

  do {
    if (!readByte(byte)) {
      return false;
    }

    result |= (byte & 127) << shift;
    shift += 7;
  } while (byte & 128 && shift < 35);

  return true;
}

bool kiwi::ByteBuffer::readVarInt(int32_t& result) {
  uint32_t value;
  if (!readVarUint(value)) {
    result = 0;
    return false;
  }

  result = value & 1 ? ~(value >> 1) : value >> 1;
  return true;
}

bool kiwi::ByteBuffer::readVarUint64(uint64_t& result) {
  uint8_t byteCount = 0;
  uint8_t byte;
  result = 0ULL;

  do {
    if (!readByte(byte)) {
      return false;
    }

    if (byteCount < 8) {
      result |= static_cast<uint64_t>(byte & 127) << (byteCount * 7);
    } else {
      result |= static_cast<uint64_t>(byte) << (byteCount * 7);
      break;
    }
    byteCount += 1;
  } while (byte & 128);

  return true;
}

bool kiwi::ByteBuffer::readVarInt64(int64_t& result) {
  uint64_t value;
  if (!readVarUint64(value)) {
    result = 0;
    return false;
  }
  result = value & 1 ? ~(value >> 1) : value >> 1;
  return true;
}

// NOTE(bsmith):
// This function can be slightly optimized by using bit twiddling-techniques to
// find the length of the string. Rather than looping once for each byte, we can
// read 8 bytes at a time and use tricks to scan for null bytes in parallel.
//
// See https://graphics.stanford.edu/~seander/bithacks.html#ZeroInWord for more
// information on this technique.
//
// In my testing this significantly improved reading long strings, but worsened
// very short strings. This ultimately didn't have much effect on reading the
// fig files I was testing, however.
//
// In the chart below readString/N indicates that all strings have a length of N
// bytes.
//
// ----------------------------------------------
// Benchmark                   Time    Iterations
// ----------------------------------------------
// opt/readString/8         222861 ns        3125
// opt/readString/16        120079 ns        5804
// opt/readString/64         41483 ns       16868
// opt/readString/256        24164 ns       28975
// opt/readString/1024       20047 ns       35339
// opt/readString/4096       18682 ns       37424
// opt/readString/16384      18068 ns       38841
// opt/readString/32768      17968 ns       38927
// unopt/readString/8       157275 ns        4457
// unopt/readString/16      120624 ns        5813
// unopt/readString/64       93004 ns        7481
// unopt/readString/256     102016 ns        6802
// unopt/readString/1024     90497 ns        7695
// unopt/readString/4096     82933 ns        8325
// unopt/readString/16384    82045 ns        8520
// unopt/readString/32768    81814 ns        8548
//
bool kiwi::ByteBuffer::readString(const char*& result) {
  result = reinterpret_cast<const char*>(_data) + _index;

  do {
    if (_index >= _size) return false;
  } while (_data[_index++] != '\0');

  return true;
}

bool kiwi::ByteBuffer::readString(String& result, MemoryPool& pool) {
  uint32_t size = 0;
  result = String();

  do {
    if ((_index + size) >= _size) return false;
  } while (_data[_index + size++] != '\0');

  result = pool.string(reinterpret_cast<const char*>(_data + _index), size - 1);
  _index += size;
  return true;
}

bool kiwi::ByteBuffer::readByteArray(uint8_t* data, uint32_t count) {
  if (_index + count > _size) return false;
  memcpy(data, &_data[_index], count);
  _index += count;
  return true;
}

bool kiwi::ByteBuffer::skipCount(uint32_t count) {
  if (_index + count > _size) return false;
  _index += count;
  return true;
}

////////////////////////////////////////////////////////////////////////////////

kiwi::WriteBuffer::WriteBuffer()
    : _data(new uint8_t[INITIAL_CAPACITY]), _capacity(INITIAL_CAPACITY) {}

kiwi::WriteBuffer::~WriteBuffer() { delete[] _data; }

#if KIWI_INDIRECT_BUFFER
Figma::JsBuffer kiwi::WriteBuffer::takeJsBuffer() {
  if (_maxSizeBeforeJsBuffer == 0) {
    return Figma::JsBuffer(_data, _size);
  } else {
    _flushToIndirect();
    return _indirect->takeBuffer();
  }
}

void kiwi::WriteBuffer::_flushToIndirect() {
  if (!_indirect) {
    _indirect.reset(new Figma::JsGrowableBufferWriter(_size));
  }
  _indirect->write(_data, _size);
  _size = 0;
}
#endif

bool kiwi::WriteBuffer::removeTrailing0() {
  if (_size == 0 || _data[_size - 1] != 0) {
    return false;
  }
  _size--;
  return true;
}

void kiwi::WriteBuffer::writeBool(bool value) { writeByte(value); }

void kiwi::WriteBuffer::writeByte(uint8_t value) {
  _growBy(1);
  size_t index = _size - 1;
  _data[index] = value;
}

void kiwi::WriteBuffer::writeVarFloat(float value) {
  // Reinterpret as an integer
  uint32_t bits;
  memcpy(&bits, &value, 4);

  // Move the exponent to the first 8 bits
  bits = (bits >> 23) | (bits << 9);

  // Optimization: use a single byte to store zero and denormals (check for an exponent of 0)
  if ((bits & 255) == 0) {
    writeByte(0);
    return;
  }

  // Endian-independent 32-bit write
  _growBy(4);
  size_t index = _size - 4;
  _data[index] = bits;
  _data[index + 1] = bits >> 8;
  _data[index + 2] = bits >> 16;
  _data[index + 3] = bits >> 24;
}

void kiwi::WriteBuffer::writeVarUint(uint32_t value) {
  do {
    uint8_t byte = value & 127;
    value >>= 7;
    writeByte(value ? byte | 128 : byte);
  } while (value);
}

void kiwi::WriteBuffer::writeVarInt(int32_t value) { writeVarUint((value << 1) ^ (value >> 31)); }

void kiwi::WriteBuffer::writeVarUint64(uint64_t value) {
  uint32_t byteCount = 0;
  uint8_t byte;
  do {
    if (byteCount < 8) {
      byte = value & 127;
      value >>= 7;
    } else {
      byte = value & 255;
      writeByte(byte);
      break;
    }
    writeByte(value ? byte | 128 : byte);
    byteCount++;
  } while (value);
}

void kiwi::WriteBuffer::writeVarInt64(int64_t value) {
  writeVarUint64((value << 1) ^ (value >> 63));
}

void kiwi::WriteBuffer::writeString(const char* value) {
  uint32_t count = strlen(value) + 1;
  _growBy(count);
  size_t index = _size - count;
  memcpy(_data + index, value, count);
}

void kiwi::WriteBuffer::_growBy(size_t amount) {
#if KIWI_INDIRECT_BUFFER
  if (_maxSizeBeforeJsBuffer > 0) {
    if (_size + amount > _maxSizeBeforeJsBuffer) {
      _flushToIndirect();
    }
  }
#endif

  if (_size + amount > _capacity) {
    size_t capacity = (_size + amount) * 2;
    uint8_t* data = new uint8_t[capacity];
    memcpy(data, _data, _size);

    delete[] _data;

    _data = data;
    _capacity = capacity;
  }

  _size += amount;
}

void kiwi::WriteBuffer::clear() {
  delete[] _data;

  uint8_t* data = new uint8_t[INITIAL_CAPACITY];
  _data = data;
  _capacity = INITIAL_CAPACITY;
  _size = 0;
}

////////////////////////////////////////////////////////////////////////////////

void kiwi::MemoryPool::clear() {
  for (Chunk *chunk = _first, *next; chunk; chunk = next) {
    next = chunk->next;
    delete[] chunk->data;
    delete chunk;
  }

  _first = _last = nullptr;
}

void* kiwi::MemoryPool::allocate(uint32_t size, uint32_t align, int typeID) {
  if (typeID >= 0) {
    if (static_cast<size_t>(typeID) >= _bytesByType.size()) {
      _bytesByType.resize(typeID + 1);
    }
    _bytesByType[typeID] += size;
  }
  Chunk* chunk = _last;
  uint32_t index = (chunk ? chunk->used : 0) + align - 1;
  index -= index % align;

  if (chunk && index + size >= index && index + size <= chunk->capacity) {
    chunk->used = index + size;
    return chunk->data + index;
  }

  chunk = new Chunk;
  chunk->capacity = size > INITIAL_CAPACITY ? size : INITIAL_CAPACITY;
  chunk->data = new uint8_t[chunk->capacity]();  // "()" means zero-initialized
  chunk->used = size;

  if (_last)
    _last->next = chunk;
  else
    _first = chunk;
  _last = chunk;

  return chunk->data;
}

kiwi::String kiwi::MemoryPool::string(const char* text, uint32_t count) {
  char* c_str = allocate<char>(count + 1);
  memcpy(c_str, text, count);
  return String(c_str);
}

////////////////////////////////////////////////////////////////////////////////

bool kiwi::BinarySchema::parse(ByteBuffer& bb) {
  uint32_t definitionCount = 0;

  _definitions = {};
  _pool.clear();

  if (!bb.readVarUint(definitionCount)) {
    return false;
  }

  _definitions = _pool.array<Definition>(definitionCount);

  for (auto& definition : _definitions) {
    uint32_t fieldCount = 0;

    if (!bb.readString(definition.name, _pool) || !bb.readByte(definition.kind) ||
        !bb.readVarUint(fieldCount) ||
        (definition.kind != KIND_ENUM && definition.kind != KIND_STRUCT &&
         definition.kind != KIND_MESSAGE)) {
      return false;
    }

    definition.fields = _pool.array<Field>(fieldCount);

    for (auto& field : definition.fields) {
      if (!bb.readString(field.name, _pool) || !bb.readVarInt(field.type) ||
          !bb.readBool(field.isArray) || !bb.readVarUint(field.value) || field.type < TYPE_STRING ||
          field.type >= (int32_t)definitionCount) {
        return false;
      }
    }
  }

  return true;
}

bool kiwi::BinarySchema::findDefinition(const char* definition, uint32_t& index) const {
  for (uint32_t i = 0; i < _definitions.size(); i++) {
    auto& item = _definitions[i];
    if (item.name == String(definition)) {
      index = i;
      return true;
    }
  }

  // Ignore fields we're looking for in an old schema
  index = -1;
  return false;
}

bool kiwi::BinarySchema::skipField(ByteBuffer& bb, uint32_t definition, uint32_t field) const {
  if (definition < _definitions.size()) {
    for (auto& item : _definitions[definition].fields) {
      if (item.value == field) {
        return _skipField(bb, item);
      }
    }
  }

  return false;
}

bool kiwi::BinarySchema::_skipField(ByteBuffer& bb, const Field& field) const {
  uint32_t count = 1;

  if (field.isArray && !bb.readVarUint(count)) {
    return false;
  }

  while (count-- > 0) {
    switch (field.type) {
      case TYPE_BOOL:
      case TYPE_BYTE: {
        uint8_t dummy = 0;
        if (!bb.readByte(dummy)) return false;
        break;
      }

      case TYPE_INT:
      case TYPE_UINT: {
        uint32_t dummy = 0;
        if (!bb.readVarUint(dummy)) return false;
        break;
      }

      case TYPE_INT64:
      case TYPE_UINT64: {
        uint64_t dummy = 0;
        if (!bb.readVarUint64(dummy)) return false;
        break;
      }

      case TYPE_FLOAT: {
        float dummy = 0;
        if (!bb.readVarFloat(dummy)) return false;
        break;
      }

      case TYPE_STRING: {
        uint8_t value = 0;
        do {
          if (!bb.readByte(value)) return false;
        } while (value);
        break;
      }

      default: {
        REPORT_IF_FALSE_DEBUG_ONLY(field.type >= 0 && (uint32_t)field.type < _definitions.size());
        auto& definition = _definitions[field.type];

        switch (definition.kind) {
          case KIND_ENUM: {
            uint32_t dummy;
            if (!bb.readVarUint(dummy)) return false;
            break;
          }

          case KIND_STRUCT: {
            for (auto& item : definition.fields) {
              if (!_skipField(bb, item)) return false;
            }
            break;
          }

          case KIND_MESSAGE: {
            uint32_t id = 0;
            while (true) {
              if (!bb.readVarUint(id)) return false;
              if (!id) break;
              if (!skipField(bb, field.type, id)) return false;
            }
            break;
          }

          default: {
            REPORT_IF_FALSE_DEBUG_ONLY(false);
            break;
          }
        }
      }
    }
  }

  return true;
}
