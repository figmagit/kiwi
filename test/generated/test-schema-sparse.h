#include "kiwi.h"

namespace test_sparse {

#ifndef INCLUDE_TEST_SPARSE_H
#define INCLUDE_TEST_SPARSE_H

class BinarySchema {
public:
  bool parse(kiwi::ByteBuffer &bb);
  const kiwi::BinarySchema &underlyingSchema() const { return _schema; }
  bool skipMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipParentField(kiwi::ByteBuffer &bb, uint32_t id) const;

private:
  kiwi::BinarySchema _schema;
  uint32_t _indexMessage = 0;
  uint32_t _indexParent = 0;
};

enum class Enum : uint32_t {
  A = 100,
  B = 200,
};

class ByteStruct;
class Message;
class Parent;

class ByteStruct {
public:
  ByteStruct() { (void)_flags; }
  ByteStruct(const ByteStruct&) = delete;
  ByteStruct& operator=(const ByteStruct&) = delete;
  ByteStruct(ByteStruct&&) = default;
  ByteStruct& operator=(ByteStruct&&) = default;

  uint8_t *x();
  const uint8_t *x() const;
  void set_x(const uint8_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint8_t _data_x = {};
};

class Message {
public:
  Message() { (void)_flags; }
  Message(const Message&) = delete;
  Message& operator=(const Message&) = delete;
  Message(Message&&) = default;
  Message& operator=(Message&&) = default;

  Message copy(kiwi::MemoryPool& pool) const;

  kiwi::Optional<uint32_t> a() const;
  void set_a(kiwi::MemoryPool &pool, const uint32_t &value);

  kiwi::Optional<float> b() const;
  void set_b(kiwi::MemoryPool &pool, const float &value);

