#include "kiwi.h"

namespace test {

#ifndef INCLUDE_TEST_H
#define INCLUDE_TEST_H

class BinarySchema {
public:
  bool parse(kiwi::ByteBuffer &bb);
  const kiwi::BinarySchema &underlyingSchema() const { return _schema; }
  bool skipBoolMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipByteMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipIntMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipUintMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipInt64MessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipUint64MessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipFloatMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipStringMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipCompoundMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipNestedMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipBoolArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipByteArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipIntArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipUintArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipInt64ArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipUint64ArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipFloatArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipStringArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipCompoundArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipRecursiveMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipNonDeprecatedMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipDeprecatedMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;

private:
  kiwi::BinarySchema _schema;
  uint32_t _indexBoolMessage = 0;
  uint32_t _indexByteMessage = 0;
  uint32_t _indexIntMessage = 0;
  uint32_t _indexUintMessage = 0;
  uint32_t _indexInt64Message = 0;
  uint32_t _indexUint64Message = 0;
  uint32_t _indexFloatMessage = 0;
  uint32_t _indexStringMessage = 0;
  uint32_t _indexCompoundMessage = 0;
  uint32_t _indexNestedMessage = 0;
  uint32_t _indexBoolArrayMessage = 0;
  uint32_t _indexByteArrayMessage = 0;
  uint32_t _indexIntArrayMessage = 0;
  uint32_t _indexUintArrayMessage = 0;
  uint32_t _indexInt64ArrayMessage = 0;
  uint32_t _indexUint64ArrayMessage = 0;
  uint32_t _indexFloatArrayMessage = 0;
  uint32_t _indexStringArrayMessage = 0;
  uint32_t _indexCompoundArrayMessage = 0;
  uint32_t _indexRecursiveMessage = 0;
  uint32_t _indexNonDeprecatedMessage = 0;
  uint32_t _indexDeprecatedMessage = 0;
};

enum class Enum : uint32_t {
  A = 100,
  B = 200,
};

class EnumStruct;
class BoolStruct;
class ByteStruct;
class IntStruct;
class UintStruct;
class Int64Struct;
class Uint64Struct;
class FloatStruct;
class StringStruct;
class CompoundStruct;
class NestedStruct;
class BoolMessage;
class ByteMessage;
class IntMessage;
class UintMessage;
class Int64Message;
class Uint64Message;
class FloatMessage;
class StringMessage;
class CompoundMessage;
class NestedMessage;
class BoolArrayStruct;
class ByteArrayStruct;
class IntArrayStruct;
class UintArrayStruct;
class Int64ArrayStruct;
class Uint64ArrayStruct;
class FloatArrayStruct;
class StringArrayStruct;
class CompoundArrayStruct;
class BoolArrayMessage;
class ByteArrayMessage;
class IntArrayMessage;
class UintArrayMessage;
class Int64ArrayMessage;
class Uint64ArrayMessage;
class FloatArrayMessage;
class StringArrayMessage;
class CompoundArrayMessage;
class RecursiveMessage;
class NonDeprecatedMessage;
class DeprecatedMessage;
class SortedStruct;

class EnumStruct {
public:
  EnumStruct() { (void)_flags; }
  EnumStruct(const EnumStruct&) = delete;
  EnumStruct& operator=(const EnumStruct&) = delete;
  EnumStruct(EnumStruct&&) = default;
  EnumStruct& operator=(EnumStruct&&) = default;

  Enum *x();
  const Enum *x() const;
  void set_x(const Enum &value);

  kiwi::Array<Enum> *y();
  const kiwi::Array<Enum> *y() const;
  kiwi::Array<Enum> &set_y(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Enum _data_x = {};
  kiwi::Array<Enum> _data_y = {};
};

class BoolStruct {
public:
  BoolStruct() { (void)_flags; }
  BoolStruct(const BoolStruct&) = delete;
  BoolStruct& operator=(const BoolStruct&) = delete;
  BoolStruct(BoolStruct&&) = default;
  BoolStruct& operator=(BoolStruct&&) = default;

  bool *x();
  const bool *x() const;
  void set_x(const bool &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  bool _data_x = {};
};

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

class IntStruct {
public:
  IntStruct() { (void)_flags; }
  IntStruct(const IntStruct&) = delete;
  IntStruct& operator=(const IntStruct&) = delete;
  IntStruct(IntStruct&&) = default;
  IntStruct& operator=(IntStruct&&) = default;

  int32_t *x();
  const int32_t *x() const;
  void set_x(const int32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  int32_t _data_x = {};
};

class UintStruct {
public:
  UintStruct() { (void)_flags; }
  UintStruct(const UintStruct&) = delete;
  UintStruct& operator=(const UintStruct&) = delete;
  UintStruct(UintStruct&&) = default;
  UintStruct& operator=(UintStruct&&) = default;

  uint32_t *x();
  const uint32_t *x() const;
  void set_x(const uint32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_x = {};
};

class Int64Struct {
public:
  Int64Struct() { (void)_flags; }
  Int64Struct(const Int64Struct&) = delete;
  Int64Struct& operator=(const Int64Struct&) = delete;
  Int64Struct(Int64Struct&&) = default;
  Int64Struct& operator=(Int64Struct&&) = default;

  int64_t *x();
  const int64_t *x() const;
  void set_x(const int64_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  int64_t _data_x = {};
};

class Uint64Struct {
public:
  Uint64Struct() { (void)_flags; }
  Uint64Struct(const Uint64Struct&) = delete;
  Uint64Struct& operator=(const Uint64Struct&) = delete;
  Uint64Struct(Uint64Struct&&) = default;
  Uint64Struct& operator=(Uint64Struct&&) = default;

  uint64_t *x();
  const uint64_t *x() const;
  void set_x(const uint64_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint64_t _data_x = {};
};

class FloatStruct {
public:
  FloatStruct() { (void)_flags; }
  FloatStruct(const FloatStruct&) = delete;
  FloatStruct& operator=(const FloatStruct&) = delete;
  FloatStruct(FloatStruct&&) = default;
  FloatStruct& operator=(FloatStruct&&) = default;

  float *x();
  const float *x() const;
  void set_x(const float &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_x = {};
};

class StringStruct {
public:
  StringStruct() { (void)_flags; }
  StringStruct(const StringStruct&) = delete;
  StringStruct& operator=(const StringStruct&) = delete;
  StringStruct(StringStruct&&) = default;
  StringStruct& operator=(StringStruct&&) = default;

  kiwi::String *x();
  const kiwi::String *x() const;
  void set_x(const kiwi::String &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_x = {};
};

class CompoundStruct {
public:
  CompoundStruct() { (void)_flags; }
  CompoundStruct(const CompoundStruct&) = delete;
  CompoundStruct& operator=(const CompoundStruct&) = delete;
  CompoundStruct(CompoundStruct&&) = default;
  CompoundStruct& operator=(CompoundStruct&&) = default;

  uint32_t *x();
  const uint32_t *x() const;
  void set_x(const uint32_t &value);

  uint32_t *y();
  const uint32_t *y() const;
  void set_y(const uint32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_x = {};
  uint32_t _data_y = {};
};

class NestedStruct {
public:
  NestedStruct() { (void)_flags; }
  NestedStruct(const NestedStruct&) = delete;
  NestedStruct& operator=(const NestedStruct&) = delete;
  NestedStruct(NestedStruct&&) = default;
  NestedStruct& operator=(NestedStruct&&) = default;

  uint32_t *a();
  const uint32_t *a() const;
  void set_a(const uint32_t &value);

  CompoundStruct *b();
  const CompoundStruct *b() const;
  void set_b(CompoundStruct *value);

  uint32_t *c();
  const uint32_t *c() const;
  void set_c(const uint32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  CompoundStruct *_data_b = {};
  uint32_t _data_a = {};
  uint32_t _data_c = {};
};

class BoolMessage {
public:
  BoolMessage() { (void)_flags; }
  BoolMessage(BoolMessage&&) = default;
  BoolMessage& operator=(BoolMessage&&) = default;

  BoolMessage copy() const;

  bool *x();
  const bool *x() const;
  void set_x(const bool &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  BoolMessage(const BoolMessage&) = default;
  BoolMessage& operator=(const BoolMessage&) = default;
  uint32_t _flags[1] = {};
  bool _data_x = {};
};

class ByteMessage {
public:
  ByteMessage() { (void)_flags; }
  ByteMessage(ByteMessage&&) = default;
  ByteMessage& operator=(ByteMessage&&) = default;

  ByteMessage copy() const;

  uint8_t *x();
  const uint8_t *x() const;
  void set_x(const uint8_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  ByteMessage(const ByteMessage&) = default;
  ByteMessage& operator=(const ByteMessage&) = default;
  uint32_t _flags[1] = {};
  uint8_t _data_x = {};
};

class IntMessage {
public:
  IntMessage() { (void)_flags; }
  IntMessage(IntMessage&&) = default;
  IntMessage& operator=(IntMessage&&) = default;

  IntMessage copy() const;

  int32_t *x();
  const int32_t *x() const;
  void set_x(const int32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  IntMessage(const IntMessage&) = default;
  IntMessage& operator=(const IntMessage&) = default;
  uint32_t _flags[1] = {};
  int32_t _data_x = {};
};

class UintMessage {
public:
  UintMessage() { (void)_flags; }
  UintMessage(UintMessage&&) = default;
  UintMessage& operator=(UintMessage&&) = default;

