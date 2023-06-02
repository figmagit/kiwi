#include "kiwi.h"

namespace test2 {

#ifndef INCLUDE_TEST2_H
#define INCLUDE_TEST2_H

class BinarySchema {
public:
  bool parse(kiwi::ByteBuffer &bb);
  const kiwi::BinarySchema &underlyingSchema() const { return _schema; }
  bool skipMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipMessage2Field(kiwi::ByteBuffer &bb, uint32_t id) const;

private:
  kiwi::BinarySchema _schema;
  uint32_t _indexMessage = 0;
  uint32_t _indexMessage2 = 0;
};

class Struct;
class Message;
class Struct2;
class Message2;

class Struct {
public:
  Struct() { (void)_flags; }
  Struct(const Struct&) = delete;
  Struct& operator=(const Struct&) = delete;
  Struct(Struct&&) = default;
  Struct& operator=(Struct&&) = default;

  float *a();
  const float *a() const;
  void set_a(const float &value);

  float *b();
  const float *b() const;
  void set_b(const float &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_a = {};
  float _data_b = {};
};

class Message {
public:
  Message() { (void)_flags; }
  Message(const Message&) = delete;
  Message& operator=(const Message&) = delete;
  Message(Message&&) = default;
  Message& operator=(Message&&) = default;

  int32_t *x();
  const int32_t *x() const;
  void set_x(const int32_t &value);

  Struct *y();
  const Struct *y() const;
  void set_y(Struct *value);

  Struct2 *z();
  const Struct2 *z() const;
  void set_z(Struct2 *value);

  Message *c();
  const Message *c() const;
  void set_c(Message *value);

  Message2 *d();
  const Message2 *d() const;
  void set_d(Message2 *value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Struct *_data_y = {};
  Struct2 *_data_z = {};
  Message *_data_c = {};
  Message2 *_data_d = {};
  int32_t _data_x = {};
};

class Struct2 {
public:
  Struct2() { (void)_flags; }
  Struct2(const Struct2&) = delete;
  Struct2& operator=(const Struct2&) = delete;
  Struct2(Struct2&&) = default;
  Struct2& operator=(Struct2&&) = default;

  bool *u();
  const bool *u() const;
  void set_u(const bool &value);

  bool *v();
  const bool *v() const;
  void set_v(const bool &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  bool _data_u = {};
  bool _data_v = {};
};

class Message2 {
public:
  Message2() { (void)_flags; }
  Message2(const Message2&) = delete;
  Message2& operator=(const Message2&) = delete;
  Message2(Message2&&) = default;
  Message2& operator=(Message2&&) = default;

  kiwi::String *e();
  const kiwi::String *e() const;
  void set_e(const kiwi::String &value);

