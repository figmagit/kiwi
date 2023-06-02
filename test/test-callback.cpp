#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "test-schema-callback.h"
#include <stdio.h>
#include <assert.h>

void testRoundTripDeprecatedMessage() {
  puts("testRoundTripDeprecatedMessage");

  kiwi::WriteBuffer wb;
  test::Writer writer(wb);

  writer.beginDeprecatedMessage();
  writer.visitDeprecatedMessage_a(123);
  writer.visitDeprecatedMessage_e(234);
  writer.visitDeprecatedMessage_c_count(3);
  writer.visitDeprecatedMessage_c_element(7);
  writer.visitDeprecatedMessage_c_element(8);
  writer.visitDeprecatedMessage_c_element(9);
  writer.endDeprecatedMessage();

  kiwi::WriteBuffer wb2;
  test::Writer writer2(wb2);

  kiwi::ByteBuffer bb(wb.data(), wb.size());
  assert(test::parseDeprecatedMessage(bb, writer2));
  assert(wb.size() == wb2.size());
  assert(!memcmp(wb.data(), wb2.data(), wb.size()));
}

void testRoundTripSortedStruct() {
  puts("testRoundTripSortedStruct");

  kiwi::WriteBuffer wb;
  test::Writer writer(wb);

  writer.beginSortedStruct();

  writer.visitSortedStruct_a1(true);
  writer.visitSortedStruct_b1(123);
  writer.visitSortedStruct_c1(-12345);
  writer.visitSortedStruct_d1(12345);
  writer.visitSortedStruct_e1(123.45);
  writer.visitSortedStruct_f1("abcde");

  writer.visitSortedStruct_a2(true);
  writer.visitSortedStruct_b2(121);
  writer.visitSortedStruct_c2(-12321);
  writer.visitSortedStruct_d2(12321);
  writer.visitSortedStruct_e2(123.21);
  writer.visitSortedStruct_f2("");

  writer.visitSortedStruct_a3_count(2);
  writer.visitSortedStruct_a3_element(false);
  writer.visitSortedStruct_a3_element(true);

  writer.visitSortedStruct_b3_count(2);
  writer.visitSortedStruct_b3_element(100);
  writer.visitSortedStruct_b3_element(200);

  writer.visitSortedStruct_c3_count(2);
  writer.visitSortedStruct_c3_element(-1000);
  writer.visitSortedStruct_c3_element(-2000);

  writer.visitSortedStruct_d3_count(2);
  writer.visitSortedStruct_d3_element(1000);
  writer.visitSortedStruct_d3_element(2000);

  writer.visitSortedStruct_e3_count(2);
  writer.visitSortedStruct_e3_element(0.1);
  writer.visitSortedStruct_e3_element(0.2);

  writer.visitSortedStruct_f3_count(2);
  writer.visitSortedStruct_f3_element("");
  writer.visitSortedStruct_f3_element("xyz");

  writer.endSortedStruct();

  kiwi::WriteBuffer wb2;
  test::Writer writer2(wb2);

  kiwi::ByteBuffer bb(wb.data(), wb.size());
  assert(test::parseSortedStruct(bb, writer2));
  assert(wb.size() == wb2.size());
  assert(!memcmp(wb.data(), wb2.data(), wb.size()));
}

int main() {
  testRoundTripDeprecatedMessage();
  testRoundTripSortedStruct();

  puts("all tests passed");
  return 0;
}