  UintMessage copy() const;

  uint32_t *x();
  const uint32_t *x() const;
  void set_x(const uint32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  UintMessage(const UintMessage&) = default;
  UintMessage& operator=(const UintMessage&) = default;
  uint32_t _flags[1] = {};
  uint32_t _data_x = {};
};

class Int64Message {
public:
  Int64Message() { (void)_flags; }
  Int64Message(const Int64Message&) = delete;
  Int64Message& operator=(const Int64Message&) = delete;
  Int64Message(Int64Message&&) = default;
  Int64Message& operator=(Int64Message&&) = default;

  int64_t *x();
  const int64_t *x() const;
  void set_x(const int64_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  int64_t _data_x = {};
};

class Uint64Message {
public:
  Uint64Message() { (void)_flags; }
  Uint64Message(const Uint64Message&) = delete;
  Uint64Message& operator=(const Uint64Message&) = delete;
  Uint64Message(Uint64Message&&) = default;
  Uint64Message& operator=(Uint64Message&&) = default;

  uint64_t *x();
  const uint64_t *x() const;
  void set_x(const uint64_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint64_t _data_x = {};
};

class FloatMessage {
public:
  FloatMessage() { (void)_flags; }
  FloatMessage(FloatMessage&&) = default;
  FloatMessage& operator=(FloatMessage&&) = default;

  FloatMessage copy() const;

  float *x();
  const float *x() const;
  void set_x(const float &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  FloatMessage(const FloatMessage&) = default;
  FloatMessage& operator=(const FloatMessage&) = default;
  uint32_t _flags[1] = {};
  float _data_x = {};
};

class StringMessage {
public:
  StringMessage() { (void)_flags; }
  StringMessage(StringMessage&&) = default;
  StringMessage& operator=(StringMessage&&) = default;

  StringMessage copy() const;

  kiwi::String *x();
  const kiwi::String *x() const;
  void set_x(const kiwi::String &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  StringMessage(const StringMessage&) = default;
  StringMessage& operator=(const StringMessage&) = default;
  uint32_t _flags[1] = {};
  kiwi::String _data_x = {};
};

class CompoundMessage {
public:
  CompoundMessage() { (void)_flags; }
  CompoundMessage(CompoundMessage&&) = default;
  CompoundMessage& operator=(CompoundMessage&&) = default;

  CompoundMessage copy() const;

  uint32_t *x();
  const uint32_t *x() const;
  void set_x(const uint32_t &value);

  uint32_t *y();
  const uint32_t *y() const;
  void set_y(const uint32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  CompoundMessage(const CompoundMessage&) = default;
  CompoundMessage& operator=(const CompoundMessage&) = default;
  uint32_t _flags[1] = {};
  uint32_t _data_x = {};
  uint32_t _data_y = {};
};

class NestedMessage {
public:
  NestedMessage() { (void)_flags; }
  NestedMessage(NestedMessage&&) = default;
  NestedMessage& operator=(NestedMessage&&) = default;

  NestedMessage copy() const;

  uint32_t *a();
  const uint32_t *a() const;
  void set_a(const uint32_t &value);

  CompoundMessage *b();
  const CompoundMessage *b() const;
  void set_b(CompoundMessage *value);

  uint32_t *c();
  const uint32_t *c() const;
  void set_c(const uint32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  NestedMessage(const NestedMessage&) = default;
  NestedMessage& operator=(const NestedMessage&) = default;
  uint32_t _flags[1] = {};
  CompoundMessage *_data_b = {};
  uint32_t _data_a = {};
  uint32_t _data_c = {};
};

class BoolArrayStruct {
public:
  BoolArrayStruct() { (void)_flags; }
  BoolArrayStruct(const BoolArrayStruct&) = delete;
  BoolArrayStruct& operator=(const BoolArrayStruct&) = delete;
  BoolArrayStruct(BoolArrayStruct&&) = default;
  BoolArrayStruct& operator=(BoolArrayStruct&&) = default;

  kiwi::Array<bool> *x();
  const kiwi::Array<bool> *x() const;
  kiwi::Array<bool> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<bool> _data_x = {};
};

class ByteArrayStruct {
public:
  ByteArrayStruct() { (void)_flags; }
  ByteArrayStruct(const ByteArrayStruct&) = delete;
  ByteArrayStruct& operator=(const ByteArrayStruct&) = delete;
  ByteArrayStruct(ByteArrayStruct&&) = default;
  ByteArrayStruct& operator=(ByteArrayStruct&&) = default;

  kiwi::Array<uint8_t> *x();
  const kiwi::Array<uint8_t> *x() const;
  kiwi::Array<uint8_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint8_t> _data_x = {};
};

class IntArrayStruct {
public:
  IntArrayStruct() { (void)_flags; }
  IntArrayStruct(const IntArrayStruct&) = delete;
  IntArrayStruct& operator=(const IntArrayStruct&) = delete;
  IntArrayStruct(IntArrayStruct&&) = default;
  IntArrayStruct& operator=(IntArrayStruct&&) = default;

  kiwi::Array<int32_t> *x();
  const kiwi::Array<int32_t> *x() const;
  kiwi::Array<int32_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<int32_t> _data_x = {};
};

class UintArrayStruct {
public:
  UintArrayStruct() { (void)_flags; }
  UintArrayStruct(const UintArrayStruct&) = delete;
  UintArrayStruct& operator=(const UintArrayStruct&) = delete;
  UintArrayStruct(UintArrayStruct&&) = default;
  UintArrayStruct& operator=(UintArrayStruct&&) = default;

  kiwi::Array<uint32_t> *x();
  const kiwi::Array<uint32_t> *x() const;
  kiwi::Array<uint32_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint32_t> _data_x = {};
};

class Int64ArrayStruct {
public:
  Int64ArrayStruct() { (void)_flags; }
  Int64ArrayStruct(const Int64ArrayStruct&) = delete;
  Int64ArrayStruct& operator=(const Int64ArrayStruct&) = delete;
  Int64ArrayStruct(Int64ArrayStruct&&) = default;
  Int64ArrayStruct& operator=(Int64ArrayStruct&&) = default;

  kiwi::Array<int64_t> *x();
  const kiwi::Array<int64_t> *x() const;
  kiwi::Array<int64_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<int64_t> _data_x = {};
};

class Uint64ArrayStruct {
public:
  Uint64ArrayStruct() { (void)_flags; }
  Uint64ArrayStruct(const Uint64ArrayStruct&) = delete;
  Uint64ArrayStruct& operator=(const Uint64ArrayStruct&) = delete;
  Uint64ArrayStruct(Uint64ArrayStruct&&) = default;
  Uint64ArrayStruct& operator=(Uint64ArrayStruct&&) = default;

  kiwi::Array<uint64_t> *x();
  const kiwi::Array<uint64_t> *x() const;
  kiwi::Array<uint64_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint64_t> _data_x = {};
};

class FloatArrayStruct {
public:
  FloatArrayStruct() { (void)_flags; }
  FloatArrayStruct(const FloatArrayStruct&) = delete;
  FloatArrayStruct& operator=(const FloatArrayStruct&) = delete;
  FloatArrayStruct(FloatArrayStruct&&) = default;
  FloatArrayStruct& operator=(FloatArrayStruct&&) = default;

  kiwi::Array<float> *x();
  const kiwi::Array<float> *x() const;
  kiwi::Array<float> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<float> _data_x = {};
};

class StringArrayStruct {
public:
  StringArrayStruct() { (void)_flags; }
  StringArrayStruct(const StringArrayStruct&) = delete;
  StringArrayStruct& operator=(const StringArrayStruct&) = delete;
  StringArrayStruct(StringArrayStruct&&) = default;
  StringArrayStruct& operator=(StringArrayStruct&&) = default;

  kiwi::Array<kiwi::String> *x();
  const kiwi::Array<kiwi::String> *x() const;
  kiwi::Array<kiwi::String> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<kiwi::String> _data_x = {};
};

class CompoundArrayStruct {
public:
  CompoundArrayStruct() { (void)_flags; }
  CompoundArrayStruct(const CompoundArrayStruct&) = delete;
  CompoundArrayStruct& operator=(const CompoundArrayStruct&) = delete;
  CompoundArrayStruct(CompoundArrayStruct&&) = default;
  CompoundArrayStruct& operator=(CompoundArrayStruct&&) = default;

  kiwi::Array<uint32_t> *x();
  const kiwi::Array<uint32_t> *x() const;
  kiwi::Array<uint32_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<uint32_t> *y();
  const kiwi::Array<uint32_t> *y() const;
  kiwi::Array<uint32_t> &set_y(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint32_t> _data_x = {};
  kiwi::Array<uint32_t> _data_y = {};
};

class BoolArrayMessage {
public:
  BoolArrayMessage() { (void)_flags; }
  BoolArrayMessage(const BoolArrayMessage&) = delete;
  BoolArrayMessage& operator=(const BoolArrayMessage&) = delete;
  BoolArrayMessage(BoolArrayMessage&&) = default;
  BoolArrayMessage& operator=(BoolArrayMessage&&) = default;

  kiwi::Array<bool> *x();
  const kiwi::Array<bool> *x() const;
  kiwi::Array<bool> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<bool> _data_x = {};
};

class ByteArrayMessage {
public:
  ByteArrayMessage() { (void)_flags; }
  ByteArrayMessage(ByteArrayMessage&&) = default;
  ByteArrayMessage& operator=(ByteArrayMessage&&) = default;

  ByteArrayMessage copy() const;