  kiwi::Optional<kiwi::Array<uint32_t>> c() const;
  kiwi::Array<uint32_t> &set_c(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Optional<Enum> d() const;
  void set_d(kiwi::MemoryPool &pool, const Enum &value);

  ByteStruct *e();
  const ByteStruct *e() const;
  void set_e(kiwi::MemoryPool &pool, ByteStruct *value);

  kiwi::Optional<uint32_t> f() const;
  void set_f(kiwi::MemoryPool &pool, const uint32_t &value);

  kiwi::Optional<kiwi::String> g() const;
  void set_g(kiwi::MemoryPool &pool, const kiwi::String &value);

  kiwi::Optional<bool> h() const;
  void set_h(kiwi::MemoryPool &pool, const bool &value);

  kiwi::Optional<kiwi::Array<Message>> i() const;
  kiwi::Array<Message> &set_i(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool encode2(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  union Field {
  public:
    bool operator==(const Field&) const { return false; }
    kiwi::Array<uint32_t> _data_c;
    Enum _data_d;
    ByteStruct *_data_e;
    kiwi::String _data_g;
    kiwi::Array<Message> _data_i;
    uint32_t _data_a;
    float _data_b;
    uint32_t _data_f;
    bool _data_h;
  };
  kiwi::SparseFields<Field> _fields;
  friend std::hash<Field>;
};

class Parent {
public:
  Parent() { (void)_flags; }
  Parent(const Parent&) = delete;
  Parent& operator=(const Parent&) = delete;
  Parent(Parent&&) = default;
  Parent& operator=(Parent&&) = default;

  Message *a();
  const Message *a() const;
  void set_a(Message *value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Message *_data_a = {};
};

inline uint8_t *ByteStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const uint8_t *ByteStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void ByteStruct::set_x(const uint8_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline Message Message::copy(kiwi::MemoryPool& pool) const {
  Message clone;
  clone._fields = _fields.copy(pool);
  memcpy(clone._flags, _flags, sizeof(_flags));
  return clone;
}

inline kiwi::Optional<uint32_t> Message::a() const {
  if (!(_flags[0] & (1 << 0))) return std::nullopt;
  const Field* field = _fields.getField(1);
  return field ? kiwi::Optional<uint32_t>(field->_data_a) : std::nullopt;
}

inline void Message::set_a(kiwi::MemoryPool &pool, const uint32_t &value) {
  if (_flags[0] & (1 << 0)) {
    Field* field = _fields.getField(1);
    field->_data_a = value;
  } else {
    _flags[0] |= (1 << 0);
    _fields.addField({1, Field{._data_a = value}}, pool);
  }
}

inline kiwi::Optional<float> Message::b() const {
  if (!(_flags[0] & (1 << 1))) return std::nullopt;
  const Field* field = _fields.getField(2);
  return field ? kiwi::Optional<float>(field->_data_b) : std::nullopt;
}

inline void Message::set_b(kiwi::MemoryPool &pool, const float &value) {
  if (_flags[0] & (1 << 1)) {
    Field* field = _fields.getField(2);
    field->_data_b = value;
  } else {
    _flags[0] |= (1 << 1);
    _fields.addField({2, Field{._data_b = value}}, pool);
  }
}

inline kiwi::Optional<kiwi::Array<uint32_t>> Message::c() const {
  if (!(_flags[0] & (1 << 2))) return std::nullopt;
  const Field* field = _fields.getField(3);
  return field ? kiwi::Optional<kiwi::Array<uint32_t>>(field->_data_c) : std::nullopt;
}

inline kiwi::Array<uint32_t> &Message::set_c(kiwi::MemoryPool &pool, uint32_t count) {
  kiwi::Array<uint32_t> value = pool.array<uint32_t>(count);
  if (_flags[0] & (1 << 2)) {
    Field* field = _fields.getField(3);
    field->_data_c = value;
    return field->_data_c;
  } else {
    _flags[0] |= (1 << 2);
    return _fields.addField({3, Field{._data_c = value}}, pool)->field._data_c;
  }
}

inline kiwi::Optional<Enum> Message::d() const {
  if (!(_flags[0] & (1 << 3))) return std::nullopt;
  const Field* field = _fields.getField(4);
  return field ? kiwi::Optional<Enum>(field->_data_d) : std::nullopt;
}

inline void Message::set_d(kiwi::MemoryPool &pool, const Enum &value) {
  if (_flags[0] & (1 << 3)) {
    Field* field = _fields.getField(4);
    field->_data_d = value;
  } else {
    _flags[0] |= (1 << 3);
    _fields.addField({4, Field{._data_d = value}}, pool);
  }
}

inline ByteStruct *Message::e() {
  if (!(_flags[0] & (1 << 4))) return nullptr;
  Field* field = _fields.getField(5);
  return field ? field->_data_e : nullptr;
}

inline const ByteStruct *Message::e() const {
  if (!(_flags[0] & (1 << 4))) return nullptr;
  const Field* field = _fields.getField(5);
  return field ? field->_data_e : nullptr;
}

inline void Message::set_e(kiwi::MemoryPool &pool, ByteStruct *value) {
  if (_flags[0] & (1 << 4)) {
    Field* field = _fields.getField(5);
    field->_data_e = value;
  } else {
    _flags[0] |= (1 << 4);
    _fields.addField({5, Field{._data_e = value}}, pool);
  }
}

inline kiwi::Optional<uint32_t> Message::f() const {
  if (!(_flags[0] & (1 << 5))) return std::nullopt;
  const Field* field = _fields.getField(6);
  return field ? kiwi::Optional<uint32_t>(field->_data_f) : std::nullopt;
}

inline void Message::set_f(kiwi::MemoryPool &pool, const uint32_t &value) {
  if (_flags[0] & (1 << 5)) {
    Field* field = _fields.getField(6);
    field->_data_f = value;
  } else {
    _flags[0] |= (1 << 5);
    _fields.addField({6, Field{._data_f = value}}, pool);
  }
}

inline kiwi::Optional<kiwi::String> Message::g() const {
  if (!(_flags[0] & (1 << 6))) return std::nullopt;
  const Field* field = _fields.getField(7);
  return field ? kiwi::Optional<kiwi::String>(field->_data_g) : std::nullopt;
}

inline void Message::set_g(kiwi::MemoryPool &pool, const kiwi::String &value) {
  if (_flags[0] & (1 << 6)) {
    Field* field = _fields.getField(7);
    field->_data_g = value;
  } else {
    _flags[0] |= (1 << 6);
    _fields.addField({7, Field{._data_g = value}}, pool);
  }
}

inline kiwi::Optional<bool> Message::h() const {
  if (!(_flags[0] & (1 << 7))) return std::nullopt;
  const Field* field = _fields.getField(8);
  return field ? kiwi::Optional<bool>(field->_data_h) : std::nullopt;
}

inline void Message::set_h(kiwi::MemoryPool &pool, const bool &value) {
  if (_flags[0] & (1 << 7)) {
    Field* field = _fields.getField(8);
    field->_data_h = value;
  } else {
    _flags[0] |= (1 << 7);
    _fields.addField({8, Field{._data_h = value}}, pool);
  }
}

inline kiwi::Optional<kiwi::Array<Message>> Message::i() const {
  if (!(_flags[0] & (1 << 8))) return std::nullopt;
  const Field* field = _fields.getField(9);
  return field ? kiwi::Optional<kiwi::Array<Message>>(field->_data_i) : std::nullopt;
}

inline kiwi::Array<Message> &Message::set_i(kiwi::MemoryPool &pool, uint32_t count) {
  kiwi::Array<Message> value = pool.array<Message>(count);
  if (_flags[0] & (1 << 8)) {
    Field* field = _fields.getField(9);
    field->_data_i = value;
    return field->_data_i;
  } else {
    _flags[0] |= (1 << 8);
    return _fields.addField({9, Field{._data_i = value}}, pool)->field._data_i;
  }
}

inline Message *Parent::a() {
  return _data_a;
}

inline const Message *Parent::a() const {
  return _data_a;
}

inline void Parent::set_a(Message *value) {
  _data_a = value;
}

}  // namespace test_sparse
template<>
struct std::hash<test_sparse::Message::Field> {
  size_t operator()(const test_sparse::Message::Field& msg) const {
    return 0;
  }
};
namespace test_sparse {
#endif  // INCLUDE_TEST_SPARSE_H
#ifdef IMPLEMENT_SCHEMA_H

bool BinarySchema::parse(kiwi::ByteBuffer &bb) {
  if (!_schema.parse(bb)) return false;
  _schema.findDefinition("Message", _indexMessage);
  _schema.findDefinition("Parent", _indexParent);
  return true;
}

bool BinarySchema::skipMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMessage, id);
}

bool BinarySchema::skipParentField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexParent, id);
}

bool ByteStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeByte(_data_x);
  return true;
}

bool ByteStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readByte(_data_x)) return false;
  set_x(_data_x);
  return true;
}

