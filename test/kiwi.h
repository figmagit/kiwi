#pragma once

#include <stdint.h>
#include <string.h>

#include <algorithm>
#include <initializer_list>
#include <optional>
#include <vector>

// Don't include anything from lib/core when KIWI_TESTS is true since KIWI_TESTS
// is true when building share/kiwi/test. That's why the below code uses defines
// a bunch of fullscreen bits and why std::optional instead of Figma::Optional.

// TODO: Consider having share/kiwi/test depend on fullscreen/lib/core. It seems
// like a reasonable dependency if you think about fullscreen/lib/core as being
// the baseline foundation of all the c/c++ code at Figma, which is the
// direction we're moving. Until then, we will need to duplicate or stub out
// anything kiwi uses from fullscreen.

#ifdef KIWI_TESTS
#  include <assert.h>
#  define REPORT_IF_FALSE_DEBUG_ONLY(condition) assert(condition)
#  define KIWI_INDIRECT_BUFFER 0
#  define KIWI_POOL_TRACKING 0
// TODO: Remove temporary error logging
#  define REPORT_ERROR(message) assert(false && message)
#  define sloge(...)

namespace kiwi {
template <typename T>
using Optional = std::optional<T>;
constexpr std::nullopt_t nullopt = std::nullopt;
}  // namespace kiwi
#else
#  include "FGLog.h"
#  include "FGOptional.h"
#  include "FGSupport.h"
#  include "FGTypeRegistry.h"
#  define KIWI_INDIRECT_BUFFER 1
#  define KIWI_POOL_TRACKING 1
namespace Figma {
struct JsBuffer;
struct JsGrowableBufferWriter;
}  // namespace Figma

// Put Optional into the kiwi namespace.
namespace kiwi {
template <typename T>
using Optional = Figma::Optional<T>;
}
#endif

namespace kiwi {
class String;
class MemoryPool;

// A wrapper around some bytes used for parsing kiwi.
// A ByteBuffer instance is a read-only view on data owned externally.
// It tracks the current location for the next read.
class ByteBuffer {
public:
  ByteBuffer(const uint8_t* data, size_t size);
  ByteBuffer(const ByteBuffer&) = delete;
  ByteBuffer& operator=(const ByteBuffer&) = delete;

  const uint8_t* data() const { return _data; }
  size_t size() const { return _size; }
  size_t index() const { return _index; }

  bool readBool(bool& result);
  bool readByte(uint8_t& result);
  bool readVarFloat(float& result);
  bool readVarUint(uint32_t& result);
  bool readVarInt(int32_t& result);
  bool readVarUint64(uint64_t& result);
  bool readVarInt64(int64_t& result);
  bool readString(const char*& result);
  bool readString(String& result, MemoryPool& pool);

  bool readByteArray(uint8_t* data, uint32_t count);
  bool skipCount(uint32_t count);

private:
  const uint8_t* _data = nullptr;
  size_t _size = 0;
  size_t _index = 0;
};

// A wrapper around some bytes used for writing out kiwi.
// A WriteBuffer instance holds a growable buffer and has operations for appending data.
// If you just wrote a WriteBuffer and want to read it, you can create a ByteBuffer view
// onto it via
//   WriteBuffer wb; ...;
//   ByteBuffer bb(wb.data(), wb.size());
class WriteBuffer {
public:
  WriteBuffer();
  ~WriteBuffer();
  WriteBuffer(const WriteBuffer&) = delete;
  WriteBuffer& operator=(const WriteBuffer&) = delete;

#if KIWI_INDIRECT_BUFFER
  // When KIWI_INDIRECT_BUFFER is on (i.e. we're not in the kiwi test suite),
  // WriteBuffer can optionally use a JsBuffer if it gets too big.
  // To enable this behavior, call setJsBufferThreshold() with the maximum amount of heap
  // memory to use.
  void setJsBufferThreshold(size_t size) { _maxSizeBeforeJsBuffer = size; }

  // Take the contents of this WriteBuffer as a JsBuffer.
  Figma::JsBuffer takeJsBuffer();