  kiwi::Array<uint8_t> *x();
  const kiwi::Array<uint8_t> *x() const;
  kiwi::Array<uint8_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  ByteArrayMessage(const ByteArrayMessage&) = default;
  ByteArrayMessage& operator=(const ByteArrayMessage&) = default;
  uint32_t _flags[1] = {};
  kiwi::Array<uint8_t> _data_x = {};
};

class IntArrayMessage {
public:
  IntArrayMessage() { (void)_flags; }
  IntArrayMessage(const IntArrayMessage&) = delete;
  IntArrayMessage& operator=(const IntArrayMessage&) = delete;
  IntArrayMessage(IntArrayMessage&&) = default;
  IntArrayMessage& operator=(IntArrayMessage&&) = default;

  kiwi::Array<int32_t> *x();
  const kiwi::Array<int32_t> *x() const;
  kiwi::Array<int32_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<int32_t> _data_x = {};
};

class UintArrayMessage {
public:
  UintArrayMessage() { (void)_flags; }
  UintArrayMessage(const UintArrayMessage&) = delete;
  UintArrayMessage& operator=(const UintArrayMessage&) = delete;
  UintArrayMessage(UintArrayMessage&&) = default;
  UintArrayMessage& operator=(UintArrayMessage&&) = default;

  kiwi::Array<uint32_t> *x();
  const kiwi::Array<uint32_t> *x() const;
  kiwi::Array<uint32_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint32_t> _data_x = {};
};

class Int64ArrayMessage {
public:
  Int64ArrayMessage() { (void)_flags; }
  Int64ArrayMessage(const Int64ArrayMessage&) = delete;
  Int64ArrayMessage& operator=(const Int64ArrayMessage&) = delete;
  Int64ArrayMessage(Int64ArrayMessage&&) = default;
  Int64ArrayMessage& operator=(Int64ArrayMessage&&) = default;

  kiwi::Array<int64_t> *x();
  const kiwi::Array<int64_t> *x() const;
  kiwi::Array<int64_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<int64_t> _data_x = {};
};

class Uint64ArrayMessage {
public:
  Uint64ArrayMessage() { (void)_flags; }
  Uint64ArrayMessage(const Uint64ArrayMessage&) = delete;
  Uint64ArrayMessage& operator=(const Uint64ArrayMessage&) = delete;
  Uint64ArrayMessage(Uint64ArrayMessage&&) = default;
  Uint64ArrayMessage& operator=(Uint64ArrayMessage&&) = default;

  kiwi::Array<uint64_t> *x();
  const kiwi::Array<uint64_t> *x() const;
  kiwi::Array<uint64_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint64_t> _data_x = {};
};

class FloatArrayMessage {
public:
  FloatArrayMessage() { (void)_flags; }
  FloatArrayMessage(const FloatArrayMessage&) = delete;
  FloatArrayMessage& operator=(const FloatArrayMessage&) = delete;
  FloatArrayMessage(FloatArrayMessage&&) = default;
  FloatArrayMessage& operator=(FloatArrayMessage&&) = default;

  kiwi::Array<float> *x();
  const kiwi::Array<float> *x() const;
  kiwi::Array<float> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<float> _data_x = {};
};

class StringArrayMessage {
public:
  StringArrayMessage() { (void)_flags; }
  StringArrayMessage(const StringArrayMessage&) = delete;
  StringArrayMessage& operator=(const StringArrayMessage&) = delete;
  StringArrayMessage(StringArrayMessage&&) = default;
  StringArrayMessage& operator=(StringArrayMessage&&) = default;

  kiwi::Array<kiwi::String> *x();
  const kiwi::Array<kiwi::String> *x() const;
  kiwi::Array<kiwi::String> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<kiwi::String> _data_x = {};
};

class CompoundArrayMessage {
public:
  CompoundArrayMessage() { (void)_flags; }
  CompoundArrayMessage(const CompoundArrayMessage&) = delete;
  CompoundArrayMessage& operator=(const CompoundArrayMessage&) = delete;
  CompoundArrayMessage(CompoundArrayMessage&&) = default;
  CompoundArrayMessage& operator=(CompoundArrayMessage&&) = default;