  kiwi::String *f();
  const kiwi::String *f() const;
  void set_f(const kiwi::String &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_e = {};
  kiwi::String _data_f = {};
};

inline float *Struct::a() {
  return _flags[0] & (1 << 0) ? &_data_a : nullptr;
}

inline const float *Struct::a() const {
  return _flags[0] & (1 << 0) ? &_data_a : nullptr;
}

inline void Struct::set_a(const float &value) {
  _flags[0] |= (1 << 0); _data_a = value;
}

inline float *Struct::b() {
  return _flags[0] & (1 << 1) ? &_data_b : nullptr;
}

inline const float *Struct::b() const {
  return _flags[0] & (1 << 1) ? &_data_b : nullptr;
}

inline void Struct::set_b(const float &value) {
  _flags[0] |= (1 << 1); _data_b = value;
}

inline int32_t *Message::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const int32_t *Message::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void Message::set_x(const int32_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline Struct *Message::y() {
  return _data_y;
}

inline const Struct *Message::y() const {
  return _data_y;
}

inline void Message::set_y(Struct *value) {
  _data_y = value;
}

inline Struct2 *Message::z() {
  return _data_z;
}

inline const Struct2 *Message::z() const {
  return _data_z;
}

inline void Message::set_z(Struct2 *value) {
  _data_z = value;
}

inline Message *Message::c() {
  return _data_c;
}

inline const Message *Message::c() const {
  return _data_c;
}

inline void Message::set_c(Message *value) {
  _data_c = value;
}

inline Message2 *Message::d() {
  return _data_d;
}

inline const Message2 *Message::d() const {
  return _data_d;
}

inline void Message::set_d(Message2 *value) {
  _data_d = value;
}

inline bool *Struct2::u() {
  return _flags[0] & (1 << 0) ? &_data_u : nullptr;
}

inline const bool *Struct2::u() const {
  return _flags[0] & (1 << 0) ? &_data_u : nullptr;
}

inline void Struct2::set_u(const bool &value) {
  _flags[0] |= (1 << 0); _data_u = value;
}

inline bool *Struct2::v() {
  return _flags[0] & (1 << 1) ? &_data_v : nullptr;
}

inline const bool *Struct2::v() const {
  return _flags[0] & (1 << 1) ? &_data_v : nullptr;
}

inline void Struct2::set_v(const bool &value) {
  _flags[0] |= (1 << 1); _data_v = value;
}

inline kiwi::String *Message2::e() {
  return _flags[0] & (1 << 0) ? &_data_e : nullptr;
}

inline const kiwi::String *Message2::e() const {
  return _flags[0] & (1 << 0) ? &_data_e : nullptr;
}

inline void Message2::set_e(const kiwi::String &value) {
  _flags[0] |= (1 << 0); _data_e = value;
}

inline kiwi::String *Message2::f() {
  return _flags[0] & (1 << 1) ? &_data_f : nullptr;
}

inline const kiwi::String *Message2::f() const {
  return _flags[0] & (1 << 1) ? &_data_f : nullptr;
}

inline void Message2::set_f(const kiwi::String &value) {
  _flags[0] |= (1 << 1); _data_f = value;
}

#endif  // INCLUDE_TEST2_H
#ifdef IMPLEMENT_SCHEMA_H

bool BinarySchema::parse(kiwi::ByteBuffer &bb) {
  if (!_schema.parse(bb)) return false;
  _schema.findDefinition("Message", _indexMessage);
  _schema.findDefinition("Message2", _indexMessage2);
  return true;
}

bool BinarySchema::skipMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMessage, id);
}

bool BinarySchema::skipMessage2Field(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMessage2, id);
}

bool Struct::encode(kiwi::WriteBuffer &_wb) const {
  if (a() == nullptr) return false;
  _wb.writeVarFloat(_data_a);
  if (b() == nullptr) return false;
  _wb.writeVarFloat(_data_b);
  return true;
}

bool Struct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_a)) return false;
  set_a(_data_a);
  if (!_bb.readVarFloat(_data_b)) return false;
  set_b(_data_b);
  return true;
}

bool Message::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarInt(_data_x);
  }
  if (y() != nullptr) {
    _wb.writeVarUint(2);
    if (!_data_y->encode(_wb)) return false;
  }
  if (z() != nullptr) {
    _wb.writeVarUint(3);
    if (!_data_z->encode(_wb)) return false;
  }
  if (c() != nullptr) {
    _wb.writeVarUint(4);
    if (!_data_c->encode(_wb)) return false;
  }
  if (d() != nullptr) {
    _wb.writeVarUint(5);
    if (!_data_d->encode(_wb)) return false;
  }
  _wb.writeVarUint(0);
  return true;
}

bool Message::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_x)) return false;
        set_x(_data_x);
        break;
      }
      case 2: {
        _data_y = _pool.allocate<Struct>();
        if (!_data_y->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_z = _pool.allocate<Struct2>();
        if (!_data_z->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_c = _pool.allocate<Message>();
        if (!_data_c->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        _data_d = _pool.allocate<Message2>();
        if (!_data_d->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool Struct2::encode(kiwi::WriteBuffer &_wb) const {
  if (u() == nullptr) return false;
  _wb.writeBool(_data_u);
  if (v() == nullptr) return false;
  _wb.writeBool(_data_v);
  return true;
}

bool Struct2::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readBool(_data_u)) return false;
  set_u(_data_u);
  if (!_bb.readBool(_data_v)) return false;
  set_v(_data_v);
  return true;
}

bool Message2::encode(kiwi::WriteBuffer &_wb) const {
  if (e() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeString(_data_e.c_str());
  }
  if (f() != nullptr) {
    _wb.writeVarUint(2);
    _wb.writeString(_data_f.c_str());
  }
  _wb.writeVarUint(0);
  return true;
}

bool Message2::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_e, _pool)) return false;
        set_e(_data_e);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_f, _pool)) return false;
        set_f(_data_f);
        break;
      }
      default: {
        if (!_schema || !_schema->skipMessage2Field(_bb, type)) return false;
        break;
      }
    }
  }
}

#endif  // IMPLEMENT_SCHEMA_H

}  // namespace test2