  // Note: you can only directly access the data or size of the buffer if you never called
  // setJsBufferThreshold().  (Otherwise, the data might already be in a JsBuffer.)
  uint8_t* data() const {
    REPORT_IF_FALSE_DEBUG_ONLY(_maxSizeBeforeJsBuffer == 0 && !_indirect);
    return _data;
  }
  size_t size() const {
    REPORT_IF_FALSE_DEBUG_ONLY(_maxSizeBeforeJsBuffer == 0 && !_indirect);
    return _size;
  }

#else
  uint8_t* data() const { return _data; }
  size_t size() const { return _size; }
#endif

  // If the buffer ends with 0, remove it.
  // This is sometimes needed in some low-level serialization logic.
  bool removeTrailing0();

  void writeBool(bool value);
  void writeByte(uint8_t value);
  void writeVarFloat(float value);
  void writeVarUint(uint32_t value);
  void writeVarInt(int32_t value);
  void writeVarUint64(uint64_t value);
  void writeVarInt64(int64_t value);
  void writeString(const char* value);

  void clear();

private:
  // Increases size (note: not capacity!) by a given amount, allowing the caller to write to that
  // new area.  Be careful to only read _size *after* calling this, as it may cause _size to go
  // down in the case where this buffer flushes to a JsBuffer when growing.
  void _growBy(size_t amount);

  enum { INITIAL_CAPACITY = 256 };
  uint8_t* _data = nullptr;
  size_t _size = 0;
  size_t _capacity = 0;

#if KIWI_INDIRECT_BUFFER
  // We spill over to a JsBuffer if the buffer grows beyond _maxSizeBeforeJsBuffer.
  // _maxSizeBeforeJsBuffer==0 disables this behavior.
  size_t _maxSizeBeforeJsBuffer = 0;
  // _indirect starts out as nullptr and gets created if we need to spill over.
  Figma::Owned<Figma::JsGrowableBufferWriter> _indirect;
  void _flushToIndirect();
#endif
};

////////////////////////////////////////////////////////////////////////////////

class String {
public:
  String() = default;
  explicit String(const char* c_str) : _c_str(c_str) {}

  const char* c_str() const { return _c_str; }

private:
  const char* _c_str = nullptr;
};

inline bool operator==(const String& a, const String& b) { return !strcmp(a.c_str(), b.c_str()); }

////////////////////////////////////////////////////////////////////////////////

template <typename T>
class Array {
public:
  Array() = default;
  Array(T* data, uint32_t size) : _data(data), _size(size) {}

  T* data() { return _data; }
  T* begin() { return _data; }
  T* end() { return _data + _size; }
  T& operator[](uint32_t index) {
    REPORT_IF_FALSE_DEBUG_ONLY(index < _size);
    return _data[index];
  }

  const T* data() const { return _data; }
  const T* begin() const { return _data; }
  const T* end() const { return _data + _size; }
  const T& operator[](uint32_t index) const {
    REPORT_IF_FALSE_DEBUG_ONLY(index < _size);
    return _data[index];
  }

  uint32_t size() const { return _size; }

  void set(const T* data, size_t size) {
    REPORT_IF_FALSE_DEBUG_ONLY(size <= _size);
    memcpy(_data, data, (size < _size ? size : _size) * sizeof(T));
  }
  void set(const Array<T>& other) { set(other.data(), other.size()); }
  void set(const std::initializer_list<T>& data) { set(data.begin(), data.size()); }

private:
  T* _data = nullptr;
  uint32_t _size = 0;
};

////////////////////////////////////////////////////////////////////////////////

class MemoryPool {
public:
  MemoryPool() = default;
  ~MemoryPool() { clear(); }
  MemoryPool(const MemoryPool&) = delete;
  MemoryPool& operator=(const MemoryPool&) = delete;

  void clear();