  kiwi::Array<uint32_t> *x();
  const kiwi::Array<uint32_t> *x() const;
  kiwi::Array<uint32_t> &set_x(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<uint32_t> *y();
  const kiwi::Array<uint32_t> *y() const;
  kiwi::Array<uint32_t> &set_y(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint32_t> _data_x = {};
  kiwi::Array<uint32_t> _data_y = {};
};

class RecursiveMessage {
public:
  RecursiveMessage() { (void)_flags; }
  RecursiveMessage(const RecursiveMessage&) = delete;
  RecursiveMessage& operator=(const RecursiveMessage&) = delete;
  RecursiveMessage(RecursiveMessage&&) = default;
  RecursiveMessage& operator=(RecursiveMessage&&) = default;

  RecursiveMessage *x();
  const RecursiveMessage *x() const;
  void set_x(RecursiveMessage *value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  RecursiveMessage *_data_x = {};
};

class NonDeprecatedMessage {
public:
  NonDeprecatedMessage() { (void)_flags; }
  NonDeprecatedMessage(const NonDeprecatedMessage&) = delete;
  NonDeprecatedMessage& operator=(const NonDeprecatedMessage&) = delete;
  NonDeprecatedMessage(NonDeprecatedMessage&&) = default;
  NonDeprecatedMessage& operator=(NonDeprecatedMessage&&) = default;

  uint32_t *a();
  const uint32_t *a() const;
  void set_a(const uint32_t &value);

  uint32_t *b();
  const uint32_t *b() const;
  void set_b(const uint32_t &value);

  kiwi::Array<uint32_t> *c();
  const kiwi::Array<uint32_t> *c() const;
  kiwi::Array<uint32_t> &set_c(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<uint32_t> *d();
  const kiwi::Array<uint32_t> *d() const;
  kiwi::Array<uint32_t> &set_d(kiwi::MemoryPool &pool, uint32_t count);

  ByteStruct *e();
  const ByteStruct *e() const;
  void set_e(ByteStruct *value);

  ByteStruct *f();
  const ByteStruct *f() const;
  void set_f(ByteStruct *value);

  uint32_t *g();
  const uint32_t *g() const;
  void set_g(const uint32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint32_t> _data_c = {};
  kiwi::Array<uint32_t> _data_d = {};
  ByteStruct *_data_e = {};
  ByteStruct *_data_f = {};
  uint32_t _data_a = {};
  uint32_t _data_b = {};
  uint32_t _data_g = {};
};

class DeprecatedMessage {
public:
  DeprecatedMessage() { (void)_flags; }
  DeprecatedMessage(const DeprecatedMessage&) = delete;
  DeprecatedMessage& operator=(const DeprecatedMessage&) = delete;
  DeprecatedMessage(DeprecatedMessage&&) = default;
  DeprecatedMessage& operator=(DeprecatedMessage&&) = default;

  uint32_t *a();
  const uint32_t *a() const;
  void set_a(const uint32_t &value);

  kiwi::Array<uint32_t> *c();
  const kiwi::Array<uint32_t> *c() const;
  kiwi::Array<uint32_t> &set_c(kiwi::MemoryPool &pool, uint32_t count);

  ByteStruct *e();
  const ByteStruct *e() const;
  void set_e(ByteStruct *value);

  uint32_t *g();
  const uint32_t *g() const;
  void set_g(const uint32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint32_t> _data_c = {};
  ByteStruct *_data_e = {};
  uint32_t _data_a = {};
  uint32_t _data_g = {};
};

class SortedStruct {
public:
  SortedStruct() { (void)_flags; }
  SortedStruct(const SortedStruct&) = delete;
  SortedStruct& operator=(const SortedStruct&) = delete;
  SortedStruct(SortedStruct&&) = default;
  SortedStruct& operator=(SortedStruct&&) = default;

  bool *a1();
  const bool *a1() const;
  void set_a1(const bool &value);

  uint8_t *b1();
  const uint8_t *b1() const;
  void set_b1(const uint8_t &value);

  int32_t *c1();
  const int32_t *c1() const;
  void set_c1(const int32_t &value);

  uint32_t *d1();
  const uint32_t *d1() const;
  void set_d1(const uint32_t &value);

  float *e1();
  const float *e1() const;
  void set_e1(const float &value);

  kiwi::String *f1();
  const kiwi::String *f1() const;
  void set_f1(const kiwi::String &value);

  bool *a2();
  const bool *a2() const;
  void set_a2(const bool &value);

  uint8_t *b2();
  const uint8_t *b2() const;
  void set_b2(const uint8_t &value);

  int32_t *c2();
  const int32_t *c2() const;
  void set_c2(const int32_t &value);

  uint32_t *d2();
  const uint32_t *d2() const;
  void set_d2(const uint32_t &value);

  float *e2();
  const float *e2() const;
  void set_e2(const float &value);

  kiwi::String *f2();
  const kiwi::String *f2() const;
  void set_f2(const kiwi::String &value);

  kiwi::Array<bool> *a3();
  const kiwi::Array<bool> *a3() const;
  kiwi::Array<bool> &set_a3(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<uint8_t> *b3();
  const kiwi::Array<uint8_t> *b3() const;
  kiwi::Array<uint8_t> &set_b3(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<int32_t> *c3();
  const kiwi::Array<int32_t> *c3() const;
  kiwi::Array<int32_t> &set_c3(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<uint32_t> *d3();
  const kiwi::Array<uint32_t> *d3() const;
  kiwi::Array<uint32_t> &set_d3(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<float> *e3();
  const kiwi::Array<float> *e3() const;
  kiwi::Array<float> &set_e3(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<kiwi::String> *f3();
  const kiwi::Array<kiwi::String> *f3() const;
  kiwi::Array<kiwi::String> &set_f3(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_f1 = {};
  kiwi::String _data_f2 = {};
  kiwi::Array<bool> _data_a3 = {};
  kiwi::Array<uint8_t> _data_b3 = {};
  kiwi::Array<int32_t> _data_c3 = {};
  kiwi::Array<uint32_t> _data_d3 = {};
  kiwi::Array<float> _data_e3 = {};
  kiwi::Array<kiwi::String> _data_f3 = {};
  int32_t _data_c1 = {};
  uint32_t _data_d1 = {};
  float _data_e1 = {};
  int32_t _data_c2 = {};
  uint32_t _data_d2 = {};
  float _data_e2 = {};
  bool _data_a1 = {};
  uint8_t _data_b1 = {};
  bool _data_a2 = {};
  uint8_t _data_b2 = {};
};

inline Enum *EnumStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const Enum *EnumStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void EnumStruct::set_x(const Enum &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline kiwi::Array<Enum> *EnumStruct::y() {
  return _flags[0] & (1 << 1) ? &_data_y : nullptr;
}

inline const kiwi::Array<Enum> *EnumStruct::y() const {
  return _flags[0] & (1 << 1) ? &_data_y : nullptr;
}

inline kiwi::Array<Enum> &EnumStruct::set_y(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 1); return _data_y = pool.array<Enum>(count);
}

inline bool *BoolStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const bool *BoolStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void BoolStruct::set_x(const bool &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline uint8_t *ByteStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const uint8_t *ByteStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void ByteStruct::set_x(const uint8_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline int32_t *IntStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const int32_t *IntStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void IntStruct::set_x(const int32_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline uint32_t *UintStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const uint32_t *UintStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void UintStruct::set_x(const uint32_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline int64_t *Int64Struct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const int64_t *Int64Struct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void Int64Struct::set_x(const int64_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline uint64_t *Uint64Struct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const uint64_t *Uint64Struct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void Uint64Struct::set_x(const uint64_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline float *FloatStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const float *FloatStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void FloatStruct::set_x(const float &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline kiwi::String *StringStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::String *StringStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void StringStruct::set_x(const kiwi::String &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline uint32_t *CompoundStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const uint32_t *CompoundStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void CompoundStruct::set_x(const uint32_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline uint32_t *CompoundStruct::y() {
  return _flags[0] & (1 << 1) ? &_data_y : nullptr;
}

inline const uint32_t *CompoundStruct::y() const {
  return _flags[0] & (1 << 1) ? &_data_y : nullptr;
}

inline void CompoundStruct::set_y(const uint32_t &value) {
  _flags[0] |= (1 << 1); _data_y = value;
}

inline uint32_t *NestedStruct::a() {
  return _flags[0] & (1 << 0) ? &_data_a : nullptr;
}

inline const uint32_t *NestedStruct::a() const {
  return _flags[0] & (1 << 0) ? &_data_a : nullptr;
}

inline void NestedStruct::set_a(const uint32_t &value) {
  _flags[0] |= (1 << 0); _data_a = value;
}

inline CompoundStruct *NestedStruct::b() {
  return _data_b;
}

inline const CompoundStruct *NestedStruct::b() const {
  return _data_b;
}

inline void NestedStruct::set_b(CompoundStruct *value) {
  _data_b = value;
}

inline uint32_t *NestedStruct::c() {
  return _flags[0] & (1 << 2) ? &_data_c : nullptr;
}

inline const uint32_t *NestedStruct::c() const {
  return _flags[0] & (1 << 2) ? &_data_c : nullptr;
}

inline void NestedStruct::set_c(const uint32_t &value) {
  _flags[0] |= (1 << 2); _data_c = value;
}

inline BoolMessage BoolMessage::copy() const {
  BoolMessage clone = *this;
  return clone;
}

inline bool *BoolMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const bool *BoolMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void BoolMessage::set_x(const bool &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline ByteMessage ByteMessage::copy() const {
  ByteMessage clone = *this;
  return clone;
}

inline uint8_t *ByteMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const uint8_t *ByteMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void ByteMessage::set_x(const uint8_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline IntMessage IntMessage::copy() const {
  IntMessage clone = *this;
  return clone;
}

inline int32_t *IntMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const int32_t *IntMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void IntMessage::set_x(const int32_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline UintMessage UintMessage::copy() const {
  UintMessage clone = *this;
  return clone;
}

inline uint32_t *UintMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const uint32_t *UintMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void UintMessage::set_x(const uint32_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline int64_t *Int64Message::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const int64_t *Int64Message::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void Int64Message::set_x(const int64_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline uint64_t *Uint64Message::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const uint64_t *Uint64Message::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void Uint64Message::set_x(const uint64_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline FloatMessage FloatMessage::copy() const {
  FloatMessage clone = *this;
  return clone;
}

inline float *FloatMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const float *FloatMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void FloatMessage::set_x(const float &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline StringMessage StringMessage::copy() const {
  StringMessage clone = *this;
  return clone;
}

inline kiwi::String *StringMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::String *StringMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void StringMessage::set_x(const kiwi::String &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline CompoundMessage CompoundMessage::copy() const {
  CompoundMessage clone = *this;
  return clone;
}

inline uint32_t *CompoundMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const uint32_t *CompoundMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline void CompoundMessage::set_x(const uint32_t &value) {
  _flags[0] |= (1 << 0); _data_x = value;
}

inline uint32_t *CompoundMessage::y() {
  return _flags[0] & (1 << 1) ? &_data_y : nullptr;
}

inline const uint32_t *CompoundMessage::y() const {
  return _flags[0] & (1 << 1) ? &_data_y : nullptr;
}

inline void CompoundMessage::set_y(const uint32_t &value) {
  _flags[0] |= (1 << 1); _data_y = value;
}

inline NestedMessage NestedMessage::copy() const {
  NestedMessage clone = *this;
  return clone;
}

inline uint32_t *NestedMessage::a() {
  return _flags[0] & (1 << 0) ? &_data_a : nullptr;
}

inline const uint32_t *NestedMessage::a() const {
  return _flags[0] & (1 << 0) ? &_data_a : nullptr;
}

inline void NestedMessage::set_a(const uint32_t &value) {
  _flags[0] |= (1 << 0); _data_a = value;
}

inline CompoundMessage *NestedMessage::b() {
  return _data_b;
}

inline const CompoundMessage *NestedMessage::b() const {
  return _data_b;
}

inline void NestedMessage::set_b(CompoundMessage *value) {
  _data_b = value;
}

inline uint32_t *NestedMessage::c() {
  return _flags[0] & (1 << 2) ? &_data_c : nullptr;
}

inline const uint32_t *NestedMessage::c() const {
  return _flags[0] & (1 << 2) ? &_data_c : nullptr;
}

inline void NestedMessage::set_c(const uint32_t &value) {
  _flags[0] |= (1 << 2); _data_c = value;
}

inline kiwi::Array<bool> *BoolArrayStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<bool> *BoolArrayStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<bool> &BoolArrayStruct::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<bool>(count);
}

inline kiwi::Array<uint8_t> *ByteArrayStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<uint8_t> *ByteArrayStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<uint8_t> &ByteArrayStruct::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<uint8_t>(count);
}

inline kiwi::Array<int32_t> *IntArrayStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<int32_t> *IntArrayStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<int32_t> &IntArrayStruct::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<int32_t>(count);
}

inline kiwi::Array<uint32_t> *UintArrayStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<uint32_t> *UintArrayStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<uint32_t> &UintArrayStruct::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<uint32_t>(count);
}

inline kiwi::Array<int64_t> *Int64ArrayStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<int64_t> *Int64ArrayStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<int64_t> &Int64ArrayStruct::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<int64_t>(count);
}

inline kiwi::Array<uint64_t> *Uint64ArrayStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<uint64_t> *Uint64ArrayStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<uint64_t> &Uint64ArrayStruct::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<uint64_t>(count);
}

inline kiwi::Array<float> *FloatArrayStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<float> *FloatArrayStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<float> &FloatArrayStruct::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<float>(count);
}

inline kiwi::Array<kiwi::String> *StringArrayStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<kiwi::String> *StringArrayStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<kiwi::String> &StringArrayStruct::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<kiwi::String>(count);
}

inline kiwi::Array<uint32_t> *CompoundArrayStruct::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<uint32_t> *CompoundArrayStruct::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<uint32_t> &CompoundArrayStruct::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<uint32_t>(count);
}

inline kiwi::Array<uint32_t> *CompoundArrayStruct::y() {
  return _flags[0] & (1 << 1) ? &_data_y : nullptr;
}

inline const kiwi::Array<uint32_t> *CompoundArrayStruct::y() const {
  return _flags[0] & (1 << 1) ? &_data_y : nullptr;
}

inline kiwi::Array<uint32_t> &CompoundArrayStruct::set_y(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 1); return _data_y = pool.array<uint32_t>(count);
}

inline kiwi::Array<bool> *BoolArrayMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<bool> *BoolArrayMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<bool> &BoolArrayMessage::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<bool>(count);
}

inline ByteArrayMessage ByteArrayMessage::copy() const {
  ByteArrayMessage clone = *this;
  return clone;
}

inline kiwi::Array<uint8_t> *ByteArrayMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<uint8_t> *ByteArrayMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<uint8_t> &ByteArrayMessage::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<uint8_t>(count);
}

inline kiwi::Array<int32_t> *IntArrayMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<int32_t> *IntArrayMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<int32_t> &IntArrayMessage::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<int32_t>(count);
}

inline kiwi::Array<uint32_t> *UintArrayMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<uint32_t> *UintArrayMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<uint32_t> &UintArrayMessage::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<uint32_t>(count);
}

inline kiwi::Array<int64_t> *Int64ArrayMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<int64_t> *Int64ArrayMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<int64_t> &Int64ArrayMessage::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<int64_t>(count);
}

inline kiwi::Array<uint64_t> *Uint64ArrayMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<uint64_t> *Uint64ArrayMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<uint64_t> &Uint64ArrayMessage::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<uint64_t>(count);
}

inline kiwi::Array<float> *FloatArrayMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<float> *FloatArrayMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<float> &FloatArrayMessage::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<float>(count);
}

inline kiwi::Array<kiwi::String> *StringArrayMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<kiwi::String> *StringArrayMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<kiwi::String> &StringArrayMessage::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<kiwi::String>(count);
}

inline kiwi::Array<uint32_t> *CompoundArrayMessage::x() {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline const kiwi::Array<uint32_t> *CompoundArrayMessage::x() const {
  return _flags[0] & (1 << 0) ? &_data_x : nullptr;
}

inline kiwi::Array<uint32_t> &CompoundArrayMessage::set_x(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 0); return _data_x = pool.array<uint32_t>(count);
}

inline kiwi::Array<uint32_t> *CompoundArrayMessage::y() {
  return _flags[0] & (1 << 1) ? &_data_y : nullptr;
}

inline const kiwi::Array<uint32_t> *CompoundArrayMessage::y() const {
  return _flags[0] & (1 << 1) ? &_data_y : nullptr;
}

inline kiwi::Array<uint32_t> &CompoundArrayMessage::set_y(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 1); return _data_y = pool.array<uint32_t>(count);
}

inline RecursiveMessage *RecursiveMessage::x() {
  return _data_x;
}

inline const RecursiveMessage *RecursiveMessage::x() const {
  return _data_x;
}

inline void RecursiveMessage::set_x(RecursiveMessage *value) {
  _data_x = value;
}

inline uint32_t *NonDeprecatedMessage::a() {
  return _flags[0] & (1 << 0) ? &_data_a : nullptr;
}

inline const uint32_t *NonDeprecatedMessage::a() const {
  return _flags[0] & (1 << 0) ? &_data_a : nullptr;
}

inline void NonDeprecatedMessage::set_a(const uint32_t &value) {
  _flags[0] |= (1 << 0); _data_a = value;
}

inline uint32_t *NonDeprecatedMessage::b() {
  return _flags[0] & (1 << 1) ? &_data_b : nullptr;
}

inline const uint32_t *NonDeprecatedMessage::b() const {
  return _flags[0] & (1 << 1) ? &_data_b : nullptr;
}

inline void NonDeprecatedMessage::set_b(const uint32_t &value) {
  _flags[0] |= (1 << 1); _data_b = value;
}

inline kiwi::Array<uint32_t> *NonDeprecatedMessage::c() {
  return _flags[0] & (1 << 2) ? &_data_c : nullptr;
}

inline const kiwi::Array<uint32_t> *NonDeprecatedMessage::c() const {
  return _flags[0] & (1 << 2) ? &_data_c : nullptr;
}

inline kiwi::Array<uint32_t> &NonDeprecatedMessage::set_c(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 2); return _data_c = pool.array<uint32_t>(count);
}

inline kiwi::Array<uint32_t> *NonDeprecatedMessage::d() {
  return _flags[0] & (1 << 3) ? &_data_d : nullptr;
}

inline const kiwi::Array<uint32_t> *NonDeprecatedMessage::d() const {
  return _flags[0] & (1 << 3) ? &_data_d : nullptr;
}

inline kiwi::Array<uint32_t> &NonDeprecatedMessage::set_d(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 3); return _data_d = pool.array<uint32_t>(count);
}

inline ByteStruct *NonDeprecatedMessage::e() {
  return _data_e;
}

inline const ByteStruct *NonDeprecatedMessage::e() const {
  return _data_e;
}

inline void NonDeprecatedMessage::set_e(ByteStruct *value) {
  _data_e = value;
}

inline ByteStruct *NonDeprecatedMessage::f() {
  return _data_f;
}

inline const ByteStruct *NonDeprecatedMessage::f() const {
  return _data_f;
}

inline void NonDeprecatedMessage::set_f(ByteStruct *value) {
  _data_f = value;
}

inline uint32_t *NonDeprecatedMessage::g() {
  return _flags[0] & (1 << 6) ? &_data_g : nullptr;
}

inline const uint32_t *NonDeprecatedMessage::g() const {
  return _flags[0] & (1 << 6) ? &_data_g : nullptr;
}

inline void NonDeprecatedMessage::set_g(const uint32_t &value) {
  _flags[0] |= (1 << 6); _data_g = value;
}

inline uint32_t *DeprecatedMessage::a() {
  return _flags[0] & (1 << 0) ? &_data_a : nullptr;
}

inline const uint32_t *DeprecatedMessage::a() const {
  return _flags[0] & (1 << 0) ? &_data_a : nullptr;
}

inline void DeprecatedMessage::set_a(const uint32_t &value) {
  _flags[0] |= (1 << 0); _data_a = value;
}

inline kiwi::Array<uint32_t> *DeprecatedMessage::c() {
  return _flags[0] & (1 << 2) ? &_data_c : nullptr;
}

inline const kiwi::Array<uint32_t> *DeprecatedMessage::c() const {
  return _flags[0] & (1 << 2) ? &_data_c : nullptr;
}

inline kiwi::Array<uint32_t> &DeprecatedMessage::set_c(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 2); return _data_c = pool.array<uint32_t>(count);
}

inline ByteStruct *DeprecatedMessage::e() {
  return _data_e;
}

inline const ByteStruct *DeprecatedMessage::e() const {
  return _data_e;
}

inline void DeprecatedMessage::set_e(ByteStruct *value) {
  _data_e = value;
}

inline uint32_t *DeprecatedMessage::g() {
  return _flags[0] & (1 << 6) ? &_data_g : nullptr;
}

inline const uint32_t *DeprecatedMessage::g() const {
  return _flags[0] & (1 << 6) ? &_data_g : nullptr;
}

inline void DeprecatedMessage::set_g(const uint32_t &value) {
  _flags[0] |= (1 << 6); _data_g = value;
}

inline bool *SortedStruct::a1() {
  return _flags[0] & (1 << 0) ? &_data_a1 : nullptr;
}

inline const bool *SortedStruct::a1() const {
  return _flags[0] & (1 << 0) ? &_data_a1 : nullptr;
}

inline void SortedStruct::set_a1(const bool &value) {
  _flags[0] |= (1 << 0); _data_a1 = value;
}

inline uint8_t *SortedStruct::b1() {
  return _flags[0] & (1 << 1) ? &_data_b1 : nullptr;
}

inline const uint8_t *SortedStruct::b1() const {
  return _flags[0] & (1 << 1) ? &_data_b1 : nullptr;
}

inline void SortedStruct::set_b1(const uint8_t &value) {
  _flags[0] |= (1 << 1); _data_b1 = value;
}

inline int32_t *SortedStruct::c1() {
  return _flags[0] & (1 << 2) ? &_data_c1 : nullptr;
}

inline const int32_t *SortedStruct::c1() const {
  return _flags[0] & (1 << 2) ? &_data_c1 : nullptr;
}

inline void SortedStruct::set_c1(const int32_t &value) {
  _flags[0] |= (1 << 2); _data_c1 = value;
}

inline uint32_t *SortedStruct::d1() {
  return _flags[0] & (1 << 3) ? &_data_d1 : nullptr;
}

inline const uint32_t *SortedStruct::d1() const {
  return _flags[0] & (1 << 3) ? &_data_d1 : nullptr;
}

inline void SortedStruct::set_d1(const uint32_t &value) {
  _flags[0] |= (1 << 3); _data_d1 = value;
}

inline float *SortedStruct::e1() {
  return _flags[0] & (1 << 4) ? &_data_e1 : nullptr;
}

inline const float *SortedStruct::e1() const {
  return _flags[0] & (1 << 4) ? &_data_e1 : nullptr;
}

inline void SortedStruct::set_e1(const float &value) {
  _flags[0] |= (1 << 4); _data_e1 = value;
}

inline kiwi::String *SortedStruct::f1() {
  return _flags[0] & (1 << 5) ? &_data_f1 : nullptr;
}

inline const kiwi::String *SortedStruct::f1() const {
  return _flags[0] & (1 << 5) ? &_data_f1 : nullptr;
}

inline void SortedStruct::set_f1(const kiwi::String &value) {
  _flags[0] |= (1 << 5); _data_f1 = value;
}

inline bool *SortedStruct::a2() {
  return _flags[0] & (1 << 6) ? &_data_a2 : nullptr;
}

inline const bool *SortedStruct::a2() const {
  return _flags[0] & (1 << 6) ? &_data_a2 : nullptr;
}

inline void SortedStruct::set_a2(const bool &value) {
  _flags[0] |= (1 << 6); _data_a2 = value;
}

inline uint8_t *SortedStruct::b2() {
  return _flags[0] & (1 << 7) ? &_data_b2 : nullptr;
}

inline const uint8_t *SortedStruct::b2() const {
  return _flags[0] & (1 << 7) ? &_data_b2 : nullptr;
}

inline void SortedStruct::set_b2(const uint8_t &value) {
  _flags[0] |= (1 << 7); _data_b2 = value;
}

inline int32_t *SortedStruct::c2() {
  return _flags[0] & (1 << 8) ? &_data_c2 : nullptr;
}

inline const int32_t *SortedStruct::c2() const {
  return _flags[0] & (1 << 8) ? &_data_c2 : nullptr;
}

inline void SortedStruct::set_c2(const int32_t &value) {
  _flags[0] |= (1 << 8); _data_c2 = value;
}

inline uint32_t *SortedStruct::d2() {
  return _flags[0] & (1 << 9) ? &_data_d2 : nullptr;
}

inline const uint32_t *SortedStruct::d2() const {
  return _flags[0] & (1 << 9) ? &_data_d2 : nullptr;
}

inline void SortedStruct::set_d2(const uint32_t &value) {
  _flags[0] |= (1 << 9); _data_d2 = value;
}

inline float *SortedStruct::e2() {
  return _flags[0] & (1 << 10) ? &_data_e2 : nullptr;
}

inline const float *SortedStruct::e2() const {
  return _flags[0] & (1 << 10) ? &_data_e2 : nullptr;
}

inline void SortedStruct::set_e2(const float &value) {
  _flags[0] |= (1 << 10); _data_e2 = value;
}

inline kiwi::String *SortedStruct::f2() {
  return _flags[0] & (1 << 11) ? &_data_f2 : nullptr;
}

inline const kiwi::String *SortedStruct::f2() const {
  return _flags[0] & (1 << 11) ? &_data_f2 : nullptr;
}

inline void SortedStruct::set_f2(const kiwi::String &value) {
  _flags[0] |= (1 << 11); _data_f2 = value;
}

inline kiwi::Array<bool> *SortedStruct::a3() {
  return _flags[0] & (1 << 12) ? &_data_a3 : nullptr;
}

inline const kiwi::Array<bool> *SortedStruct::a3() const {
  return _flags[0] & (1 << 12) ? &_data_a3 : nullptr;
}

inline kiwi::Array<bool> &SortedStruct::set_a3(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 12); return _data_a3 = pool.array<bool>(count);
}

inline kiwi::Array<uint8_t> *SortedStruct::b3() {
  return _flags[0] & (1 << 13) ? &_data_b3 : nullptr;
}

inline const kiwi::Array<uint8_t> *SortedStruct::b3() const {
  return _flags[0] & (1 << 13) ? &_data_b3 : nullptr;
}

inline kiwi::Array<uint8_t> &SortedStruct::set_b3(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 13); return _data_b3 = pool.array<uint8_t>(count);
}

inline kiwi::Array<int32_t> *SortedStruct::c3() {
  return _flags[0] & (1 << 14) ? &_data_c3 : nullptr;
}

inline const kiwi::Array<int32_t> *SortedStruct::c3() const {
  return _flags[0] & (1 << 14) ? &_data_c3 : nullptr;
}

inline kiwi::Array<int32_t> &SortedStruct::set_c3(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 14); return _data_c3 = pool.array<int32_t>(count);
}

inline kiwi::Array<uint32_t> *SortedStruct::d3() {
  return _flags[0] & (1 << 15) ? &_data_d3 : nullptr;
}

inline const kiwi::Array<uint32_t> *SortedStruct::d3() const {
  return _flags[0] & (1 << 15) ? &_data_d3 : nullptr;
}

inline kiwi::Array<uint32_t> &SortedStruct::set_d3(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 15); return _data_d3 = pool.array<uint32_t>(count);
}

inline kiwi::Array<float> *SortedStruct::e3() {
  return _flags[0] & (1 << 16) ? &_data_e3 : nullptr;
}

inline const kiwi::Array<float> *SortedStruct::e3() const {
  return _flags[0] & (1 << 16) ? &_data_e3 : nullptr;
}

inline kiwi::Array<float> &SortedStruct::set_e3(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 16); return _data_e3 = pool.array<float>(count);
}

inline kiwi::Array<kiwi::String> *SortedStruct::f3() {
  return _flags[0] & (1 << 17) ? &_data_f3 : nullptr;
}

inline const kiwi::Array<kiwi::String> *SortedStruct::f3() const {
  return _flags[0] & (1 << 17) ? &_data_f3 : nullptr;
}

inline kiwi::Array<kiwi::String> &SortedStruct::set_f3(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= (1 << 17); return _data_f3 = pool.array<kiwi::String>(count);
}

#endif  // INCLUDE_TEST_H
#ifdef IMPLEMENT_SCHEMA_H

bool BinarySchema::parse(kiwi::ByteBuffer &bb) {
  if (!_schema.parse(bb)) return false;
  _schema.findDefinition("BoolMessage", _indexBoolMessage);
  _schema.findDefinition("ByteMessage", _indexByteMessage);
  _schema.findDefinition("IntMessage", _indexIntMessage);
  _schema.findDefinition("UintMessage", _indexUintMessage);
  _schema.findDefinition("Int64Message", _indexInt64Message);
  _schema.findDefinition("Uint64Message", _indexUint64Message);
  _schema.findDefinition("FloatMessage", _indexFloatMessage);
  _schema.findDefinition("StringMessage", _indexStringMessage);
  _schema.findDefinition("CompoundMessage", _indexCompoundMessage);
  _schema.findDefinition("NestedMessage", _indexNestedMessage);
  _schema.findDefinition("BoolArrayMessage", _indexBoolArrayMessage);
  _schema.findDefinition("ByteArrayMessage", _indexByteArrayMessage);
  _schema.findDefinition("IntArrayMessage", _indexIntArrayMessage);
  _schema.findDefinition("UintArrayMessage", _indexUintArrayMessage);
  _schema.findDefinition("Int64ArrayMessage", _indexInt64ArrayMessage);
  _schema.findDefinition("Uint64ArrayMessage", _indexUint64ArrayMessage);
  _schema.findDefinition("FloatArrayMessage", _indexFloatArrayMessage);
  _schema.findDefinition("StringArrayMessage", _indexStringArrayMessage);
  _schema.findDefinition("CompoundArrayMessage", _indexCompoundArrayMessage);
  _schema.findDefinition("RecursiveMessage", _indexRecursiveMessage);
  _schema.findDefinition("NonDeprecatedMessage", _indexNonDeprecatedMessage);
  _schema.findDefinition("DeprecatedMessage", _indexDeprecatedMessage);
  return true;
}

bool BinarySchema::skipBoolMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexBoolMessage, id);
}

bool BinarySchema::skipByteMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexByteMessage, id);
}

bool BinarySchema::skipIntMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexIntMessage, id);
}

bool BinarySchema::skipUintMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexUintMessage, id);
}

bool BinarySchema::skipInt64MessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexInt64Message, id);
}

bool BinarySchema::skipUint64MessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexUint64Message, id);
}

bool BinarySchema::skipFloatMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexFloatMessage, id);
}

bool BinarySchema::skipStringMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexStringMessage, id);
}

bool BinarySchema::skipCompoundMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexCompoundMessage, id);
}

bool BinarySchema::skipNestedMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexNestedMessage, id);
}

bool BinarySchema::skipBoolArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexBoolArrayMessage, id);
}

bool BinarySchema::skipByteArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexByteArrayMessage, id);
}

