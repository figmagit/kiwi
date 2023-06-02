#include "kiwi.h"

namespace test_large {

#ifndef INCLUDE_TEST_LARGE_H
#define INCLUDE_TEST_LARGE_H

class BinarySchema {
public:
  bool parse(kiwi::ByteBuffer &bb);
  const kiwi::BinarySchema &underlyingSchema() const { return _schema; }
  bool skipMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;

private:
  kiwi::BinarySchema _schema;
  uint32_t _indexMessage = 0;
};

class Struct;
class Message;

class Struct {
public:
  Struct() { (void)_flags; }
  Struct(const Struct&) = delete;
  Struct& operator=(const Struct&) = delete;
  Struct(Struct&&) = default;
  Struct& operator=(Struct&&) = default;

  int32_t *f0();
  const int32_t *f0() const;
  void set_f0(const int32_t &value);

  int32_t *f1();
  const int32_t *f1() const;
  void set_f1(const int32_t &value);

  int32_t *f2();
  const int32_t *f2() const;
  void set_f2(const int32_t &value);

  int32_t *f3();
  const int32_t *f3() const;
  void set_f3(const int32_t &value);

  int32_t *f4();
  const int32_t *f4() const;
  void set_f4(const int32_t &value);

  int32_t *f5();
  const int32_t *f5() const;
  void set_f5(const int32_t &value);

  int32_t *f6();
  const int32_t *f6() const;
  void set_f6(const int32_t &value);

  int32_t *f7();
  const int32_t *f7() const;
  void set_f7(const int32_t &value);

  int32_t *f8();
  const int32_t *f8() const;
  void set_f8(const int32_t &value);

  int32_t *f9();
  const int32_t *f9() const;
  void set_f9(const int32_t &value);

  int32_t *f10();
  const int32_t *f10() const;
  void set_f10(const int32_t &value);

  int32_t *f11();
  const int32_t *f11() const;
  void set_f11(const int32_t &value);

  int32_t *f12();
  const int32_t *f12() const;
  void set_f12(const int32_t &value);

  int32_t *f13();
  const int32_t *f13() const;
  void set_f13(const int32_t &value);

  int32_t *f14();
  const int32_t *f14() const;
  void set_f14(const int32_t &value);

  int32_t *f15();
  const int32_t *f15() const;
  void set_f15(const int32_t &value);

  int32_t *f16();
  const int32_t *f16() const;
  void set_f16(const int32_t &value);

  int32_t *f17();
  const int32_t *f17() const;
  void set_f17(const int32_t &value);

  int32_t *f18();
  const int32_t *f18() const;
  void set_f18(const int32_t &value);

  int32_t *f19();
  const int32_t *f19() const;
  void set_f19(const int32_t &value);

  int32_t *f20();
  const int32_t *f20() const;
  void set_f20(const int32_t &value);

  int32_t *f21();
  const int32_t *f21() const;
  void set_f21(const int32_t &value);

  int32_t *f22();
  const int32_t *f22() const;
  void set_f22(const int32_t &value);

  int32_t *f23();
  const int32_t *f23() const;
  void set_f23(const int32_t &value);

  int32_t *f24();
  const int32_t *f24() const;
  void set_f24(const int32_t &value);

  int32_t *f25();
  const int32_t *f25() const;
  void set_f25(const int32_t &value);

  int32_t *f26();
  const int32_t *f26() const;
  void set_f26(const int32_t &value);

  int32_t *f27();
  const int32_t *f27() const;
  void set_f27(const int32_t &value);

  int32_t *f28();
  const int32_t *f28() const;
  void set_f28(const int32_t &value);

  int32_t *f29();
  const int32_t *f29() const;
  void set_f29(const int32_t &value);

  int32_t *f30();
  const int32_t *f30() const;
  void set_f30(const int32_t &value);

  int32_t *f31();
  const int32_t *f31() const;
  void set_f31(const int32_t &value);

  int32_t *f32();
  const int32_t *f32() const;
  void set_f32(const int32_t &value);

  int32_t *f33();
  const int32_t *f33() const;
  void set_f33(const int32_t &value);

  int32_t *f34();
  const int32_t *f34() const;
  void set_f34(const int32_t &value);

  int32_t *f35();
  const int32_t *f35() const;
  void set_f35(const int32_t &value);

  int32_t *f36();
  const int32_t *f36() const;
  void set_f36(const int32_t &value);

  int32_t *f37();
  const int32_t *f37() const;
  void set_f37(const int32_t &value);

  int32_t *f38();
  const int32_t *f38() const;
  void set_f38(const int32_t &value);

  int32_t *f39();
  const int32_t *f39() const;
  void set_f39(const int32_t &value);

  int32_t *f40();
  const int32_t *f40() const;
  void set_f40(const int32_t &value);

  int32_t *f41();
  const int32_t *f41() const;
  void set_f41(const int32_t &value);

  int32_t *f42();
  const int32_t *f42() const;
  void set_f42(const int32_t &value);

  int32_t *f43();
  const int32_t *f43() const;
  void set_f43(const int32_t &value);

  int32_t *f44();
  const int32_t *f44() const;
  void set_f44(const int32_t &value);

  int32_t *f45();
  const int32_t *f45() const;
  void set_f45(const int32_t &value);

  int32_t *f46();
  const int32_t *f46() const;
  void set_f46(const int32_t &value);

  int32_t *f47();
  const int32_t *f47() const;
  void set_f47(const int32_t &value);

  int32_t *f48();
  const int32_t *f48() const;
  void set_f48(const int32_t &value);

  int32_t *f49();
  const int32_t *f49() const;
  void set_f49(const int32_t &value);

  int32_t *f50();
  const int32_t *f50() const;
  void set_f50(const int32_t &value);

  int32_t *f51();
  const int32_t *f51() const;
  void set_f51(const int32_t &value);

  int32_t *f52();
  const int32_t *f52() const;
  void set_f52(const int32_t &value);

  int32_t *f53();
  const int32_t *f53() const;
  void set_f53(const int32_t &value);

  int32_t *f54();
  const int32_t *f54() const;
  void set_f54(const int32_t &value);

  int32_t *f55();
  const int32_t *f55() const;
  void set_f55(const int32_t &value);

  int32_t *f56();
  const int32_t *f56() const;
  void set_f56(const int32_t &value);

  int32_t *f57();
  const int32_t *f57() const;
  void set_f57(const int32_t &value);

  int32_t *f58();
  const int32_t *f58() const;
  void set_f58(const int32_t &value);

  int32_t *f59();
  const int32_t *f59() const;
  void set_f59(const int32_t &value);

  int32_t *f60();
  const int32_t *f60() const;
  void set_f60(const int32_t &value);

  int32_t *f61();
  const int32_t *f61() const;
  void set_f61(const int32_t &value);

  int32_t *f62();
  const int32_t *f62() const;
  void set_f62(const int32_t &value);

  int32_t *f63();
  const int32_t *f63() const;
  void set_f63(const int32_t &value);

  int32_t *f64();
  const int32_t *f64() const;
  void set_f64(const int32_t &value);

  int32_t *f65();
  const int32_t *f65() const;
  void set_f65(const int32_t &value);

  int32_t *f66();
  const int32_t *f66() const;
  void set_f66(const int32_t &value);

  int32_t *f67();
  const int32_t *f67() const;
  void set_f67(const int32_t &value);

  int32_t *f68();
  const int32_t *f68() const;
  void set_f68(const int32_t &value);

  int32_t *f69();
  const int32_t *f69() const;
  void set_f69(const int32_t &value);

  int32_t *f70();
  const int32_t *f70() const;
  void set_f70(const int32_t &value);

  int32_t *f71();
  const int32_t *f71() const;
  void set_f71(const int32_t &value);

  int32_t *f72();
  const int32_t *f72() const;
  void set_f72(const int32_t &value);

  int32_t *f73();
  const int32_t *f73() const;
  void set_f73(const int32_t &value);

  int32_t *f74();
  const int32_t *f74() const;
  void set_f74(const int32_t &value);

  int32_t *f75();
  const int32_t *f75() const;
  void set_f75(const int32_t &value);

  int32_t *f76();
  const int32_t *f76() const;
  void set_f76(const int32_t &value);

  int32_t *f77();
  const int32_t *f77() const;
  void set_f77(const int32_t &value);

  int32_t *f78();
  const int32_t *f78() const;
  void set_f78(const int32_t &value);

  int32_t *f79();
  const int32_t *f79() const;
  void set_f79(const int32_t &value);

  int32_t *f80();
  const int32_t *f80() const;
  void set_f80(const int32_t &value);

  int32_t *f81();
  const int32_t *f81() const;
  void set_f81(const int32_t &value);

  int32_t *f82();
  const int32_t *f82() const;
  void set_f82(const int32_t &value);

  int32_t *f83();
  const int32_t *f83() const;
  void set_f83(const int32_t &value);

  int32_t *f84();
  const int32_t *f84() const;
  void set_f84(const int32_t &value);

  int32_t *f85();
  const int32_t *f85() const;
  void set_f85(const int32_t &value);

  int32_t *f86();
  const int32_t *f86() const;
  void set_f86(const int32_t &value);

  int32_t *f87();
  const int32_t *f87() const;
  void set_f87(const int32_t &value);

  int32_t *f88();
  const int32_t *f88() const;
  void set_f88(const int32_t &value);

  int32_t *f89();
  const int32_t *f89() const;
  void set_f89(const int32_t &value);

  int32_t *f90();
  const int32_t *f90() const;
  void set_f90(const int32_t &value);

  int32_t *f91();
  const int32_t *f91() const;
  void set_f91(const int32_t &value);

  int32_t *f92();
  const int32_t *f92() const;
  void set_f92(const int32_t &value);

  int32_t *f93();
  const int32_t *f93() const;
  void set_f93(const int32_t &value);

  int32_t *f94();
  const int32_t *f94() const;
  void set_f94(const int32_t &value);

  int32_t *f95();
  const int32_t *f95() const;
  void set_f95(const int32_t &value);

  int32_t *f96();
  const int32_t *f96() const;
  void set_f96(const int32_t &value);

  int32_t *f97();
  const int32_t *f97() const;
  void set_f97(const int32_t &value);

  int32_t *f98();
  const int32_t *f98() const;
  void set_f98(const int32_t &value);

  int32_t *f99();
  const int32_t *f99() const;
  void set_f99(const int32_t &value);

  int32_t *f100();
  const int32_t *f100() const;
  void set_f100(const int32_t &value);

  int32_t *f101();
  const int32_t *f101() const;
  void set_f101(const int32_t &value);

  int32_t *f102();
  const int32_t *f102() const;
  void set_f102(const int32_t &value);

  int32_t *f103();
  const int32_t *f103() const;
  void set_f103(const int32_t &value);

  int32_t *f104();
  const int32_t *f104() const;
  void set_f104(const int32_t &value);

  int32_t *f105();
  const int32_t *f105() const;
  void set_f105(const int32_t &value);

  int32_t *f106();
  const int32_t *f106() const;
  void set_f106(const int32_t &value);

  int32_t *f107();
  const int32_t *f107() const;
  void set_f107(const int32_t &value);

  int32_t *f108();
  const int32_t *f108() const;
  void set_f108(const int32_t &value);

  int32_t *f109();
  const int32_t *f109() const;
  void set_f109(const int32_t &value);

  int32_t *f110();
  const int32_t *f110() const;
  void set_f110(const int32_t &value);

  int32_t *f111();
  const int32_t *f111() const;
  void set_f111(const int32_t &value);

  int32_t *f112();
  const int32_t *f112() const;
  void set_f112(const int32_t &value);

  int32_t *f113();
  const int32_t *f113() const;
  void set_f113(const int32_t &value);

  int32_t *f114();
  const int32_t *f114() const;
  void set_f114(const int32_t &value);

  int32_t *f115();
  const int32_t *f115() const;
  void set_f115(const int32_t &value);

  int32_t *f116();
  const int32_t *f116() const;
  void set_f116(const int32_t &value);

  int32_t *f117();
  const int32_t *f117() const;
  void set_f117(const int32_t &value);

  int32_t *f118();
  const int32_t *f118() const;
  void set_f118(const int32_t &value);

  int32_t *f119();
  const int32_t *f119() const;
  void set_f119(const int32_t &value);

  int32_t *f120();
  const int32_t *f120() const;
  void set_f120(const int32_t &value);

  int32_t *f121();
  const int32_t *f121() const;
  void set_f121(const int32_t &value);

  int32_t *f122();
  const int32_t *f122() const;
  void set_f122(const int32_t &value);

  int32_t *f123();
  const int32_t *f123() const;
  void set_f123(const int32_t &value);

  int32_t *f124();
  const int32_t *f124() const;
  void set_f124(const int32_t &value);

  int32_t *f125();
  const int32_t *f125() const;
  void set_f125(const int32_t &value);

  int32_t *f126();
  const int32_t *f126() const;
  void set_f126(const int32_t &value);

  int32_t *f127();
  const int32_t *f127() const;
  void set_f127(const int32_t &value);

  int32_t *f128();
  const int32_t *f128() const;
  void set_f128(const int32_t &value);

  int32_t *f129();
  const int32_t *f129() const;
  void set_f129(const int32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[5] = {};
  int32_t _data_f0 = {};
  int32_t _data_f1 = {};
  int32_t _data_f2 = {};
  int32_t _data_f3 = {};
  int32_t _data_f4 = {};
  int32_t _data_f5 = {};
  int32_t _data_f6 = {};
  int32_t _data_f7 = {};
  int32_t _data_f8 = {};
  int32_t _data_f9 = {};
  int32_t _data_f10 = {};
  int32_t _data_f11 = {};
  int32_t _data_f12 = {};
  int32_t _data_f13 = {};
  int32_t _data_f14 = {};
  int32_t _data_f15 = {};
  int32_t _data_f16 = {};
  int32_t _data_f17 = {};
  int32_t _data_f18 = {};
  int32_t _data_f19 = {};
  int32_t _data_f20 = {};
  int32_t _data_f21 = {};
  int32_t _data_f22 = {};
  int32_t _data_f23 = {};
  int32_t _data_f24 = {};
  int32_t _data_f25 = {};
  int32_t _data_f26 = {};
  int32_t _data_f27 = {};
  int32_t _data_f28 = {};
  int32_t _data_f29 = {};
  int32_t _data_f30 = {};
  int32_t _data_f31 = {};
  int32_t _data_f32 = {};
  int32_t _data_f33 = {};
  int32_t _data_f34 = {};
  int32_t _data_f35 = {};
  int32_t _data_f36 = {};
  int32_t _data_f37 = {};
  int32_t _data_f38 = {};
  int32_t _data_f39 = {};
  int32_t _data_f40 = {};
  int32_t _data_f41 = {};
  int32_t _data_f42 = {};
  int32_t _data_f43 = {};
  int32_t _data_f44 = {};
  int32_t _data_f45 = {};
  int32_t _data_f46 = {};
  int32_t _data_f47 = {};
  int32_t _data_f48 = {};
  int32_t _data_f49 = {};
  int32_t _data_f50 = {};
  int32_t _data_f51 = {};
  int32_t _data_f52 = {};
  int32_t _data_f53 = {};
  int32_t _data_f54 = {};
  int32_t _data_f55 = {};
  int32_t _data_f56 = {};
  int32_t _data_f57 = {};
  int32_t _data_f58 = {};
  int32_t _data_f59 = {};
  int32_t _data_f60 = {};
  int32_t _data_f61 = {};
  int32_t _data_f62 = {};
  int32_t _data_f63 = {};
  int32_t _data_f64 = {};
  int32_t _data_f65 = {};
  int32_t _data_f66 = {};
  int32_t _data_f67 = {};
  int32_t _data_f68 = {};
  int32_t _data_f69 = {};
  int32_t _data_f70 = {};
  int32_t _data_f71 = {};
  int32_t _data_f72 = {};
  int32_t _data_f73 = {};
  int32_t _data_f74 = {};
  int32_t _data_f75 = {};
  int32_t _data_f76 = {};
  int32_t _data_f77 = {};
  int32_t _data_f78 = {};
  int32_t _data_f79 = {};
  int32_t _data_f80 = {};
  int32_t _data_f81 = {};
  int32_t _data_f82 = {};
  int32_t _data_f83 = {};
  int32_t _data_f84 = {};
  int32_t _data_f85 = {};
  int32_t _data_f86 = {};
  int32_t _data_f87 = {};
  int32_t _data_f88 = {};
  int32_t _data_f89 = {};
  int32_t _data_f90 = {};
  int32_t _data_f91 = {};
  int32_t _data_f92 = {};
  int32_t _data_f93 = {};
  int32_t _data_f94 = {};
  int32_t _data_f95 = {};
  int32_t _data_f96 = {};
  int32_t _data_f97 = {};
  int32_t _data_f98 = {};
  int32_t _data_f99 = {};
  int32_t _data_f100 = {};
  int32_t _data_f101 = {};
  int32_t _data_f102 = {};
  int32_t _data_f103 = {};
  int32_t _data_f104 = {};
  int32_t _data_f105 = {};
  int32_t _data_f106 = {};
  int32_t _data_f107 = {};
  int32_t _data_f108 = {};
  int32_t _data_f109 = {};
  int32_t _data_f110 = {};
  int32_t _data_f111 = {};
  int32_t _data_f112 = {};
  int32_t _data_f113 = {};
  int32_t _data_f114 = {};
  int32_t _data_f115 = {};
  int32_t _data_f116 = {};
  int32_t _data_f117 = {};
  int32_t _data_f118 = {};
  int32_t _data_f119 = {};
  int32_t _data_f120 = {};
  int32_t _data_f121 = {};
  int32_t _data_f122 = {};
  int32_t _data_f123 = {};
  int32_t _data_f124 = {};
  int32_t _data_f125 = {};
  int32_t _data_f126 = {};
  int32_t _data_f127 = {};
  int32_t _data_f128 = {};
  int32_t _data_f129 = {};
};

class Message {
public:
  Message() { (void)_flags; }
  Message(const Message&) = delete;
  Message& operator=(const Message&) = delete;
  Message(Message&&) = default;
  Message& operator=(Message&&) = default;

  int32_t *f0();
  const int32_t *f0() const;
  void set_f0(const int32_t &value);

  int32_t *f1();
  const int32_t *f1() const;
  void set_f1(const int32_t &value);

  int32_t *f2();
  const int32_t *f2() const;
  void set_f2(const int32_t &value);

  int32_t *f3();
  const int32_t *f3() const;
  void set_f3(const int32_t &value);

  int32_t *f4();
  const int32_t *f4() const;
  void set_f4(const int32_t &value);

  int32_t *f5();
  const int32_t *f5() const;
  void set_f5(const int32_t &value);

  int32_t *f6();
  const int32_t *f6() const;
  void set_f6(const int32_t &value);

  int32_t *f7();
  const int32_t *f7() const;
  void set_f7(const int32_t &value);

  int32_t *f8();
  const int32_t *f8() const;
  void set_f8(const int32_t &value);

  int32_t *f9();
  const int32_t *f9() const;
  void set_f9(const int32_t &value);

  int32_t *f10();
  const int32_t *f10() const;
  void set_f10(const int32_t &value);

  int32_t *f11();
  const int32_t *f11() const;
  void set_f11(const int32_t &value);

  int32_t *f12();
  const int32_t *f12() const;
  void set_f12(const int32_t &value);

  int32_t *f13();
  const int32_t *f13() const;
  void set_f13(const int32_t &value);

  int32_t *f14();
  const int32_t *f14() const;
  void set_f14(const int32_t &value);

  int32_t *f15();
  const int32_t *f15() const;
  void set_f15(const int32_t &value);

  int32_t *f16();
  const int32_t *f16() const;
  void set_f16(const int32_t &value);

  int32_t *f17();
  const int32_t *f17() const;
  void set_f17(const int32_t &value);

  int32_t *f18();
  const int32_t *f18() const;
  void set_f18(const int32_t &value);

  int32_t *f19();
  const int32_t *f19() const;
  void set_f19(const int32_t &value);

  int32_t *f20();
  const int32_t *f20() const;
  void set_f20(const int32_t &value);

  int32_t *f21();
  const int32_t *f21() const;
  void set_f21(const int32_t &value);

  int32_t *f22();
  const int32_t *f22() const;
  void set_f22(const int32_t &value);

  int32_t *f23();
  const int32_t *f23() const;
  void set_f23(const int32_t &value);

  int32_t *f24();
  const int32_t *f24() const;
  void set_f24(const int32_t &value);

  int32_t *f25();
  const int32_t *f25() const;
  void set_f25(const int32_t &value);

  int32_t *f26();
  const int32_t *f26() const;
  void set_f26(const int32_t &value);

  int32_t *f27();
  const int32_t *f27() const;
  void set_f27(const int32_t &value);

  int32_t *f28();
  const int32_t *f28() const;
  void set_f28(const int32_t &value);

  int32_t *f29();
  const int32_t *f29() const;
  void set_f29(const int32_t &value);

  int32_t *f30();
  const int32_t *f30() const;
  void set_f30(const int32_t &value);

  int32_t *f31();
  const int32_t *f31() const;
  void set_f31(const int32_t &value);

  int32_t *f32();
  const int32_t *f32() const;
  void set_f32(const int32_t &value);

  int32_t *f33();
  const int32_t *f33() const;
  void set_f33(const int32_t &value);

  int32_t *f34();
  const int32_t *f34() const;
  void set_f34(const int32_t &value);

  int32_t *f35();
  const int32_t *f35() const;
  void set_f35(const int32_t &value);

  int32_t *f36();
  const int32_t *f36() const;
  void set_f36(const int32_t &value);

  int32_t *f37();
  const int32_t *f37() const;
  void set_f37(const int32_t &value);

  int32_t *f38();
  const int32_t *f38() const;
  void set_f38(const int32_t &value);

  int32_t *f39();
  const int32_t *f39() const;
  void set_f39(const int32_t &value);

  int32_t *f40();
  const int32_t *f40() const;
  void set_f40(const int32_t &value);

  int32_t *f41();
  const int32_t *f41() const;
  void set_f41(const int32_t &value);

  int32_t *f42();
  const int32_t *f42() const;
  void set_f42(const int32_t &value);

  int32_t *f43();
  const int32_t *f43() const;
  void set_f43(const int32_t &value);

  int32_t *f44();
  const int32_t *f44() const;
  void set_f44(const int32_t &value);

  int32_t *f45();
  const int32_t *f45() const;
  void set_f45(const int32_t &value);

  int32_t *f46();
  const int32_t *f46() const;
  void set_f46(const int32_t &value);

  int32_t *f47();
  const int32_t *f47() const;
  void set_f47(const int32_t &value);

  int32_t *f48();
  const int32_t *f48() const;
  void set_f48(const int32_t &value);

  int32_t *f49();
  const int32_t *f49() const;
  void set_f49(const int32_t &value);

  int32_t *f50();
  const int32_t *f50() const;
  void set_f50(const int32_t &value);

  int32_t *f51();
  const int32_t *f51() const;
  void set_f51(const int32_t &value);

  int32_t *f52();
  const int32_t *f52() const;
  void set_f52(const int32_t &value);

  int32_t *f53();
  const int32_t *f53() const;
  void set_f53(const int32_t &value);

  int32_t *f54();
  const int32_t *f54() const;
  void set_f54(const int32_t &value);

  int32_t *f55();
  const int32_t *f55() const;
  void set_f55(const int32_t &value);