  template <typename T>
  T* allocate(uint32_t count = 1) {
#if KIWI_POOL_TRACKING
    int typeID = Figma::TypeID::value<T>();
#else
    int typeID = 0;
#endif
    return reinterpret_cast<T*>(allocate(count * sizeof(T), alignof(T), typeID));
  }
  void* allocate(uint32_t size, uint32_t align, int typeID);

  template <typename T>
  Array<T> array(uint32_t size) {
    return Array<T>(allocate<T>(size), size);
  }

  String string(const char* data, uint32_t count);
  String string(const char* c_str) { return string(c_str, strlen(c_str)); }

  // Allows access to the array where the index is a TypeID and the value is the number of bytes
  // allocated so far that TypeID via the allocate() or array() method above.
  const std::vector<uint32_t>& bytesByType() const { return _bytesByType; }

private:
  enum { INITIAL_CAPACITY = 1 << 12 };

  struct Chunk {
    uint8_t* data = nullptr;
    uint32_t capacity = 0;
    uint32_t used = 0;
    Chunk* next = nullptr;
  };

  Chunk* _first = nullptr;
  Chunk* _last = nullptr;

  std::vector<uint32_t> _bytesByType;
};

////////////////////////////////////////////////////////////////////////////////
// GrowableArray
// An array allocated in a MemoryPool which can grow beyond it's initial allocation.
// The array grows by doubling in size when the current allocation is full.

template <typename T>
class GrowableArray {
public:
  GrowableArray() = default;
  GrowableArray(uint32_t size, MemoryPool& pool) : _capacity(size) { _data = pool.array<T>(size); }

  GrowableArray(const GrowableArray&) = delete;
  GrowableArray& operator=(const GrowableArray&) = delete;
  GrowableArray(GrowableArray&&) = default;
  GrowableArray& operator=(GrowableArray&&) = default;

  T* data() { return _data.data(); }
  T* begin() { return _data.begin(); }
  T* end() { return _data.end(); }
  T& operator[](uint32_t index) { return _data[index]; }

  const T* data() const { return _data.data(); }
  const T* begin() const { return _data.begin(); }
  const T* end() const { return _data.end(); }
  const T& operator[](uint32_t index) const { return _data[index]; }

  uint32_t size() const { return _data.size(); }

  void set(const T* data, size_t size) { _data.set(data, size); }
  void set(const std::initializer_list<T>& data) { _data.set(data); }

  void pushBack(const T& value, MemoryPool& pool) {
    growByOne(pool);
    _data[size() - 1] = value;
  }

  void pushBack(T&& value, MemoryPool& pool) {
    growByOne(pool);
    _data[size() - 1] = std::move(value);
  }

  void reserve(uint32_t capacity, MemoryPool& pool) {
    if (capacity <= _capacity) {
      return;
    }

    Array<T> data = pool.array<T>(capacity);
    uint32_t currentSize = size();
    if (currentSize > 0) {
      data.set(_data);
    }

    // The old data gets freed when the pool is freed.
    _data = Array<T>(data.data(), currentSize);
    _capacity = capacity;
  }

  GrowableArray copy(MemoryPool& pool) const {
    GrowableArray clone(_data.size(), pool);

    for (uint32_t i = 0; i < _data.size(); i++) {
      clone._data[i] = _data[i];
    }

    return clone;
  }

private:
  Array<T> _data;
  uint32_t _capacity = 0;

  // Increase the size of the _data array be one element. If there is not enough
  // space in the backing array, double its size.
  void growByOne(MemoryPool& pool) {
    uint32_t currentSize = size();
    if (currentSize >= _capacity) {
      reserve((currentSize + 1) * 2, pool);
    }

    _data = Array<T>(data(), currentSize + 1);
  }
};

////////////////////////////////////////////////////////////////////////////////
// SparseFields
// A GrowableArray that can be used for storing kiwi message fields.
// Each field has an index which is used for retrieving the field's value.
// Keys can sorted for faster lookups, but adding fields does not implicitly sort.
// This is done to avoid breaking outstanding pointers to fields at the cost of
// some additional lookup time.

template <typename T>
struct SparseField {
  uint32_t index = 0;
  T field = {};
};

template <typename T>
class SparseFields {
public:
  typedef SparseField<T> Element;