bool BinarySchema::skipIntArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexIntArrayMessage, id);
}

bool BinarySchema::skipUintArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexUintArrayMessage, id);
}

bool BinarySchema::skipInt64ArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexInt64ArrayMessage, id);
}

bool BinarySchema::skipUint64ArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexUint64ArrayMessage, id);
}

bool BinarySchema::skipFloatArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexFloatArrayMessage, id);
}

bool BinarySchema::skipStringArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexStringArrayMessage, id);
}

bool BinarySchema::skipCompoundArrayMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexCompoundArrayMessage, id);
}

bool BinarySchema::skipRecursiveMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexRecursiveMessage, id);
}

bool BinarySchema::skipNonDeprecatedMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexNonDeprecatedMessage, id);
}

bool BinarySchema::skipDeprecatedMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexDeprecatedMessage, id);
}

bool EnumStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(static_cast<uint32_t>(_data_x));
  if (y() == nullptr) return false;
  _wb.writeVarUint(_data_y.size());
  for (const Enum &_it : _data_y) _wb.writeVarUint(static_cast<uint32_t>(_it));
  return true;
}

bool EnumStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_x))) return false;
  set_x(_data_x);
  if (!_bb.readVarUint(count)) return false;
  for (Enum &_it : set_y(_pool, count)) if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_it))) return false;
  return true;
}