  int32_t *f56();
  const int32_t *f56() const;
  void set_f56(const int32_t &value);

  int32_t *f57();
  const int32_t *f57() const;
  void set_f57(const int32_t &value);

  int32_t *f58();
  const int32_t *f58() const;
  void set_f58(const int32_t &value);

  int32_t *f59();
  const int32_t *f59() const;
  void set_f59(const int32_t &value);

  int32_t *f60();
  const int32_t *f60() const;
  void set_f60(const int32_t &value);

  int32_t *f61();
  const int32_t *f61() const;
  void set_f61(const int32_t &value);

  int32_t *f62();
  const int32_t *f62() const;
  void set_f62(const int32_t &value);

  int32_t *f63();
  const int32_t *f63() const;
  void set_f63(const int32_t &value);

  int32_t *f64();
  const int32_t *f64() const;
  void set_f64(const int32_t &value);

  int32_t *f65();
  const int32_t *f65() const;
  void set_f65(const int32_t &value);

  int32_t *f66();
  const int32_t *f66() const;
  void set_f66(const int32_t &value);

  int32_t *f67();
  const int32_t *f67() const;
  void set_f67(const int32_t &value);

  int32_t *f68();
  const int32_t *f68() const;
  void set_f68(const int32_t &value);

  int32_t *f69();
  const int32_t *f69() const;
  void set_f69(const int32_t &value);

  int32_t *f70();
  const int32_t *f70() const;
  void set_f70(const int32_t &value);

  int32_t *f71();
  const int32_t *f71() const;
  void set_f71(const int32_t &value);

  int32_t *f72();
  const int32_t *f72() const;
  void set_f72(const int32_t &value);

  int32_t *f73();
  const int32_t *f73() const;
  void set_f73(const int32_t &value);

  int32_t *f74();
  const int32_t *f74() const;
  void set_f74(const int32_t &value);

  int32_t *f75();
  const int32_t *f75() const;
  void set_f75(const int32_t &value);

  int32_t *f76();
  const int32_t *f76() const;
  void set_f76(const int32_t &value);

  int32_t *f77();
  const int32_t *f77() const;
  void set_f77(const int32_t &value);

  int32_t *f78();
  const int32_t *f78() const;
  void set_f78(const int32_t &value);

  int32_t *f79();
  const int32_t *f79() const;
  void set_f79(const int32_t &value);

  int32_t *f80();
  const int32_t *f80() const;
  void set_f80(const int32_t &value);

  int32_t *f81();
  const int32_t *f81() const;
  void set_f81(const int32_t &value);

  int32_t *f82();
  const int32_t *f82() const;
  void set_f82(const int32_t &value);

  int32_t *f83();
  const int32_t *f83() const;
  void set_f83(const int32_t &value);

  int32_t *f84();
  const int32_t *f84() const;
  void set_f84(const int32_t &value);

  int32_t *f85();
  const int32_t *f85() const;
  void set_f85(const int32_t &value);

  int32_t *f86();
  const int32_t *f86() const;
  void set_f86(const int32_t &value);

  int32_t *f87();
  const int32_t *f87() const;
  void set_f87(const int32_t &value);

  int32_t *f88();
  const int32_t *f88() const;
  void set_f88(const int32_t &value);

  int32_t *f89();
  const int32_t *f89() const;
  void set_f89(const int32_t &value);

  int32_t *f90();
  const int32_t *f90() const;
  void set_f90(const int32_t &value);

  int32_t *f91();
  const int32_t *f91() const;
  void set_f91(const int32_t &value);

  int32_t *f92();
  const int32_t *f92() const;
  void set_f92(const int32_t &value);

  int32_t *f93();
  const int32_t *f93() const;
  void set_f93(const int32_t &value);

  int32_t *f94();
  const int32_t *f94() const;
  void set_f94(const int32_t &value);

  int32_t *f95();
  const int32_t *f95() const;
  void set_f95(const int32_t &value);

  int32_t *f96();
  const int32_t *f96() const;
  void set_f96(const int32_t &value);

  int32_t *f97();
  const int32_t *f97() const;
  void set_f97(const int32_t &value);

  int32_t *f98();
  const int32_t *f98() const;
  void set_f98(const int32_t &value);

  int32_t *f99();
  const int32_t *f99() const;
  void set_f99(const int32_t &value);

  int32_t *f100();
  const int32_t *f100() const;
  void set_f100(const int32_t &value);

  int32_t *f101();
  const int32_t *f101() const;
  void set_f101(const int32_t &value);

  int32_t *f102();
  const int32_t *f102() const;
  void set_f102(const int32_t &value);

  int32_t *f103();
  const int32_t *f103() const;
  void set_f103(const int32_t &value);

  int32_t *f104();
  const int32_t *f104() const;
  void set_f104(const int32_t &value);

  int32_t *f105();
  const int32_t *f105() const;
  void set_f105(const int32_t &value);

  int32_t *f106();
  const int32_t *f106() const;
  void set_f106(const int32_t &value);

  int32_t *f107();
  const int32_t *f107() const;
  void set_f107(const int32_t &value);

  int32_t *f108();
  const int32_t *f108() const;
  void set_f108(const int32_t &value);

  int32_t *f109();
  const int32_t *f109() const;
  void set_f109(const int32_t &value);

  int32_t *f110();
  const int32_t *f110() const;
  void set_f110(const int32_t &value);

  int32_t *f111();
  const int32_t *f111() const;
  void set_f111(const int32_t &value);

  int32_t *f112();
  const int32_t *f112() const;
  void set_f112(const int32_t &value);

  int32_t *f113();
  const int32_t *f113() const;
  void set_f113(const int32_t &value);

  int32_t *f114();
  const int32_t *f114() const;
  void set_f114(const int32_t &value);

  int32_t *f115();
  const int32_t *f115() const;
  void set_f115(const int32_t &value);

  int32_t *f116();
  const int32_t *f116() const;
  void set_f116(const int32_t &value);

  int32_t *f117();
  const int32_t *f117() const;
  void set_f117(const int32_t &value);

  int32_t *f118();
  const int32_t *f118() const;
  void set_f118(const int32_t &value);

  int32_t *f119();
  const int32_t *f119() const;
  void set_f119(const int32_t &value);

  int32_t *f120();
  const int32_t *f120() const;
  void set_f120(const int32_t &value);

  int32_t *f121();
  const int32_t *f121() const;
  void set_f121(const int32_t &value);

  int32_t *f122();
  const int32_t *f122() const;
  void set_f122(const int32_t &value);

  int32_t *f123();
  const int32_t *f123() const;
  void set_f123(const int32_t &value);

  int32_t *f124();
  const int32_t *f124() const;
  void set_f124(const int32_t &value);

  int32_t *f125();
  const int32_t *f125() const;
  void set_f125(const int32_t &value);

  int32_t *f126();
  const int32_t *f126() const;
  void set_f126(const int32_t &value);

  int32_t *f127();
  const int32_t *f127() const;
  void set_f127(const int32_t &value);

  int32_t *f128();
  const int32_t *f128() const;
  void set_f128(const int32_t &value);

  int32_t *f129();
  const int32_t *f129() const;
  void set_f129(const int32_t &value);

