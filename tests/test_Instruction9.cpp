#include <gtest/gtest.h>
#include <cppasm.h>
#include "asmstr.h"


TEST(Instruction9, Type1)
{
    m8 addr { RBX };

    VPBROADCASTB(XMM0, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastb %eax, %xmm0");
    VPBROADCASTB(YMM0, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastb %eax, %ymm0");
    VPBROADCASTB(ZMM0, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastb %eax, %zmm0");
    VPBROADCASTB(XMM0.k1, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastb %eax, %xmm0{%k1}");
    VPBROADCASTB(YMM0.k1, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastb %eax, %ymm0{%k1}");
    VPBROADCASTB(ZMM0.k1, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastb %eax, %zmm0{%k1}");
    VPBROADCASTB(XMM0.k1.z, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastb %eax, %xmm0{%k1}{z}");
    VPBROADCASTB(YMM0.k1.z, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastb %eax, %ymm0{%k1}{z}");
    VPBROADCASTB(ZMM0.k1.z, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastb %eax, %zmm0{%k1}{z}");
    VPBROADCASTB(XMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastb %xmm0, %xmm0");
    VPBROADCASTB(YMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastb %xmm0, %ymm0");
    VPBROADCASTB(ZMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastb %xmm0, %zmm0");
    VPBROADCASTB(XMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastb %xmm0, %xmm0{%k1}");
    VPBROADCASTB(YMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastb %xmm0, %ymm0{%k1}");
    VPBROADCASTB(ZMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastb %xmm0, %zmm0{%k1}");
    VPBROADCASTB(XMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastb %xmm0, %xmm0{%k1}{z}");
    VPBROADCASTB(YMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastb %xmm0, %ymm0{%k1}{z}");
    VPBROADCASTB(ZMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastb %xmm0, %zmm0{%k1}{z}");
    VPBROADCASTB(XMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastb (%rbx), %xmm0");
    VPBROADCASTB(YMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastb (%rbx), %ymm0");
    VPBROADCASTB(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastb (%rbx), %zmm0");
    VPBROADCASTB(XMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastb (%rbx), %xmm0{%k1}");
    VPBROADCASTB(YMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastb (%rbx), %ymm0{%k1}");
    VPBROADCASTB(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastb (%rbx), %zmm0{%k1}");
    VPBROADCASTB(XMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastb (%rbx), %xmm0{%k1}{z}");
    VPBROADCASTB(YMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastb (%rbx), %ymm0{%k1}{z}");
    VPBROADCASTB(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastb (%rbx), %zmm0{%k1}{z}");
}

TEST(Instruction9, Type2)
{
    m16 addr { RBX };

    VPBROADCASTW(XMM0, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastw %eax, %xmm0");
    VPBROADCASTW(YMM0, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastw %eax, %ymm0");
    VPBROADCASTW(ZMM0, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastw %eax, %zmm0");
    VPBROADCASTW(XMM0.k1, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastw %eax, %xmm0{%k1}");
    VPBROADCASTW(YMM0.k1, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastw %eax, %ymm0{%k1}");
    VPBROADCASTW(ZMM0.k1, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastw %eax, %zmm0{%k1}");
    VPBROADCASTW(XMM0.k1.z, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastw %eax, %xmm0{%k1}{z}");
    VPBROADCASTW(YMM0.k1.z, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastw %eax, %ymm0{%k1}{z}");
    VPBROADCASTW(ZMM0.k1.z, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastw %eax, %zmm0{%k1}{z}");
    VPBROADCASTW(XMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastw %xmm0, %xmm0");
    VPBROADCASTW(YMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastw %xmm0, %ymm0");
    VPBROADCASTW(ZMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastw %xmm0, %zmm0");
    VPBROADCASTW(XMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastw %xmm0, %xmm0{%k1}");
    VPBROADCASTW(YMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastw %xmm0, %ymm0{%k1}");
    VPBROADCASTW(ZMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastw %xmm0, %zmm0{%k1}");
    VPBROADCASTW(XMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastw %xmm0, %xmm0{%k1}{z}");
    VPBROADCASTW(YMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastw %xmm0, %ymm0{%k1}{z}");
    VPBROADCASTW(ZMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastw %xmm0, %zmm0{%k1}{z}");
    VPBROADCASTW(XMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastw (%rbx), %xmm0");
    VPBROADCASTW(YMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastw (%rbx), %ymm0");
    VPBROADCASTW(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastw (%rbx), %zmm0");
    VPBROADCASTW(XMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastw (%rbx), %xmm0{%k1}");
    VPBROADCASTW(YMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastw (%rbx), %ymm0{%k1}");
    VPBROADCASTW(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastw (%rbx), %zmm0{%k1}");
    VPBROADCASTW(XMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastw (%rbx), %xmm0{%k1}{z}");
    VPBROADCASTW(YMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastw (%rbx), %ymm0{%k1}{z}");
    VPBROADCASTW(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastw (%rbx), %zmm0{%k1}{z}");
}

TEST(Instruction9, Type3)
{
    m32 addr { RBX };

    VPBROADCASTD(XMM0, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastd %eax, %xmm0");
    VPBROADCASTD(YMM0, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastd %eax, %ymm0");
    VPBROADCASTD(ZMM0, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastd %eax, %zmm0");
    VPBROADCASTD(XMM0.k1, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastd %eax, %xmm0{%k1}");
    VPBROADCASTD(YMM0.k1, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastd %eax, %ymm0{%k1}");
    VPBROADCASTD(ZMM0.k1, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastd %eax, %zmm0{%k1}");
    VPBROADCASTD(XMM0.k1.z, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastd %eax, %xmm0{%k1}{z}");
    VPBROADCASTD(YMM0.k1.z, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastd %eax, %ymm0{%k1}{z}");
    VPBROADCASTD(ZMM0.k1.z, EAX);
    EXPECT_EQ(asmstr(), "vpbroadcastd %eax, %zmm0{%k1}{z}");
    VPBROADCASTD(XMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastd %xmm0, %xmm0");
    VPBROADCASTD(YMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastd %xmm0, %ymm0");
    VPBROADCASTD(ZMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastd %xmm0, %zmm0");
    VPBROADCASTD(XMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastd %xmm0, %xmm0{%k1}");
    VPBROADCASTD(YMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastd %xmm0, %ymm0{%k1}");
    VPBROADCASTD(ZMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastd %xmm0, %zmm0{%k1}");
    VPBROADCASTD(XMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastd %xmm0, %xmm0{%k1}{z}");
    VPBROADCASTD(YMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastd %xmm0, %ymm0{%k1}{z}");
    VPBROADCASTD(ZMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastd %xmm0, %zmm0{%k1}{z}");
    VPBROADCASTD(XMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastd (%rbx), %xmm0");
    VPBROADCASTD(YMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastd (%rbx), %ymm0");
    VPBROADCASTD(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastd (%rbx), %zmm0");
    VPBROADCASTD(XMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastd (%rbx), %xmm0{%k1}");
    VPBROADCASTD(YMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastd (%rbx), %ymm0{%k1}");
    VPBROADCASTD(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastd (%rbx), %zmm0{%k1}");
    VPBROADCASTD(XMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastd (%rbx), %xmm0{%k1}{z}");
    VPBROADCASTD(YMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastd (%rbx), %ymm0{%k1}{z}");
    VPBROADCASTD(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastd (%rbx), %zmm0{%k1}{z}");
}

TEST(Instruction9, Type4)
{
    m64 addr { RBX };

    VPBROADCASTQ(XMM0, RAX);
    EXPECT_EQ(asmstr(), "vpbroadcastq %rax, %xmm0");
    VPBROADCASTQ(YMM0, RAX);
    EXPECT_EQ(asmstr(), "vpbroadcastq %rax, %ymm0");
    VPBROADCASTQ(ZMM0, RAX);
    EXPECT_EQ(asmstr(), "vpbroadcastq %rax, %zmm0");
    VPBROADCASTQ(XMM0.k1, RAX);
    EXPECT_EQ(asmstr(), "vpbroadcastq %rax, %xmm0{%k1}");
    VPBROADCASTQ(YMM0.k1, RAX);
    EXPECT_EQ(asmstr(), "vpbroadcastq %rax, %ymm0{%k1}");
    VPBROADCASTQ(ZMM0.k1, RAX);
    EXPECT_EQ(asmstr(), "vpbroadcastq %rax, %zmm0{%k1}");
    VPBROADCASTQ(XMM0.k1.z, RAX);
    EXPECT_EQ(asmstr(), "vpbroadcastq %rax, %xmm0{%k1}{z}");
    VPBROADCASTQ(YMM0.k1.z, RAX);
    EXPECT_EQ(asmstr(), "vpbroadcastq %rax, %ymm0{%k1}{z}");
    VPBROADCASTQ(ZMM0.k1.z, RAX);
    EXPECT_EQ(asmstr(), "vpbroadcastq %rax, %zmm0{%k1}{z}");
    VPBROADCASTQ(XMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastq %xmm0, %xmm0");
    VPBROADCASTQ(YMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastq %xmm0, %ymm0");
    VPBROADCASTQ(ZMM0, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastq %xmm0, %zmm0");
    VPBROADCASTQ(XMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastq %xmm0, %xmm0{%k1}");
    VPBROADCASTQ(YMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastq %xmm0, %ymm0{%k1}");
    VPBROADCASTQ(ZMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastq %xmm0, %zmm0{%k1}");
    VPBROADCASTQ(XMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastq %xmm0, %xmm0{%k1}{z}");
    VPBROADCASTQ(YMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastq %xmm0, %ymm0{%k1}{z}");
    VPBROADCASTQ(ZMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vpbroadcastq %xmm0, %zmm0{%k1}{z}");
    VPBROADCASTQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastq (%rbx), %xmm0");
    VPBROADCASTQ(YMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastq (%rbx), %ymm0");
    VPBROADCASTQ(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastq (%rbx), %zmm0");
    VPBROADCASTQ(XMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastq (%rbx), %xmm0{%k1}");
    VPBROADCASTQ(YMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastq (%rbx), %ymm0{%k1}");
    VPBROADCASTQ(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastq (%rbx), %zmm0{%k1}");
    VPBROADCASTQ(XMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastq (%rbx), %xmm0{%k1}{z}");
    VPBROADCASTQ(YMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastq (%rbx), %ymm0{%k1}{z}");
    VPBROADCASTQ(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vpbroadcastq (%rbx), %zmm0{%k1}{z}");
}

TEST(Instruction9, Type5)
{
    imm8 value { 1 };
    m128 addr1 { RAX };
    m256 addr2 { RBX };
    m512 addr3 { RCX };
    m32 addr4 { RDX };

    VALIGND(XMM1, XMM2, XMM3, value);
    EXPECT_EQ(asmstr(), "valignd $0x01, %xmm3, %xmm2, %xmm1");
    VALIGND(XMM1, XMM2, addr1, value);
    EXPECT_EQ(asmstr(), "valignd $0x01, (%rax), %xmm2, %xmm1");
    VALIGND(XMM1, XMM2, addr4.broadcast(1, 4), value);
    EXPECT_EQ(asmstr(), "valignd $0x01, (%rdx){1to4}, %xmm2, %xmm1");
    VALIGND(YMM1, YMM2, YMM3, value);
    EXPECT_EQ(asmstr(), "valignd $0x01, %ymm3, %ymm2, %ymm1");
    VALIGND(YMM1, YMM2, addr2, value);
    EXPECT_EQ(asmstr(), "valignd $0x01, (%rbx), %ymm2, %ymm1");
    VALIGND(YMM1, YMM2, addr4.broadcast(1, 8), value);
    EXPECT_EQ(asmstr(), "valignd $0x01, (%rdx){1to8}, %ymm2, %ymm1");
    VALIGND(ZMM1, ZMM2, ZMM3, value);
    EXPECT_EQ(asmstr(), "valignd $0x01, %zmm3, %zmm2, %zmm1");
    VALIGND(ZMM1, ZMM2, addr3, value);
    EXPECT_EQ(asmstr(), "valignd $0x01, (%rcx), %zmm2, %zmm1");
    VALIGND(ZMM1, ZMM2, addr4.broadcast(1, 16), value);
    EXPECT_EQ(asmstr(), "valignd $0x01, (%rdx){1to16}, %zmm2, %zmm1");
}

TEST(Instruction9, Type6)
{
    imm8 value { 1 };
    m128 addr1 { RAX };
    m256 addr2 { RBX };
    m512 addr3 { RCX };
    m64 addr4 { RDX };

    VALIGNQ(XMM1, XMM2, XMM3, value);
    EXPECT_EQ(asmstr(), "valignq $0x01, %xmm3, %xmm2, %xmm1");
    VALIGNQ(XMM1, XMM2, addr1, value);
    EXPECT_EQ(asmstr(), "valignq $0x01, (%rax), %xmm2, %xmm1");
    VALIGNQ(XMM1, XMM2, addr4.broadcast(1, 2), value);
    EXPECT_EQ(asmstr(), "valignq $0x01, (%rdx){1to2}, %xmm2, %xmm1");
    VALIGNQ(YMM1, YMM2, YMM3, value);
    EXPECT_EQ(asmstr(), "valignq $0x01, %ymm3, %ymm2, %ymm1");
    VALIGNQ(YMM1, YMM2, addr2, value);
    EXPECT_EQ(asmstr(), "valignq $0x01, (%rbx), %ymm2, %ymm1");
    VALIGNQ(YMM1, YMM2, addr4.broadcast(1, 4), value);
    EXPECT_EQ(asmstr(), "valignq $0x01, (%rdx){1to4}, %ymm2, %ymm1");
    VALIGNQ(ZMM1, ZMM2, ZMM3, value);
    EXPECT_EQ(asmstr(), "valignq $0x01, %zmm3, %zmm2, %zmm1");
    VALIGNQ(ZMM1, ZMM2, addr3, value);
    EXPECT_EQ(asmstr(), "valignq $0x01, (%rcx), %zmm2, %zmm1");
    VALIGNQ(ZMM1, ZMM2, addr4.broadcast(1, 8), value);
    EXPECT_EQ(asmstr(), "valignq $0x01, (%rdx){1to8}, %zmm2, %zmm1");
}

TEST(Instruction9, Type7)
{
    m32 addr1 { RAX };
    m128 addr2 { RBX };
    m256 addr3 { RCX };
    m512 addr4 { RDX };

    VBLENDMPS(XMM2, XMM1, XMM0);
    EXPECT_EQ(asmstr(), "vblendmps %xmm0, %xmm1, %xmm2");
    VBLENDMPS(XMM2, XMM1, addr2);
    EXPECT_EQ(asmstr(), "vblendmps (%rbx), %xmm1, %xmm2");
    VBLENDMPS(XMM2, XMM1, addr1.broadcast(1, 4));
    EXPECT_EQ(asmstr(), "vblendmps (%rax){1to4}, %xmm1, %xmm2");
    VBLENDMPS(YMM2, YMM1, YMM0);
    EXPECT_EQ(asmstr(), "vblendmps %ymm0, %ymm1, %ymm2");
    VBLENDMPS(YMM2, YMM1, addr3);
    EXPECT_EQ(asmstr(), "vblendmps (%rcx), %ymm1, %ymm2");
    VBLENDMPS(YMM2, YMM1, addr1.broadcast(1, 8));
    EXPECT_EQ(asmstr(), "vblendmps (%rax){1to8}, %ymm1, %ymm2");
    VBLENDMPS(ZMM2, ZMM1, ZMM0);
    EXPECT_EQ(asmstr(), "vblendmps %zmm0, %zmm1, %zmm2");
    VBLENDMPS(ZMM2, ZMM1, addr4);
    EXPECT_EQ(asmstr(), "vblendmps (%rdx), %zmm1, %zmm2");
    VBLENDMPS(ZMM2, ZMM1, addr1.broadcast(1, 16));
    EXPECT_EQ(asmstr(), "vblendmps (%rax){1to16}, %zmm1, %zmm2");
}