bool BoolStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeBool(_data_x);
  return true;
}

bool BoolStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readBool(_data_x)) return false;
  set_x(_data_x);
  return true;
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

bool IntStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarInt(_data_x);
  return true;
}

bool IntStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarInt(_data_x)) return false;
  set_x(_data_x);
  return true;
}

bool UintStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(_data_x);
  return true;
}

bool UintStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarUint(_data_x)) return false;
  set_x(_data_x);
  return true;
}

bool Int64Struct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarInt64(_data_x);
  return true;
}

bool Int64Struct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarInt64(_data_x)) return false;
  set_x(_data_x);
  return true;
}

bool Uint64Struct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint64(_data_x);
  return true;
}

bool Uint64Struct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarUint64(_data_x)) return false;
  set_x(_data_x);
  return true;
}

bool FloatStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarFloat(_data_x);
  return true;
}

bool FloatStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_x)) return false;
  set_x(_data_x);
  return true;
}

bool StringStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeString(_data_x.c_str());
  return true;
}

bool StringStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readString(_data_x, _pool)) return false;
  set_x(_data_x);
  return true;
}

bool CompoundStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(_data_x);
  if (y() == nullptr) return false;
  _wb.writeVarUint(_data_y);
  return true;
}

bool CompoundStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarUint(_data_x)) return false;
  set_x(_data_x);
  if (!_bb.readVarUint(_data_y)) return false;
  set_y(_data_y);
  return true;
}