  SparseFields() = default;

  SparseFields(const SparseFields&) = delete;
  SparseFields& operator=(const SparseFields&) = delete;
  SparseFields(SparseFields&&) = default;
  SparseFields& operator=(SparseFields&&) = default;

  SparseFields(const Element* values, uint32_t size, MemoryPool& pool) : _sorted(false) {
    _data = GrowableArray<Element>(size, pool);

    // It would probably be safe to memcpy here as kiwi types don't have non-default constructors.
    // But the performance gain is minor, and it adds risk to future changes.
    for (uint32_t i = 0; i < size; i++) {
      _data[i] = values[i];
    }

    sort();
  }

  Element* begin() { return _data.begin(); }
  Element* end() { return _data.end(); }
  T* back() { return &_data[size() - 1].field; }

  const Element* begin() const { return _data.begin(); }
  const Element* end() const { return _data.end(); }
  const T* back() const { return &_data[size() - 1].field; }

  const T* getField(uint32_t value) const {
    if (_sorted) {
      int32_t l = 0;
      int32_t r = size() - 1;

      while (l <= r) {
        int32_t i = (l + r) / 2;
        if (_data[i].index == value) {
          return &_data[i].field;
        } else if (value > _data[i].index) {
          l = i + 1;
        } else {
          r = i - 1;
        }
      }
    } else {
      for (const Element& element : _data) {
        if (element.index == value) return &element.field;
      }
    }

    return nullptr;
  }

  T* getField(uint32_t value) {
    return const_cast<T*>(static_cast<const SparseFields&>(*this).getField(value));
  }

  bool sorted() const { return _sorted; }

  void sort() {
    if (_sorted) {
      return;
    }

    std::sort(_data.begin(), _data.end(),
              [](const Element& a, const Element& b) { return a.index < b.index; });
    _sorted = true;
  }

  uint32_t size() const { return _data.size(); }

  Element* addField(const Element& value, MemoryPool& pool) {
    // This check is too expensive to do in production.
#if BUILD_DEBUG
    if (getField(value.index)) {
      REPORT_ERROR("Duplicate field added");
    }
#endif

    _data.pushBack(value, pool);

    // Check if the fields are still sorted
    uint32_t newSize = _data.size();
    _sorted = _sorted && (newSize < 2 || _data[newSize - 2].index < _data[newSize - 1].index);

    return &_data[_data.size() - 1];
  }

  void reserve(uint32_t capacity, MemoryPool& pool) { _data.reserve(capacity, pool); }

  SparseFields copy(MemoryPool& pool) const {
    SparseFields clone;
    clone._data = _data.copy(pool);
    clone._sorted = _sorted;
    return clone;
  }

private:
  GrowableArray<Element> _data;
  bool _sorted = true;
};

////////////////////////////////////////////////////////////////////////////////

class BinarySchema {
public:
  bool parse(ByteBuffer& bb);
  bool findDefinition(const char* definition, uint32_t& index) const;
  bool skipField(ByteBuffer& bb, uint32_t definition, uint32_t field) const;

private:
  enum {
    TYPE_BOOL = -1,
    TYPE_BYTE = -2,
    TYPE_INT = -3,
    TYPE_UINT = -4,
    TYPE_FLOAT = -5,
    TYPE_STRING = -6,
    TYPE_INT64 = -7,
    TYPE_UINT64 = -8
  };

  struct Field {
    String name;
    int32_t type = 0;
    bool isArray = false;
    uint32_t value = 0;
  };

  enum {
    KIND_ENUM = 0,
    KIND_STRUCT = 1,
    KIND_MESSAGE = 2,
  };

  struct Definition {
    String name;
    uint8_t kind = 0;
    Array<Field> fields;
  };

  bool _skipField(ByteBuffer& bb, const Field& field) const;

  MemoryPool _pool;
  Array<Definition> _definitions;
};

}  // namespace kiwi