  bool encode(kiwi::WriteBuffer &wb) const;
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[5] = {};
  int32_t _data_f0 = {};
  int32_t _data_f1 = {};
  int32_t _data_f2 = {};
  int32_t _data_f3 = {};
  int32_t _data_f4 = {};
  int32_t _data_f5 = {};
  int32_t _data_f6 = {};
  int32_t _data_f7 = {};
  int32_t _data_f8 = {};
  int32_t _data_f9 = {};
  int32_t _data_f10 = {};
  int32_t _data_f11 = {};
  int32_t _data_f12 = {};
  int32_t _data_f13 = {};
  int32_t _data_f14 = {};
  int32_t _data_f15 = {};
  int32_t _data_f16 = {};
  int32_t _data_f17 = {};
  int32_t _data_f18 = {};
  int32_t _data_f19 = {};
  int32_t _data_f20 = {};
  int32_t _data_f21 = {};
  int32_t _data_f22 = {};
  int32_t _data_f23 = {};
  int32_t _data_f24 = {};
  int32_t _data_f25 = {};
  int32_t _data_f26 = {};
  int32_t _data_f27 = {};
  int32_t _data_f28 = {};
  int32_t _data_f29 = {};
  int32_t _data_f30 = {};
  int32_t _data_f31 = {};
  int32_t _data_f32 = {};
  int32_t _data_f33 = {};
  int32_t _data_f34 = {};
  int32_t _data_f35 = {};
  int32_t _data_f36 = {};
  int32_t _data_f37 = {};
  int32_t _data_f38 = {};
  int32_t _data_f39 = {};
  int32_t _data_f40 = {};
  int32_t _data_f41 = {};
  int32_t _data_f42 = {};
  int32_t _data_f43 = {};
  int32_t _data_f44 = {};
  int32_t _data_f45 = {};
  int32_t _data_f46 = {};
  int32_t _data_f47 = {};
  int32_t _data_f48 = {};
  int32_t _data_f49 = {};
  int32_t _data_f50 = {};
  int32_t _data_f51 = {};
  int32_t _data_f52 = {};
  int32_t _data_f53 = {};
  int32_t _data_f54 = {};
  int32_t _data_f55 = {};
  int32_t _data_f56 = {};
  int32_t _data_f57 = {};
  int32_t _data_f58 = {};
  int32_t _data_f59 = {};
  int32_t _data_f60 = {};
  int32_t _data_f61 = {};
  int32_t _data_f62 = {};
  int32_t _data_f63 = {};
  int32_t _data_f64 = {};
  int32_t _data_f65 = {};
  int32_t _data_f66 = {};
  int32_t _data_f67 = {};
  int32_t _data_f68 = {};
  int32_t _data_f69 = {};
  int32_t _data_f70 = {};
  int32_t _data_f71 = {};
  int32_t _data_f72 = {};
  int32_t _data_f73 = {};
  int32_t _data_f74 = {};
  int32_t _data_f75 = {};
  int32_t _data_f76 = {};
  int32_t _data_f77 = {};
  int32_t _data_f78 = {};
  int32_t _data_f79 = {};
  int32_t _data_f80 = {};
  int32_t _data_f81 = {};
  int32_t _data_f82 = {};
  int32_t _data_f83 = {};
  int32_t _data_f84 = {};
  int32_t _data_f85 = {};
  int32_t _data_f86 = {};
  int32_t _data_f87 = {};
  int32_t _data_f88 = {};
  int32_t _data_f89 = {};
  int32_t _data_f90 = {};
  int32_t _data_f91 = {};
  int32_t _data_f92 = {};
  int32_t _data_f93 = {};
  int32_t _data_f94 = {};
  int32_t _data_f95 = {};
  int32_t _data_f96 = {};
  int32_t _data_f97 = {};
  int32_t _data_f98 = {};
  int32_t _data_f99 = {};
  int32_t _data_f100 = {};
  int32_t _data_f101 = {};
  int32_t _data_f102 = {};
  int32_t _data_f103 = {};
  int32_t _data_f104 = {};
  int32_t _data_f105 = {};
  int32_t _data_f106 = {};
  int32_t _data_f107 = {};
  int32_t _data_f108 = {};
  int32_t _data_f109 = {};
  int32_t _data_f110 = {};
  int32_t _data_f111 = {};
  int32_t _data_f112 = {};
  int32_t _data_f113 = {};
  int32_t _data_f114 = {};
  int32_t _data_f115 = {};
  int32_t _data_f116 = {};
  int32_t _data_f117 = {};
  int32_t _data_f118 = {};
  int32_t _data_f119 = {};
  int32_t _data_f120 = {};
  int32_t _data_f121 = {};
  int32_t _data_f122 = {};
  int32_t _data_f123 = {};
  int32_t _data_f124 = {};
  int32_t _data_f125 = {};
  int32_t _data_f126 = {};
  int32_t _data_f127 = {};
  int32_t _data_f128 = {};
  int32_t _data_f129 = {};
};

inline int32_t *Struct::f0() {
  return _flags[0] & (1 << 0) ? &_data_f0 : nullptr;
}

inline const int32_t *Struct::f0() const {
  return _flags[0] & (1 << 0) ? &_data_f0 : nullptr;
}

inline void Struct::set_f0(const int32_t &value) {
  _flags[0] |= (1 << 0); _data_f0 = value;
}

inline int32_t *Struct::f1() {
  return _flags[0] & (1 << 1) ? &_data_f1 : nullptr;
}

inline const int32_t *Struct::f1() const {
  return _flags[0] & (1 << 1) ? &_data_f1 : nullptr;
}

inline void Struct::set_f1(const int32_t &value) {
  _flags[0] |= (1 << 1); _data_f1 = value;
}

inline int32_t *Struct::f2() {
  return _flags[0] & (1 << 2) ? &_data_f2 : nullptr;
}

inline const int32_t *Struct::f2() const {
  return _flags[0] & (1 << 2) ? &_data_f2 : nullptr;
}

inline void Struct::set_f2(const int32_t &value) {
  _flags[0] |= (1 << 2); _data_f2 = value;
}

inline int32_t *Struct::f3() {
  return _flags[0] & (1 << 3) ? &_data_f3 : nullptr;
}

inline const int32_t *Struct::f3() const {
  return _flags[0] & (1 << 3) ? &_data_f3 : nullptr;
}

inline void Struct::set_f3(const int32_t &value) {
  _flags[0] |= (1 << 3); _data_f3 = value;
}

inline int32_t *Struct::f4() {
  return _flags[0] & (1 << 4) ? &_data_f4 : nullptr;
}

inline const int32_t *Struct::f4() const {
  return _flags[0] & (1 << 4) ? &_data_f4 : nullptr;
}

inline void Struct::set_f4(const int32_t &value) {
  _flags[0] |= (1 << 4); _data_f4 = value;
}

inline int32_t *Struct::f5() {
  return _flags[0] & (1 << 5) ? &_data_f5 : nullptr;
}

inline const int32_t *Struct::f5() const {
  return _flags[0] & (1 << 5) ? &_data_f5 : nullptr;
}

inline void Struct::set_f5(const int32_t &value) {
  _flags[0] |= (1 << 5); _data_f5 = value;
}

inline int32_t *Struct::f6() {
  return _flags[0] & (1 << 6) ? &_data_f6 : nullptr;
}

inline const int32_t *Struct::f6() const {
  return _flags[0] & (1 << 6) ? &_data_f6 : nullptr;
}

inline void Struct::set_f6(const int32_t &value) {
  _flags[0] |= (1 << 6); _data_f6 = value;
}

inline int32_t *Struct::f7() {
  return _flags[0] & (1 << 7) ? &_data_f7 : nullptr;
}

inline const int32_t *Struct::f7() const {
  return _flags[0] & (1 << 7) ? &_data_f7 : nullptr;
}

inline void Struct::set_f7(const int32_t &value) {
  _flags[0] |= (1 << 7); _data_f7 = value;
}

inline int32_t *Struct::f8() {
  return _flags[0] & (1 << 8) ? &_data_f8 : nullptr;
}

inline const int32_t *Struct::f8() const {
  return _flags[0] & (1 << 8) ? &_data_f8 : nullptr;
}

inline void Struct::set_f8(const int32_t &value) {
  _flags[0] |= (1 << 8); _data_f8 = value;
}

inline int32_t *Struct::f9() {
  return _flags[0] & (1 << 9) ? &_data_f9 : nullptr;
}

inline const int32_t *Struct::f9() const {
  return _flags[0] & (1 << 9) ? &_data_f9 : nullptr;
}

inline void Struct::set_f9(const int32_t &value) {
  _flags[0] |= (1 << 9); _data_f9 = value;
}

inline int32_t *Struct::f10() {
  return _flags[0] & (1 << 10) ? &_data_f10 : nullptr;
}

inline const int32_t *Struct::f10() const {
  return _flags[0] & (1 << 10) ? &_data_f10 : nullptr;
}

inline void Struct::set_f10(const int32_t &value) {
  _flags[0] |= (1 << 10); _data_f10 = value;
}

inline int32_t *Struct::f11() {
  return _flags[0] & (1 << 11) ? &_data_f11 : nullptr;
}

inline const int32_t *Struct::f11() const {
  return _flags[0] & (1 << 11) ? &_data_f11 : nullptr;
}

inline void Struct::set_f11(const int32_t &value) {
  _flags[0] |= (1 << 11); _data_f11 = value;
}

inline int32_t *Struct::f12() {
  return _flags[0] & (1 << 12) ? &_data_f12 : nullptr;
}

inline const int32_t *Struct::f12() const {
  return _flags[0] & (1 << 12) ? &_data_f12 : nullptr;
}

inline void Struct::set_f12(const int32_t &value) {
  _flags[0] |= (1 << 12); _data_f12 = value;
}

inline int32_t *Struct::f13() {
  return _flags[0] & (1 << 13) ? &_data_f13 : nullptr;
}

inline const int32_t *Struct::f13() const {
  return _flags[0] & (1 << 13) ? &_data_f13 : nullptr;
}

inline void Struct::set_f13(const int32_t &value) {
  _flags[0] |= (1 << 13); _data_f13 = value;
}

inline int32_t *Struct::f14() {
  return _flags[0] & (1 << 14) ? &_data_f14 : nullptr;
}

inline const int32_t *Struct::f14() const {
  return _flags[0] & (1 << 14) ? &_data_f14 : nullptr;
}

inline void Struct::set_f14(const int32_t &value) {
  _flags[0] |= (1 << 14); _data_f14 = value;
}

inline int32_t *Struct::f15() {
  return _flags[0] & (1 << 15) ? &_data_f15 : nullptr;
}

inline const int32_t *Struct::f15() const {
  return _flags[0] & (1 << 15) ? &_data_f15 : nullptr;
}

inline void Struct::set_f15(const int32_t &value) {
  _flags[0] |= (1 << 15); _data_f15 = value;
}

inline int32_t *Struct::f16() {
  return _flags[0] & (1 << 16) ? &_data_f16 : nullptr;
}

inline const int32_t *Struct::f16() const {
  return _flags[0] & (1 << 16) ? &_data_f16 : nullptr;
}

inline void Struct::set_f16(const int32_t &value) {
  _flags[0] |= (1 << 16); _data_f16 = value;
}

inline int32_t *Struct::f17() {
  return _flags[0] & (1 << 17) ? &_data_f17 : nullptr;
}

inline const int32_t *Struct::f17() const {
  return _flags[0] & (1 << 17) ? &_data_f17 : nullptr;
}

inline void Struct::set_f17(const int32_t &value) {
  _flags[0] |= (1 << 17); _data_f17 = value;
}

inline int32_t *Struct::f18() {
  return _flags[0] & (1 << 18) ? &_data_f18 : nullptr;
}

inline const int32_t *Struct::f18() const {
  return _flags[0] & (1 << 18) ? &_data_f18 : nullptr;
}

inline void Struct::set_f18(const int32_t &value) {
  _flags[0] |= (1 << 18); _data_f18 = value;
}

inline int32_t *Struct::f19() {
  return _flags[0] & (1 << 19) ? &_data_f19 : nullptr;
}

inline const int32_t *Struct::f19() const {
  return _flags[0] & (1 << 19) ? &_data_f19 : nullptr;
}

inline void Struct::set_f19(const int32_t &value) {
  _flags[0] |= (1 << 19); _data_f19 = value;
}

inline int32_t *Struct::f20() {
  return _flags[0] & (1 << 20) ? &_data_f20 : nullptr;
}

inline const int32_t *Struct::f20() const {
  return _flags[0] & (1 << 20) ? &_data_f20 : nullptr;
}

inline void Struct::set_f20(const int32_t &value) {
  _flags[0] |= (1 << 20); _data_f20 = value;
}

inline int32_t *Struct::f21() {
  return _flags[0] & (1 << 21) ? &_data_f21 : nullptr;
}

inline const int32_t *Struct::f21() const {
  return _flags[0] & (1 << 21) ? &_data_f21 : nullptr;
}

inline void Struct::set_f21(const int32_t &value) {
  _flags[0] |= (1 << 21); _data_f21 = value;
}

inline int32_t *Struct::f22() {
  return _flags[0] & (1 << 22) ? &_data_f22 : nullptr;
}

inline const int32_t *Struct::f22() const {
  return _flags[0] & (1 << 22) ? &_data_f22 : nullptr;
}

inline void Struct::set_f22(const int32_t &value) {
  _flags[0] |= (1 << 22); _data_f22 = value;
}

inline int32_t *Struct::f23() {
  return _flags[0] & (1 << 23) ? &_data_f23 : nullptr;
}

inline const int32_t *Struct::f23() const {
  return _flags[0] & (1 << 23) ? &_data_f23 : nullptr;
}

inline void Struct::set_f23(const int32_t &value) {
  _flags[0] |= (1 << 23); _data_f23 = value;
}

inline int32_t *Struct::f24() {
  return _flags[0] & (1 << 24) ? &_data_f24 : nullptr;
}

inline const int32_t *Struct::f24() const {
  return _flags[0] & (1 << 24) ? &_data_f24 : nullptr;
}

inline void Struct::set_f24(const int32_t &value) {
  _flags[0] |= (1 << 24); _data_f24 = value;
}

inline int32_t *Struct::f25() {
  return _flags[0] & (1 << 25) ? &_data_f25 : nullptr;
}

inline const int32_t *Struct::f25() const {
  return _flags[0] & (1 << 25) ? &_data_f25 : nullptr;
}

inline void Struct::set_f25(const int32_t &value) {
  _flags[0] |= (1 << 25); _data_f25 = value;
}

inline int32_t *Struct::f26() {
  return _flags[0] & (1 << 26) ? &_data_f26 : nullptr;
}

inline const int32_t *Struct::f26() const {
  return _flags[0] & (1 << 26) ? &_data_f26 : nullptr;
}

inline void Struct::set_f26(const int32_t &value) {
  _flags[0] |= (1 << 26); _data_f26 = value;
}

inline int32_t *Struct::f27() {
  return _flags[0] & (1 << 27) ? &_data_f27 : nullptr;
}

inline const int32_t *Struct::f27() const {
  return _flags[0] & (1 << 27) ? &_data_f27 : nullptr;
}

inline void Struct::set_f27(const int32_t &value) {
  _flags[0] |= (1 << 27); _data_f27 = value;
}

inline int32_t *Struct::f28() {
  return _flags[0] & (1 << 28) ? &_data_f28 : nullptr;
}

inline const int32_t *Struct::f28() const {
  return _flags[0] & (1 << 28) ? &_data_f28 : nullptr;
}

inline void Struct::set_f28(const int32_t &value) {
  _flags[0] |= (1 << 28); _data_f28 = value;
}

inline int32_t *Struct::f29() {
  return _flags[0] & (1 << 29) ? &_data_f29 : nullptr;
}

inline const int32_t *Struct::f29() const {
  return _flags[0] & (1 << 29) ? &_data_f29 : nullptr;
}

inline void Struct::set_f29(const int32_t &value) {
  _flags[0] |= (1 << 29); _data_f29 = value;
}

inline int32_t *Struct::f30() {
  return _flags[0] & (1 << 30) ? &_data_f30 : nullptr;
}

inline const int32_t *Struct::f30() const {
  return _flags[0] & (1 << 30) ? &_data_f30 : nullptr;
}

inline void Struct::set_f30(const int32_t &value) {
  _flags[0] |= (1 << 30); _data_f30 = value;
}

inline int32_t *Struct::f31() {
  return _flags[0] & (1 << 31) ? &_data_f31 : nullptr;
}

inline const int32_t *Struct::f31() const {
  return _flags[0] & (1 << 31) ? &_data_f31 : nullptr;
}

inline void Struct::set_f31(const int32_t &value) {
  _flags[0] |= (1 << 31); _data_f31 = value;
}

inline int32_t *Struct::f32() {
  return _flags[1] & (1 << 0) ? &_data_f32 : nullptr;
}

inline const int32_t *Struct::f32() const {
  return _flags[1] & (1 << 0) ? &_data_f32 : nullptr;
}

inline void Struct::set_f32(const int32_t &value) {
  _flags[1] |= (1 << 0); _data_f32 = value;
}

inline int32_t *Struct::f33() {
  return _flags[1] & (1 << 1) ? &_data_f33 : nullptr;
}

inline const int32_t *Struct::f33() const {
  return _flags[1] & (1 << 1) ? &_data_f33 : nullptr;
}

inline void Struct::set_f33(const int32_t &value) {
  _flags[1] |= (1 << 1); _data_f33 = value;
}

inline int32_t *Struct::f34() {
  return _flags[1] & (1 << 2) ? &_data_f34 : nullptr;
}

inline const int32_t *Struct::f34() const {
  return _flags[1] & (1 << 2) ? &_data_f34 : nullptr;
}

inline void Struct::set_f34(const int32_t &value) {
  _flags[1] |= (1 << 2); _data_f34 = value;
}

inline int32_t *Struct::f35() {
  return _flags[1] & (1 << 3) ? &_data_f35 : nullptr;
}

inline const int32_t *Struct::f35() const {
  return _flags[1] & (1 << 3) ? &_data_f35 : nullptr;
}

inline void Struct::set_f35(const int32_t &value) {
  _flags[1] |= (1 << 3); _data_f35 = value;
}

inline int32_t *Struct::f36() {
  return _flags[1] & (1 << 4) ? &_data_f36 : nullptr;
}

inline const int32_t *Struct::f36() const {
  return _flags[1] & (1 << 4) ? &_data_f36 : nullptr;
}

inline void Struct::set_f36(const int32_t &value) {
  _flags[1] |= (1 << 4); _data_f36 = value;
}

inline int32_t *Struct::f37() {
  return _flags[1] & (1 << 5) ? &_data_f37 : nullptr;
}

inline const int32_t *Struct::f37() const {
  return _flags[1] & (1 << 5) ? &_data_f37 : nullptr;
}

inline void Struct::set_f37(const int32_t &value) {
  _flags[1] |= (1 << 5); _data_f37 = value;
}

inline int32_t *Struct::f38() {
  return _flags[1] & (1 << 6) ? &_data_f38 : nullptr;
}

inline const int32_t *Struct::f38() const {
  return _flags[1] & (1 << 6) ? &_data_f38 : nullptr;
}

inline void Struct::set_f38(const int32_t &value) {
  _flags[1] |= (1 << 6); _data_f38 = value;
}

inline int32_t *Struct::f39() {
  return _flags[1] & (1 << 7) ? &_data_f39 : nullptr;
}

inline const int32_t *Struct::f39() const {
  return _flags[1] & (1 << 7) ? &_data_f39 : nullptr;
}

inline void Struct::set_f39(const int32_t &value) {
  _flags[1] |= (1 << 7); _data_f39 = value;
}

inline int32_t *Struct::f40() {
  return _flags[1] & (1 << 8) ? &_data_f40 : nullptr;
}

inline const int32_t *Struct::f40() const {
  return _flags[1] & (1 << 8) ? &_data_f40 : nullptr;
}

inline void Struct::set_f40(const int32_t &value) {
  _flags[1] |= (1 << 8); _data_f40 = value;
}

inline int32_t *Struct::f41() {
  return _flags[1] & (1 << 9) ? &_data_f41 : nullptr;
}

inline const int32_t *Struct::f41() const {
  return _flags[1] & (1 << 9) ? &_data_f41 : nullptr;
}

inline void Struct::set_f41(const int32_t &value) {
  _flags[1] |= (1 << 9); _data_f41 = value;
}

inline int32_t *Struct::f42() {
  return _flags[1] & (1 << 10) ? &_data_f42 : nullptr;
}

inline const int32_t *Struct::f42() const {
  return _flags[1] & (1 << 10) ? &_data_f42 : nullptr;
}

inline void Struct::set_f42(const int32_t &value) {
  _flags[1] |= (1 << 10); _data_f42 = value;
}

inline int32_t *Struct::f43() {
  return _flags[1] & (1 << 11) ? &_data_f43 : nullptr;
}

inline const int32_t *Struct::f43() const {
  return _flags[1] & (1 << 11) ? &_data_f43 : nullptr;
}

inline void Struct::set_f43(const int32_t &value) {
  _flags[1] |= (1 << 11); _data_f43 = value;
}

inline int32_t *Struct::f44() {
  return _flags[1] & (1 << 12) ? &_data_f44 : nullptr;
}

inline const int32_t *Struct::f44() const {
  return _flags[1] & (1 << 12) ? &_data_f44 : nullptr;
}

inline void Struct::set_f44(const int32_t &value) {
  _flags[1] |= (1 << 12); _data_f44 = value;
}

inline int32_t *Struct::f45() {
  return _flags[1] & (1 << 13) ? &_data_f45 : nullptr;
}

inline const int32_t *Struct::f45() const {
  return _flags[1] & (1 << 13) ? &_data_f45 : nullptr;
}

inline void Struct::set_f45(const int32_t &value) {
  _flags[1] |= (1 << 13); _data_f45 = value;
}

inline int32_t *Struct::f46() {
  return _flags[1] & (1 << 14) ? &_data_f46 : nullptr;
}

inline const int32_t *Struct::f46() const {
  return _flags[1] & (1 << 14) ? &_data_f46 : nullptr;
}

inline void Struct::set_f46(const int32_t &value) {
  _flags[1] |= (1 << 14); _data_f46 = value;
}

inline int32_t *Struct::f47() {
  return _flags[1] & (1 << 15) ? &_data_f47 : nullptr;
}

inline const int32_t *Struct::f47() const {
  return _flags[1] & (1 << 15) ? &_data_f47 : nullptr;
}

inline void Struct::set_f47(const int32_t &value) {
  _flags[1] |= (1 << 15); _data_f47 = value;
}

inline int32_t *Struct::f48() {
  return _flags[1] & (1 << 16) ? &_data_f48 : nullptr;
}

inline const int32_t *Struct::f48() const {
  return _flags[1] & (1 << 16) ? &_data_f48 : nullptr;
}

inline void Struct::set_f48(const int32_t &value) {
  _flags[1] |= (1 << 16); _data_f48 = value;
}

inline int32_t *Struct::f49() {
  return _flags[1] & (1 << 17) ? &_data_f49 : nullptr;
}

inline const int32_t *Struct::f49() const {
  return _flags[1] & (1 << 17) ? &_data_f49 : nullptr;
}

inline void Struct::set_f49(const int32_t &value) {
  _flags[1] |= (1 << 17); _data_f49 = value;
}

inline int32_t *Struct::f50() {
  return _flags[1] & (1 << 18) ? &_data_f50 : nullptr;
}

inline const int32_t *Struct::f50() const {
  return _flags[1] & (1 << 18) ? &_data_f50 : nullptr;
}

inline void Struct::set_f50(const int32_t &value) {
  _flags[1] |= (1 << 18); _data_f50 = value;
}

inline int32_t *Struct::f51() {
  return _flags[1] & (1 << 19) ? &_data_f51 : nullptr;
}

inline const int32_t *Struct::f51() const {
  return _flags[1] & (1 << 19) ? &_data_f51 : nullptr;
}

inline void Struct::set_f51(const int32_t &value) {
  _flags[1] |= (1 << 19); _data_f51 = value;
}

inline int32_t *Struct::f52() {
  return _flags[1] & (1 << 20) ? &_data_f52 : nullptr;
}

inline const int32_t *Struct::f52() const {
  return _flags[1] & (1 << 20) ? &_data_f52 : nullptr;
}

inline void Struct::set_f52(const int32_t &value) {
  _flags[1] |= (1 << 20); _data_f52 = value;
}

inline int32_t *Struct::f53() {
  return _flags[1] & (1 << 21) ? &_data_f53 : nullptr;
}

inline const int32_t *Struct::f53() const {
  return _flags[1] & (1 << 21) ? &_data_f53 : nullptr;
}

inline void Struct::set_f53(const int32_t &value) {
  _flags[1] |= (1 << 21); _data_f53 = value;
}

inline int32_t *Struct::f54() {
  return _flags[1] & (1 << 22) ? &_data_f54 : nullptr;
}

inline const int32_t *Struct::f54() const {
  return _flags[1] & (1 << 22) ? &_data_f54 : nullptr;
}

inline void Struct::set_f54(const int32_t &value) {
  _flags[1] |= (1 << 22); _data_f54 = value;
}

inline int32_t *Struct::f55() {
  return _flags[1] & (1 << 23) ? &_data_f55 : nullptr;
}

inline const int32_t *Struct::f55() const {
  return _flags[1] & (1 << 23) ? &_data_f55 : nullptr;
}

inline void Struct::set_f55(const int32_t &value) {
  _flags[1] |= (1 << 23); _data_f55 = value;
}

inline int32_t *Struct::f56() {
  return _flags[1] & (1 << 24) ? &_data_f56 : nullptr;
}

inline const int32_t *Struct::f56() const {
  return _flags[1] & (1 << 24) ? &_data_f56 : nullptr;
}

inline void Struct::set_f56(const int32_t &value) {
  _flags[1] |= (1 << 24); _data_f56 = value;
}

inline int32_t *Struct::f57() {
  return _flags[1] & (1 << 25) ? &_data_f57 : nullptr;
}

inline const int32_t *Struct::f57() const {
  return _flags[1] & (1 << 25) ? &_data_f57 : nullptr;
}

inline void Struct::set_f57(const int32_t &value) {
  _flags[1] |= (1 << 25); _data_f57 = value;
}

inline int32_t *Struct::f58() {
  return _flags[1] & (1 << 26) ? &_data_f58 : nullptr;
}

inline const int32_t *Struct::f58() const {
  return _flags[1] & (1 << 26) ? &_data_f58 : nullptr;
}

inline void Struct::set_f58(const int32_t &value) {
  _flags[1] |= (1 << 26); _data_f58 = value;
}

inline int32_t *Struct::f59() {
  return _flags[1] & (1 << 27) ? &_data_f59 : nullptr;
}

inline const int32_t *Struct::f59() const {
  return _flags[1] & (1 << 27) ? &_data_f59 : nullptr;
}

inline void Struct::set_f59(const int32_t &value) {
  _flags[1] |= (1 << 27); _data_f59 = value;
}

inline int32_t *Struct::f60() {
  return _flags[1] & (1 << 28) ? &_data_f60 : nullptr;
}

inline const int32_t *Struct::f60() const {
  return _flags[1] & (1 << 28) ? &_data_f60 : nullptr;
}

inline void Struct::set_f60(const int32_t &value) {
  _flags[1] |= (1 << 28); _data_f60 = value;
}

inline int32_t *Struct::f61() {
  return _flags[1] & (1 << 29) ? &_data_f61 : nullptr;
}

inline const int32_t *Struct::f61() const {
  return _flags[1] & (1 << 29) ? &_data_f61 : nullptr;
}

inline void Struct::set_f61(const int32_t &value) {
  _flags[1] |= (1 << 29); _data_f61 = value;
}

inline int32_t *Struct::f62() {
  return _flags[1] & (1 << 30) ? &_data_f62 : nullptr;
}

inline const int32_t *Struct::f62() const {
  return _flags[1] & (1 << 30) ? &_data_f62 : nullptr;
}

inline void Struct::set_f62(const int32_t &value) {
  _flags[1] |= (1 << 30); _data_f62 = value;
}

inline int32_t *Struct::f63() {
  return _flags[1] & (1 << 31) ? &_data_f63 : nullptr;
}

inline const int32_t *Struct::f63() const {
  return _flags[1] & (1 << 31) ? &_data_f63 : nullptr;
}

inline void Struct::set_f63(const int32_t &value) {
  _flags[1] |= (1 << 31); _data_f63 = value;
}

inline int32_t *Struct::f64() {
  return _flags[2] & (1 << 0) ? &_data_f64 : nullptr;
}

inline const int32_t *Struct::f64() const {
  return _flags[2] & (1 << 0) ? &_data_f64 : nullptr;
}

inline void Struct::set_f64(const int32_t &value) {
  _flags[2] |= (1 << 0); _data_f64 = value;
}

inline int32_t *Struct::f65() {
  return _flags[2] & (1 << 1) ? &_data_f65 : nullptr;
}

inline const int32_t *Struct::f65() const {
  return _flags[2] & (1 << 1) ? &_data_f65 : nullptr;
}

inline void Struct::set_f65(const int32_t &value) {
  _flags[2] |= (1 << 1); _data_f65 = value;
}

inline int32_t *Struct::f66() {
  return _flags[2] & (1 << 2) ? &_data_f66 : nullptr;
}

inline const int32_t *Struct::f66() const {
  return _flags[2] & (1 << 2) ? &_data_f66 : nullptr;
}

inline void Struct::set_f66(const int32_t &value) {
  _flags[2] |= (1 << 2); _data_f66 = value;
}

inline int32_t *Struct::f67() {
  return _flags[2] & (1 << 3) ? &_data_f67 : nullptr;
}

inline const int32_t *Struct::f67() const {
  return _flags[2] & (1 << 3) ? &_data_f67 : nullptr;
}

inline void Struct::set_f67(const int32_t &value) {
  _flags[2] |= (1 << 3); _data_f67 = value;
}

inline int32_t *Struct::f68() {
  return _flags[2] & (1 << 4) ? &_data_f68 : nullptr;
}

inline const int32_t *Struct::f68() const {
  return _flags[2] & (1 << 4) ? &_data_f68 : nullptr;
}

inline void Struct::set_f68(const int32_t &value) {
  _flags[2] |= (1 << 4); _data_f68 = value;
}

inline int32_t *Struct::f69() {
  return _flags[2] & (1 << 5) ? &_data_f69 : nullptr;
}

inline const int32_t *Struct::f69() const {
  return _flags[2] & (1 << 5) ? &_data_f69 : nullptr;
}

inline void Struct::set_f69(const int32_t &value) {
  _flags[2] |= (1 << 5); _data_f69 = value;
}

inline int32_t *Struct::f70() {
  return _flags[2] & (1 << 6) ? &_data_f70 : nullptr;
}

inline const int32_t *Struct::f70() const {
  return _flags[2] & (1 << 6) ? &_data_f70 : nullptr;
}

inline void Struct::set_f70(const int32_t &value) {
  _flags[2] |= (1 << 6); _data_f70 = value;
}

inline int32_t *Struct::f71() {
  return _flags[2] & (1 << 7) ? &_data_f71 : nullptr;
}

inline const int32_t *Struct::f71() const {
  return _flags[2] & (1 << 7) ? &_data_f71 : nullptr;
}

inline void Struct::set_f71(const int32_t &value) {
  _flags[2] |= (1 << 7); _data_f71 = value;
}

inline int32_t *Struct::f72() {
  return _flags[2] & (1 << 8) ? &_data_f72 : nullptr;
}

inline const int32_t *Struct::f72() const {
  return _flags[2] & (1 << 8) ? &_data_f72 : nullptr;
}

inline void Struct::set_f72(const int32_t &value) {
  _flags[2] |= (1 << 8); _data_f72 = value;
}

inline int32_t *Struct::f73() {
  return _flags[2] & (1 << 9) ? &_data_f73 : nullptr;
}

inline const int32_t *Struct::f73() const {
  return _flags[2] & (1 << 9) ? &_data_f73 : nullptr;
}

inline void Struct::set_f73(const int32_t &value) {
  _flags[2] |= (1 << 9); _data_f73 = value;
}

inline int32_t *Struct::f74() {
  return _flags[2] & (1 << 10) ? &_data_f74 : nullptr;
}

inline const int32_t *Struct::f74() const {
  return _flags[2] & (1 << 10) ? &_data_f74 : nullptr;
}

inline void Struct::set_f74(const int32_t &value) {
  _flags[2] |= (1 << 10); _data_f74 = value;
}

inline int32_t *Struct::f75() {
  return _flags[2] & (1 << 11) ? &_data_f75 : nullptr;
}

inline const int32_t *Struct::f75() const {
  return _flags[2] & (1 << 11) ? &_data_f75 : nullptr;
}

inline void Struct::set_f75(const int32_t &value) {
  _flags[2] |= (1 << 11); _data_f75 = value;
}

inline int32_t *Struct::f76() {
  return _flags[2] & (1 << 12) ? &_data_f76 : nullptr;
}

inline const int32_t *Struct::f76() const {
  return _flags[2] & (1 << 12) ? &_data_f76 : nullptr;
}

inline void Struct::set_f76(const int32_t &value) {
  _flags[2] |= (1 << 12); _data_f76 = value;
}

inline int32_t *Struct::f77() {
  return _flags[2] & (1 << 13) ? &_data_f77 : nullptr;
}

inline const int32_t *Struct::f77() const {
  return _flags[2] & (1 << 13) ? &_data_f77 : nullptr;
}

inline void Struct::set_f77(const int32_t &value) {
  _flags[2] |= (1 << 13); _data_f77 = value;
}

inline int32_t *Struct::f78() {
  return _flags[2] & (1 << 14) ? &_data_f78 : nullptr;
}

inline const int32_t *Struct::f78() const {
  return _flags[2] & (1 << 14) ? &_data_f78 : nullptr;
}

inline void Struct::set_f78(const int32_t &value) {
  _flags[2] |= (1 << 14); _data_f78 = value;
}

inline int32_t *Struct::f79() {
  return _flags[2] & (1 << 15) ? &_data_f79 : nullptr;
}

inline const int32_t *Struct::f79() const {
  return _flags[2] & (1 << 15) ? &_data_f79 : nullptr;
}

inline void Struct::set_f79(const int32_t &value) {
  _flags[2] |= (1 << 15); _data_f79 = value;
}

inline int32_t *Struct::f80() {
  return _flags[2] & (1 << 16) ? &_data_f80 : nullptr;
}

inline const int32_t *Struct::f80() const {
  return _flags[2] & (1 << 16) ? &_data_f80 : nullptr;
}

inline void Struct::set_f80(const int32_t &value) {
  _flags[2] |= (1 << 16); _data_f80 = value;
}

inline int32_t *Struct::f81() {
  return _flags[2] & (1 << 17) ? &_data_f81 : nullptr;
}

inline const int32_t *Struct::f81() const {
  return _flags[2] & (1 << 17) ? &_data_f81 : nullptr;
}

inline void Struct::set_f81(const int32_t &value) {
  _flags[2] |= (1 << 17); _data_f81 = value;
}

inline int32_t *Struct::f82() {
  return _flags[2] & (1 << 18) ? &_data_f82 : nullptr;
}

inline const int32_t *Struct::f82() const {
  return _flags[2] & (1 << 18) ? &_data_f82 : nullptr;
}

inline void Struct::set_f82(const int32_t &value) {
  _flags[2] |= (1 << 18); _data_f82 = value;
}

inline int32_t *Struct::f83() {
  return _flags[2] & (1 << 19) ? &_data_f83 : nullptr;
}

inline const int32_t *Struct::f83() const {
  return _flags[2] & (1 << 19) ? &_data_f83 : nullptr;
}

inline void Struct::set_f83(const int32_t &value) {
  _flags[2] |= (1 << 19); _data_f83 = value;
}

inline int32_t *Struct::f84() {
  return _flags[2] & (1 << 20) ? &_data_f84 : nullptr;
}

inline const int32_t *Struct::f84() const {
  return _flags[2] & (1 << 20) ? &_data_f84 : nullptr;
}

inline void Struct::set_f84(const int32_t &value) {
  _flags[2] |= (1 << 20); _data_f84 = value;
}

inline int32_t *Struct::f85() {
  return _flags[2] & (1 << 21) ? &_data_f85 : nullptr;
}

inline const int32_t *Struct::f85() const {
  return _flags[2] & (1 << 21) ? &_data_f85 : nullptr;
}

inline void Struct::set_f85(const int32_t &value) {
  _flags[2] |= (1 << 21); _data_f85 = value;
}

inline int32_t *Struct::f86() {
  return _flags[2] & (1 << 22) ? &_data_f86 : nullptr;
}

inline const int32_t *Struct::f86() const {
  return _flags[2] & (1 << 22) ? &_data_f86 : nullptr;
}

inline void Struct::set_f86(const int32_t &value) {
  _flags[2] |= (1 << 22); _data_f86 = value;
}

inline int32_t *Struct::f87() {
  return _flags[2] & (1 << 23) ? &_data_f87 : nullptr;
}

inline const int32_t *Struct::f87() const {
  return _flags[2] & (1 << 23) ? &_data_f87 : nullptr;
}

inline void Struct::set_f87(const int32_t &value) {
  _flags[2] |= (1 << 23); _data_f87 = value;
}

inline int32_t *Struct::f88() {
  return _flags[2] & (1 << 24) ? &_data_f88 : nullptr;
}

inline const int32_t *Struct::f88() const {
  return _flags[2] & (1 << 24) ? &_data_f88 : nullptr;
}

inline void Struct::set_f88(const int32_t &value) {
  _flags[2] |= (1 << 24); _data_f88 = value;
}

inline int32_t *Struct::f89() {
  return _flags[2] & (1 << 25) ? &_data_f89 : nullptr;
}

inline const int32_t *Struct::f89() const {
  return _flags[2] & (1 << 25) ? &_data_f89 : nullptr;
}

inline void Struct::set_f89(const int32_t &value) {
  _flags[2] |= (1 << 25); _data_f89 = value;
}

inline int32_t *Struct::f90() {
  return _flags[2] & (1 << 26) ? &_data_f90 : nullptr;
}

inline const int32_t *Struct::f90() const {
  return _flags[2] & (1 << 26) ? &_data_f90 : nullptr;
}

inline void Struct::set_f90(const int32_t &value) {
  _flags[2] |= (1 << 26); _data_f90 = value;
}

inline int32_t *Struct::f91() {
  return _flags[2] & (1 << 27) ? &_data_f91 : nullptr;
}

inline const int32_t *Struct::f91() const {
  return _flags[2] & (1 << 27) ? &_data_f91 : nullptr;
}

inline void Struct::set_f91(const int32_t &value) {
  _flags[2] |= (1 << 27); _data_f91 = value;
}

inline int32_t *Struct::f92() {
  return _flags[2] & (1 << 28) ? &_data_f92 : nullptr;
}

inline const int32_t *Struct::f92() const {
  return _flags[2] & (1 << 28) ? &_data_f92 : nullptr;
}

inline void Struct::set_f92(const int32_t &value) {
  _flags[2] |= (1 << 28); _data_f92 = value;
}

inline int32_t *Struct::f93() {
  return _flags[2] & (1 << 29) ? &_data_f93 : nullptr;
}

inline const int32_t *Struct::f93() const {
  return _flags[2] & (1 << 29) ? &_data_f93 : nullptr;
}

inline void Struct::set_f93(const int32_t &value) {
  _flags[2] |= (1 << 29); _data_f93 = value;
}

inline int32_t *Struct::f94() {
  return _flags[2] & (1 << 30) ? &_data_f94 : nullptr;
}

inline const int32_t *Struct::f94() const {
  return _flags[2] & (1 << 30) ? &_data_f94 : nullptr;
}

inline void Struct::set_f94(const int32_t &value) {
  _flags[2] |= (1 << 30); _data_f94 = value;
}

inline int32_t *Struct::f95() {
  return _flags[2] & (1 << 31) ? &_data_f95 : nullptr;
}

inline const int32_t *Struct::f95() const {
  return _flags[2] & (1 << 31) ? &_data_f95 : nullptr;
}

inline void Struct::set_f95(const int32_t &value) {
  _flags[2] |= (1 << 31); _data_f95 = value;
}

inline int32_t *Struct::f96() {
  return _flags[3] & (1 << 0) ? &_data_f96 : nullptr;
}

inline const int32_t *Struct::f96() const {
  return _flags[3] & (1 << 0) ? &_data_f96 : nullptr;
}

inline void Struct::set_f96(const int32_t &value) {
  _flags[3] |= (1 << 0); _data_f96 = value;
}

inline int32_t *Struct::f97() {
  return _flags[3] & (1 << 1) ? &_data_f97 : nullptr;
}

inline const int32_t *Struct::f97() const {
  return _flags[3] & (1 << 1) ? &_data_f97 : nullptr;
}

inline void Struct::set_f97(const int32_t &value) {
  _flags[3] |= (1 << 1); _data_f97 = value;
}

inline int32_t *Struct::f98() {
  return _flags[3] & (1 << 2) ? &_data_f98 : nullptr;
}

inline const int32_t *Struct::f98() const {
  return _flags[3] & (1 << 2) ? &_data_f98 : nullptr;
}

inline void Struct::set_f98(const int32_t &value) {
  _flags[3] |= (1 << 2); _data_f98 = value;
}

inline int32_t *Struct::f99() {
  return _flags[3] & (1 << 3) ? &_data_f99 : nullptr;
}

inline const int32_t *Struct::f99() const {
  return _flags[3] & (1 << 3) ? &_data_f99 : nullptr;
}

inline void Struct::set_f99(const int32_t &value) {
  _flags[3] |= (1 << 3); _data_f99 = value;
}

inline int32_t *Struct::f100() {
  return _flags[3] & (1 << 4) ? &_data_f100 : nullptr;
}

inline const int32_t *Struct::f100() const {
  return _flags[3] & (1 << 4) ? &_data_f100 : nullptr;
}

inline void Struct::set_f100(const int32_t &value) {
  _flags[3] |= (1 << 4); _data_f100 = value;
}

inline int32_t *Struct::f101() {
  return _flags[3] & (1 << 5) ? &_data_f101 : nullptr;
}

inline const int32_t *Struct::f101() const {
  return _flags[3] & (1 << 5) ? &_data_f101 : nullptr;
}

inline void Struct::set_f101(const int32_t &value) {
  _flags[3] |= (1 << 5); _data_f101 = value;
}

inline int32_t *Struct::f102() {
  return _flags[3] & (1 << 6) ? &_data_f102 : nullptr;
}

inline const int32_t *Struct::f102() const {
  return _flags[3] & (1 << 6) ? &_data_f102 : nullptr;
}

inline void Struct::set_f102(const int32_t &value) {
  _flags[3] |= (1 << 6); _data_f102 = value;
}

inline int32_t *Struct::f103() {
  return _flags[3] & (1 << 7) ? &_data_f103 : nullptr;
}

inline const int32_t *Struct::f103() const {
  return _flags[3] & (1 << 7) ? &_data_f103 : nullptr;
}

inline void Struct::set_f103(const int32_t &value) {
  _flags[3] |= (1 << 7); _data_f103 = value;
}

inline int32_t *Struct::f104() {
  return _flags[3] & (1 << 8) ? &_data_f104 : nullptr;
}

inline const int32_t *Struct::f104() const {
  return _flags[3] & (1 << 8) ? &_data_f104 : nullptr;
}

inline void Struct::set_f104(const int32_t &value) {
  _flags[3] |= (1 << 8); _data_f104 = value;
}

inline int32_t *Struct::f105() {
  return _flags[3] & (1 << 9) ? &_data_f105 : nullptr;
}

inline const int32_t *Struct::f105() const {
  return _flags[3] & (1 << 9) ? &_data_f105 : nullptr;
}

inline void Struct::set_f105(const int32_t &value) {
  _flags[3] |= (1 << 9); _data_f105 = value;
}

inline int32_t *Struct::f106() {
  return _flags[3] & (1 << 10) ? &_data_f106 : nullptr;
}

inline const int32_t *Struct::f106() const {
  return _flags[3] & (1 << 10) ? &_data_f106 : nullptr;
}

inline void Struct::set_f106(const int32_t &value) {
  _flags[3] |= (1 << 10); _data_f106 = value;
}

inline int32_t *Struct::f107() {
  return _flags[3] & (1 << 11) ? &_data_f107 : nullptr;
}

inline const int32_t *Struct::f107() const {
  return _flags[3] & (1 << 11) ? &_data_f107 : nullptr;
}

inline void Struct::set_f107(const int32_t &value) {
  _flags[3] |= (1 << 11); _data_f107 = value;
}

inline int32_t *Struct::f108() {
  return _flags[3] & (1 << 12) ? &_data_f108 : nullptr;
}

inline const int32_t *Struct::f108() const {
  return _flags[3] & (1 << 12) ? &_data_f108 : nullptr;
}

inline void Struct::set_f108(const int32_t &value) {
  _flags[3] |= (1 << 12); _data_f108 = value;
}

inline int32_t *Struct::f109() {
  return _flags[3] & (1 << 13) ? &_data_f109 : nullptr;
}

inline const int32_t *Struct::f109() const {
  return _flags[3] & (1 << 13) ? &_data_f109 : nullptr;
}

inline void Struct::set_f109(const int32_t &value) {
  _flags[3] |= (1 << 13); _data_f109 = value;
}

inline int32_t *Struct::f110() {
  return _flags[3] & (1 << 14) ? &_data_f110 : nullptr;
}

inline const int32_t *Struct::f110() const {
  return _flags[3] & (1 << 14) ? &_data_f110 : nullptr;
}

inline void Struct::set_f110(const int32_t &value) {
  _flags[3] |= (1 << 14); _data_f110 = value;
}

inline int32_t *Struct::f111() {
  return _flags[3] & (1 << 15) ? &_data_f111 : nullptr;
}

inline const int32_t *Struct::f111() const {
  return _flags[3] & (1 << 15) ? &_data_f111 : nullptr;
}

inline void Struct::set_f111(const int32_t &value) {
  _flags[3] |= (1 << 15); _data_f111 = value;
}

inline int32_t *Struct::f112() {
  return _flags[3] & (1 << 16) ? &_data_f112 : nullptr;
}

inline const int32_t *Struct::f112() const {
  return _flags[3] & (1 << 16) ? &_data_f112 : nullptr;
}

inline void Struct::set_f112(const int32_t &value) {
  _flags[3] |= (1 << 16); _data_f112 = value;
}

inline int32_t *Struct::f113() {
  return _flags[3] & (1 << 17) ? &_data_f113 : nullptr;
}

inline const int32_t *Struct::f113() const {
  return _flags[3] & (1 << 17) ? &_data_f113 : nullptr;
}

inline void Struct::set_f113(const int32_t &value) {
  _flags[3] |= (1 << 17); _data_f113 = value;
}

inline int32_t *Struct::f114() {
  return _flags[3] & (1 << 18) ? &_data_f114 : nullptr;
}

inline const int32_t *Struct::f114() const {
  return _flags[3] & (1 << 18) ? &_data_f114 : nullptr;
}

inline void Struct::set_f114(const int32_t &value) {
  _flags[3] |= (1 << 18); _data_f114 = value;
}

inline int32_t *Struct::f115() {
  return _flags[3] & (1 << 19) ? &_data_f115 : nullptr;
}

inline const int32_t *Struct::f115() const {
  return _flags[3] & (1 << 19) ? &_data_f115 : nullptr;
}

inline void Struct::set_f115(const int32_t &value) {
  _flags[3] |= (1 << 19); _data_f115 = value;
}

inline int32_t *Struct::f116() {
  return _flags[3] & (1 << 20) ? &_data_f116 : nullptr;
}

inline const int32_t *Struct::f116() const {
  return _flags[3] & (1 << 20) ? &_data_f116 : nullptr;
}

inline void Struct::set_f116(const int32_t &value) {
  _flags[3] |= (1 << 20); _data_f116 = value;
}

inline int32_t *Struct::f117() {
  return _flags[3] & (1 << 21) ? &_data_f117 : nullptr;
}

inline const int32_t *Struct::f117() const {
  return _flags[3] & (1 << 21) ? &_data_f117 : nullptr;
}

inline void Struct::set_f117(const int32_t &value) {
  _flags[3] |= (1 << 21); _data_f117 = value;
}

inline int32_t *Struct::f118() {
  return _flags[3] & (1 << 22) ? &_data_f118 : nullptr;
}

inline const int32_t *Struct::f118() const {
  return _flags[3] & (1 << 22) ? &_data_f118 : nullptr;
}

inline void Struct::set_f118(const int32_t &value) {
  _flags[3] |= (1 << 22); _data_f118 = value;
}

inline int32_t *Struct::f119() {
  return _flags[3] & (1 << 23) ? &_data_f119 : nullptr;
}

inline const int32_t *Struct::f119() const {
  return _flags[3] & (1 << 23) ? &_data_f119 : nullptr;
}

inline void Struct::set_f119(const int32_t &value) {
  _flags[3] |= (1 << 23); _data_f119 = value;
}

inline int32_t *Struct::f120() {
  return _flags[3] & (1 << 24) ? &_data_f120 : nullptr;
}

inline const int32_t *Struct::f120() const {
  return _flags[3] & (1 << 24) ? &_data_f120 : nullptr;
}

inline void Struct::set_f120(const int32_t &value) {
  _flags[3] |= (1 << 24); _data_f120 = value;
}

inline int32_t *Struct::f121() {
  return _flags[3] & (1 << 25) ? &_data_f121 : nullptr;
}

inline const int32_t *Struct::f121() const {
  return _flags[3] & (1 << 25) ? &_data_f121 : nullptr;
}

inline void Struct::set_f121(const int32_t &value) {
  _flags[3] |= (1 << 25); _data_f121 = value;
}

inline int32_t *Struct::f122() {
  return _flags[3] & (1 << 26) ? &_data_f122 : nullptr;
}

inline const int32_t *Struct::f122() const {
  return _flags[3] & (1 << 26) ? &_data_f122 : nullptr;
}

inline void Struct::set_f122(const int32_t &value) {
  _flags[3] |= (1 << 26); _data_f122 = value;
}

inline int32_t *Struct::f123() {
  return _flags[3] & (1 << 27) ? &_data_f123 : nullptr;
}

inline const int32_t *Struct::f123() const {
  return _flags[3] & (1 << 27) ? &_data_f123 : nullptr;
}

inline void Struct::set_f123(const int32_t &value) {
  _flags[3] |= (1 << 27); _data_f123 = value;
}

inline int32_t *Struct::f124() {
  return _flags[3] & (1 << 28) ? &_data_f124 : nullptr;
}

inline const int32_t *Struct::f124() const {
  return _flags[3] & (1 << 28) ? &_data_f124 : nullptr;
}

inline void Struct::set_f124(const int32_t &value) {
  _flags[3] |= (1 << 28); _data_f124 = value;
}

inline int32_t *Struct::f125() {
  return _flags[3] & (1 << 29) ? &_data_f125 : nullptr;
}

inline const int32_t *Struct::f125() const {
  return _flags[3] & (1 << 29) ? &_data_f125 : nullptr;
}

inline void Struct::set_f125(const int32_t &value) {
  _flags[3] |= (1 << 29); _data_f125 = value;
}

inline int32_t *Struct::f126() {
  return _flags[3] & (1 << 30) ? &_data_f126 : nullptr;
}

inline const int32_t *Struct::f126() const {
  return _flags[3] & (1 << 30) ? &_data_f126 : nullptr;
}

inline void Struct::set_f126(const int32_t &value) {
  _flags[3] |= (1 << 30); _data_f126 = value;
}

inline int32_t *Struct::f127() {
  return _flags[3] & (1 << 31) ? &_data_f127 : nullptr;
}

inline const int32_t *Struct::f127() const {
  return _flags[3] & (1 << 31) ? &_data_f127 : nullptr;
}

inline void Struct::set_f127(const int32_t &value) {
  _flags[3] |= (1 << 31); _data_f127 = value;
}

inline int32_t *Struct::f128() {
  return _flags[4] & (1 << 0) ? &_data_f128 : nullptr;
}

inline const int32_t *Struct::f128() const {
  return _flags[4] & (1 << 0) ? &_data_f128 : nullptr;
}

inline void Struct::set_f128(const int32_t &value) {
  _flags[4] |= (1 << 0); _data_f128 = value;
}

inline int32_t *Struct::f129() {
  return _flags[4] & (1 << 1) ? &_data_f129 : nullptr;
}

inline const int32_t *Struct::f129() const {
  return _flags[4] & (1 << 1) ? &_data_f129 : nullptr;
}

inline void Struct::set_f129(const int32_t &value) {
  _flags[4] |= (1 << 1); _data_f129 = value;
}

inline int32_t *Message::f0() {
  return _flags[0] & (1 << 0) ? &_data_f0 : nullptr;
}

inline const int32_t *Message::f0() const {
  return _flags[0] & (1 << 0) ? &_data_f0 : nullptr;
}

inline void Message::set_f0(const int32_t &value) {
  _flags[0] |= (1 << 0); _data_f0 = value;
}

inline int32_t *Message::f1() {
  return _flags[0] & (1 << 1) ? &_data_f1 : nullptr;
}

inline const int32_t *Message::f1() const {
  return _flags[0] & (1 << 1) ? &_data_f1 : nullptr;
}

inline void Message::set_f1(const int32_t &value) {
  _flags[0] |= (1 << 1); _data_f1 = value;
}

inline int32_t *Message::f2() {
  return _flags[0] & (1 << 2) ? &_data_f2 : nullptr;
}

inline const int32_t *Message::f2() const {
  return _flags[0] & (1 << 2) ? &_data_f2 : nullptr;
}

inline void Message::set_f2(const int32_t &value) {
  _flags[0] |= (1 << 2); _data_f2 = value;
}

inline int32_t *Message::f3() {
  return _flags[0] & (1 << 3) ? &_data_f3 : nullptr;
}

inline const int32_t *Message::f3() const {
  return _flags[0] & (1 << 3) ? &_data_f3 : nullptr;
}

inline void Message::set_f3(const int32_t &value) {
  _flags[0] |= (1 << 3); _data_f3 = value;
}

inline int32_t *Message::f4() {
  return _flags[0] & (1 << 4) ? &_data_f4 : nullptr;
}

inline const int32_t *Message::f4() const {
  return _flags[0] & (1 << 4) ? &_data_f4 : nullptr;
}

inline void Message::set_f4(const int32_t &value) {
  _flags[0] |= (1 << 4); _data_f4 = value;
}

inline int32_t *Message::f5() {
  return _flags[0] & (1 << 5) ? &_data_f5 : nullptr;
}

inline const int32_t *Message::f5() const {
  return _flags[0] & (1 << 5) ? &_data_f5 : nullptr;
}

inline void Message::set_f5(const int32_t &value) {
  _flags[0] |= (1 << 5); _data_f5 = value;
}

inline int32_t *Message::f6() {
  return _flags[0] & (1 << 6) ? &_data_f6 : nullptr;
}

inline const int32_t *Message::f6() const {
  return _flags[0] & (1 << 6) ? &_data_f6 : nullptr;
}

inline void Message::set_f6(const int32_t &value) {
  _flags[0] |= (1 << 6); _data_f6 = value;
}

inline int32_t *Message::f7() {
  return _flags[0] & (1 << 7) ? &_data_f7 : nullptr;
}

inline const int32_t *Message::f7() const {
  return _flags[0] & (1 << 7) ? &_data_f7 : nullptr;
}

inline void Message::set_f7(const int32_t &value) {
  _flags[0] |= (1 << 7); _data_f7 = value;
}

inline int32_t *Message::f8() {
  return _flags[0] & (1 << 8) ? &_data_f8 : nullptr;
}

inline const int32_t *Message::f8() const {
  return _flags[0] & (1 << 8) ? &_data_f8 : nullptr;
}

inline void Message::set_f8(const int32_t &value) {
  _flags[0] |= (1 << 8); _data_f8 = value;
}

inline int32_t *Message::f9() {
  return _flags[0] & (1 << 9) ? &_data_f9 : nullptr;
}

inline const int32_t *Message::f9() const {
  return _flags[0] & (1 << 9) ? &_data_f9 : nullptr;
}

inline void Message::set_f9(const int32_t &value) {
  _flags[0] |= (1 << 9); _data_f9 = value;
}

inline int32_t *Message::f10() {
  return _flags[0] & (1 << 10) ? &_data_f10 : nullptr;
}

inline const int32_t *Message::f10() const {
  return _flags[0] & (1 << 10) ? &_data_f10 : nullptr;
}

inline void Message::set_f10(const int32_t &value) {
  _flags[0] |= (1 << 10); _data_f10 = value;
}

inline int32_t *Message::f11() {
  return _flags[0] & (1 << 11) ? &_data_f11 : nullptr;
}

inline const int32_t *Message::f11() const {
  return _flags[0] & (1 << 11) ? &_data_f11 : nullptr;
}

inline void Message::set_f11(const int32_t &value) {
  _flags[0] |= (1 << 11); _data_f11 = value;
}

inline int32_t *Message::f12() {
  return _flags[0] & (1 << 12) ? &_data_f12 : nullptr;
}

inline const int32_t *Message::f12() const {
  return _flags[0] & (1 << 12) ? &_data_f12 : nullptr;
}

inline void Message::set_f12(const int32_t &value) {
  _flags[0] |= (1 << 12); _data_f12 = value;
}

inline int32_t *Message::f13() {
  return _flags[0] & (1 << 13) ? &_data_f13 : nullptr;
}

inline const int32_t *Message::f13() const {
  return _flags[0] & (1 << 13) ? &_data_f13 : nullptr;
}

inline void Message::set_f13(const int32_t &value) {
  _flags[0] |= (1 << 13); _data_f13 = value;
}

inline int32_t *Message::f14() {
  return _flags[0] & (1 << 14) ? &_data_f14 : nullptr;
}

inline const int32_t *Message::f14() const {
  return _flags[0] & (1 << 14) ? &_data_f14 : nullptr;
}

inline void Message::set_f14(const int32_t &value) {
  _flags[0] |= (1 << 14); _data_f14 = value;
}

inline int32_t *Message::f15() {
  return _flags[0] & (1 << 15) ? &_data_f15 : nullptr;
}

inline const int32_t *Message::f15() const {
  return _flags[0] & (1 << 15) ? &_data_f15 : nullptr;
}

inline void Message::set_f15(const int32_t &value) {
  _flags[0] |= (1 << 15); _data_f15 = value;
}

inline int32_t *Message::f16() {
  return _flags[0] & (1 << 16) ? &_data_f16 : nullptr;
}

inline const int32_t *Message::f16() const {
  return _flags[0] & (1 << 16) ? &_data_f16 : nullptr;
}

inline void Message::set_f16(const int32_t &value) {
  _flags[0] |= (1 << 16); _data_f16 = value;
}

inline int32_t *Message::f17() {
  return _flags[0] & (1 << 17) ? &_data_f17 : nullptr;
}

inline const int32_t *Message::f17() const {
  return _flags[0] & (1 << 17) ? &_data_f17 : nullptr;
}

inline void Message::set_f17(const int32_t &value) {
  _flags[0] |= (1 << 17); _data_f17 = value;
}

inline int32_t *Message::f18() {
  return _flags[0] & (1 << 18) ? &_data_f18 : nullptr;
}

inline const int32_t *Message::f18() const {
  return _flags[0] & (1 << 18) ? &_data_f18 : nullptr;
}

inline void Message::set_f18(const int32_t &value) {
  _flags[0] |= (1 << 18); _data_f18 = value;
}

inline int32_t *Message::f19() {
  return _flags[0] & (1 << 19) ? &_data_f19 : nullptr;
}

inline const int32_t *Message::f19() const {
  return _flags[0] & (1 << 19) ? &_data_f19 : nullptr;
}

inline void Message::set_f19(const int32_t &value) {
  _flags[0] |= (1 << 19); _data_f19 = value;
}

inline int32_t *Message::f20() {
  return _flags[0] & (1 << 20) ? &_data_f20 : nullptr;
}

inline const int32_t *Message::f20() const {
  return _flags[0] & (1 << 20) ? &_data_f20 : nullptr;
}

inline void Message::set_f20(const int32_t &value) {
  _flags[0] |= (1 << 20); _data_f20 = value;
}

inline int32_t *Message::f21() {
  return _flags[0] & (1 << 21) ? &_data_f21 : nullptr;
}

inline const int32_t *Message::f21() const {
  return _flags[0] & (1 << 21) ? &_data_f21 : nullptr;
}

inline void Message::set_f21(const int32_t &value) {
  _flags[0] |= (1 << 21); _data_f21 = value;
}

inline int32_t *Message::f22() {
  return _flags[0] & (1 << 22) ? &_data_f22 : nullptr;
}

inline const int32_t *Message::f22() const {
  return _flags[0] & (1 << 22) ? &_data_f22 : nullptr;
}

inline void Message::set_f22(const int32_t &value) {
  _flags[0] |= (1 << 22); _data_f22 = value;
}

inline int32_t *Message::f23() {
  return _flags[0] & (1 << 23) ? &_data_f23 : nullptr;
}

inline const int32_t *Message::f23() const {
  return _flags[0] & (1 << 23) ? &_data_f23 : nullptr;
}

inline void Message::set_f23(const int32_t &value) {
  _flags[0] |= (1 << 23); _data_f23 = value;
}

inline int32_t *Message::f24() {
  return _flags[0] & (1 << 24) ? &_data_f24 : nullptr;
}

inline const int32_t *Message::f24() const {
  return _flags[0] & (1 << 24) ? &_data_f24 : nullptr;
}

inline void Message::set_f24(const int32_t &value) {
  _flags[0] |= (1 << 24); _data_f24 = value;
}

inline int32_t *Message::f25() {
  return _flags[0] & (1 << 25) ? &_data_f25 : nullptr;
}

inline const int32_t *Message::f25() const {
  return _flags[0] & (1 << 25) ? &_data_f25 : nullptr;
}

inline void Message::set_f25(const int32_t &value) {
  _flags[0] |= (1 << 25); _data_f25 = value;
}

inline int32_t *Message::f26() {
  return _flags[0] & (1 << 26) ? &_data_f26 : nullptr;
}

inline const int32_t *Message::f26() const {
  return _flags[0] & (1 << 26) ? &_data_f26 : nullptr;
}

inline void Message::set_f26(const int32_t &value) {
  _flags[0] |= (1 << 26); _data_f26 = value;
}

inline int32_t *Message::f27() {
  return _flags[0] & (1 << 27) ? &_data_f27 : nullptr;
}

inline const int32_t *Message::f27() const {
  return _flags[0] & (1 << 27) ? &_data_f27 : nullptr;
}

inline void Message::set_f27(const int32_t &value) {
  _flags[0] |= (1 << 27); _data_f27 = value;
}

inline int32_t *Message::f28() {
  return _flags[0] & (1 << 28) ? &_data_f28 : nullptr;
}

inline const int32_t *Message::f28() const {
  return _flags[0] & (1 << 28) ? &_data_f28 : nullptr;
}

inline void Message::set_f28(const int32_t &value) {
  _flags[0] |= (1 << 28); _data_f28 = value;
}

inline int32_t *Message::f29() {
  return _flags[0] & (1 << 29) ? &_data_f29 : nullptr;
}

inline const int32_t *Message::f29() const {
  return _flags[0] & (1 << 29) ? &_data_f29 : nullptr;
}

inline void Message::set_f29(const int32_t &value) {
  _flags[0] |= (1 << 29); _data_f29 = value;
}

inline int32_t *Message::f30() {
  return _flags[0] & (1 << 30) ? &_data_f30 : nullptr;
}

inline const int32_t *Message::f30() const {
  return _flags[0] & (1 << 30) ? &_data_f30 : nullptr;
}

inline void Message::set_f30(const int32_t &value) {
  _flags[0] |= (1 << 30); _data_f30 = value;
}

inline int32_t *Message::f31() {
  return _flags[0] & (1 << 31) ? &_data_f31 : nullptr;
}

inline const int32_t *Message::f31() const {
  return _flags[0] & (1 << 31) ? &_data_f31 : nullptr;
}

inline void Message::set_f31(const int32_t &value) {
  _flags[0] |= (1 << 31); _data_f31 = value;
}

inline int32_t *Message::f32() {
  return _flags[1] & (1 << 0) ? &_data_f32 : nullptr;
}

inline const int32_t *Message::f32() const {
  return _flags[1] & (1 << 0) ? &_data_f32 : nullptr;
}

inline void Message::set_f32(const int32_t &value) {
  _flags[1] |= (1 << 0); _data_f32 = value;
}

inline int32_t *Message::f33() {
  return _flags[1] & (1 << 1) ? &_data_f33 : nullptr;
}

inline const int32_t *Message::f33() const {
  return _flags[1] & (1 << 1) ? &_data_f33 : nullptr;
}

inline void Message::set_f33(const int32_t &value) {
  _flags[1] |= (1 << 1); _data_f33 = value;
}

inline int32_t *Message::f34() {
  return _flags[1] & (1 << 2) ? &_data_f34 : nullptr;
}

inline const int32_t *Message::f34() const {
  return _flags[1] & (1 << 2) ? &_data_f34 : nullptr;
}

inline void Message::set_f34(const int32_t &value) {
  _flags[1] |= (1 << 2); _data_f34 = value;
}

inline int32_t *Message::f35() {
  return _flags[1] & (1 << 3) ? &_data_f35 : nullptr;
}

inline const int32_t *Message::f35() const {
  return _flags[1] & (1 << 3) ? &_data_f35 : nullptr;
}

inline void Message::set_f35(const int32_t &value) {
  _flags[1] |= (1 << 3); _data_f35 = value;
}

inline int32_t *Message::f36() {
  return _flags[1] & (1 << 4) ? &_data_f36 : nullptr;
}

inline const int32_t *Message::f36() const {
  return _flags[1] & (1 << 4) ? &_data_f36 : nullptr;
}

inline void Message::set_f36(const int32_t &value) {
  _flags[1] |= (1 << 4); _data_f36 = value;
}

inline int32_t *Message::f37() {
  return _flags[1] & (1 << 5) ? &_data_f37 : nullptr;
}

inline const int32_t *Message::f37() const {
  return _flags[1] & (1 << 5) ? &_data_f37 : nullptr;
}

inline void Message::set_f37(const int32_t &value) {
  _flags[1] |= (1 << 5); _data_f37 = value;
}

inline int32_t *Message::f38() {
  return _flags[1] & (1 << 6) ? &_data_f38 : nullptr;
}

inline const int32_t *Message::f38() const {
  return _flags[1] & (1 << 6) ? &_data_f38 : nullptr;
}

inline void Message::set_f38(const int32_t &value) {
  _flags[1] |= (1 << 6); _data_f38 = value;
}

inline int32_t *Message::f39() {
  return _flags[1] & (1 << 7) ? &_data_f39 : nullptr;
}

inline const int32_t *Message::f39() const {
  return _flags[1] & (1 << 7) ? &_data_f39 : nullptr;
}

inline void Message::set_f39(const int32_t &value) {
  _flags[1] |= (1 << 7); _data_f39 = value;
}

inline int32_t *Message::f40() {
  return _flags[1] & (1 << 8) ? &_data_f40 : nullptr;
}

inline const int32_t *Message::f40() const {
  return _flags[1] & (1 << 8) ? &_data_f40 : nullptr;
}

inline void Message::set_f40(const int32_t &value) {
  _flags[1] |= (1 << 8); _data_f40 = value;
}

inline int32_t *Message::f41() {
  return _flags[1] & (1 << 9) ? &_data_f41 : nullptr;
}

inline const int32_t *Message::f41() const {
  return _flags[1] & (1 << 9) ? &_data_f41 : nullptr;
}

inline void Message::set_f41(const int32_t &value) {
  _flags[1] |= (1 << 9); _data_f41 = value;
}

inline int32_t *Message::f42() {
  return _flags[1] & (1 << 10) ? &_data_f42 : nullptr;
}

inline const int32_t *Message::f42() const {
  return _flags[1] & (1 << 10) ? &_data_f42 : nullptr;
}

inline void Message::set_f42(const int32_t &value) {
  _flags[1] |= (1 << 10); _data_f42 = value;
}

inline int32_t *Message::f43() {
  return _flags[1] & (1 << 11) ? &_data_f43 : nullptr;
}

inline const int32_t *Message::f43() const {
  return _flags[1] & (1 << 11) ? &_data_f43 : nullptr;
}

inline void Message::set_f43(const int32_t &value) {
  _flags[1] |= (1 << 11); _data_f43 = value;
}

inline int32_t *Message::f44() {
  return _flags[1] & (1 << 12) ? &_data_f44 : nullptr;
}

inline const int32_t *Message::f44() const {
  return _flags[1] & (1 << 12) ? &_data_f44 : nullptr;
}

inline void Message::set_f44(const int32_t &value) {
  _flags[1] |= (1 << 12); _data_f44 = value;
}

inline int32_t *Message::f45() {
  return _flags[1] & (1 << 13) ? &_data_f45 : nullptr;
}

inline const int32_t *Message::f45() const {
  return _flags[1] & (1 << 13) ? &_data_f45 : nullptr;
}

inline void Message::set_f45(const int32_t &value) {
  _flags[1] |= (1 << 13); _data_f45 = value;
}

inline int32_t *Message::f46() {
  return _flags[1] & (1 << 14) ? &_data_f46 : nullptr;
}

inline const int32_t *Message::f46() const {
  return _flags[1] & (1 << 14) ? &_data_f46 : nullptr;
}

inline void Message::set_f46(const int32_t &value) {
  _flags[1] |= (1 << 14); _data_f46 = value;
}

inline int32_t *Message::f47() {
  return _flags[1] & (1 << 15) ? &_data_f47 : nullptr;
}

inline const int32_t *Message::f47() const {
  return _flags[1] & (1 << 15) ? &_data_f47 : nullptr;
}

inline void Message::set_f47(const int32_t &value) {
  _flags[1] |= (1 << 15); _data_f47 = value;
}

inline int32_t *Message::f48() {
  return _flags[1] & (1 << 16) ? &_data_f48 : nullptr;
}

inline const int32_t *Message::f48() const {
  return _flags[1] & (1 << 16) ? &_data_f48 : nullptr;
}

inline void Message::set_f48(const int32_t &value) {
  _flags[1] |= (1 << 16); _data_f48 = value;
}

inline int32_t *Message::f49() {
  return _flags[1] & (1 << 17) ? &_data_f49 : nullptr;
}

inline const int32_t *Message::f49() const {
  return _flags[1] & (1 << 17) ? &_data_f49 : nullptr;
}

inline void Message::set_f49(const int32_t &value) {
  _flags[1] |= (1 << 17); _data_f49 = value;
}

inline int32_t *Message::f50() {
  return _flags[1] & (1 << 18) ? &_data_f50 : nullptr;
}

inline const int32_t *Message::f50() const {
  return _flags[1] & (1 << 18) ? &_data_f50 : nullptr;
}

inline void Message::set_f50(const int32_t &value) {
  _flags[1] |= (1 << 18); _data_f50 = value;
}

inline int32_t *Message::f51() {
  return _flags[1] & (1 << 19) ? &_data_f51 : nullptr;
}

inline const int32_t *Message::f51() const {
  return _flags[1] & (1 << 19) ? &_data_f51 : nullptr;
}

inline void Message::set_f51(const int32_t &value) {
  _flags[1] |= (1 << 19); _data_f51 = value;
}

inline int32_t *Message::f52() {
  return _flags[1] & (1 << 20) ? &_data_f52 : nullptr;
}

inline const int32_t *Message::f52() const {
  return _flags[1] & (1 << 20) ? &_data_f52 : nullptr;
}

inline void Message::set_f52(const int32_t &value) {
  _flags[1] |= (1 << 20); _data_f52 = value;
}

inline int32_t *Message::f53() {
  return _flags[1] & (1 << 21) ? &_data_f53 : nullptr;
}

inline const int32_t *Message::f53() const {
  return _flags[1] & (1 << 21) ? &_data_f53 : nullptr;
}

inline void Message::set_f53(const int32_t &value) {
  _flags[1] |= (1 << 21); _data_f53 = value;
}

inline int32_t *Message::f54() {
  return _flags[1] & (1 << 22) ? &_data_f54 : nullptr;
}

inline const int32_t *Message::f54() const {
  return _flags[1] & (1 << 22) ? &_data_f54 : nullptr;
}

inline void Message::set_f54(const int32_t &value) {
  _flags[1] |= (1 << 22); _data_f54 = value;
}

inline int32_t *Message::f55() {
  return _flags[1] & (1 << 23) ? &_data_f55 : nullptr;
}

inline const int32_t *Message::f55() const {
  return _flags[1] & (1 << 23) ? &_data_f55 : nullptr;
}

inline void Message::set_f55(const int32_t &value) {
  _flags[1] |= (1 << 23); _data_f55 = value;
}

inline int32_t *Message::f56() {
  return _flags[1] & (1 << 24) ? &_data_f56 : nullptr;
}

inline const int32_t *Message::f56() const {
  return _flags[1] & (1 << 24) ? &_data_f56 : nullptr;
}

inline void Message::set_f56(const int32_t &value) {
  _flags[1] |= (1 << 24); _data_f56 = value;
}

inline int32_t *Message::f57() {
  return _flags[1] & (1 << 25) ? &_data_f57 : nullptr;
}

inline const int32_t *Message::f57() const {
  return _flags[1] & (1 << 25) ? &_data_f57 : nullptr;
}

inline void Message::set_f57(const int32_t &value) {
  _flags[1] |= (1 << 25); _data_f57 = value;
}

inline int32_t *Message::f58() {
  return _flags[1] & (1 << 26) ? &_data_f58 : nullptr;
}

inline const int32_t *Message::f58() const {
  return _flags[1] & (1 << 26) ? &_data_f58 : nullptr;
}

inline void Message::set_f58(const int32_t &value) {
  _flags[1] |= (1 << 26); _data_f58 = value;
}

inline int32_t *Message::f59() {
  return _flags[1] & (1 << 27) ? &_data_f59 : nullptr;
}

inline const int32_t *Message::f59() const {
  return _flags[1] & (1 << 27) ? &_data_f59 : nullptr;
}

inline void Message::set_f59(const int32_t &value) {
  _flags[1] |= (1 << 27); _data_f59 = value;
}

inline int32_t *Message::f60() {
  return _flags[1] & (1 << 28) ? &_data_f60 : nullptr;
}

inline const int32_t *Message::f60() const {
  return _flags[1] & (1 << 28) ? &_data_f60 : nullptr;
}

inline void Message::set_f60(const int32_t &value) {
  _flags[1] |= (1 << 28); _data_f60 = value;
}

inline int32_t *Message::f61() {
  return _flags[1] & (1 << 29) ? &_data_f61 : nullptr;
}

inline const int32_t *Message::f61() const {
  return _flags[1] & (1 << 29) ? &_data_f61 : nullptr;
}

inline void Message::set_f61(const int32_t &value) {
  _flags[1] |= (1 << 29); _data_f61 = value;
}

inline int32_t *Message::f62() {
  return _flags[1] & (1 << 30) ? &_data_f62 : nullptr;
}

inline const int32_t *Message::f62() const {
  return _flags[1] & (1 << 30) ? &_data_f62 : nullptr;
}

inline void Message::set_f62(const int32_t &value) {
  _flags[1] |= (1 << 30); _data_f62 = value;
}

inline int32_t *Message::f63() {
  return _flags[1] & (1 << 31) ? &_data_f63 : nullptr;
}

inline const int32_t *Message::f63() const {
  return _flags[1] & (1 << 31) ? &_data_f63 : nullptr;
}

inline void Message::set_f63(const int32_t &value) {
  _flags[1] |= (1 << 31); _data_f63 = value;
}

inline int32_t *Message::f64() {
  return _flags[2] & (1 << 0) ? &_data_f64 : nullptr;
}

inline const int32_t *Message::f64() const {
  return _flags[2] & (1 << 0) ? &_data_f64 : nullptr;
}

inline void Message::set_f64(const int32_t &value) {
  _flags[2] |= (1 << 0); _data_f64 = value;
}

inline int32_t *Message::f65() {
  return _flags[2] & (1 << 1) ? &_data_f65 : nullptr;
}

inline const int32_t *Message::f65() const {
  return _flags[2] & (1 << 1) ? &_data_f65 : nullptr;
}

inline void Message::set_f65(const int32_t &value) {
  _flags[2] |= (1 << 1); _data_f65 = value;
}

inline int32_t *Message::f66() {
  return _flags[2] & (1 << 2) ? &_data_f66 : nullptr;
}

inline const int32_t *Message::f66() const {
  return _flags[2] & (1 << 2) ? &_data_f66 : nullptr;
}

inline void Message::set_f66(const int32_t &value) {
  _flags[2] |= (1 << 2); _data_f66 = value;
}

inline int32_t *Message::f67() {
  return _flags[2] & (1 << 3) ? &_data_f67 : nullptr;
}

inline const int32_t *Message::f67() const {
  return _flags[2] & (1 << 3) ? &_data_f67 : nullptr;
}

inline void Message::set_f67(const int32_t &value) {
  _flags[2] |= (1 << 3); _data_f67 = value;
}

inline int32_t *Message::f68() {
  return _flags[2] & (1 << 4) ? &_data_f68 : nullptr;
}

inline const int32_t *Message::f68() const {
  return _flags[2] & (1 << 4) ? &_data_f68 : nullptr;
}

inline void Message::set_f68(const int32_t &value) {
  _flags[2] |= (1 << 4); _data_f68 = value;
}

inline int32_t *Message::f69() {
  return _flags[2] & (1 << 5) ? &_data_f69 : nullptr;
}

inline const int32_t *Message::f69() const {
  return _flags[2] & (1 << 5) ? &_data_f69 : nullptr;
}

inline void Message::set_f69(const int32_t &value) {
  _flags[2] |= (1 << 5); _data_f69 = value;
}

inline int32_t *Message::f70() {
  return _flags[2] & (1 << 6) ? &_data_f70 : nullptr;
}

inline const int32_t *Message::f70() const {
  return _flags[2] & (1 << 6) ? &_data_f70 : nullptr;
}

inline void Message::set_f70(const int32_t &value) {
  _flags[2] |= (1 << 6); _data_f70 = value;
}

inline int32_t *Message::f71() {
  return _flags[2] & (1 << 7) ? &_data_f71 : nullptr;
}

inline const int32_t *Message::f71() const {
  return _flags[2] & (1 << 7) ? &_data_f71 : nullptr;
}

inline void Message::set_f71(const int32_t &value) {
  _flags[2] |= (1 << 7); _data_f71 = value;
}

inline int32_t *Message::f72() {
  return _flags[2] & (1 << 8) ? &_data_f72 : nullptr;
}

inline const int32_t *Message::f72() const {
  return _flags[2] & (1 << 8) ? &_data_f72 : nullptr;
}

inline void Message::set_f72(const int32_t &value) {
  _flags[2] |= (1 << 8); _data_f72 = value;
}

inline int32_t *Message::f73() {
  return _flags[2] & (1 << 9) ? &_data_f73 : nullptr;
}

inline const int32_t *Message::f73() const {
  return _flags[2] & (1 << 9) ? &_data_f73 : nullptr;
}

inline void Message::set_f73(const int32_t &value) {
  _flags[2] |= (1 << 9); _data_f73 = value;
}

inline int32_t *Message::f74() {
  return _flags[2] & (1 << 10) ? &_data_f74 : nullptr;
}

inline const int32_t *Message::f74() const {
  return _flags[2] & (1 << 10) ? &_data_f74 : nullptr;
}

inline void Message::set_f74(const int32_t &value) {
  _flags[2] |= (1 << 10); _data_f74 = value;
}

inline int32_t *Message::f75() {
  return _flags[2] & (1 << 11) ? &_data_f75 : nullptr;
}

inline const int32_t *Message::f75() const {
  return _flags[2] & (1 << 11) ? &_data_f75 : nullptr;
}

inline void Message::set_f75(const int32_t &value) {
  _flags[2] |= (1 << 11); _data_f75 = value;
}

inline int32_t *Message::f76() {
  return _flags[2] & (1 << 12) ? &_data_f76 : nullptr;
}

inline const int32_t *Message::f76() const {
  return _flags[2] & (1 << 12) ? &_data_f76 : nullptr;
}

inline void Message::set_f76(const int32_t &value) {
  _flags[2] |= (1 << 12); _data_f76 = value;
}

inline int32_t *Message::f77() {
  return _flags[2] & (1 << 13) ? &_data_f77 : nullptr;
}

inline const int32_t *Message::f77() const {
  return _flags[2] & (1 << 13) ? &_data_f77 : nullptr;
}

inline void Message::set_f77(const int32_t &value) {
  _flags[2] |= (1 << 13); _data_f77 = value;
}

inline int32_t *Message::f78() {
  return _flags[2] & (1 << 14) ? &_data_f78 : nullptr;
}

inline const int32_t *Message::f78() const {
  return _flags[2] & (1 << 14) ? &_data_f78 : nullptr;
}

inline void Message::set_f78(const int32_t &value) {
  _flags[2] |= (1 << 14); _data_f78 = value;
}

inline int32_t *Message::f79() {
  return _flags[2] & (1 << 15) ? &_data_f79 : nullptr;
}

inline const int32_t *Message::f79() const {
  return _flags[2] & (1 << 15) ? &_data_f79 : nullptr;
}

inline void Message::set_f79(const int32_t &value) {
  _flags[2] |= (1 << 15); _data_f79 = value;
}

inline int32_t *Message::f80() {
  return _flags[2] & (1 << 16) ? &_data_f80 : nullptr;
}

inline const int32_t *Message::f80() const {
  return _flags[2] & (1 << 16) ? &_data_f80 : nullptr;
}

inline void Message::set_f80(const int32_t &value) {
  _flags[2] |= (1 << 16); _data_f80 = value;
}

inline int32_t *Message::f81() {
  return _flags[2] & (1 << 17) ? &_data_f81 : nullptr;
}

inline const int32_t *Message::f81() const {
  return _flags[2] & (1 << 17) ? &_data_f81 : nullptr;
}

inline void Message::set_f81(const int32_t &value) {
  _flags[2] |= (1 << 17); _data_f81 = value;
}

inline int32_t *Message::f82() {
  return _flags[2] & (1 << 18) ? &_data_f82 : nullptr;
}

inline const int32_t *Message::f82() const {
  return _flags[2] & (1 << 18) ? &_data_f82 : nullptr;
}

inline void Message::set_f82(const int32_t &value) {
  _flags[2] |= (1 << 18); _data_f82 = value;
}

inline int32_t *Message::f83() {
  return _flags[2] & (1 << 19) ? &_data_f83 : nullptr;
}

inline const int32_t *Message::f83() const {
  return _flags[2] & (1 << 19) ? &_data_f83 : nullptr;
}

inline void Message::set_f83(const int32_t &value) {
  _flags[2] |= (1 << 19); _data_f83 = value;
}

inline int32_t *Message::f84() {
  return _flags[2] & (1 << 20) ? &_data_f84 : nullptr;
}

inline const int32_t *Message::f84() const {
  return _flags[2] & (1 << 20) ? &_data_f84 : nullptr;
}

inline void Message::set_f84(const int32_t &value) {
  _flags[2] |= (1 << 20); _data_f84 = value;
}

inline int32_t *Message::f85() {
  return _flags[2] & (1 << 21) ? &_data_f85 : nullptr;
}

inline const int32_t *Message::f85() const {
  return _flags[2] & (1 << 21) ? &_data_f85 : nullptr;
}

inline void Message::set_f85(const int32_t &value) {
  _flags[2] |= (1 << 21); _data_f85 = value;
}

inline int32_t *Message::f86() {
  return _flags[2] & (1 << 22) ? &_data_f86 : nullptr;
}

inline const int32_t *Message::f86() const {
  return _flags[2] & (1 << 22) ? &_data_f86 : nullptr;
}

inline void Message::set_f86(const int32_t &value) {
  _flags[2] |= (1 << 22); _data_f86 = value;
}

inline int32_t *Message::f87() {
  return _flags[2] & (1 << 23) ? &_data_f87 : nullptr;
}

inline const int32_t *Message::f87() const {
  return _flags[2] & (1 << 23) ? &_data_f87 : nullptr;
}

inline void Message::set_f87(const int32_t &value) {
  _flags[2] |= (1 << 23); _data_f87 = value;
}

inline int32_t *Message::f88() {
  return _flags[2] & (1 << 24) ? &_data_f88 : nullptr;
}

inline const int32_t *Message::f88() const {
  return _flags[2] & (1 << 24) ? &_data_f88 : nullptr;
}

inline void Message::set_f88(const int32_t &value) {
  _flags[2] |= (1 << 24); _data_f88 = value;
}

inline int32_t *Message::f89() {
  return _flags[2] & (1 << 25) ? &_data_f89 : nullptr;
}

inline const int32_t *Message::f89() const {
  return _flags[2] & (1 << 25) ? &_data_f89 : nullptr;
}

inline void Message::set_f89(const int32_t &value) {
  _flags[2] |= (1 << 25); _data_f89 = value;
}

inline int32_t *Message::f90() {
  return _flags[2] & (1 << 26) ? &_data_f90 : nullptr;
}

inline const int32_t *Message::f90() const {
  return _flags[2] & (1 << 26) ? &_data_f90 : nullptr;
}

inline void Message::set_f90(const int32_t &value) {
  _flags[2] |= (1 << 26); _data_f90 = value;
}

inline int32_t *Message::f91() {
  return _flags[2] & (1 << 27) ? &_data_f91 : nullptr;
}

inline const int32_t *Message::f91() const {
  return _flags[2] & (1 << 27) ? &_data_f91 : nullptr;
}

inline void Message::set_f91(const int32_t &value) {
  _flags[2] |= (1 << 27); _data_f91 = value;
}

inline int32_t *Message::f92() {
  return _flags[2] & (1 << 28) ? &_data_f92 : nullptr;
}

inline const int32_t *Message::f92() const {
  return _flags[2] & (1 << 28) ? &_data_f92 : nullptr;
}

inline void Message::set_f92(const int32_t &value) {
  _flags[2] |= (1 << 28); _data_f92 = value;
}

inline int32_t *Message::f93() {
  return _flags[2] & (1 << 29) ? &_data_f93 : nullptr;
}

inline const int32_t *Message::f93() const {
  return _flags[2] & (1 << 29) ? &_data_f93 : nullptr;
}

inline void Message::set_f93(const int32_t &value) {
  _flags[2] |= (1 << 29); _data_f93 = value;
}

inline int32_t *Message::f94() {
  return _flags[2] & (1 << 30) ? &_data_f94 : nullptr;
}

inline const int32_t *Message::f94() const {
  return _flags[2] & (1 << 30) ? &_data_f94 : nullptr;
}

inline void Message::set_f94(const int32_t &value) {
  _flags[2] |= (1 << 30); _data_f94 = value;
}

inline int32_t *Message::f95() {
  return _flags[2] & (1 << 31) ? &_data_f95 : nullptr;
}

inline const int32_t *Message::f95() const {
  return _flags[2] & (1 << 31) ? &_data_f95 : nullptr;
}

inline void Message::set_f95(const int32_t &value) {
  _flags[2] |= (1 << 31); _data_f95 = value;
}

inline int32_t *Message::f96() {
  return _flags[3] & (1 << 0) ? &_data_f96 : nullptr;
}

inline const int32_t *Message::f96() const {
  return _flags[3] & (1 << 0) ? &_data_f96 : nullptr;
}

inline void Message::set_f96(const int32_t &value) {
  _flags[3] |= (1 << 0); _data_f96 = value;
}

inline int32_t *Message::f97() {
  return _flags[3] & (1 << 1) ? &_data_f97 : nullptr;
}

inline const int32_t *Message::f97() const {
  return _flags[3] & (1 << 1) ? &_data_f97 : nullptr;
}

inline void Message::set_f97(const int32_t &value) {
  _flags[3] |= (1 << 1); _data_f97 = value;
}

inline int32_t *Message::f98() {
  return _flags[3] & (1 << 2) ? &_data_f98 : nullptr;
}

inline const int32_t *Message::f98() const {
  return _flags[3] & (1 << 2) ? &_data_f98 : nullptr;
}

inline void Message::set_f98(const int32_t &value) {
  _flags[3] |= (1 << 2); _data_f98 = value;
}

inline int32_t *Message::f99() {
  return _flags[3] & (1 << 3) ? &_data_f99 : nullptr;
}

inline const int32_t *Message::f99() const {
  return _flags[3] & (1 << 3) ? &_data_f99 : nullptr;
}

inline void Message::set_f99(const int32_t &value) {
  _flags[3] |= (1 << 3); _data_f99 = value;
}

inline int32_t *Message::f100() {
  return _flags[3] & (1 << 4) ? &_data_f100 : nullptr;
}

inline const int32_t *Message::f100() const {
  return _flags[3] & (1 << 4) ? &_data_f100 : nullptr;
}

inline void Message::set_f100(const int32_t &value) {
  _flags[3] |= (1 << 4); _data_f100 = value;
}

inline int32_t *Message::f101() {
  return _flags[3] & (1 << 5) ? &_data_f101 : nullptr;
}

inline const int32_t *Message::f101() const {
  return _flags[3] & (1 << 5) ? &_data_f101 : nullptr;
}

inline void Message::set_f101(const int32_t &value) {
  _flags[3] |= (1 << 5); _data_f101 = value;
}

inline int32_t *Message::f102() {
  return _flags[3] & (1 << 6) ? &_data_f102 : nullptr;
}

inline const int32_t *Message::f102() const {
  return _flags[3] & (1 << 6) ? &_data_f102 : nullptr;
}

inline void Message::set_f102(const int32_t &value) {
  _flags[3] |= (1 << 6); _data_f102 = value;
}

inline int32_t *Message::f103() {
  return _flags[3] & (1 << 7) ? &_data_f103 : nullptr;
}

inline const int32_t *Message::f103() const {
  return _flags[3] & (1 << 7) ? &_data_f103 : nullptr;
}

inline void Message::set_f103(const int32_t &value) {
  _flags[3] |= (1 << 7); _data_f103 = value;
}

inline int32_t *Message::f104() {
  return _flags[3] & (1 << 8) ? &_data_f104 : nullptr;
}

inline const int32_t *Message::f104() const {
  return _flags[3] & (1 << 8) ? &_data_f104 : nullptr;
}

inline void Message::set_f104(const int32_t &value) {
  _flags[3] |= (1 << 8); _data_f104 = value;
}

inline int32_t *Message::f105() {
  return _flags[3] & (1 << 9) ? &_data_f105 : nullptr;
}

inline const int32_t *Message::f105() const {
  return _flags[3] & (1 << 9) ? &_data_f105 : nullptr;
}

inline void Message::set_f105(const int32_t &value) {
  _flags[3] |= (1 << 9); _data_f105 = value;
}

inline int32_t *Message::f106() {
  return _flags[3] & (1 << 10) ? &_data_f106 : nullptr;
}

inline const int32_t *Message::f106() const {
  return _flags[3] & (1 << 10) ? &_data_f106 : nullptr;
}

inline void Message::set_f106(const int32_t &value) {
  _flags[3] |= (1 << 10); _data_f106 = value;
}

inline int32_t *Message::f107() {
  return _flags[3] & (1 << 11) ? &_data_f107 : nullptr;
}

inline const int32_t *Message::f107() const {
  return _flags[3] & (1 << 11) ? &_data_f107 : nullptr;
}

inline void Message::set_f107(const int32_t &value) {
  _flags[3] |= (1 << 11); _data_f107 = value;
}

inline int32_t *Message::f108() {
  return _flags[3] & (1 << 12) ? &_data_f108 : nullptr;
}

inline const int32_t *Message::f108() const {
  return _flags[3] & (1 << 12) ? &_data_f108 : nullptr;
}

inline void Message::set_f108(const int32_t &value) {
  _flags[3] |= (1 << 12); _data_f108 = value;
}

inline int32_t *Message::f109() {
  return _flags[3] & (1 << 13) ? &_data_f109 : nullptr;
}

inline const int32_t *Message::f109() const {
  return _flags[3] & (1 << 13) ? &_data_f109 : nullptr;
}

inline void Message::set_f109(const int32_t &value) {
  _flags[3] |= (1 << 13); _data_f109 = value;
}

inline int32_t *Message::f110() {
  return _flags[3] & (1 << 14) ? &_data_f110 : nullptr;
}

inline const int32_t *Message::f110() const {
  return _flags[3] & (1 << 14) ? &_data_f110 : nullptr;
}

inline void Message::set_f110(const int32_t &value) {
  _flags[3] |= (1 << 14); _data_f110 = value;
}

inline int32_t *Message::f111() {
  return _flags[3] & (1 << 15) ? &_data_f111 : nullptr;
}

inline const int32_t *Message::f111() const {
  return _flags[3] & (1 << 15) ? &_data_f111 : nullptr;
}

inline void Message::set_f111(const int32_t &value) {
  _flags[3] |= (1 << 15); _data_f111 = value;
}

inline int32_t *Message::f112() {
  return _flags[3] & (1 << 16) ? &_data_f112 : nullptr;
}

inline const int32_t *Message::f112() const {
  return _flags[3] & (1 << 16) ? &_data_f112 : nullptr;
}

inline void Message::set_f112(const int32_t &value) {
  _flags[3] |= (1 << 16); _data_f112 = value;
}

inline int32_t *Message::f113() {
  return _flags[3] & (1 << 17) ? &_data_f113 : nullptr;
}

inline const int32_t *Message::f113() const {
  return _flags[3] & (1 << 17) ? &_data_f113 : nullptr;
}

inline void Message::set_f113(const int32_t &value) {
  _flags[3] |= (1 << 17); _data_f113 = value;
}

inline int32_t *Message::f114() {
  return _flags[3] & (1 << 18) ? &_data_f114 : nullptr;
}

inline const int32_t *Message::f114() const {
  return _flags[3] & (1 << 18) ? &_data_f114 : nullptr;
}

inline void Message::set_f114(const int32_t &value) {
  _flags[3] |= (1 << 18); _data_f114 = value;
}

inline int32_t *Message::f115() {
  return _flags[3] & (1 << 19) ? &_data_f115 : nullptr;
}

inline const int32_t *Message::f115() const {
  return _flags[3] & (1 << 19) ? &_data_f115 : nullptr;
}

inline void Message::set_f115(const int32_t &value) {
  _flags[3] |= (1 << 19); _data_f115 = value;
}

inline int32_t *Message::f116() {
  return _flags[3] & (1 << 20) ? &_data_f116 : nullptr;
}

inline const int32_t *Message::f116() const {
  return _flags[3] & (1 << 20) ? &_data_f116 : nullptr;
}

inline void Message::set_f116(const int32_t &value) {
  _flags[3] |= (1 << 20); _data_f116 = value;
}

inline int32_t *Message::f117() {
  return _flags[3] & (1 << 21) ? &_data_f117 : nullptr;
}

inline const int32_t *Message::f117() const {
  return _flags[3] & (1 << 21) ? &_data_f117 : nullptr;
}

inline void Message::set_f117(const int32_t &value) {
  _flags[3] |= (1 << 21); _data_f117 = value;
}

inline int32_t *Message::f118() {
  return _flags[3] & (1 << 22) ? &_data_f118 : nullptr;
}

inline const int32_t *Message::f118() const {
  return _flags[3] & (1 << 22) ? &_data_f118 : nullptr;
}

inline void Message::set_f118(const int32_t &value) {
  _flags[3] |= (1 << 22); _data_f118 = value;
}

inline int32_t *Message::f119() {
  return _flags[3] & (1 << 23) ? &_data_f119 : nullptr;
}

inline const int32_t *Message::f119() const {
  return _flags[3] & (1 << 23) ? &_data_f119 : nullptr;
}

inline void Message::set_f119(const int32_t &value) {
  _flags[3] |= (1 << 23); _data_f119 = value;
}

inline int32_t *Message::f120() {
  return _flags[3] & (1 << 24) ? &_data_f120 : nullptr;
}

inline const int32_t *Message::f120() const {
  return _flags[3] & (1 << 24) ? &_data_f120 : nullptr;
}

inline void Message::set_f120(const int32_t &value) {
  _flags[3] |= (1 << 24); _data_f120 = value;
}

inline int32_t *Message::f121() {
  return _flags[3] & (1 << 25) ? &_data_f121 : nullptr;
}

inline const int32_t *Message::f121() const {
  return _flags[3] & (1 << 25) ? &_data_f121 : nullptr;
}

inline void Message::set_f121(const int32_t &value) {
  _flags[3] |= (1 << 25); _data_f121 = value;
}

inline int32_t *Message::f122() {
  return _flags[3] & (1 << 26) ? &_data_f122 : nullptr;
}

inline const int32_t *Message::f122() const {
  return _flags[3] & (1 << 26) ? &_data_f122 : nullptr;
}

inline void Message::set_f122(const int32_t &value) {
  _flags[3] |= (1 << 26); _data_f122 = value;
}

inline int32_t *Message::f123() {
  return _flags[3] & (1 << 27) ? &_data_f123 : nullptr;
}

inline const int32_t *Message::f123() const {
  return _flags[3] & (1 << 27) ? &_data_f123 : nullptr;
}

inline void Message::set_f123(const int32_t &value) {
  _flags[3] |= (1 << 27); _data_f123 = value;
}

inline int32_t *Message::f124() {
  return _flags[3] & (1 << 28) ? &_data_f124 : nullptr;
}

inline const int32_t *Message::f124() const {
  return _flags[3] & (1 << 28) ? &_data_f124 : nullptr;
}

inline void Message::set_f124(const int32_t &value) {
  _flags[3] |= (1 << 28); _data_f124 = value;
}

inline int32_t *Message::f125() {
  return _flags[3] & (1 << 29) ? &_data_f125 : nullptr;
}

inline const int32_t *Message::f125() const {
  return _flags[3] & (1 << 29) ? &_data_f125 : nullptr;
}

inline void Message::set_f125(const int32_t &value) {
  _flags[3] |= (1 << 29); _data_f125 = value;
}

inline int32_t *Message::f126() {
  return _flags[3] & (1 << 30) ? &_data_f126 : nullptr;
}

inline const int32_t *Message::f126() const {
  return _flags[3] & (1 << 30) ? &_data_f126 : nullptr;
}

inline void Message::set_f126(const int32_t &value) {
  _flags[3] |= (1 << 30); _data_f126 = value;
}

inline int32_t *Message::f127() {
  return _flags[3] & (1 << 31) ? &_data_f127 : nullptr;
}

inline const int32_t *Message::f127() const {
  return _flags[3] & (1 << 31) ? &_data_f127 : nullptr;
}

inline void Message::set_f127(const int32_t &value) {
  _flags[3] |= (1 << 31); _data_f127 = value;
}

inline int32_t *Message::f128() {
  return _flags[4] & (1 << 0) ? &_data_f128 : nullptr;
}

inline const int32_t *Message::f128() const {
  return _flags[4] & (1 << 0) ? &_data_f128 : nullptr;
}

inline void Message::set_f128(const int32_t &value) {
  _flags[4] |= (1 << 0); _data_f128 = value;
}

inline int32_t *Message::f129() {
  return _flags[4] & (1 << 1) ? &_data_f129 : nullptr;
}

inline const int32_t *Message::f129() const {
  return _flags[4] & (1 << 1) ? &_data_f129 : nullptr;
}

inline void Message::set_f129(const int32_t &value) {
  _flags[4] |= (1 << 1); _data_f129 = value;
}

#endif  // INCLUDE_TEST_LARGE_H
#ifdef IMPLEMENT_SCHEMA_H

bool BinarySchema::parse(kiwi::ByteBuffer &bb) {
  if (!_schema.parse(bb)) return false;
  _schema.findDefinition("Message", _indexMessage);
  return true;
}

bool BinarySchema::skipMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMessage, id);
}