bool NestedStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (a() == nullptr) return false;
  _wb.writeVarUint(_data_a);
  if (b() == nullptr) return false;
  if (!_data_b->encode(_wb)) return false;
  if (c() == nullptr) return false;
  _wb.writeVarUint(_data_c);
  return true;
}

bool NestedStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarUint(_data_a)) return false;
  set_a(_data_a);
  _data_b = _pool.allocate<CompoundStruct>();
  if (!_data_b->decode(_bb, _pool, _schema)) return false;
  if (!_bb.readVarUint(_data_c)) return false;
  set_c(_data_c);
  return true;
}

bool BoolMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeBool(_data_x);
  }
  _wb.writeVarUint(0);
  return true;
}

bool BoolMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readBool(_data_x)) return false;
        set_x(_data_x);
        break;
      }
      default: {
        if (!_schema || !_schema->skipBoolMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool ByteMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeByte(_data_x);
  }
  _wb.writeVarUint(0);
  return true;
}

bool ByteMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readByte(_data_x)) return false;
        set_x(_data_x);
        break;
      }
      default: {
        if (!_schema || !_schema->skipByteMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool IntMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarInt(_data_x);
  }
  _wb.writeVarUint(0);
  return true;
}

bool IntMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
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
      default: {
        if (!_schema || !_schema->skipIntMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool UintMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_x);
  }
  _wb.writeVarUint(0);
  return true;
}

bool UintMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_x)) return false;
        set_x(_data_x);
        break;
      }
      default: {
        if (!_schema || !_schema->skipUintMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool Int64Message::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarInt64(_data_x);
  }
  _wb.writeVarUint(0);
  return true;
}

bool Int64Message::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt64(_data_x)) return false;
        set_x(_data_x);
        break;
      }
      default: {
        if (!_schema || !_schema->skipInt64MessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool Uint64Message::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint64(_data_x);
  }
  _wb.writeVarUint(0);
  return true;
}

bool Uint64Message::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint64(_data_x)) return false;
        set_x(_data_x);
        break;
      }
      default: {
        if (!_schema || !_schema->skipUint64MessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool FloatMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarFloat(_data_x);
  }
  _wb.writeVarUint(0);
  return true;
}

bool FloatMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_x)) return false;
        set_x(_data_x);
        break;
      }
      default: {
        if (!_schema || !_schema->skipFloatMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool StringMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeString(_data_x.c_str());
  }
  _wb.writeVarUint(0);
  return true;
}

bool StringMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_x, _pool)) return false;
        set_x(_data_x);
        break;
      }
      default: {
        if (!_schema || !_schema->skipStringMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool CompoundMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_x);
  }
  if (y() != nullptr) {
    _wb.writeVarUint(2);
    _wb.writeVarUint(_data_y);
  }
  _wb.writeVarUint(0);
  return true;
}

bool CompoundMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_x)) return false;
        set_x(_data_x);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_y)) return false;
        set_y(_data_y);
        break;
      }
      default: {
        if (!_schema || !_schema->skipCompoundMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool NestedMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (a() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_a);
  }
  if (b() != nullptr) {
    _wb.writeVarUint(2);
    if (!_data_b->encode(_wb)) return false;
  }
  if (c() != nullptr) {
    _wb.writeVarUint(3);
    _wb.writeVarUint(_data_c);
  }
  _wb.writeVarUint(0);
  return true;
}

bool NestedMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_a)) return false;
        set_a(_data_a);
        break;
      }
      case 2: {
        _data_b = _pool.allocate<CompoundMessage>();
        if (!_data_b->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_c)) return false;
        set_c(_data_c);
        break;
      }
      default: {
        if (!_schema || !_schema->skipNestedMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool BoolArrayStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(_data_x.size());
  for (const bool &_it : _data_x) _wb.writeBool(_it);
  return true;
}

bool BoolArrayStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  if (!_bb.readVarUint(count)) return false;
  for (bool &_it : set_x(_pool, count)) if (!_bb.readBool(_it)) return false;
  return true;
}

bool ByteArrayStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(_data_x.size());
  for (const uint8_t &_it : _data_x) _wb.writeByte(_it);
  return true;
}

bool ByteArrayStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  if (!_bb.readVarUint(count)) return false;
  if (!_bb.readByteArray(set_x(_pool, count).data(), count)) return false;
  return true;
}

bool IntArrayStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(_data_x.size());
  for (const int32_t &_it : _data_x) _wb.writeVarInt(_it);
  return true;
}

bool IntArrayStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  if (!_bb.readVarUint(count)) return false;
  for (int32_t &_it : set_x(_pool, count)) if (!_bb.readVarInt(_it)) return false;
  return true;
}

bool UintArrayStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(_data_x.size());
  for (const uint32_t &_it : _data_x) _wb.writeVarUint(_it);
  return true;
}

bool UintArrayStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  if (!_bb.readVarUint(count)) return false;
  for (uint32_t &_it : set_x(_pool, count)) if (!_bb.readVarUint(_it)) return false;
  return true;
}

bool Int64ArrayStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(_data_x.size());
  for (const int64_t &_it : _data_x) _wb.writeVarInt64(_it);
  return true;
}

bool Int64ArrayStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  if (!_bb.readVarUint(count)) return false;
  for (int64_t &_it : set_x(_pool, count)) if (!_bb.readVarInt64(_it)) return false;
  return true;
}

bool Uint64ArrayStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(_data_x.size());
  for (const uint64_t &_it : _data_x) _wb.writeVarUint64(_it);
  return true;
}

bool Uint64ArrayStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  if (!_bb.readVarUint(count)) return false;
  for (uint64_t &_it : set_x(_pool, count)) if (!_bb.readVarUint64(_it)) return false;
  return true;
}

bool FloatArrayStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(_data_x.size());
  for (const float &_it : _data_x) _wb.writeVarFloat(_it);
  return true;
}

bool FloatArrayStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  if (!_bb.readVarUint(count)) return false;
  for (float &_it : set_x(_pool, count)) if (!_bb.readVarFloat(_it)) return false;
  return true;
}

bool StringArrayStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(_data_x.size());
  for (const kiwi::String &_it : _data_x) _wb.writeString(_it.c_str());
  return true;
}

bool StringArrayStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  if (!_bb.readVarUint(count)) return false;
  for (kiwi::String &_it : set_x(_pool, count)) if (!_bb.readString(_it, _pool)) return false;
  return true;
}

bool CompoundArrayStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (x() == nullptr) return false;
  _wb.writeVarUint(_data_x.size());
  for (const uint32_t &_it : _data_x) _wb.writeVarUint(_it);
  if (y() == nullptr) return false;
  _wb.writeVarUint(_data_y.size());
  for (const uint32_t &_it : _data_y) _wb.writeVarUint(_it);
  return true;
}

bool CompoundArrayStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  if (!_bb.readVarUint(count)) return false;
  for (uint32_t &_it : set_x(_pool, count)) if (!_bb.readVarUint(_it)) return false;
  if (!_bb.readVarUint(count)) return false;
  for (uint32_t &_it : set_y(_pool, count)) if (!_bb.readVarUint(_it)) return false;
  return true;
}

bool BoolArrayMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_x.size());
    for (const bool &_it : _data_x) _wb.writeBool(_it);
  }
  _wb.writeVarUint(0);
  return true;
}

bool BoolArrayMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(count)) return false;
        for (bool &_it : set_x(_pool, count)) if (!_bb.readBool(_it)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipBoolArrayMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool ByteArrayMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_x.size());
    for (const uint8_t &_it : _data_x) _wb.writeByte(_it);
  }
  _wb.writeVarUint(0);
  return true;
}

bool ByteArrayMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(count)) return false;
        if (!_bb.readByteArray(set_x(_pool, count).data(), count)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipByteArrayMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool IntArrayMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_x.size());
    for (const int32_t &_it : _data_x) _wb.writeVarInt(_it);
  }
  _wb.writeVarUint(0);
  return true;
}

bool IntArrayMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(count)) return false;
        for (int32_t &_it : set_x(_pool, count)) if (!_bb.readVarInt(_it)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipIntArrayMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool UintArrayMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_x.size());
    for (const uint32_t &_it : _data_x) _wb.writeVarUint(_it);
  }
  _wb.writeVarUint(0);
  return true;
}

bool UintArrayMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(count)) return false;
        for (uint32_t &_it : set_x(_pool, count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipUintArrayMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool Int64ArrayMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_x.size());
    for (const int64_t &_it : _data_x) _wb.writeVarInt64(_it);
  }
  _wb.writeVarUint(0);
  return true;
}

