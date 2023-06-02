// ../js/cli.js --schema test-schema.kiwi --cpp test-schema.h && c++ test.cpp -std=c++11 -I.. && ./a.out

#include <limits>
#include <stdio.h>
#include <string>
#include <vector>

#include "catch2/catch_all.hpp"

#define IMPLEMENT_SCHEMA_H
#include "test-schema.h"
#include "test-schema-sparse.h"
#include "test1-schema.h"
#include "test2-schema.h"
#include "test-schema-large.h"

#define IMPLEMENT_KIWI_H
#include "kiwi.h"

// Include a second time to test that it's safe to include the kiwi header
// multiple times in the same compilatinon unit
#include "kiwi.h"

static std::vector<uint8_t> readFile(const char *path) {
  FILE *f = fopen(path, "rb");
  if (!f) {
    // Try path as found under Bazel as well.
    f = fopen((std::string("share/kiwi/test/") + path).c_str(), "rb");
  }
  if (!f) {
    fprintf(stderr, "open '%s' failed\n", path);
    REQUIRE(f);
  }

  std::vector<uint8_t> buf;
  int c;
  while ((c = fgetc(f)) != EOF) {
    buf.push_back(c);
  }
  fclose(f);
  return buf;
}

TEST_CASE("StructBool") {

  auto check = [](bool i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer wb;
    kiwi::MemoryPool pool;

    test::BoolStruct s;
    s.set_x(i);
    REQUIRE(s.encode(wb));
    REQUIRE(std::vector<uint8_t>(wb.data(), wb.data() + wb.size()) == o);

    kiwi::ByteBuffer bb(o.data(), o.size());
    test::BoolStruct s2;
    REQUIRE(s2.decode(bb, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(false, {0});
  check(true, {1});
}

TEST_CASE("StructByte") {

  auto check = [](uint8_t i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer wb;
    kiwi::MemoryPool pool;

    test::ByteStruct s;
    s.set_x(i);
    REQUIRE(s.encode(wb));
    REQUIRE(std::vector<uint8_t>(wb.data(), wb.data() + wb.size()) == o);

    kiwi::ByteBuffer bb(o.data(), o.size());
    test::ByteStruct s2;
    REQUIRE(s2.decode(bb, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(0x00, {0x00});
  check(0x01, {0x01});
  check(0x7F, {0x7F});
  check(0x80, {0x80});
  check(0xFF, {0xFF});
}

TEST_CASE("StructUint") {

  auto check = [](uint32_t i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer wb;
    kiwi::MemoryPool pool;

    test::UintStruct s;
    s.set_x(i);
    REQUIRE(s.encode(wb));
    REQUIRE(std::vector<uint8_t>(wb.data(), wb.data() + wb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::UintStruct s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(0x00, {0x00});
  check(0x01, {0x01});
  check(0x02, {0x02});
  check(0x7F, {0x7F});
  check(0x80, {0x80, 0x01});
  check(0x81, {0x81, 0x01});
  check(0x100, {0x80, 0x02});
  check(0x101, {0x81, 0x02});
  check(0x17F, {0xFF, 0x02});
  check(0x180, {0x80, 0x03});
  check(0x1FF, {0xFF, 0x03});
  check(0x200, {0x80, 0x04});
  check(0x7FFF, {0xFF, 0xFF, 0x01});
  check(0x8000, {0x80, 0x80, 0x02});
  check(0x7FFFFFFF, {0xFF, 0xFF, 0xFF, 0xFF, 0x07});
  check(0x80000000, {0x80, 0x80, 0x80, 0x80, 0x08});
}

TEST_CASE("StructInt") {

  auto check = [](int32_t i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer wb;
    kiwi::MemoryPool pool;

    test::IntStruct s;
    s.set_x(i);
    REQUIRE(s.encode(wb));
    REQUIRE(std::vector<uint8_t>(wb.data(), wb.data() + wb.size()) == o);

    kiwi::ByteBuffer bb(o.data(), o.size());
    test::IntStruct s2;
    REQUIRE(s2.decode(bb, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(0x00, {0x00});
  check(-0x01, {0x01});
  check(0x01, {0x02});
  check(-0x02, {0x03});
  check(0x02, {0x04});
  check(-0x3F, {0x7D});
  check(0x3F, {0x7E});
  check(-0x40, {0x7F});
  check(0x40, {0x80, 0x01});
  check(-0x3FFF, {0xFD, 0xFF, 0x01});
  check(0x3FFF, {0xFE, 0xFF, 0x01});
  check(-0x4000, {0xFF, 0xFF, 0x01});
  check(0x4000, {0x80, 0x80, 0x02});
  check(-0x3FFFFFFF, {0xFD, 0xFF, 0xFF, 0xFF, 0x07});
  check(0x3FFFFFFF, {0xFE, 0xFF, 0xFF, 0xFF, 0x07});
  check(-0x40000000, {0xFF, 0xFF, 0xFF, 0xFF, 0x07});
  check(0x40000000, {0x80, 0x80, 0x80, 0x80, 0x08});
  check(-0x7FFFFFFF, {0xFD, 0xFF, 0xFF, 0xFF, 0x0F});
  check(0x7FFFFFFF, {0xFE, 0xFF, 0xFF, 0xFF, 0x0F});
  check(-0x80000000, {0xFF, 0xFF, 0xFF, 0xFF, 0x0F});
}

TEST_CASE("StructUint64") {

  auto check = [](uint64_t i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer wb;
    kiwi::MemoryPool pool;

    test::Uint64Struct s;
    s.set_x(i);
    REQUIRE(s.encode(wb));
    REQUIRE(std::vector<uint8_t>(wb.data(), wb.data() + wb.size()) == o);
    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::Uint64Struct s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(0x00, {0x00});
  check(0x01, {0x01});
  check(0x02, {0x02});
  check(0x7F, {0x7F});
  check(0x80, {0x80, 0x01});
  check(0x81, {0x81, 0x01});
  check(0x100, {0x80, 0x02});
  check(0x101, {0x81, 0x02});
  check(0x17F, {0xFF, 0x02});
  check(0x180, {0x80, 0x03});
  check(0x1FF, {0xFF, 0x03});
  check(0x200, {0x80, 0x04});
  check(0x7FFF, {0xFF, 0xFF, 0x01});
  check(0x8000, {0x80, 0x80, 0x02});
  check(0x7FFFFFFF, {0xFF, 0xFF, 0xFF, 0xFF, 0x07});
  check(0x80000000, {0x80, 0x80, 0x80, 0x80, 0x08});
  check(0xFFFFFFFFFFFFFFFFll, {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF});
}

TEST_CASE("StructInt64") {

  auto check = [](int64_t i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer wb;
    kiwi::MemoryPool pool;

    test::Int64Struct s;
    s.set_x(i);
    REQUIRE(s.encode(wb));
    REQUIRE(std::vector<uint8_t>(wb.data(), wb.data() + wb.size()) == o);

    kiwi::ByteBuffer bb(o.data(), o.size());
    test::Int64Struct s2;
    REQUIRE(s2.decode(bb, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(0x00, {0x00});
  check(-0x01, {0x01});
  check(0x01, {0x02});
  check(-0x02, {0x03});
  check(0x02, {0x04});
  check(-0x3F, {0x7D});
  check(0x3F, {0x7E});
  check(-0x40, {0x7F});
  check(0x40, {0x80, 0x01});
  check(-0x3FFF, {0xFD, 0xFF, 0x01});
  check(0x3FFF, {0xFE, 0xFF, 0x01});
  check(-0x4000, {0xFF, 0xFF, 0x01});
  check(0x4000, {0x80, 0x80, 0x02});
  check(-0x3FFFFFFF, {0xFD, 0xFF, 0xFF, 0xFF, 0x07});
  check(0x3FFFFFFF, {0xFE, 0xFF, 0xFF, 0xFF, 0x07});
  check(-0x40000000, {0xFF, 0xFF, 0xFF, 0xFF, 0x07});
  check(0x40000000, {0x80, 0x80, 0x80, 0x80, 0x08});
  check(-0x7FFFFFFF, {0xFD, 0xFF, 0xFF, 0xFF, 0x0F});
  check(0x7FFFFFFF, {0xFE, 0xFF, 0xFF, 0xFF, 0x0F});
  check(-0x80000000ll, {0xFF, 0xFF, 0xFF, 0xFF, 0x0F});
  check(-0x7FFFFFFFFFFFFFFFll, {0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF});
  check(0x7FFFFFFFFFFFFFFFll, {0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF});
  check(-0x8000000000000000ll, {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF});
}

TEST_CASE("StructFloat") {

  auto check = [](float i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer wb;
    kiwi::MemoryPool pool;

    test::FloatStruct s;
    s.set_x(i);
    REQUIRE(s.encode(wb));
    REQUIRE(std::vector<uint8_t>(wb.data(), wb.data() + wb.size()) == o);

    kiwi::ByteBuffer bb(o.data(), o.size());
    test::FloatStruct s2;
    REQUIRE(s2.decode(bb, pool));
    REQUIRE(s2.x());
    REQUIRE((*s2.x() == i || (*s2.x() != *s2.x() && i != i)));
  };

  check(0, {0});
  check(1, {127, 0, 0, 0});
  check(-1, {127, 1, 0, 0});
  check(3.1415927410125732, {128, 182, 31, 146});
  check(-3.1415927410125732, {128, 183, 31, 146});
  check(std::numeric_limits<float>::infinity(), {255, 0, 0, 0});
  check(-std::numeric_limits<float>::infinity(), {255, 1, 0, 0});
  check(std::numeric_limits<float>::quiet_NaN(), {255, 0, 0, 128});
}

TEST_CASE("StructString") {

  auto check = [](const char *i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer wb;
    kiwi::MemoryPool pool;

    test::StringStruct s;
    s.set_x(pool.string(i));
    REQUIRE(s.encode(wb));
    REQUIRE(std::vector<uint8_t>(wb.data(), wb.data() + wb.size()) == o);

    kiwi::ByteBuffer bb(o.data(), o.size());
    test::StringStruct s2;
    REQUIRE(s2.decode(bb, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == kiwi::String(i));
  };

  check("", {0});
  check("\0abc\0", {0});
  check("abc", {97, 98, 99, 0});
  check("🙉🙈🙊", {240, 159, 153, 137, 240, 159, 153, 136, 240, 159, 153, 138, 0});

  {
    auto data = std::vector<uint8_t>({16, 97, 98, 99}); // length 16, but only 3 chars left in input
    kiwi::ByteBuffer bb(data.data(), data.size());
    test::StringStruct s2;
    kiwi::MemoryPool pool;
    REQUIRE(s2.decode(bb, pool) == false);  // expect parse failure
  }
}



TEST_CASE("StructCompound") {

  auto check = [](uint32_t x, uint32_t y, std::vector<uint8_t> o) {
    kiwi::WriteBuffer wb;
    kiwi::MemoryPool pool;

    test::CompoundStruct s;
    s.set_x(x);
    s.set_y(y);
    REQUIRE(s.encode(wb));
    REQUIRE(std::vector<uint8_t>(wb.data(), wb.data() + wb.size()) == o);

    kiwi::ByteBuffer bb(o.data(), o.size());
    test::CompoundStruct s2;
    REQUIRE(s2.decode(bb, pool));
    REQUIRE(s2.x());
    REQUIRE(s2.y());
    REQUIRE(*s2.x() == x);
    REQUIRE(*s2.y() == y);
  };

  check(0, 0, {0, 0});
  check(1, 2, {1, 2});
  check(12345, 54321, {185, 96, 177, 168, 3});
}

TEST_CASE("StructNested") {

  auto check = [](uint32_t a, uint32_t bx, uint32_t by, uint32_t c, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::NestedStruct s;
    s.set_a(a);
    test::CompoundStruct b;
    s.set_b(&b);
    b.set_x(bx);
    b.set_y(by);
    s.set_c(c);
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::NestedStruct s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(s2.a());
    REQUIRE(s2.b());
    REQUIRE(s2.b()->x());
    REQUIRE(s2.b()->y());
    REQUIRE(s2.c());
    REQUIRE(*s2.a() == a);
    REQUIRE(*s2.b()->x() == bx);
    REQUIRE(*s2.b()->y() == by);
    REQUIRE(*s2.c() == c);
  };

  check(0, 0, 0, 0, {0, 0, 0, 0});
  check(1, 2, 3, 4, {1, 2, 3, 4});
  check(534, 12345, 54321, 321, {150, 4, 185, 96, 177, 168, 3, 193, 2});
}

TEST_CASE("MessageBool") {

  {
    std::vector<uint8_t> o{0};
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::BoolMessage s;
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::BoolMessage s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(!s2.x());
  }

  auto check = [](bool i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::BoolMessage s;
    s.set_x(i);
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::BoolMessage s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(false, {1, 0, 0});
  check(true, {1, 1, 0});
}

TEST_CASE("MessageByte") {

  auto check = [](uint8_t i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::ByteMessage s;
    s.set_x(i);
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::ByteMessage s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(234, {1, 234, 0});
}

TEST_CASE("MessageUint") {

  auto check = [](uint32_t i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::UintMessage s;
    s.set_x(i);
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::UintMessage s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(12345678, {1, 206, 194, 241, 5, 0});
}

TEST_CASE("MessageInt") {

  auto check = [](int32_t i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::IntMessage s;
    s.set_x(i);
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::IntMessage s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(12345678, {1, 156, 133, 227, 11, 0});
}

TEST_CASE("MessageUint64") {

  auto check = [](uint64_t i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::Uint64Message s;
    s.set_x(i);
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::Uint64Message s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(12345678, {1, 206, 194, 241, 5, 0});
  check(1234567898, {1, 218, 133, 216, 204, 4, 0});
}

TEST_CASE("MessageInt64") {

  auto check = [](int64_t i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::Int64Message s;
    s.set_x(i);
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::Int64Message s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };
  check(-1, {1, 1, 0});
  check(12345678, {1, 156, 133, 227, 11, 0});
  check(1234567898, {1, 180, 139, 176, 153, 9, 0});

}

TEST_CASE("MessageFloat") {

  auto check = [](float i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::FloatMessage s;
    s.set_x(i);
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::FloatMessage s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == i);
  };

  check(3.1415927410125732, {1, 128, 182, 31, 146, 0});
}

TEST_CASE("MessageString") {

  auto check = [](const char *i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::StringMessage s;
    s.set_x(pool.string(i));
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::StringMessage s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(s2.x());
    REQUIRE(*s2.x() == kiwi::String(i));
  };

  check("", {1, 0, 0});
  check("\0abc\0", {1, 0, 0});
  check("abc", {1, 97, 98, 99, 0, 0});
  check("🙉🙈🙊", {1, 240, 159, 153, 137, 240, 159, 153, 136, 240, 159, 153, 138, 0, 0});
}

TEST_CASE("MessageCompound") {

  auto check = [](uint32_t x, uint32_t y, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::CompoundMessage s;
    if (x) s.set_x(x);
    if (y) s.set_y(y);
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::CompoundMessage s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(!!s2.x() == !!x);
    REQUIRE(!!s2.y() == !!y);
    if (x) REQUIRE(*s2.x() == x);
    if (y) REQUIRE(*s2.y() == y);
  };

  check(0, 0, {0});
  check(123, 0, {1, 123, 0});
  check(0, 234, {2, 234, 1, 0});
  check(123, 234, {1, 123, 2, 234, 1, 0});
}

TEST_CASE("MessageNested") {

  auto check = [](uint32_t a, uint32_t bx, uint32_t by, uint32_t c, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::NestedMessage s;
    if (a) s.set_a(a);
    if (bx || by) {
      auto b = pool.allocate<test::CompoundMessage>();
      s.set_b(b);
      if (bx) b->set_x(bx);
      if (by) b->set_y(by);
    }
    if (c) s.set_c(c);
    REQUIRE(s.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::NestedMessage s2;
    REQUIRE(s2.decode(bb2, pool));
    REQUIRE(!!s2.a() == !!a);
    REQUIRE(!!s2.b() == (bx || by));
    REQUIRE(!!s2.c() == !!c);
    if (a) REQUIRE(*s2.a() == a);
    if (bx) REQUIRE(*s2.b()->x() == bx);
    if (by) REQUIRE(*s2.b()->y() == by);
    if (c) REQUIRE(*s2.c() == c);
  };

  check(0, 0, 0, 0, {0});
  check(123, 0, 0, 234, {1, 123, 3, 234, 1, 0});
  check(0, 5, 6, 0, {2, 1, 5, 2, 6, 0, 0});
  check(0, 5, 0, 123, {2, 1, 5, 0, 3, 123, 0});
  check(234, 5, 6, 123, {1, 234, 1, 2, 1, 5, 2, 6, 0, 3, 123, 0});
}

TEST_CASE("StructByteArray") {

  auto check = [](std::vector<uint8_t> i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::ByteArrayStruct message;
    message.set_x(pool, i.size()).set(i.data(), i.size());

    REQUIRE(message.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::ByteArrayStruct message2;
    REQUIRE(message2.decode(bb2, pool));
    REQUIRE(message2.x());
    REQUIRE(std::vector<uint8_t>(message2.x()->begin(), message2.x()->end()) == i);
  };

  check({}, {0});
  check({123, 234}, {2, 123, 234});
}

TEST_CASE("MessageByteArray") {

  auto check = [](bool present, std::vector<uint8_t> i, std::vector<uint8_t> o) {
    kiwi::WriteBuffer bb;
    kiwi::MemoryPool pool;

    test::ByteArrayMessage message;
    if (present) message.set_x(pool, i.size()).set(i.data(), i.size());

    REQUIRE(message.encode(bb));
    REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

    kiwi::ByteBuffer bb2(o.data(), o.size());
    test::ByteArrayMessage message2;
    REQUIRE(message2.decode(bb2, pool));

    if (present) {
      REQUIRE(message2.x());
      REQUIRE(std::vector<uint8_t>(message2.x()->begin(), message2.x()->end()) == i);
    } else {
      REQUIRE(!message2.x());
    }
  };

  check(false, {}, {0});
  check(true, {}, {1, 0, 0});
  check(true, {123, 234}, {1, 2, 123, 234, 0});
}

TEST_CASE("RecursiveMessage") {

  std::vector<uint8_t> o{1, 1, 0, 0, 0};
  kiwi::WriteBuffer bb;
  kiwi::MemoryPool pool;

  test::RecursiveMessage a;
  test::RecursiveMessage b;
  test::RecursiveMessage c;

  a.set_x(&b);
  b.set_x(&c);
  REQUIRE(a.encode(bb));
  REQUIRE(std::vector<uint8_t>(bb.data(), bb.data() + bb.size()) == o);

  kiwi::ByteBuffer bb2(o.data(), o.size());
  test::RecursiveMessage a2;
  REQUIRE(a2.decode(bb2, pool));
  REQUIRE(a2.x());
  REQUIRE(a2.x()->x());
  REQUIRE(!a2.x()->x()->x());
}

TEST_CASE("BinarySchema") {

  test1::BinarySchema test1_schema1;
  test1::BinarySchema test1_schema2;
  test2::BinarySchema test2_schema1;
  test2::BinarySchema test2_schema2;

  {
    auto file = readFile("test1-schema.bkiwi");
    kiwi::ByteBuffer bb(file.data(), file.size());
    REQUIRE(test1_schema1.parse(bb));
  }

  {
    auto file = readFile("test2-schema.bkiwi");
    kiwi::ByteBuffer bb(file.data(), file.size());
    REQUIRE(test1_schema2.parse(bb));
  }

  {
    auto file = readFile("test1-schema.bkiwi");
    kiwi::ByteBuffer bb(file.data(), file.size());
    REQUIRE(test2_schema1.parse(bb));
  }

  {
    auto file = readFile("test2-schema.bkiwi");
    kiwi::ByteBuffer bb(file.data(), file.size());
    REQUIRE(test2_schema2.parse(bb));
  }

  auto check1 = [](const std::vector<uint8_t> &i, test1::BinarySchema *schema, const std::vector<uint8_t> &o) {
    kiwi::MemoryPool pool;
    kiwi::ByteBuffer bb(i.data(), i.size());
    test1::Message message;
    if (o.empty()) {
      REQUIRE(!message.decode(bb, pool, schema));
    } else {
      REQUIRE(message.decode(bb, pool, schema));
      kiwi::WriteBuffer wb;
      REQUIRE(message.encode(wb));
      REQUIRE(std::vector<uint8_t>(wb.data(), wb.data() + wb.size()) == o);
    }
  };

  auto check2 = [](const std::vector<uint8_t> &i, test2::BinarySchema *schema, const std::vector<uint8_t> &o) {
    kiwi::MemoryPool pool;
    kiwi::ByteBuffer bb(i.data(), i.size());
    test2::Message message;
    if (o.empty()) {
      REQUIRE(!message.decode(bb, pool, schema));
    } else {
      REQUIRE(message.decode(bb, pool, schema));
      kiwi::WriteBuffer wb;
      REQUIRE(message.encode(wb));
      REQUIRE(std::vector<uint8_t>(wb.data(), wb.data() + wb.size()) == o);
    }
  };

  std::vector<uint8_t> bytes1{1, 2, 2, 128, 0, 0, 0, 128, 0, 0, 128, 0};
  check1(bytes1, nullptr,        bytes1);
  check1(bytes1, &test1_schema1, bytes1);
  check1(bytes1, &test1_schema2, bytes1);
  check2(bytes1, nullptr,        bytes1);
  check2(bytes1, &test2_schema1, bytes1);
  check2(bytes1, &test2_schema2, bytes1);

  std::vector<uint8_t> bytes2{1, 2, 2, 128, 0, 0, 0, 128, 0, 0, 128, 3, 1, 0, 4, 0, 5, 1, 240, 159, 141, 149, 0, 0, 0};
  check1(bytes2, nullptr,        {});
  check1(bytes2, &test1_schema1, {});
  check1(bytes2, &test1_schema2, bytes1);
  check2(bytes2, nullptr,        bytes2);
  check2(bytes2, &test2_schema1, bytes2);
  check2(bytes2, &test2_schema2, bytes2);
}

#define SET_10(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9)  \
  x.set_f ## n0(n0); \
  x.set_f ## n1(n1); \
  x.set_f ## n2(n2); \
  x.set_f ## n3(n3); \
  x.set_f ## n4(n4); \
  x.set_f ## n5(n5); \
  x.set_f ## n6(n6); \
  x.set_f ## n7(n7); \
  x.set_f ## n8(n8); \
  x.set_f ## n9(n9);

#define GET_10(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9)  \
  ptr = x.f ## n0(); REQUIRE(*ptr == n0); \
  ptr = x.f ## n1(); REQUIRE(*ptr == n1); \
  ptr = x.f ## n2(); REQUIRE(*ptr == n2); \
  ptr = x.f ## n3(); REQUIRE(*ptr == n3); \
  ptr = x.f ## n4(); REQUIRE(*ptr == n4); \
  ptr = x.f ## n5(); REQUIRE(*ptr == n5); \
  ptr = x.f ## n6(); REQUIRE(*ptr == n6); \
  ptr = x.f ## n7(); REQUIRE(*ptr == n7); \
  ptr = x.f ## n8(); REQUIRE(*ptr == n8); \
  ptr = x.f ## n9(); REQUIRE(*ptr == n9);

#define REPEAT(OP) \
  OP ## _10(0, 1, 2, 3, 4, 5, 6, 7, 8, 9); \
  OP ## _10(10, 11, 12, 13, 14, 15, 16, 17, 18, 19); \
  OP ## _10(20, 21, 22, 23, 24, 25, 26, 27, 28, 29); \
  OP ## _10(30, 31, 32, 33, 34, 35, 36, 37, 38, 39); \
  OP ## _10(40, 41, 42, 43, 44, 45, 46, 47, 48, 49); \
  OP ## _10(50, 51, 52, 53, 54, 55, 56, 57, 58, 59); \
  OP ## _10(60, 61, 62, 63, 64, 65, 66, 67, 68, 69); \
  OP ## _10(70, 71, 72, 73, 74, 75, 76, 77, 78, 79); \
  OP ## _10(80, 81, 82, 83, 84, 85, 86, 87, 88, 89); \
  OP ## _10(90, 91, 92, 93, 94, 95, 96, 97, 98, 99); \
  OP ## _10(100, 101, 102, 103, 104, 105, 106, 107, 108, 109); \
  OP ## _10(110, 111, 112, 113, 114, 115, 116, 117, 118, 119); \
  OP ## _10(120, 121, 122, 123, 124, 125, 126, 127, 128, 129); \

TEST_CASE("LargeStruct") {

  test_large::Struct x;

  REPEAT(SET)

  kiwi::WriteBuffer bb;
  kiwi::MemoryPool pool;
  test_large::Struct x2;
  int *ptr;

  REQUIRE(x.encode(bb));
  kiwi::ByteBuffer bb2(bb.data(), bb.size());
  REQUIRE(x2.decode(bb2, pool));

  REPEAT(GET)
}

TEST_CASE("LargeMessage") {

  test_large::Message x;

  REPEAT(SET)

  kiwi::WriteBuffer bb;
  kiwi::MemoryPool pool;
  test_large::Message x2;
  int *ptr;

  REQUIRE(x.encode(bb));
  kiwi::ByteBuffer bb2(bb.data(), bb.size());
  REQUIRE(x2.decode(bb2, pool));

  REPEAT(GET)
}

#undef SET
#undef GET
#undef REPEAT

TEST_CASE("DeprecatedFields") {

  kiwi::WriteBuffer wb;
  kiwi::MemoryPool pool;

  test::NonDeprecatedMessage nonDeprecated;
  nonDeprecated.set_a(1);
  nonDeprecated.set_b(2);
  nonDeprecated.set_c(pool, 3).set({3, 4, 5});
  nonDeprecated.set_d(pool, 3).set({6, 7, 8});
  nonDeprecated.set_e(pool.allocate<test::ByteStruct>());
  nonDeprecated.e()->set_x(123);
  nonDeprecated.set_f(pool.allocate<test::ByteStruct>());
  nonDeprecated.f()->set_x(234);
  nonDeprecated.set_g(9);

  test::DeprecatedMessage deprecated;
  REQUIRE(nonDeprecated.encode(wb));
  kiwi::ByteBuffer bb(wb.data(), wb.size());
  REQUIRE(deprecated.decode(bb, pool));

  REQUIRE(deprecated.a());
  REQUIRE(deprecated.c());
  REQUIRE(deprecated.e());
  REQUIRE(deprecated.g());

  REQUIRE(*deprecated.a() == 1);
  REQUIRE(std::vector<uint32_t>(deprecated.c()->begin(), deprecated.c()->end()) == (std::vector<uint32_t>{3, 4, 5}));
  REQUIRE(deprecated.e()->x());
  REQUIRE(*deprecated.e()->x() == 123);
  REQUIRE(*deprecated.g() == 9);

  kiwi::WriteBuffer wb2;
  test::NonDeprecatedMessage nonDeprecated2;
  REQUIRE(deprecated.encode(wb2));
  kiwi::ByteBuffer bb2(wb2.data(), wb2.size());
  REQUIRE(nonDeprecated2.decode(bb2, pool));

  REQUIRE(nonDeprecated2.a());
  REQUIRE(!nonDeprecated2.b());
  REQUIRE(nonDeprecated2.c());
  REQUIRE(!nonDeprecated2.d());
  REQUIRE(nonDeprecated2.e());
  REQUIRE(!nonDeprecated2.f());
  REQUIRE(nonDeprecated2.g());

  REQUIRE(*nonDeprecated2.a() == 1);
  REQUIRE(std::vector<uint32_t>(nonDeprecated2.c()->begin(), nonDeprecated2.c()->end()) == (std::vector<uint32_t>{3, 4, 5}));
  REQUIRE(nonDeprecated2.e()->x());
  REQUIRE(*nonDeprecated2.e()->x() == 123);
  REQUIRE(*nonDeprecated2.g() == 9);
}

template <typename MessageType, typename ValueType>
void testCopy(const ValueType& value1, const ValueType& value2) {
  // Copy empty message
  MessageType message;
  MessageType messageCopy = message.copy();
  REQUIRE(message.x() == nullptr);
  REQUIRE(messageCopy.x() == nullptr);

  // Change values on original
  message.set_x(value1);
  REQUIRE(*message.x() == value1);
  REQUIRE(messageCopy.x() == nullptr);

  // Copy updated message
  messageCopy = message.copy();
  REQUIRE(*messageCopy.x() == *message.x());
  REQUIRE(messageCopy.x() != message.x());

  // Change values on copy
  messageCopy.set_x(value2);
  REQUIRE(*message.x() == value1);
  REQUIRE(*messageCopy.x() == value2);
}

void testCopyCompoundMessage() {
  // Copy empty message
  test::CompoundMessage message;
  test::CompoundMessage messageCopy = message.copy();
  REQUIRE(message.x() == nullptr);
  REQUIRE(message.y() == nullptr);
  REQUIRE(messageCopy.x() == nullptr);
  REQUIRE(messageCopy.y() == nullptr);

  // Change values on original
  message.set_x(123);
  message.set_y(456);
  REQUIRE(*message.x() == 123);
  REQUIRE(*message.y() == 456);
  REQUIRE(messageCopy.x() == nullptr);
  REQUIRE(messageCopy.y() == nullptr);

  // Copy updated message
  messageCopy = message.copy();
  REQUIRE(*messageCopy.x() == *message.x());
  REQUIRE(*messageCopy.y() == *message.y());
  REQUIRE(messageCopy.x() != message.x());
  REQUIRE(messageCopy.y() != message.y());

  // Change values on copy
  messageCopy.set_x(1);
  messageCopy.set_y(2);
  REQUIRE(*message.x() == 123);
  REQUIRE(*message.y() == 456);
  REQUIRE(*messageCopy.x() == 1);
  REQUIRE(*messageCopy.y() == 2);
}

void testCopyNestedMessage() {
  kiwi::MemoryPool pool;

  // Copy empty message
  test::NestedMessage message;
  test::NestedMessage messageCopy = message.copy();
  REQUIRE(message.a() == nullptr);
  REQUIRE(message.b() == nullptr);
  REQUIRE(messageCopy.a() == nullptr);
  REQUIRE(messageCopy.b() == nullptr);

  // Change values on original
  test::CompoundMessage nested;
  nested.set_x(1);
  message.set_a(2);
  message.set_b(&nested);
  REQUIRE(*message.a() == 2);
  REQUIRE(*message.b()->x() == 1);
  REQUIRE(messageCopy.a() == nullptr);
  REQUIRE(messageCopy.b() == nullptr);

  // Copy updated message
  messageCopy = message.copy();
  REQUIRE(*messageCopy.a() == *message.a());
  REQUIRE(*messageCopy.b()->x() == *message.b()->x());
  REQUIRE(messageCopy.a() != message.a());
  REQUIRE(messageCopy.b() == message.b());

  // Nested message exists on both copy and original
  nested.set_x(3);
  REQUIRE(*messageCopy.b()->x() == *message.b()->x());

  // Change values on copy
  test::CompoundMessage nested1;
  nested1.set_x(4);
  messageCopy.set_a(5);
  messageCopy.set_b(&nested1);
  REQUIRE(*message.a() == 2);
  REQUIRE(*message.b()->x() == 3);
  REQUIRE(*messageCopy.a() == 5);
  REQUIRE(*messageCopy.b()->x() == 4);
}

TEST_CASE("Copy") {
  kiwi::MemoryPool pool;

  testCopy<test::BoolMessage>(true, false);
  testCopy<test::ByteMessage>(123, 4);
  testCopy<test::IntMessage>(1234, -1234);
  testCopy<test::UintMessage>(1234u, 123u);
  testCopy<test::FloatMessage>(1234.5f, -12.3f);

  kiwi::String str1 = pool.string("test1");
  kiwi::String str2 = pool.string("test2");
  testCopy<test::StringMessage>(str1, str2);

  testCopyCompoundMessage();
  testCopyNestedMessage();
}

TEST_CASE("GrowableArray") {

  kiwi::MemoryPool pool;
  kiwi::GrowableArray<int> array;

  REQUIRE(array.size() == 0);
  REQUIRE(array.data() == nullptr);

  array.pushBack(0, pool);
  array.pushBack(1, pool);
  array.pushBack(2, pool);

  REQUIRE(array.size() == 3);
  REQUIRE(array[0] == 0);
  REQUIRE(array[1] == 1);
  REQUIRE(array[2] == 2);

  array.reserve(20, pool);
  int* oldData = array.data();
  for (int i = array.size(); i < 20; i++) {
    array.pushBack(i, pool);
  }

  REQUIRE(array.size() == 20);
  // We should not have needed to reallocate, since we reserved up front.
  REQUIRE(array.data() == oldData);
}

union TestFields {
  uint32_t u;
  float f;
  kiwi::Array<float> array;
};

TEST_CASE("SparseFields") {
  kiwi::MemoryPool pool;
  kiwi::SparseFields<TestFields> fields;

  typedef kiwi::SparseFields<TestFields>::Element Element;

  REQUIRE(fields.size() == 0);

  fields.addField(Element{0, TestFields{.u = 1}}, pool);
  REQUIRE(fields.size() == 1);
  REQUIRE(fields.sorted());

  TestFields* field = fields.getField(0);
  REQUIRE(field);
  REQUIRE(field->u == 1);

  field = fields.getField(1);
  REQUIRE(!field);

  // Add in reverse order to check sorting
  for (int i = 20; i > 1; i--) {
    fields.addField(Element{static_cast<uint32_t>(i), TestFields{.f = static_cast<float>(i)}}, pool);
  }

  REQUIRE(!fields.sorted());
  fields.sort();
  REQUIRE(fields.sorted());

  field = fields.getField(20);
  REQUIRE(field->f == static_cast<float>(20));

  field = fields.getField(9);
  REQUIRE(field->f == static_cast<float>(9));

  field = fields.getField(21);
  REQUIRE(!field);

  // Defer sort, but still sorted because the last key is in order
  fields.addField(Element{22, TestFields{.u = 1}}, pool);
  REQUIRE(fields.sorted());

  field = fields.getField(22);
  REQUIRE(field->u == 1);

  fields.addField(Element{21, TestFields{.u = 1}}, pool);
  REQUIRE(!fields.sorted());

  // Can still retrieve field in unsorted array
  field = fields.getField(21);
  REQUIRE(field->u == 1);

  kiwi::Array<float> array = pool.array<float>(4);

  Element staticFields[3] = {
    {3, TestFields{.u = 1}},
    {1, TestFields{.f = 4.4f}},
    {2, TestFields{.array = array}}
  };

  kiwi::SparseFields<TestFields> fields2(staticFields, 3, pool);
  REQUIRE(fields2.size() == 3);
  REQUIRE(fields2.sorted());

  field = fields2.getField(1);
  REQUIRE(field);
  REQUIRE(field->f == 4.4f);

  field = fields2.getField(2);
  REQUIRE(field);
  REQUIRE(field->array.size() == 4);

  field = fields2.getField(3);
  REQUIRE(field);
  REQUIRE(field->u == 1);
}

TEST_CASE("SparseFields copy") {
  kiwi::MemoryPool pool;
  kiwi::SparseFields<TestFields> fields;

  typedef kiwi::SparseFields<TestFields>::Element Element;

  // Build source fields
  kiwi::Array<float> array = pool.array<float>(4);
  fields.addField(Element{0, TestFields{.u = 1}}, pool);
  fields.addField(Element{1, TestFields{.f = 3.1}}, pool);
  fields.addField(Element{2, TestFields{.array = array}}, pool);
  REQUIRE(fields.size() == 3);

  // Copy fields
  kiwi::SparseFields<TestFields> fieldsCopy1 = fields.copy(pool);
  REQUIRE(fieldsCopy1.size() == 3);

  // Check field values
  TestFields* copyField = fieldsCopy1.getField(0);
  REQUIRE(copyField);
  REQUIRE(copyField->u == 1);

  copyField = fieldsCopy1.getField(1);
  REQUIRE(copyField);
  REQUIRE(copyField->f == 3.1f);

  copyField = fieldsCopy1.getField(2);
  REQUIRE(copyField);
  // Copy should point to the same array
  REQUIRE(copyField->array.data() == array.data());

  // Adding to the original doesn't affect copy
  fields.addField(Element{3, TestFields{.u = 2}}, pool);
  REQUIRE(fields.size() == 4);
  REQUIRE(fieldsCopy1.size() == 3);

  TestFields* field = fields.getField(3);
  REQUIRE(field);
  REQUIRE(field->u == 2);

  copyField = fieldsCopy1.getField(3);
  REQUIRE(!copyField);

  // Adding to the copy doesn't affect original
  fieldsCopy1.addField(Element{3, TestFields{.u = 3}}, pool);
  REQUIRE(fieldsCopy1.size() == 4);

  field = fields.getField(3);
  REQUIRE(field);
  REQUIRE(field->u == 2);

  copyField = fieldsCopy1.getField(3);
  REQUIRE(copyField);
  REQUIRE(copyField->u == 3);

  // Copy the copy
  kiwi::SparseFields<TestFields> fieldsCopy2 = fieldsCopy1.copy(pool);
  REQUIRE(fieldsCopy1.size() == 4);

  copyField = fieldsCopy2.getField(3);
  REQUIRE(copyField);
  REQUIRE(copyField->u == 3);
}

template <typename T>
void deepEqual(const T& a, const T& b) {
  // This is the base case overload, and it should only be picked when T is
  // some primitive type.
  REQUIRE(a == b);
}

template <typename T>
void deepEqual(const kiwi::Array<T>& a, const kiwi::Array<T>& b) {
  REQUIRE(a.size() == b.size());
  for (uint32_t i = 0; i < a.size(); i++) {
    deepEqual(a[i], b[i]);
  }
}

template <typename T>
void deepEqual(const kiwi::Optional<T>& a, const kiwi::Optional<T>& b) {
  REQUIRE(((a && b) || (!a && !b)));
  if (a && b) {
    deepEqual(*a, *b);
  }
}

template <typename T>
void deepEqual(const T* a, const T* b) {
  REQUIRE(((a && b) || (!a && !b)));
  if (a && b) {
    deepEqual(*a, *b);
  }
}

template <>
void deepEqual(const test_sparse::ByteStruct& a, const test_sparse::ByteStruct& b) {
  deepEqual(*a.x(), *b.x());
}

template <>
void deepEqual(const test_sparse::Message& a, const test_sparse::Message& b) {
  deepEqual(a.a(), b.a());
  deepEqual(a.b(), b.b());
  deepEqual(a.c(), b.c());
  deepEqual(a.d(), b.d());
  deepEqual(a.e(), b.e());
  deepEqual(a.f(), b.f());
  deepEqual(a.g(), b.g());
  deepEqual(a.h(), b.h());
  deepEqual(a.i(), b.i());
}

TEST_CASE("Sparse round trip") {
  kiwi::MemoryPool pool;
  test_sparse::Message m;

  m.set_a(pool, 4);
  m.set_b(pool, 8);
  kiwi::Array<uint32_t>& c = m.set_c(pool, 2);
  c[0] = 129;
  c[1] = 3998;
  test_sparse::ByteStruct *e = pool.allocate<test_sparse::ByteStruct>();
  e->set_x(4);
  m.set_e(pool, e);

  test_sparse::Message& nested = m.set_i(pool, 1)[0];
  nested.set_c(pool, 1)[0] = 102;
  nested.set_b(pool, 9);
  nested.set_e(pool, e);

  kiwi::WriteBuffer wb;
  REQUIRE(m.encode2(wb));

  test_sparse::Message m2;

  kiwi::ByteBuffer bb(wb.data(), wb.size());
  REQUIRE(m2.decode(bb, pool));
  deepEqual(m, m2);
}

TEST_CASE("Sparse get-set") {
  kiwi::MemoryPool pool;
  test_sparse::Message m;

  m.set_a(pool, 4);
  kiwi::Optional<uint32_t> a = m.a();
  REQUIRE(a);
  REQUIRE(*a == 4);

  m.set_a(pool, 6);
  REQUIRE(m.a());
  REQUIRE(*m.a() == 6);

  kiwi::Array<uint32_t>& c = m.set_c(pool, 2);
  c[0] = 129;
  c[1] = 3998;

  kiwi::Optional<kiwi::Array<uint32_t>> c2 = m.c();
  REQUIRE(c2);
  REQUIRE(c2->size() == 2);
  REQUIRE((*c2)[0] == 129);
  REQUIRE((*c2)[1] == 3998);

  m.set_b(pool, 8.0);
  kiwi::Optional<float> b = m.b();
  REQUIRE(b);
  REQUIRE(*b == 8.0);

  test_sparse::ByteStruct *e = pool.allocate<test_sparse::ByteStruct>();
  e->set_x(4);
  m.set_e(pool, e);
  REQUIRE(m.e());
  REQUIRE(m.e()->x());
  REQUIRE(*m.e()->x() == 4);
  e->set_x(6);
  REQUIRE(*m.e()->x() == 6);
}

TEST_CASE("Sparse optional get-set") {
  kiwi::MemoryPool pool;
  test_sparse::Message m;

  m.set_a(pool, 4);
  kiwi::Array<uint32_t>& c = m.set_c(pool, 2);
  c[0] = 129;
  c[1] = 3998;
  m.set_b(pool, 8.0);

  test_sparse::ByteStruct *e = pool.allocate<test_sparse::ByteStruct>();
  e->set_x(4);
  m.set_e(pool, e);

  // Use getter with optionals
  kiwi::Optional<uint32_t> a = m.a();
  REQUIRE(a);
  REQUIRE(*a == 4);

  kiwi::Optional<kiwi::Array<uint32_t>> c3 = m.c();
  REQUIRE(c3);
  REQUIRE(c3->size() == 2);
  REQUIRE((*c3)[0] == 129);
  REQUIRE((*c3)[1] == 3998);

  kiwi::Optional<float> b = m.b();
  REQUIRE(b);
  REQUIRE(*b == 8.0);

  REQUIRE(m.e());
  REQUIRE(m.e()->x());
  REQUIRE(*m.e()->x() == 4);
}

TEST_CASE("Sparse copy") {
  kiwi::MemoryPool pool;
  test_sparse::Message m;

  // Setup original message
  m.set_a(pool, 4);

  kiwi::Array<uint32_t>& c = m.set_c(pool, 2);
  c[0] = 129;
  c[1] = 3998;

  m.set_b(pool, 8.0);

  test_sparse::ByteStruct *e = pool.allocate<test_sparse::ByteStruct>();
  e->set_x(4);
  m.set_e(pool, e);

  // Copy
  test_sparse::Message copy = m.copy(pool);
  deepEqual(m, copy);

  // Change value on original
  m.set_b(pool, 9.0);
  REQUIRE(*m.b() == 9.0);
  REQUIRE(*copy.b() == 8.0);

  // Change value on copy
  copy.set_a(pool, 5);
  REQUIRE(*m.a() == 4);
  REQUIRE(*copy.a() == 5);

  // Change nested value on both
  e->set_x(5);
  REQUIRE(*m.e()->x() == 5);
  REQUIRE(*copy.e()->x() == 5);
}