bool Struct::encode(kiwi::WriteBuffer &_wb) const {
  if (f0() == nullptr) return false;
  _wb.writeVarInt(_data_f0);
  if (f1() == nullptr) return false;
  _wb.writeVarInt(_data_f1);
  if (f2() == nullptr) return false;
  _wb.writeVarInt(_data_f2);
  if (f3() == nullptr) return false;
  _wb.writeVarInt(_data_f3);
  if (f4() == nullptr) return false;
  _wb.writeVarInt(_data_f4);
  if (f5() == nullptr) return false;
  _wb.writeVarInt(_data_f5);
  if (f6() == nullptr) return false;
  _wb.writeVarInt(_data_f6);
  if (f7() == nullptr) return false;
  _wb.writeVarInt(_data_f7);
  if (f8() == nullptr) return false;
  _wb.writeVarInt(_data_f8);
  if (f9() == nullptr) return false;
  _wb.writeVarInt(_data_f9);
  if (f10() == nullptr) return false;
  _wb.writeVarInt(_data_f10);
  if (f11() == nullptr) return false;
  _wb.writeVarInt(_data_f11);
  if (f12() == nullptr) return false;
  _wb.writeVarInt(_data_f12);
  if (f13() == nullptr) return false;
  _wb.writeVarInt(_data_f13);
  if (f14() == nullptr) return false;
  _wb.writeVarInt(_data_f14);
  if (f15() == nullptr) return false;
  _wb.writeVarInt(_data_f15);
  if (f16() == nullptr) return false;
  _wb.writeVarInt(_data_f16);
  if (f17() == nullptr) return false;
  _wb.writeVarInt(_data_f17);
  if (f18() == nullptr) return false;
  _wb.writeVarInt(_data_f18);
  if (f19() == nullptr) return false;
  _wb.writeVarInt(_data_f19);
  if (f20() == nullptr) return false;
  _wb.writeVarInt(_data_f20);
  if (f21() == nullptr) return false;
  _wb.writeVarInt(_data_f21);
  if (f22() == nullptr) return false;
  _wb.writeVarInt(_data_f22);
  if (f23() == nullptr) return false;
  _wb.writeVarInt(_data_f23);
  if (f24() == nullptr) return false;
  _wb.writeVarInt(_data_f24);
  if (f25() == nullptr) return false;
  _wb.writeVarInt(_data_f25);
  if (f26() == nullptr) return false;
  _wb.writeVarInt(_data_f26);
  if (f27() == nullptr) return false;
  _wb.writeVarInt(_data_f27);
  if (f28() == nullptr) return false;
  _wb.writeVarInt(_data_f28);
  if (f29() == nullptr) return false;
  _wb.writeVarInt(_data_f29);
  if (f30() == nullptr) return false;
  _wb.writeVarInt(_data_f30);
  if (f31() == nullptr) return false;
  _wb.writeVarInt(_data_f31);
  if (f32() == nullptr) return false;
  _wb.writeVarInt(_data_f32);
  if (f33() == nullptr) return false;
  _wb.writeVarInt(_data_f33);
  if (f34() == nullptr) return false;
  _wb.writeVarInt(_data_f34);
  if (f35() == nullptr) return false;
  _wb.writeVarInt(_data_f35);
  if (f36() == nullptr) return false;
  _wb.writeVarInt(_data_f36);
  if (f37() == nullptr) return false;
  _wb.writeVarInt(_data_f37);
  if (f38() == nullptr) return false;
  _wb.writeVarInt(_data_f38);
  if (f39() == nullptr) return false;
  _wb.writeVarInt(_data_f39);
  if (f40() == nullptr) return false;
  _wb.writeVarInt(_data_f40);
  if (f41() == nullptr) return false;
  _wb.writeVarInt(_data_f41);
  if (f42() == nullptr) return false;
  _wb.writeVarInt(_data_f42);
  if (f43() == nullptr) return false;
  _wb.writeVarInt(_data_f43);
  if (f44() == nullptr) return false;
  _wb.writeVarInt(_data_f44);
  if (f45() == nullptr) return false;
  _wb.writeVarInt(_data_f45);
  if (f46() == nullptr) return false;
  _wb.writeVarInt(_data_f46);
  if (f47() == nullptr) return false;
  _wb.writeVarInt(_data_f47);
  if (f48() == nullptr) return false;
  _wb.writeVarInt(_data_f48);
  if (f49() == nullptr) return false;
  _wb.writeVarInt(_data_f49);
  if (f50() == nullptr) return false;
  _wb.writeVarInt(_data_f50);
  if (f51() == nullptr) return false;
  _wb.writeVarInt(_data_f51);
  if (f52() == nullptr) return false;
  _wb.writeVarInt(_data_f52);
  if (f53() == nullptr) return false;
  _wb.writeVarInt(_data_f53);
  if (f54() == nullptr) return false;
  _wb.writeVarInt(_data_f54);
  if (f55() == nullptr) return false;
  _wb.writeVarInt(_data_f55);
  if (f56() == nullptr) return false;
  _wb.writeVarInt(_data_f56);
  if (f57() == nullptr) return false;
  _wb.writeVarInt(_data_f57);
  if (f58() == nullptr) return false;
  _wb.writeVarInt(_data_f58);
  if (f59() == nullptr) return false;
  _wb.writeVarInt(_data_f59);
  if (f60() == nullptr) return false;
  _wb.writeVarInt(_data_f60);
  if (f61() == nullptr) return false;
  _wb.writeVarInt(_data_f61);
  if (f62() == nullptr) return false;
  _wb.writeVarInt(_data_f62);
  if (f63() == nullptr) return false;
  _wb.writeVarInt(_data_f63);
  if (f64() == nullptr) return false;
  _wb.writeVarInt(_data_f64);
  if (f65() == nullptr) return false;
  _wb.writeVarInt(_data_f65);
  if (f66() == nullptr) return false;
  _wb.writeVarInt(_data_f66);
  if (f67() == nullptr) return false;
  _wb.writeVarInt(_data_f67);
  if (f68() == nullptr) return false;
  _wb.writeVarInt(_data_f68);
  if (f69() == nullptr) return false;
  _wb.writeVarInt(_data_f69);
  if (f70() == nullptr) return false;
  _wb.writeVarInt(_data_f70);
  if (f71() == nullptr) return false;
  _wb.writeVarInt(_data_f71);
  if (f72() == nullptr) return false;
  _wb.writeVarInt(_data_f72);
  if (f73() == nullptr) return false;
  _wb.writeVarInt(_data_f73);
  if (f74() == nullptr) return false;
  _wb.writeVarInt(_data_f74);
  if (f75() == nullptr) return false;
  _wb.writeVarInt(_data_f75);
  if (f76() == nullptr) return false;
  _wb.writeVarInt(_data_f76);
  if (f77() == nullptr) return false;
  _wb.writeVarInt(_data_f77);
  if (f78() == nullptr) return false;
  _wb.writeVarInt(_data_f78);
  if (f79() == nullptr) return false;
  _wb.writeVarInt(_data_f79);
  if (f80() == nullptr) return false;
  _wb.writeVarInt(_data_f80);
  if (f81() == nullptr) return false;
  _wb.writeVarInt(_data_f81);
  if (f82() == nullptr) return false;
  _wb.writeVarInt(_data_f82);
  if (f83() == nullptr) return false;
  _wb.writeVarInt(_data_f83);
  if (f84() == nullptr) return false;
  _wb.writeVarInt(_data_f84);
  if (f85() == nullptr) return false;
  _wb.writeVarInt(_data_f85);
  if (f86() == nullptr) return false;
  _wb.writeVarInt(_data_f86);
  if (f87() == nullptr) return false;
  _wb.writeVarInt(_data_f87);
  if (f88() == nullptr) return false;
  _wb.writeVarInt(_data_f88);
  if (f89() == nullptr) return false;
  _wb.writeVarInt(_data_f89);
  if (f90() == nullptr) return false;
  _wb.writeVarInt(_data_f90);
  if (f91() == nullptr) return false;
  _wb.writeVarInt(_data_f91);
  if (f92() == nullptr) return false;
  _wb.writeVarInt(_data_f92);
  if (f93() == nullptr) return false;
  _wb.writeVarInt(_data_f93);
  if (f94() == nullptr) return false;
  _wb.writeVarInt(_data_f94);
  if (f95() == nullptr) return false;
  _wb.writeVarInt(_data_f95);
  if (f96() == nullptr) return false;
  _wb.writeVarInt(_data_f96);
  if (f97() == nullptr) return false;
  _wb.writeVarInt(_data_f97);
  if (f98() == nullptr) return false;
  _wb.writeVarInt(_data_f98);
  if (f99() == nullptr) return false;
  _wb.writeVarInt(_data_f99);
  if (f100() == nullptr) return false;
  _wb.writeVarInt(_data_f100);
  if (f101() == nullptr) return false;
  _wb.writeVarInt(_data_f101);
  if (f102() == nullptr) return false;
  _wb.writeVarInt(_data_f102);
  if (f103() == nullptr) return false;
  _wb.writeVarInt(_data_f103);
  if (f104() == nullptr) return false;
  _wb.writeVarInt(_data_f104);
  if (f105() == nullptr) return false;
  _wb.writeVarInt(_data_f105);
  if (f106() == nullptr) return false;
  _wb.writeVarInt(_data_f106);
  if (f107() == nullptr) return false;
  _wb.writeVarInt(_data_f107);
  if (f108() == nullptr) return false;
  _wb.writeVarInt(_data_f108);
  if (f109() == nullptr) return false;
  _wb.writeVarInt(_data_f109);
  if (f110() == nullptr) return false;
  _wb.writeVarInt(_data_f110);
  if (f111() == nullptr) return false;
  _wb.writeVarInt(_data_f111);
  if (f112() == nullptr) return false;
  _wb.writeVarInt(_data_f112);
  if (f113() == nullptr) return false;
  _wb.writeVarInt(_data_f113);
  if (f114() == nullptr) return false;
  _wb.writeVarInt(_data_f114);
  if (f115() == nullptr) return false;
  _wb.writeVarInt(_data_f115);
  if (f116() == nullptr) return false;
  _wb.writeVarInt(_data_f116);
  if (f117() == nullptr) return false;
  _wb.writeVarInt(_data_f117);
  if (f118() == nullptr) return false;
  _wb.writeVarInt(_data_f118);
  if (f119() == nullptr) return false;
  _wb.writeVarInt(_data_f119);
  if (f120() == nullptr) return false;
  _wb.writeVarInt(_data_f120);
  if (f121() == nullptr) return false;
  _wb.writeVarInt(_data_f121);
  if (f122() == nullptr) return false;
  _wb.writeVarInt(_data_f122);
  if (f123() == nullptr) return false;
  _wb.writeVarInt(_data_f123);
  if (f124() == nullptr) return false;
  _wb.writeVarInt(_data_f124);
  if (f125() == nullptr) return false;
  _wb.writeVarInt(_data_f125);
  if (f126() == nullptr) return false;
  _wb.writeVarInt(_data_f126);
  if (f127() == nullptr) return false;
  _wb.writeVarInt(_data_f127);
  if (f128() == nullptr) return false;
  _wb.writeVarInt(_data_f128);
  if (f129() == nullptr) return false;
  _wb.writeVarInt(_data_f129);
  return true;
}

