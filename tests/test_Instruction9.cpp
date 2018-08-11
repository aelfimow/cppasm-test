#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

static void gen_Instruction9_Type2(Instruction9_Type2 &instr)
{
    m16 addr { RBX };
    instr(XMM0, EAX);
    instr(YMM0, EAX);
    instr(ZMM0, EAX);
    instr(XMM0.k1, EAX);
    instr(YMM0.k1, EAX);
    instr(ZMM0.k1, EAX);
    instr(XMM0.k1.z, EAX);
    instr(YMM0.k1.z, EAX);
    instr(ZMM0.k1.z, EAX);
    instr(XMM0, XMM0);
    instr(YMM0, XMM0);
    instr(ZMM0, XMM0);
    instr(XMM0.k1, XMM0);
    instr(YMM0.k1, XMM0);
    instr(ZMM0.k1, XMM0);
    instr(XMM0.k1.z, XMM0);
    instr(YMM0.k1.z, XMM0);
    instr(ZMM0.k1.z, XMM0);
    instr(XMM0, addr);
    instr(YMM0, addr);
    instr(ZMM0, addr);
    instr(XMM0.k1, addr);
    instr(YMM0.k1, addr);
    instr(ZMM0.k1, addr);
    instr(XMM0.k1.z, addr);
    instr(YMM0.k1.z, addr);
    instr(ZMM0.k1.z, addr);
}

static void gen_Instruction9_Type3(Instruction9_Type3 &instr)
{
    m32 addr { RBX };
    instr(XMM0, EAX);
    instr(YMM0, EAX);
    instr(ZMM0, EAX);
    instr(XMM0.k1, EAX);
    instr(YMM0.k1, EAX);
    instr(ZMM0.k1, EAX);
    instr(XMM0.k1.z, EAX);
    instr(YMM0.k1.z, EAX);
    instr(ZMM0.k1.z, EAX);
    instr(XMM0, XMM0);
    instr(YMM0, XMM0);
    instr(ZMM0, XMM0);
    instr(XMM0.k1, XMM0);
    instr(YMM0.k1, XMM0);
    instr(ZMM0.k1, XMM0);
    instr(XMM0.k1.z, XMM0);
    instr(YMM0.k1.z, XMM0);
    instr(ZMM0.k1.z, XMM0);
    instr(XMM0, addr);
    instr(YMM0, addr);
    instr(ZMM0, addr);
    instr(XMM0.k1, addr);
    instr(YMM0.k1, addr);
    instr(ZMM0.k1, addr);
    instr(XMM0.k1.z, addr);
    instr(YMM0.k1.z, addr);
    instr(ZMM0.k1.z, addr);
}

static void gen_Instruction9_Type4(Instruction9_Type4 &instr)
{
    m64 addr { RBX };
    instr(XMM0, RAX);
    instr(YMM0, RAX);
    instr(ZMM0, RAX);
    instr(XMM0.k1, RAX);
    instr(YMM0.k1, RAX);
    instr(ZMM0.k1, RAX);
    instr(XMM0.k1.z, RAX);
    instr(YMM0.k1.z, RAX);
    instr(ZMM0.k1.z, RAX);
    instr(XMM0, XMM0);
    instr(YMM0, XMM0);
    instr(ZMM0, XMM0);
    instr(XMM0.k1, XMM0);
    instr(YMM0.k1, XMM0);
    instr(ZMM0.k1, XMM0);
    instr(XMM0.k1.z, XMM0);
    instr(YMM0.k1.z, XMM0);
    instr(ZMM0.k1.z, XMM0);
    instr(XMM0, addr);
    instr(YMM0, addr);
    instr(ZMM0, addr);
    instr(XMM0.k1, addr);
    instr(YMM0.k1, addr);
    instr(ZMM0.k1, addr);
    instr(XMM0.k1.z, addr);
    instr(YMM0.k1.z, addr);
    instr(ZMM0.k1.z, addr);
}

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

TEST(Instruction9, TypeX)
{
    gen_Instruction9_Type2(VPBROADCASTW);
    gen_Instruction9_Type3(VPBROADCASTD);
    gen_Instruction9_Type4(VPBROADCASTQ);
}
