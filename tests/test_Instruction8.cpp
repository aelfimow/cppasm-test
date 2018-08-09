#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

static void gen_Instruction8_Type3(Instruction8_Type3 &instr)
{
    instr(AL);
    instr(AX);
    instr(EAX);
    instr(RAX);

    m8  addr1 { RDX };
    m16 addr2 { RDX };
    m32 addr3 { RDX };
    m64 addr4 { RDX };
    instr(addr1);
    instr(addr2);
    instr(addr3);
    instr(addr4);
}

static void gen_Instruction8_Type4(Instruction8_Type4 &instr)
{
    m8  addr1 { RDX };
    m16 addr2 { RDX };
    m32 addr3 { RDX };
    m64 addr4 { RDX };
    instr(AL, BL);
    instr(addr1, CL);
    instr(AX, BX);
    instr(addr2, CX);
    instr(EAX, EBX);
    instr(addr3, ECX);
    instr(RAX, RBX);
    instr(addr4, RCX);
}

static void gen_Instruction8_Type5(Instruction8_Type5 &instr)
{
    m128 addr1 { RDX };
    m256 addr2 { RDX };
    imm8 mask { 255 };
    instr(XMM0, XMM1, XMM2);
    instr(XMM0, XMM1, addr1);
    instr(YMM0, YMM1, YMM2);
    instr(YMM0, YMM1, addr2);
    instr(XMM0, XMM1, mask);
    instr(XMM0, addr1, mask);
    instr(YMM0, YMM1, mask);
    instr(YMM0, addr2, mask);
}

TEST(Instruction8, Type1)
{
    m32 addr { EDX };

    MOVD(MM0, EAX);
    EXPECT_EQ(asmstr(), "movd %eax, %mm0");
    MOVD(MM0, addr);
    EXPECT_EQ(asmstr(), "movd (%edx), %mm0");
    MOVD(EAX, MM0);
    EXPECT_EQ(asmstr(), "movd %mm0, %eax");
    MOVD(addr, MM0);
    EXPECT_EQ(asmstr(), "movd %mm0, (%edx)");
    MOVD(XMM0, EAX);
    EXPECT_EQ(asmstr(), "movd %eax, %xmm0");
    MOVD(XMM0, addr);
    EXPECT_EQ(asmstr(), "movd (%edx), %xmm0");
    MOVD(EAX, XMM0);
    EXPECT_EQ(asmstr(), "movd %xmm0, %eax");
    MOVD(addr, XMM0);
    EXPECT_EQ(asmstr(), "movd %xmm0, (%edx)");
}

TEST(Instruction8, Type2)
{
    m64 addr { RDX };

    MOVQ(MM0, RAX);
    EXPECT_EQ(asmstr(), "movq %rax, %mm0");
    MOVQ(MM0, addr);
    EXPECT_EQ(asmstr(), "movq (%rdx), %mm0");
    MOVQ(RAX, MM0);
    EXPECT_EQ(asmstr(), "movq %mm0, %rax");
    MOVQ(addr, MM0);
    EXPECT_EQ(asmstr(), "movq %mm0, (%rdx)");
    MOVQ(XMM0, RAX);
    EXPECT_EQ(asmstr(), "movq %rax, %xmm0");
    MOVQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "movq (%rdx), %xmm0");
    MOVQ(RAX, XMM0);
    EXPECT_EQ(asmstr(), "movq %xmm0, %rax");
    MOVQ(addr, XMM0);
    EXPECT_EQ(asmstr(), "movq %xmm0, (%rdx)");
}

TEST(Instruction8, TypeX)
{
    gen_Instruction8_Type3(MUL);
    gen_Instruction8_Type3(IMUL);
    gen_Instruction8_Type3(DIV);
    gen_Instruction8_Type3(IDIV);
    gen_Instruction8_Type3(NEG);
    gen_Instruction8_Type3(INC);
    gen_Instruction8_Type3(DEC);
    gen_Instruction8_Type3(NOT);

    gen_Instruction8_Type4(XADD);
    gen_Instruction8_Type4(CMPXCHG);

    gen_Instruction8_Type5(VPERMILPD);
    gen_Instruction8_Type5(VPERMILPS);
}