bool Struct::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarInt(_data_f0)) return false;
  set_f0(_data_f0);
  if (!_bb.readVarInt(_data_f1)) return false;
  set_f1(_data_f1);
  if (!_bb.readVarInt(_data_f2)) return false;
  set_f2(_data_f2);
  if (!_bb.readVarInt(_data_f3)) return false;
  set_f3(_data_f3);
  if (!_bb.readVarInt(_data_f4)) return false;
  set_f4(_data_f4);
  if (!_bb.readVarInt(_data_f5)) return false;
  set_f5(_data_f5);
  if (!_bb.readVarInt(_data_f6)) return false;
  set_f6(_data_f6);
  if (!_bb.readVarInt(_data_f7)) return false;
  set_f7(_data_f7);
  if (!_bb.readVarInt(_data_f8)) return false;
  set_f8(_data_f8);
  if (!_bb.readVarInt(_data_f9)) return false;
  set_f9(_data_f9);
  if (!_bb.readVarInt(_data_f10)) return false;
  set_f10(_data_f10);
  if (!_bb.readVarInt(_data_f11)) return false;
  set_f11(_data_f11);
  if (!_bb.readVarInt(_data_f12)) return false;
  set_f12(_data_f12);
  if (!_bb.readVarInt(_data_f13)) return false;
  set_f13(_data_f13);
  if (!_bb.readVarInt(_data_f14)) return false;
  set_f14(_data_f14);
  if (!_bb.readVarInt(_data_f15)) return false;
  set_f15(_data_f15);
  if (!_bb.readVarInt(_data_f16)) return false;
  set_f16(_data_f16);
  if (!_bb.readVarInt(_data_f17)) return false;
  set_f17(_data_f17);
  if (!_bb.readVarInt(_data_f18)) return false;
  set_f18(_data_f18);
  if (!_bb.readVarInt(_data_f19)) return false;
  set_f19(_data_f19);
  if (!_bb.readVarInt(_data_f20)) return false;
  set_f20(_data_f20);
  if (!_bb.readVarInt(_data_f21)) return false;
  set_f21(_data_f21);
  if (!_bb.readVarInt(_data_f22)) return false;
  set_f22(_data_f22);
  if (!_bb.readVarInt(_data_f23)) return false;
  set_f23(_data_f23);
  if (!_bb.readVarInt(_data_f24)) return false;
  set_f24(_data_f24);
  if (!_bb.readVarInt(_data_f25)) return false;
  set_f25(_data_f25);
  if (!_bb.readVarInt(_data_f26)) return false;
  set_f26(_data_f26);
  if (!_bb.readVarInt(_data_f27)) return false;
  set_f27(_data_f27);
  if (!_bb.readVarInt(_data_f28)) return false;
  set_f28(_data_f28);
  if (!_bb.readVarInt(_data_f29)) return false;
  set_f29(_data_f29);
  if (!_bb.readVarInt(_data_f30)) return false;
  set_f30(_data_f30);
  if (!_bb.readVarInt(_data_f31)) return false;
  set_f31(_data_f31);
  if (!_bb.readVarInt(_data_f32)) return false;
  set_f32(_data_f32);
  if (!_bb.readVarInt(_data_f33)) return false;
  set_f33(_data_f33);
  if (!_bb.readVarInt(_data_f34)) return false;
  set_f34(_data_f34);
  if (!_bb.readVarInt(_data_f35)) return false;
  set_f35(_data_f35);
  if (!_bb.readVarInt(_data_f36)) return false;
  set_f36(_data_f36);
  if (!_bb.readVarInt(_data_f37)) return false;
  set_f37(_data_f37);
  if (!_bb.readVarInt(_data_f38)) return false;
  set_f38(_data_f38);
  if (!_bb.readVarInt(_data_f39)) return false;
  set_f39(_data_f39);
  if (!_bb.readVarInt(_data_f40)) return false;
  set_f40(_data_f40);
  if (!_bb.readVarInt(_data_f41)) return false;
  set_f41(_data_f41);
  if (!_bb.readVarInt(_data_f42)) return false;
  set_f42(_data_f42);
  if (!_bb.readVarInt(_data_f43)) return false;
  set_f43(_data_f43);
  if (!_bb.readVarInt(_data_f44)) return false;
  set_f44(_data_f44);
  if (!_bb.readVarInt(_data_f45)) return false;
  set_f45(_data_f45);
  if (!_bb.readVarInt(_data_f46)) return false;
  set_f46(_data_f46);
  if (!_bb.readVarInt(_data_f47)) return false;
  set_f47(_data_f47);
  if (!_bb.readVarInt(_data_f48)) return false;
  set_f48(_data_f48);
  if (!_bb.readVarInt(_data_f49)) return false;
  set_f49(_data_f49);
  if (!_bb.readVarInt(_data_f50)) return false;
  set_f50(_data_f50);
  if (!_bb.readVarInt(_data_f51)) return false;
  set_f51(_data_f51);
  if (!_bb.readVarInt(_data_f52)) return false;
  set_f52(_data_f52);
  if (!_bb.readVarInt(_data_f53)) return false;
  set_f53(_data_f53);
  if (!_bb.readVarInt(_data_f54)) return false;
  set_f54(_data_f54);
  if (!_bb.readVarInt(_data_f55)) return false;
  set_f55(_data_f55);
  if (!_bb.readVarInt(_data_f56)) return false;
  set_f56(_data_f56);
  if (!_bb.readVarInt(_data_f57)) return false;
  set_f57(_data_f57);
  if (!_bb.readVarInt(_data_f58)) return false;
  set_f58(_data_f58);
  if (!_bb.readVarInt(_data_f59)) return false;
  set_f59(_data_f59);
  if (!_bb.readVarInt(_data_f60)) return false;
  set_f60(_data_f60);
  if (!_bb.readVarInt(_data_f61)) return false;
  set_f61(_data_f61);
  if (!_bb.readVarInt(_data_f62)) return false;
  set_f62(_data_f62);
  if (!_bb.readVarInt(_data_f63)) return false;
  set_f63(_data_f63);
  if (!_bb.readVarInt(_data_f64)) return false;
  set_f64(_data_f64);
  if (!_bb.readVarInt(_data_f65)) return false;
  set_f65(_data_f65);
  if (!_bb.readVarInt(_data_f66)) return false;
  set_f66(_data_f66);
  if (!_bb.readVarInt(_data_f67)) return false;
  set_f67(_data_f67);
  if (!_bb.readVarInt(_data_f68)) return false;
  set_f68(_data_f68);
  if (!_bb.readVarInt(_data_f69)) return false;
  set_f69(_data_f69);
  if (!_bb.readVarInt(_data_f70)) return false;
  set_f70(_data_f70);
  if (!_bb.readVarInt(_data_f71)) return false;
  set_f71(_data_f71);
  if (!_bb.readVarInt(_data_f72)) return false;
  set_f72(_data_f72);
  if (!_bb.readVarInt(_data_f73)) return false;
  set_f73(_data_f73);
  if (!_bb.readVarInt(_data_f74)) return false;
  set_f74(_data_f74);
  if (!_bb.readVarInt(_data_f75)) return false;
  set_f75(_data_f75);
  if (!_bb.readVarInt(_data_f76)) return false;
  set_f76(_data_f76);
  if (!_bb.readVarInt(_data_f77)) return false;
  set_f77(_data_f77);
  if (!_bb.readVarInt(_data_f78)) return false;
  set_f78(_data_f78);
  if (!_bb.readVarInt(_data_f79)) return false;
  set_f79(_data_f79);
  if (!_bb.readVarInt(_data_f80)) return false;
  set_f80(_data_f80);
  if (!_bb.readVarInt(_data_f81)) return false;
  set_f81(_data_f81);
  if (!_bb.readVarInt(_data_f82)) return false;
  set_f82(_data_f82);
  if (!_bb.readVarInt(_data_f83)) return false;
  set_f83(_data_f83);
  if (!_bb.readVarInt(_data_f84)) return false;
  set_f84(_data_f84);
  if (!_bb.readVarInt(_data_f85)) return false;
  set_f85(_data_f85);
  if (!_bb.readVarInt(_data_f86)) return false;
  set_f86(_data_f86);
  if (!_bb.readVarInt(_data_f87)) return false;
  set_f87(_data_f87);
  if (!_bb.readVarInt(_data_f88)) return false;
  set_f88(_data_f88);
  if (!_bb.readVarInt(_data_f89)) return false;
  set_f89(_data_f89);
  if (!_bb.readVarInt(_data_f90)) return false;
  set_f90(_data_f90);
  if (!_bb.readVarInt(_data_f91)) return false;
  set_f91(_data_f91);
  if (!_bb.readVarInt(_data_f92)) return false;
  set_f92(_data_f92);
  if (!_bb.readVarInt(_data_f93)) return false;
  set_f93(_data_f93);
  if (!_bb.readVarInt(_data_f94)) return false;
  set_f94(_data_f94);
  if (!_bb.readVarInt(_data_f95)) return false;
  set_f95(_data_f95);
  if (!_bb.readVarInt(_data_f96)) return false;
  set_f96(_data_f96);
  if (!_bb.readVarInt(_data_f97)) return false;
  set_f97(_data_f97);
  if (!_bb.readVarInt(_data_f98)) return false;
  set_f98(_data_f98);
  if (!_bb.readVarInt(_data_f99)) return false;
  set_f99(_data_f99);
  if (!_bb.readVarInt(_data_f100)) return false;
  set_f100(_data_f100);
  if (!_bb.readVarInt(_data_f101)) return false;
  set_f101(_data_f101);
  if (!_bb.readVarInt(_data_f102)) return false;
  set_f102(_data_f102);
  if (!_bb.readVarInt(_data_f103)) return false;
  set_f103(_data_f103);
  if (!_bb.readVarInt(_data_f104)) return false;
  set_f104(_data_f104);
  if (!_bb.readVarInt(_data_f105)) return false;
  set_f105(_data_f105);
  if (!_bb.readVarInt(_data_f106)) return false;
  set_f106(_data_f106);
  if (!_bb.readVarInt(_data_f107)) return false;
  set_f107(_data_f107);
  if (!_bb.readVarInt(_data_f108)) return false;
  set_f108(_data_f108);
  if (!_bb.readVarInt(_data_f109)) return false;
  set_f109(_data_f109);
  if (!_bb.readVarInt(_data_f110)) return false;
  set_f110(_data_f110);
  if (!_bb.readVarInt(_data_f111)) return false;
  set_f111(_data_f111);
  if (!_bb.readVarInt(_data_f112)) return false;
  set_f112(_data_f112);
  if (!_bb.readVarInt(_data_f113)) return false;
  set_f113(_data_f113);
  if (!_bb.readVarInt(_data_f114)) return false;
  set_f114(_data_f114);
  if (!_bb.readVarInt(_data_f115)) return false;
  set_f115(_data_f115);
  if (!_bb.readVarInt(_data_f116)) return false;
  set_f116(_data_f116);
  if (!_bb.readVarInt(_data_f117)) return false;
  set_f117(_data_f117);
  if (!_bb.readVarInt(_data_f118)) return false;
  set_f118(_data_f118);
  if (!_bb.readVarInt(_data_f119)) return false;
  set_f119(_data_f119);
  if (!_bb.readVarInt(_data_f120)) return false;
  set_f120(_data_f120);
  if (!_bb.readVarInt(_data_f121)) return false;
  set_f121(_data_f121);
  if (!_bb.readVarInt(_data_f122)) return false;
  set_f122(_data_f122);
  if (!_bb.readVarInt(_data_f123)) return false;
  set_f123(_data_f123);
  if (!_bb.readVarInt(_data_f124)) return false;
  set_f124(_data_f124);
  if (!_bb.readVarInt(_data_f125)) return false;
  set_f125(_data_f125);
  if (!_bb.readVarInt(_data_f126)) return false;
  set_f126(_data_f126);
  if (!_bb.readVarInt(_data_f127)) return false;
  set_f127(_data_f127);
  if (!_bb.readVarInt(_data_f128)) return false;
  set_f128(_data_f128);
  if (!_bb.readVarInt(_data_f129)) return false;
  set_f129(_data_f129);
  return true;
}