bool Message::encode(kiwi::WriteBuffer &_wb) const {
  const kiwi::Optional<uint32_t> _data_a = a();
  if (_data_a) {
    const uint32_t& _data = *_data_a;
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data);
  }
  const kiwi::Optional<float> _data_b = b();
  if (_data_b) {
    const float& _data = *_data_b;
    _wb.writeVarUint(2);
    _wb.writeVarFloat(_data);
  }
  const kiwi::Optional<kiwi::Array<uint32_t>> _data_c = c();
  if (_data_c) {
    const kiwi::Array<uint32_t>& _data = *_data_c;
    _wb.writeVarUint(3);
    _wb.writeVarUint(_data.size());
    for (const uint32_t &_it : _data) _wb.writeVarUint(_it);
  }
  const kiwi::Optional<Enum> _data_d = d();
  if (_data_d) {
    const Enum& _data = *_data_d;
    _wb.writeVarUint(4);
    _wb.writeVarUint(static_cast<uint32_t>(_data));
  }
  const ByteStruct* _data_e = e();
  if (_data_e) {
    const ByteStruct* _data = _data_e;
    _wb.writeVarUint(5);
    if (!_data->encode(_wb)) return false;
  }
  const kiwi::Optional<uint32_t> _data_f = f();
  if (_data_f) {
    const uint32_t& _data = *_data_f;
    _wb.writeVarUint(6);
    _wb.writeVarUint(_data);
  }
  const kiwi::Optional<kiwi::String> _data_g = g();
  if (_data_g) {
    const kiwi::String& _data = *_data_g;
    _wb.writeVarUint(7);
    _wb.writeString(_data.c_str());
  }
  const kiwi::Optional<bool> _data_h = h();
  if (_data_h) {
    const bool& _data = *_data_h;
    _wb.writeVarUint(8);
    _wb.writeBool(_data);
  }
  const kiwi::Optional<kiwi::Array<Message>> _data_i = i();
  if (_data_i) {
    const kiwi::Array<Message>& _data = *_data_i;
    _wb.writeVarUint(9);
    _wb.writeVarUint(_data.size());
    for (const Message &_it : _data) if (!_it.encode(_wb)) return false;
  }
  _wb.writeVarUint(0);
  return true;
}