bool Int64ArrayMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(count)) return false;
        for (int64_t &_it : set_x(_pool, count)) if (!_bb.readVarInt64(_it)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipInt64ArrayMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool Uint64ArrayMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_x.size());
    for (const uint64_t &_it : _data_x) _wb.writeVarUint64(_it);
  }
  _wb.writeVarUint(0);
  return true;
}

bool Uint64ArrayMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(count)) return false;
        for (uint64_t &_it : set_x(_pool, count)) if (!_bb.readVarUint64(_it)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipUint64ArrayMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool FloatArrayMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_x.size());
    for (const float &_it : _data_x) _wb.writeVarFloat(_it);
  }
  _wb.writeVarUint(0);
  return true;
}

bool FloatArrayMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(count)) return false;
        for (float &_it : set_x(_pool, count)) if (!_bb.readVarFloat(_it)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipFloatArrayMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool StringArrayMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_x.size());
    for (const kiwi::String &_it : _data_x) _wb.writeString(_it.c_str());
  }
  _wb.writeVarUint(0);
  return true;
}

bool StringArrayMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(count)) return false;
        for (kiwi::String &_it : set_x(_pool, count)) if (!_bb.readString(_it, _pool)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipStringArrayMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool CompoundArrayMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_x.size());
    for (const uint32_t &_it : _data_x) _wb.writeVarUint(_it);
  }
  if (y() != nullptr) {
    _wb.writeVarUint(2);
    _wb.writeVarUint(_data_y.size());
    for (const uint32_t &_it : _data_y) _wb.writeVarUint(_it);
  }
  _wb.writeVarUint(0);
  return true;
}

bool CompoundArrayMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(count)) return false;
        for (uint32_t &_it : set_x(_pool, count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(count)) return false;
        for (uint32_t &_it : set_y(_pool, count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipCompoundArrayMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool RecursiveMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (x() != nullptr) {
    _wb.writeVarUint(1);
    if (!_data_x->encode(_wb)) return false;
  }
  _wb.writeVarUint(0);
  return true;
}

bool RecursiveMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        _data_x = _pool.allocate<RecursiveMessage>();
        if (!_data_x->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipRecursiveMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool NonDeprecatedMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (a() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_a);
  }
  if (b() != nullptr) {
    _wb.writeVarUint(2);
    _wb.writeVarUint(_data_b);
  }
  if (c() != nullptr) {
    _wb.writeVarUint(3);
    _wb.writeVarUint(_data_c.size());
    for (const uint32_t &_it : _data_c) _wb.writeVarUint(_it);
  }
  if (d() != nullptr) {
    _wb.writeVarUint(4);
    _wb.writeVarUint(_data_d.size());
    for (const uint32_t &_it : _data_d) _wb.writeVarUint(_it);
  }
  if (e() != nullptr) {
    _wb.writeVarUint(5);
    if (!_data_e->encode(_wb)) return false;
  }
  if (f() != nullptr) {
    _wb.writeVarUint(6);
    if (!_data_f->encode(_wb)) return false;
  }
  if (g() != nullptr) {
    _wb.writeVarUint(7);
    _wb.writeVarUint(_data_g);
  }
  _wb.writeVarUint(0);
  return true;
}

bool NonDeprecatedMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_a)) return false;
        set_a(_data_a);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_b)) return false;
        set_b(_data_b);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(count)) return false;
        for (uint32_t &_it : set_c(_pool, count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarUint(count)) return false;
        for (uint32_t &_it : set_d(_pool, count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      case 5: {
        _data_e = _pool.allocate<ByteStruct>();
        if (!_data_e->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        _data_f = _pool.allocate<ByteStruct>();
        if (!_data_f->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        if (!_bb.readVarUint(_data_g)) return false;
        set_g(_data_g);
        break;
      }
      default: {
        if (!_schema || !_schema->skipNonDeprecatedMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool DeprecatedMessage::encode(kiwi::WriteBuffer &_wb) const {
  if (a() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarUint(_data_a);
  }
  if (c() != nullptr) {
    _wb.writeVarUint(3);
    _wb.writeVarUint(_data_c.size());
    for (const uint32_t &_it : _data_c) _wb.writeVarUint(_it);
  }
  if (e() != nullptr) {
    _wb.writeVarUint(5);
    if (!_data_e->encode(_wb)) return false;
  }
  if (g() != nullptr) {
    _wb.writeVarUint(7);
    _wb.writeVarUint(_data_g);
  }
  _wb.writeVarUint(0);
  return true;
}

bool DeprecatedMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  while (true) {
    uint32_t type;
    if (!_bb.readVarUint(type)) return false;
    switch (type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_a)) return false;
        set_a(_data_a);
        break;
      }
      case 2: {
        uint32_t _data_b = {};
        if (!_bb.readVarUint(_data_b)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(count)) return false;
        for (uint32_t &_it : set_c(_pool, count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarUint(count)) return false;
        for (uint32_t &_it : _pool.array<uint32_t>(count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      case 5: {
        _data_e = _pool.allocate<ByteStruct>();
        if (!_data_e->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        ByteStruct *_data_f = _pool.allocate<ByteStruct>();
        if (!_data_f->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        if (!_bb.readVarUint(_data_g)) return false;
        set_g(_data_g);
        break;
      }
      default: {
        if (!_schema || !_schema->skipDeprecatedMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

bool SortedStruct::encode(kiwi::WriteBuffer &_wb) const {
  if (a1() == nullptr) return false;
  _wb.writeBool(_data_a1);
  if (b1() == nullptr) return false;
  _wb.writeByte(_data_b1);
  if (c1() == nullptr) return false;
  _wb.writeVarInt(_data_c1);
  if (d1() == nullptr) return false;
  _wb.writeVarUint(_data_d1);
  if (e1() == nullptr) return false;
  _wb.writeVarFloat(_data_e1);
  if (f1() == nullptr) return false;
  _wb.writeString(_data_f1.c_str());
  if (a2() == nullptr) return false;
  _wb.writeBool(_data_a2);
  if (b2() == nullptr) return false;
  _wb.writeByte(_data_b2);
  if (c2() == nullptr) return false;
  _wb.writeVarInt(_data_c2);
  if (d2() == nullptr) return false;
  _wb.writeVarUint(_data_d2);
  if (e2() == nullptr) return false;
  _wb.writeVarFloat(_data_e2);
  if (f2() == nullptr) return false;
  _wb.writeString(_data_f2.c_str());
  if (a3() == nullptr) return false;
  _wb.writeVarUint(_data_a3.size());
  for (const bool &_it : _data_a3) _wb.writeBool(_it);
  if (b3() == nullptr) return false;
  _wb.writeVarUint(_data_b3.size());
  for (const uint8_t &_it : _data_b3) _wb.writeByte(_it);
  if (c3() == nullptr) return false;
  _wb.writeVarUint(_data_c3.size());
  for (const int32_t &_it : _data_c3) _wb.writeVarInt(_it);
  if (d3() == nullptr) return false;
  _wb.writeVarUint(_data_d3.size());
  for (const uint32_t &_it : _data_d3) _wb.writeVarUint(_it);
  if (e3() == nullptr) return false;
  _wb.writeVarUint(_data_e3.size());
  for (const float &_it : _data_e3) _wb.writeVarFloat(_it);
  if (f3() == nullptr) return false;
  _wb.writeVarUint(_data_f3.size());
  for (const kiwi::String &_it : _data_f3) _wb.writeString(_it.c_str());
  return true;
}

bool SortedStruct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t count;
  if (!_bb.readBool(_data_a1)) return false;
  set_a1(_data_a1);
  if (!_bb.readByte(_data_b1)) return false;
  set_b1(_data_b1);
  if (!_bb.readVarInt(_data_c1)) return false;
  set_c1(_data_c1);
  if (!_bb.readVarUint(_data_d1)) return false;
  set_d1(_data_d1);
  if (!_bb.readVarFloat(_data_e1)) return false;
  set_e1(_data_e1);
  if (!_bb.readString(_data_f1, _pool)) return false;
  set_f1(_data_f1);
  if (!_bb.readBool(_data_a2)) return false;
  set_a2(_data_a2);
  if (!_bb.readByte(_data_b2)) return false;
  set_b2(_data_b2);
  if (!_bb.readVarInt(_data_c2)) return false;
  set_c2(_data_c2);
  if (!_bb.readVarUint(_data_d2)) return false;
  set_d2(_data_d2);
  if (!_bb.readVarFloat(_data_e2)) return false;
  set_e2(_data_e2);
  if (!_bb.readString(_data_f2, _pool)) return false;
  set_f2(_data_f2);
  if (!_bb.readVarUint(count)) return false;
  for (bool &_it : set_a3(_pool, count)) if (!_bb.readBool(_it)) return false;
  if (!_bb.readVarUint(count)) return false;
  if (!_bb.readByteArray(set_b3(_pool, count).data(), count)) return false;
  if (!_bb.readVarUint(count)) return false;
  for (int32_t &_it : set_c3(_pool, count)) if (!_bb.readVarInt(_it)) return false;
  if (!_bb.readVarUint(count)) return false;
  for (uint32_t &_it : set_d3(_pool, count)) if (!_bb.readVarUint(_it)) return false;
  if (!_bb.readVarUint(count)) return false;
  for (float &_it : set_e3(_pool, count)) if (!_bb.readVarFloat(_it)) return false;
  if (!_bb.readVarUint(count)) return false;
  for (kiwi::String &_it : set_f3(_pool, count)) if (!_bb.readString(_it, _pool)) return false;
  return true;
}

#endif  // IMPLEMENT_SCHEMA_H

}  // namespace test