bool Message::encode(kiwi::WriteBuffer &_wb) const {
  if (f0() != nullptr) {
    _wb.writeVarUint(1);
    _wb.writeVarInt(_data_f0);
  }
  if (f1() != nullptr) {
    _wb.writeVarUint(2);
    _wb.writeVarInt(_data_f1);
  }
  if (f2() != nullptr) {
    _wb.writeVarUint(3);
    _wb.writeVarInt(_data_f2);
  }
  if (f3() != nullptr) {
    _wb.writeVarUint(4);
    _wb.writeVarInt(_data_f3);
  }
  if (f4() != nullptr) {
    _wb.writeVarUint(5);
    _wb.writeVarInt(_data_f4);
  }
  if (f5() != nullptr) {
    _wb.writeVarUint(6);
    _wb.writeVarInt(_data_f5);
  }
  if (f6() != nullptr) {
    _wb.writeVarUint(7);
    _wb.writeVarInt(_data_f6);
  }
  if (f7() != nullptr) {
    _wb.writeVarUint(8);
    _wb.writeVarInt(_data_f7);
  }
  if (f8() != nullptr) {
    _wb.writeVarUint(9);
    _wb.writeVarInt(_data_f8);
  }
  if (f9() != nullptr) {
    _wb.writeVarUint(10);
    _wb.writeVarInt(_data_f9);
  }
  if (f10() != nullptr) {
    _wb.writeVarUint(11);
    _wb.writeVarInt(_data_f10);
  }
  if (f11() != nullptr) {
    _wb.writeVarUint(12);
    _wb.writeVarInt(_data_f11);
  }
  if (f12() != nullptr) {
    _wb.writeVarUint(13);
    _wb.writeVarInt(_data_f12);
  }
  if (f13() != nullptr) {
    _wb.writeVarUint(14);
    _wb.writeVarInt(_data_f13);
  }
  if (f14() != nullptr) {
    _wb.writeVarUint(15);
    _wb.writeVarInt(_data_f14);
  }
  if (f15() != nullptr) {
    _wb.writeVarUint(16);
    _wb.writeVarInt(_data_f15);
  }
  if (f16() != nullptr) {
    _wb.writeVarUint(17);
    _wb.writeVarInt(_data_f16);
  }
  if (f17() != nullptr) {
    _wb.writeVarUint(18);
    _wb.writeVarInt(_data_f17);
  }
  if (f18() != nullptr) {
    _wb.writeVarUint(19);
    _wb.writeVarInt(_data_f18);
  }
  if (f19() != nullptr) {
    _wb.writeVarUint(20);
    _wb.writeVarInt(_data_f19);
  }
  if (f20() != nullptr) {
    _wb.writeVarUint(21);
    _wb.writeVarInt(_data_f20);
  }
  if (f21() != nullptr) {
    _wb.writeVarUint(22);
    _wb.writeVarInt(_data_f21);
  }
  if (f22() != nullptr) {
    _wb.writeVarUint(23);
    _wb.writeVarInt(_data_f22);
  }
  if (f23() != nullptr) {
    _wb.writeVarUint(24);
    _wb.writeVarInt(_data_f23);
  }
  if (f24() != nullptr) {
    _wb.writeVarUint(25);
    _wb.writeVarInt(_data_f24);
  }
  if (f25() != nullptr) {
    _wb.writeVarUint(26);
    _wb.writeVarInt(_data_f25);
  }
  if (f26() != nullptr) {
    _wb.writeVarUint(27);
    _wb.writeVarInt(_data_f26);
  }
  if (f27() != nullptr) {
    _wb.writeVarUint(28);
    _wb.writeVarInt(_data_f27);
  }
  if (f28() != nullptr) {
    _wb.writeVarUint(29);
    _wb.writeVarInt(_data_f28);
  }
  if (f29() != nullptr) {
    _wb.writeVarUint(30);
    _wb.writeVarInt(_data_f29);
  }
  if (f30() != nullptr) {
    _wb.writeVarUint(31);
    _wb.writeVarInt(_data_f30);
  }
  if (f31() != nullptr) {
    _wb.writeVarUint(32);
    _wb.writeVarInt(_data_f31);
  }
  if (f32() != nullptr) {
    _wb.writeVarUint(33);
    _wb.writeVarInt(_data_f32);
  }
  if (f33() != nullptr) {
    _wb.writeVarUint(34);
    _wb.writeVarInt(_data_f33);
  }
  if (f34() != nullptr) {
    _wb.writeVarUint(35);
    _wb.writeVarInt(_data_f34);
  }
  if (f35() != nullptr) {
    _wb.writeVarUint(36);
    _wb.writeVarInt(_data_f35);
  }
  if (f36() != nullptr) {
    _wb.writeVarUint(37);
    _wb.writeVarInt(_data_f36);
  }
  if (f37() != nullptr) {
    _wb.writeVarUint(38);
    _wb.writeVarInt(_data_f37);
  }
  if (f38() != nullptr) {
    _wb.writeVarUint(39);
    _wb.writeVarInt(_data_f38);
  }
  if (f39() != nullptr) {
    _wb.writeVarUint(40);
    _wb.writeVarInt(_data_f39);
  }
  if (f40() != nullptr) {
    _wb.writeVarUint(41);
    _wb.writeVarInt(_data_f40);
  }
  if (f41() != nullptr) {
    _wb.writeVarUint(42);
    _wb.writeVarInt(_data_f41);
  }
  if (f42() != nullptr) {
    _wb.writeVarUint(43);
    _wb.writeVarInt(_data_f42);
  }
  if (f43() != nullptr) {
    _wb.writeVarUint(44);
    _wb.writeVarInt(_data_f43);
  }
  if (f44() != nullptr) {
    _wb.writeVarUint(45);
    _wb.writeVarInt(_data_f44);
  }
  if (f45() != nullptr) {
    _wb.writeVarUint(46);
    _wb.writeVarInt(_data_f45);
  }
  if (f46() != nullptr) {
    _wb.writeVarUint(47);
    _wb.writeVarInt(_data_f46);
  }
  if (f47() != nullptr) {
    _wb.writeVarUint(48);
    _wb.writeVarInt(_data_f47);
  }
  if (f48() != nullptr) {
    _wb.writeVarUint(49);
    _wb.writeVarInt(_data_f48);
  }
  if (f49() != nullptr) {
    _wb.writeVarUint(50);
    _wb.writeVarInt(_data_f49);
  }
  if (f50() != nullptr) {
    _wb.writeVarUint(51);
    _wb.writeVarInt(_data_f50);
  }
  if (f51() != nullptr) {
    _wb.writeVarUint(52);
    _wb.writeVarInt(_data_f51);
  }
  if (f52() != nullptr) {
    _wb.writeVarUint(53);
    _wb.writeVarInt(_data_f52);
  }
  if (f53() != nullptr) {
    _wb.writeVarUint(54);
    _wb.writeVarInt(_data_f53);
  }
  if (f54() != nullptr) {
    _wb.writeVarUint(55);
    _wb.writeVarInt(_data_f54);
  }
  if (f55() != nullptr) {
    _wb.writeVarUint(56);
    _wb.writeVarInt(_data_f55);
  }
  if (f56() != nullptr) {
    _wb.writeVarUint(57);
    _wb.writeVarInt(_data_f56);
  }
  if (f57() != nullptr) {
    _wb.writeVarUint(58);
    _wb.writeVarInt(_data_f57);
  }
  if (f58() != nullptr) {
    _wb.writeVarUint(59);
    _wb.writeVarInt(_data_f58);
  }
  if (f59() != nullptr) {
    _wb.writeVarUint(60);
    _wb.writeVarInt(_data_f59);
  }
  if (f60() != nullptr) {
    _wb.writeVarUint(61);
    _wb.writeVarInt(_data_f60);
  }
  if (f61() != nullptr) {
    _wb.writeVarUint(62);
    _wb.writeVarInt(_data_f61);
  }
  if (f62() != nullptr) {
    _wb.writeVarUint(63);
    _wb.writeVarInt(_data_f62);
  }
  if (f63() != nullptr) {
    _wb.writeVarUint(64);
    _wb.writeVarInt(_data_f63);
  }
  if (f64() != nullptr) {
    _wb.writeVarUint(65);
    _wb.writeVarInt(_data_f64);
  }
  if (f65() != nullptr) {
    _wb.writeVarUint(66);
    _wb.writeVarInt(_data_f65);
  }
  if (f66() != nullptr) {
    _wb.writeVarUint(67);
    _wb.writeVarInt(_data_f66);
  }
  if (f67() != nullptr) {
    _wb.writeVarUint(68);
    _wb.writeVarInt(_data_f67);
  }
  if (f68() != nullptr) {
    _wb.writeVarUint(69);
    _wb.writeVarInt(_data_f68);
  }
  if (f69() != nullptr) {
    _wb.writeVarUint(70);
    _wb.writeVarInt(_data_f69);
  }
  if (f70() != nullptr) {
    _wb.writeVarUint(71);
    _wb.writeVarInt(_data_f70);
  }
  if (f71() != nullptr) {
    _wb.writeVarUint(72);
    _wb.writeVarInt(_data_f71);
  }
  if (f72() != nullptr) {
    _wb.writeVarUint(73);
    _wb.writeVarInt(_data_f72);
  }
  if (f73() != nullptr) {
    _wb.writeVarUint(74);
    _wb.writeVarInt(_data_f73);
  }
  if (f74() != nullptr) {
    _wb.writeVarUint(75);
    _wb.writeVarInt(_data_f74);
  }
  if (f75() != nullptr) {
    _wb.writeVarUint(76);
    _wb.writeVarInt(_data_f75);
  }
  if (f76() != nullptr) {
    _wb.writeVarUint(77);
    _wb.writeVarInt(_data_f76);
  }
  if (f77() != nullptr) {
    _wb.writeVarUint(78);
    _wb.writeVarInt(_data_f77);
  }
  if (f78() != nullptr) {
    _wb.writeVarUint(79);
    _wb.writeVarInt(_data_f78);
  }
  if (f79() != nullptr) {
    _wb.writeVarUint(80);
    _wb.writeVarInt(_data_f79);
  }
  if (f80() != nullptr) {
    _wb.writeVarUint(81);
    _wb.writeVarInt(_data_f80);
  }
  if (f81() != nullptr) {
    _wb.writeVarUint(82);
    _wb.writeVarInt(_data_f81);
  }
  if (f82() != nullptr) {
    _wb.writeVarUint(83);
    _wb.writeVarInt(_data_f82);
  }
  if (f83() != nullptr) {
    _wb.writeVarUint(84);
    _wb.writeVarInt(_data_f83);
  }
  if (f84() != nullptr) {
    _wb.writeVarUint(85);
    _wb.writeVarInt(_data_f84);
  }
  if (f85() != nullptr) {
    _wb.writeVarUint(86);
    _wb.writeVarInt(_data_f85);
  }
  if (f86() != nullptr) {
    _wb.writeVarUint(87);
    _wb.writeVarInt(_data_f86);
  }
  if (f87() != nullptr) {
    _wb.writeVarUint(88);
    _wb.writeVarInt(_data_f87);
  }
  if (f88() != nullptr) {
    _wb.writeVarUint(89);
    _wb.writeVarInt(_data_f88);
  }
  if (f89() != nullptr) {
    _wb.writeVarUint(90);
    _wb.writeVarInt(_data_f89);
  }
  if (f90() != nullptr) {
    _wb.writeVarUint(91);
    _wb.writeVarInt(_data_f90);
  }
  if (f91() != nullptr) {
    _wb.writeVarUint(92);
    _wb.writeVarInt(_data_f91);
  }
  if (f92() != nullptr) {
    _wb.writeVarUint(93);
    _wb.writeVarInt(_data_f92);
  }
  if (f93() != nullptr) {
    _wb.writeVarUint(94);
    _wb.writeVarInt(_data_f93);
  }
  if (f94() != nullptr) {
    _wb.writeVarUint(95);
    _wb.writeVarInt(_data_f94);
  }
  if (f95() != nullptr) {
    _wb.writeVarUint(96);
    _wb.writeVarInt(_data_f95);
  }
  if (f96() != nullptr) {
    _wb.writeVarUint(97);
    _wb.writeVarInt(_data_f96);
  }
  if (f97() != nullptr) {
    _wb.writeVarUint(98);
    _wb.writeVarInt(_data_f97);
  }
  if (f98() != nullptr) {
    _wb.writeVarUint(99);
    _wb.writeVarInt(_data_f98);
  }
  if (f99() != nullptr) {
    _wb.writeVarUint(100);
    _wb.writeVarInt(_data_f99);
  }
  if (f100() != nullptr) {
    _wb.writeVarUint(101);
    _wb.writeVarInt(_data_f100);
  }
  if (f101() != nullptr) {
    _wb.writeVarUint(102);
    _wb.writeVarInt(_data_f101);
  }
  if (f102() != nullptr) {
    _wb.writeVarUint(103);
    _wb.writeVarInt(_data_f102);
  }
  if (f103() != nullptr) {
    _wb.writeVarUint(104);
    _wb.writeVarInt(_data_f103);
  }
  if (f104() != nullptr) {
    _wb.writeVarUint(105);
    _wb.writeVarInt(_data_f104);
  }
  if (f105() != nullptr) {
    _wb.writeVarUint(106);
    _wb.writeVarInt(_data_f105);
  }
  if (f106() != nullptr) {
    _wb.writeVarUint(107);
    _wb.writeVarInt(_data_f106);
  }
  if (f107() != nullptr) {
    _wb.writeVarUint(108);
    _wb.writeVarInt(_data_f107);
  }
  if (f108() != nullptr) {
    _wb.writeVarUint(109);
    _wb.writeVarInt(_data_f108);
  }
  if (f109() != nullptr) {
    _wb.writeVarUint(110);
    _wb.writeVarInt(_data_f109);
  }
  if (f110() != nullptr) {
    _wb.writeVarUint(111);
    _wb.writeVarInt(_data_f110);
  }
  if (f111() != nullptr) {
    _wb.writeVarUint(112);
    _wb.writeVarInt(_data_f111);
  }
  if (f112() != nullptr) {
    _wb.writeVarUint(113);
    _wb.writeVarInt(_data_f112);
  }
  if (f113() != nullptr) {
    _wb.writeVarUint(114);
    _wb.writeVarInt(_data_f113);
  }
  if (f114() != nullptr) {
    _wb.writeVarUint(115);
    _wb.writeVarInt(_data_f114);
  }
  if (f115() != nullptr) {
    _wb.writeVarUint(116);
    _wb.writeVarInt(_data_f115);
  }
  if (f116() != nullptr) {
    _wb.writeVarUint(117);
    _wb.writeVarInt(_data_f116);
  }
  if (f117() != nullptr) {
    _wb.writeVarUint(118);
    _wb.writeVarInt(_data_f117);
  }
  if (f118() != nullptr) {
    _wb.writeVarUint(119);
    _wb.writeVarInt(_data_f118);
  }
  if (f119() != nullptr) {
    _wb.writeVarUint(120);
    _wb.writeVarInt(_data_f119);
  }
  if (f120() != nullptr) {
    _wb.writeVarUint(121);
    _wb.writeVarInt(_data_f120);
  }
  if (f121() != nullptr) {
    _wb.writeVarUint(122);
    _wb.writeVarInt(_data_f121);
  }
  if (f122() != nullptr) {
    _wb.writeVarUint(123);
    _wb.writeVarInt(_data_f122);
  }
  if (f123() != nullptr) {
    _wb.writeVarUint(124);
    _wb.writeVarInt(_data_f123);
  }
  if (f124() != nullptr) {
    _wb.writeVarUint(125);
    _wb.writeVarInt(_data_f124);
  }
  if (f125() != nullptr) {
    _wb.writeVarUint(126);
    _wb.writeVarInt(_data_f125);
  }
  if (f126() != nullptr) {
    _wb.writeVarUint(127);
    _wb.writeVarInt(_data_f126);
  }
  if (f127() != nullptr) {
    _wb.writeVarUint(128);
    _wb.writeVarInt(_data_f127);
  }
  if (f128() != nullptr) {
    _wb.writeVarUint(129);
    _wb.writeVarInt(_data_f128);
  }
  if (f129() != nullptr) {
    _wb.writeVarUint(130);
    _wb.writeVarInt(_data_f129);
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
        if (!_bb.readVarInt(_data_f0)) return false;
        set_f0(_data_f0);
        break;
      }
      case 2: {
        if (!_bb.readVarInt(_data_f1)) return false;
        set_f1(_data_f1);
        break;
      }
      case 3: {
        if (!_bb.readVarInt(_data_f2)) return false;
        set_f2(_data_f2);
        break;
      }
      case 4: {
        if (!_bb.readVarInt(_data_f3)) return false;
        set_f3(_data_f3);
        break;
      }
      case 5: {
        if (!_bb.readVarInt(_data_f4)) return false;
        set_f4(_data_f4);
        break;
      }
      case 6: {
        if (!_bb.readVarInt(_data_f5)) return false;
        set_f5(_data_f5);
        break;
      }
      case 7: {
        if (!_bb.readVarInt(_data_f6)) return false;
        set_f6(_data_f6);
        break;
      }
      case 8: {
        if (!_bb.readVarInt(_data_f7)) return false;
        set_f7(_data_f7);
        break;
      }
      case 9: {
        if (!_bb.readVarInt(_data_f8)) return false;
        set_f8(_data_f8);
        break;
      }
      case 10: {
        if (!_bb.readVarInt(_data_f9)) return false;
        set_f9(_data_f9);
        break;
      }
      case 11: {
        if (!_bb.readVarInt(_data_f10)) return false;
        set_f10(_data_f10);
        break;
      }
      case 12: {
        if (!_bb.readVarInt(_data_f11)) return false;
        set_f11(_data_f11);
        break;
      }
      case 13: {
        if (!_bb.readVarInt(_data_f12)) return false;
        set_f12(_data_f12);
        break;
      }
      case 14: {
        if (!_bb.readVarInt(_data_f13)) return false;
        set_f13(_data_f13);
        break;
      }
      case 15: {
        if (!_bb.readVarInt(_data_f14)) return false;
        set_f14(_data_f14);
        break;
      }
      case 16: {
        if (!_bb.readVarInt(_data_f15)) return false;
        set_f15(_data_f15);
        break;
      }
      case 17: {
        if (!_bb.readVarInt(_data_f16)) return false;
        set_f16(_data_f16);
        break;
      }
      case 18: {
        if (!_bb.readVarInt(_data_f17)) return false;
        set_f17(_data_f17);
        break;
      }
      case 19: {
        if (!_bb.readVarInt(_data_f18)) return false;
        set_f18(_data_f18);
        break;
      }
      case 20: {
        if (!_bb.readVarInt(_data_f19)) return false;
        set_f19(_data_f19);
        break;
      }
      case 21: {
        if (!_bb.readVarInt(_data_f20)) return false;
        set_f20(_data_f20);
        break;
      }
      case 22: {
        if (!_bb.readVarInt(_data_f21)) return false;
        set_f21(_data_f21);
        break;
      }
      case 23: {
        if (!_bb.readVarInt(_data_f22)) return false;
        set_f22(_data_f22);
        break;
      }
      case 24: {
        if (!_bb.readVarInt(_data_f23)) return false;
        set_f23(_data_f23);
        break;
      }
      case 25: {
        if (!_bb.readVarInt(_data_f24)) return false;
        set_f24(_data_f24);
        break;
      }
      case 26: {
        if (!_bb.readVarInt(_data_f25)) return false;
        set_f25(_data_f25);
        break;
      }
      case 27: {
        if (!_bb.readVarInt(_data_f26)) return false;
        set_f26(_data_f26);
        break;
      }
      case 28: {
        if (!_bb.readVarInt(_data_f27)) return false;
        set_f27(_data_f27);
        break;
      }
      case 29: {
        if (!_bb.readVarInt(_data_f28)) return false;
        set_f28(_data_f28);
        break;
      }
      case 30: {
        if (!_bb.readVarInt(_data_f29)) return false;
        set_f29(_data_f29);
        break;
      }
      case 31: {
        if (!_bb.readVarInt(_data_f30)) return false;
        set_f30(_data_f30);
        break;
      }
      case 32: {
        if (!_bb.readVarInt(_data_f31)) return false;
        set_f31(_data_f31);
        break;
      }
      case 33: {
        if (!_bb.readVarInt(_data_f32)) return false;
        set_f32(_data_f32);
        break;
      }
      case 34: {
        if (!_bb.readVarInt(_data_f33)) return false;
        set_f33(_data_f33);
        break;
      }
      case 35: {
        if (!_bb.readVarInt(_data_f34)) return false;
        set_f34(_data_f34);
        break;
      }
      case 36: {
        if (!_bb.readVarInt(_data_f35)) return false;
        set_f35(_data_f35);
        break;
      }
      case 37: {
        if (!_bb.readVarInt(_data_f36)) return false;
        set_f36(_data_f36);
        break;
      }
      case 38: {
        if (!_bb.readVarInt(_data_f37)) return false;
        set_f37(_data_f37);
        break;
      }
      case 39: {
        if (!_bb.readVarInt(_data_f38)) return false;
        set_f38(_data_f38);
        break;
      }
      case 40: {
        if (!_bb.readVarInt(_data_f39)) return false;
        set_f39(_data_f39);
        break;
      }
      case 41: {
        if (!_bb.readVarInt(_data_f40)) return false;
        set_f40(_data_f40);
        break;
      }
      case 42: {
        if (!_bb.readVarInt(_data_f41)) return false;
        set_f41(_data_f41);
        break;
      }
      case 43: {
        if (!_bb.readVarInt(_data_f42)) return false;
        set_f42(_data_f42);
        break;
      }
      case 44: {
        if (!_bb.readVarInt(_data_f43)) return false;
        set_f43(_data_f43);
        break;
      }
      case 45: {
        if (!_bb.readVarInt(_data_f44)) return false;
        set_f44(_data_f44);
        break;
      }
      case 46: {
        if (!_bb.readVarInt(_data_f45)) return false;
        set_f45(_data_f45);
        break;
      }
      case 47: {
        if (!_bb.readVarInt(_data_f46)) return false;
        set_f46(_data_f46);
        break;
      }
      case 48: {
        if (!_bb.readVarInt(_data_f47)) return false;
        set_f47(_data_f47);
        break;
      }
      case 49: {
        if (!_bb.readVarInt(_data_f48)) return false;
        set_f48(_data_f48);
        break;
      }
      case 50: {
        if (!_bb.readVarInt(_data_f49)) return false;
        set_f49(_data_f49);
        break;
      }
      case 51: {
        if (!_bb.readVarInt(_data_f50)) return false;
        set_f50(_data_f50);
        break;
      }
      case 52: {
        if (!_bb.readVarInt(_data_f51)) return false;
        set_f51(_data_f51);
        break;
      }
      case 53: {
        if (!_bb.readVarInt(_data_f52)) return false;
        set_f52(_data_f52);
        break;
      }
      case 54: {
        if (!_bb.readVarInt(_data_f53)) return false;
        set_f53(_data_f53);
        break;
      }
      case 55: {
        if (!_bb.readVarInt(_data_f54)) return false;
        set_f54(_data_f54);
        break;
      }
      case 56: {
        if (!_bb.readVarInt(_data_f55)) return false;
        set_f55(_data_f55);
        break;
      }
      case 57: {
        if (!_bb.readVarInt(_data_f56)) return false;
        set_f56(_data_f56);
        break;
      }
      case 58: {
        if (!_bb.readVarInt(_data_f57)) return false;
        set_f57(_data_f57);
        break;
      }
      case 59: {
        if (!_bb.readVarInt(_data_f58)) return false;
        set_f58(_data_f58);
        break;
      }
      case 60: {
        if (!_bb.readVarInt(_data_f59)) return false;
        set_f59(_data_f59);
        break;
      }
      case 61: {
        if (!_bb.readVarInt(_data_f60)) return false;
        set_f60(_data_f60);
        break;
      }
      case 62: {
        if (!_bb.readVarInt(_data_f61)) return false;
        set_f61(_data_f61);
        break;
      }
      case 63: {
        if (!_bb.readVarInt(_data_f62)) return false;
        set_f62(_data_f62);
        break;
      }
      case 64: {
        if (!_bb.readVarInt(_data_f63)) return false;
        set_f63(_data_f63);
        break;
      }
      case 65: {
        if (!_bb.readVarInt(_data_f64)) return false;
        set_f64(_data_f64);
        break;
      }
      case 66: {
        if (!_bb.readVarInt(_data_f65)) return false;
        set_f65(_data_f65);
        break;
      }
      case 67: {
        if (!_bb.readVarInt(_data_f66)) return false;
        set_f66(_data_f66);
        break;
      }
      case 68: {
        if (!_bb.readVarInt(_data_f67)) return false;
        set_f67(_data_f67);
        break;
      }
      case 69: {
        if (!_bb.readVarInt(_data_f68)) return false;
        set_f68(_data_f68);
        break;
      }
      case 70: {
        if (!_bb.readVarInt(_data_f69)) return false;
        set_f69(_data_f69);
        break;
      }
      case 71: {
        if (!_bb.readVarInt(_data_f70)) return false;
        set_f70(_data_f70);
        break;
      }
      case 72: {
        if (!_bb.readVarInt(_data_f71)) return false;
        set_f71(_data_f71);
        break;
      }
      case 73: {
        if (!_bb.readVarInt(_data_f72)) return false;
        set_f72(_data_f72);
        break;
      }
      case 74: {
        if (!_bb.readVarInt(_data_f73)) return false;
        set_f73(_data_f73);
        break;
      }
      case 75: {
        if (!_bb.readVarInt(_data_f74)) return false;
        set_f74(_data_f74);
        break;
      }
      case 76: {
        if (!_bb.readVarInt(_data_f75)) return false;
        set_f75(_data_f75);
        break;
      }
      case 77: {
        if (!_bb.readVarInt(_data_f76)) return false;
        set_f76(_data_f76);
        break;
      }
      case 78: {
        if (!_bb.readVarInt(_data_f77)) return false;
        set_f77(_data_f77);
        break;
      }
      case 79: {
        if (!_bb.readVarInt(_data_f78)) return false;
        set_f78(_data_f78);
        break;
      }
      case 80: {
        if (!_bb.readVarInt(_data_f79)) return false;
        set_f79(_data_f79);
        break;
      }
      case 81: {
        if (!_bb.readVarInt(_data_f80)) return false;
        set_f80(_data_f80);
        break;
      }
      case 82: {
        if (!_bb.readVarInt(_data_f81)) return false;
        set_f81(_data_f81);
        break;
      }
      case 83: {
        if (!_bb.readVarInt(_data_f82)) return false;
        set_f82(_data_f82);
        break;
      }
      case 84: {
        if (!_bb.readVarInt(_data_f83)) return false;
        set_f83(_data_f83);
        break;
      }
      case 85: {
        if (!_bb.readVarInt(_data_f84)) return false;
        set_f84(_data_f84);
        break;
      }
      case 86: {
        if (!_bb.readVarInt(_data_f85)) return false;
        set_f85(_data_f85);
        break;
      }
      case 87: {
        if (!_bb.readVarInt(_data_f86)) return false;
        set_f86(_data_f86);
        break;
      }
      case 88: {
        if (!_bb.readVarInt(_data_f87)) return false;
        set_f87(_data_f87);
        break;
      }
      case 89: {
        if (!_bb.readVarInt(_data_f88)) return false;
        set_f88(_data_f88);
        break;
      }
      case 90: {
        if (!_bb.readVarInt(_data_f89)) return false;
        set_f89(_data_f89);
        break;
      }
      case 91: {
        if (!_bb.readVarInt(_data_f90)) return false;
        set_f90(_data_f90);
        break;
      }
      case 92: {
        if (!_bb.readVarInt(_data_f91)) return false;
        set_f91(_data_f91);
        break;
      }
      case 93: {
        if (!_bb.readVarInt(_data_f92)) return false;
        set_f92(_data_f92);
        break;
      }
      case 94: {
        if (!_bb.readVarInt(_data_f93)) return false;
        set_f93(_data_f93);
        break;
      }
      case 95: {
        if (!_bb.readVarInt(_data_f94)) return false;
        set_f94(_data_f94);
        break;
      }
      case 96: {
        if (!_bb.readVarInt(_data_f95)) return false;
        set_f95(_data_f95);
        break;
      }
      case 97: {
        if (!_bb.readVarInt(_data_f96)) return false;
        set_f96(_data_f96);
        break;
      }
      case 98: {
        if (!_bb.readVarInt(_data_f97)) return false;
        set_f97(_data_f97);
        break;
      }
      case 99: {
        if (!_bb.readVarInt(_data_f98)) return false;
        set_f98(_data_f98);
        break;
      }
      case 100: {
        if (!_bb.readVarInt(_data_f99)) return false;
        set_f99(_data_f99);
        break;
      }
      case 101: {
        if (!_bb.readVarInt(_data_f100)) return false;
        set_f100(_data_f100);
        break;
      }
      case 102: {
        if (!_bb.readVarInt(_data_f101)) return false;
        set_f101(_data_f101);
        break;
      }
      case 103: {
        if (!_bb.readVarInt(_data_f102)) return false;
        set_f102(_data_f102);
        break;
      }
      case 104: {
        if (!_bb.readVarInt(_data_f103)) return false;
        set_f103(_data_f103);
        break;
      }
      case 105: {
        if (!_bb.readVarInt(_data_f104)) return false;
        set_f104(_data_f104);
        break;
      }
      case 106: {
        if (!_bb.readVarInt(_data_f105)) return false;
        set_f105(_data_f105);
        break;
      }
      case 107: {
        if (!_bb.readVarInt(_data_f106)) return false;
        set_f106(_data_f106);
        break;
      }
      case 108: {
        if (!_bb.readVarInt(_data_f107)) return false;
        set_f107(_data_f107);
        break;
      }
      case 109: {
        if (!_bb.readVarInt(_data_f108)) return false;
        set_f108(_data_f108);
        break;
      }
      case 110: {
        if (!_bb.readVarInt(_data_f109)) return false;
        set_f109(_data_f109);
        break;
      }
      case 111: {
        if (!_bb.readVarInt(_data_f110)) return false;
        set_f110(_data_f110);
        break;
      }
      case 112: {
        if (!_bb.readVarInt(_data_f111)) return false;
        set_f111(_data_f111);
        break;
      }
      case 113: {
        if (!_bb.readVarInt(_data_f112)) return false;
        set_f112(_data_f112);
        break;
      }
      case 114: {
        if (!_bb.readVarInt(_data_f113)) return false;
        set_f113(_data_f113);
        break;
      }
      case 115: {
        if (!_bb.readVarInt(_data_f114)) return false;
        set_f114(_data_f114);
        break;
      }
      case 116: {
        if (!_bb.readVarInt(_data_f115)) return false;
        set_f115(_data_f115);
        break;
      }
      case 117: {
        if (!_bb.readVarInt(_data_f116)) return false;
        set_f116(_data_f116);
        break;
      }
      case 118: {
        if (!_bb.readVarInt(_data_f117)) return false;
        set_f117(_data_f117);
        break;
      }
      case 119: {
        if (!_bb.readVarInt(_data_f118)) return false;
        set_f118(_data_f118);
        break;
      }
      case 120: {
        if (!_bb.readVarInt(_data_f119)) return false;
        set_f119(_data_f119);
        break;
      }
      case 121: {
        if (!_bb.readVarInt(_data_f120)) return false;
        set_f120(_data_f120);
        break;
      }
      case 122: {
        if (!_bb.readVarInt(_data_f121)) return false;
        set_f121(_data_f121);
        break;
      }
      case 123: {
        if (!_bb.readVarInt(_data_f122)) return false;
        set_f122(_data_f122);
        break;
      }
      case 124: {
        if (!_bb.readVarInt(_data_f123)) return false;
        set_f123(_data_f123);
        break;
      }
      case 125: {
        if (!_bb.readVarInt(_data_f124)) return false;
        set_f124(_data_f124);
        break;
      }
      case 126: {
        if (!_bb.readVarInt(_data_f125)) return false;
        set_f125(_data_f125);
        break;
      }
      case 127: {
        if (!_bb.readVarInt(_data_f126)) return false;
        set_f126(_data_f126);
        break;
      }
      case 128: {
        if (!_bb.readVarInt(_data_f127)) return false;
        set_f127(_data_f127);
        break;
      }
      case 129: {
        if (!_bb.readVarInt(_data_f128)) return false;
        set_f128(_data_f128);
        break;
      }
      case 130: {
        if (!_bb.readVarInt(_data_f129)) return false;
        set_f129(_data_f129);
        break;
      }
      default: {
        if (!_schema || !_schema->skipMessageField(_bb, type)) return false;
        break;
      }
    }
  }
}

#endif  // IMPLEMENT_SCHEMA_H

}  // namespace test_large