bool Message::encode2(kiwi::WriteBuffer &_wb) const {
  for (auto* it = _fields.begin(); it != _fields.end(); it++) {
    uint32_t index = it->index;
    const Field& field = it->field;
    _wb.writeVarUint(index);
    switch (index) {
      case 1: {
        const uint32_t& _data_a = field._data_a;
        _wb.writeVarUint(_data_a);
        break;
      }
      case 2: {
        const float& _data_b = field._data_b;
        _wb.writeVarFloat(_data_b);
        break;
      }
      case 3: {
        const kiwi::Array<uint32_t>& _data_c = field._data_c;
        _wb.writeVarUint(_data_c.size());
        for (const uint32_t &_it : _data_c) _wb.writeVarUint(_it);
        break;
      }
      case 4: {
        const Enum& _data_d = field._data_d;
        _wb.writeVarUint(static_cast<uint32_t>(_data_d));
        break;
      }
      case 5: {
        const ByteStruct* _data_e = field._data_e;
        if (!_data_e->encode(_wb)) return false;
        break;
      }
      case 6: {
        const uint32_t& _data_f = field._data_f;
        _wb.writeVarUint(_data_f);
        break;
      }
      case 7: {
        const kiwi::String& _data_g = field._data_g;
        _wb.writeString(_data_g.c_str());
        break;
      }
      case 8: {
        const bool& _data_h = field._data_h;
        _wb.writeBool(_data_h);
        break;
      }
      case 9: {
        const kiwi::Array<Message>& _data_i = field._data_i;
        _wb.writeVarUint(_data_i.size());
        for (const Message &_it : _data_i) if (!_it.encode(_wb)) return false;
        break;
      }
      default: {
        continue;
      }
    }
  }
  _wb.writeVarUint(0);
  return true;
}

bool Message::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  std::vector<kiwi::SparseFields<Field>::Element> tempFields;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0: {
        _fields = kiwi::SparseFields<Field>(tempFields.data(), tempFields.size(), _pool);
        return true;
      }
      case 1: {
        uint32_t _data_a = {};
        if (!_bb.readVarUint(_data_a)) return false;
        _flags[0] |= (1 << 0);
        tempFields.push_back({1, Field{._data_a = _data_a}});
        break;
      }
      case 2: {
        float _data_b = {};
        if (!_bb.readVarFloat(_data_b)) return false;
        _flags[0] |= (1 << 1);
        tempFields.push_back({2, Field{._data_b = _data_b}});
        break;
      }
      case 3: {
        if (!_bb.readVarUint(count)) return false;
        _flags[0] |= (1 << 2);
        kiwi::Array<uint32_t> _data_c = _pool.array<uint32_t>(count);
        for (uint32_t &_it : _data_c) if (!_bb.readVarUint(_it)) return false;
        tempFields.push_back({3, Field{._data_c = _data_c}});
        break;
      }
      case 4: {
        Enum _data_d = {};
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_d))) return false;
        _flags[0] |= (1 << 3);
        tempFields.push_back({4, Field{._data_d = _data_d}});
        break;
      }
      case 5: {
        ByteStruct* _data_e = _pool.allocate<ByteStruct>();
        if (!_data_e->decode(_bb, _pool, _schema)) return false;
        _flags[0] |= (1 << 4);
        tempFields.push_back({5, Field{._data_e = _data_e}});
        break;
      }
      case 6: {
        uint32_t _data_f = {};
        if (!_bb.readVarUint(_data_f)) return false;
        _flags[0] |= (1 << 5);
        tempFields.push_back({6, Field{._data_f = _data_f}});
        break;
      }
      case 7: {
        kiwi::String _data_g = {};
        if (!_bb.readString(_data_g, _pool)) return false;
        _flags[0] |= (1 << 6);
        tempFields.push_back({7, Field{._data_g = _data_g}});
        break;
      }
      case 8: {
        bool _data_h = {};
        if (!_bb.readBool(_data_h)) return false;
        _flags[0] |= (1 << 7);
        tempFields.push_back({8, Field{._data_h = _data_h}});
        break;
      }
      case 9: {
        if (!_bb.readVarUint(count)) return false;
        _flags[0] |= (1 << 8);
        kiwi::Array<Message> _data_i = _pool.array<Message>(count);
        for (Message &_it : _data_i) if (!_it.decode(_bb, _pool, _schema)) return false;
        tempFields.push_back({9, Field{._data_i = _data_i}});
        break;
      }
      default: {
        if (!_schema || !_schema->skipMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool Parent::encode(kiwi::WriteBuffer &_wb) const {
  if (a() != nullptr) {
    _wb.writeVarUint(1);
    if (!_data_a->encode(_wb)) return false;
  }
  _wb.writeVarUint(0);
  return true;
}

bool Parent::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        _data_a = _pool.allocate<Message>();
        if (!_data_a->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipParentField(_bb, type)) return false;
        break;
      }
    }
  }
}

#endif  // IMPLEMENT_SCHEMA_H

}  // namespace test_sparse
