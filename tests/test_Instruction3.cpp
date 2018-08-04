#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

static void gen_Instruction3_Type5(Instruction3_Type5 &instr)
{
    m128 addr { RAX };
    instr(XMM0, XMM1);
    instr(XMM0, addr);
    instr(addr, XMM0);
}

static void gen_Instruction3_Type6(Instruction3_Type6 &instr)
{
    m16 addr1 { RAX };
    m32 addr2 { RBX };
    m64 addr3 { RCX };
    instr(addr1);
    instr(addr2);
    instr(addr3);
}

static void gen_Instruction3_Type7(Instruction3_Type7 &instr)
{
    m32fp addr1 { RAX };
    m64fp addr2 { RBX };
    instr(addr1);
    instr(addr2);
    instr(ST(0));
}

static void gen_Instruction3_Type8(Instruction3_Type8 &instr)
{
    m32fp addr1 { RAX };
    m64fp addr2 { RBX };
    instr(addr1);
    instr(addr2);
    instr(ST(1), ST(0));
}

static void gen_Instruction3_Type9(Instruction3_Type9 &instr)
{
    imm8 mask { 255 };
    m8 addr { RAX };
    instr(EAX, XMM0, mask);
    instr(RAX, XMM0, mask);
    instr(addr, XMM0, mask);
}

static void gen_Instruction3_Type10(Instruction3_Type10 &instr)
{
    imm8 mask { 255 };
    m32 addr { RAX };
    instr(EAX, XMM0, mask);
    instr(RAX, XMM0, mask);
    instr(addr, XMM0, mask);
}

TEST(Instruction3, Type1)
{
    m64 addr { RAX };

    LFS(AX, addr);
    EXPECT_EQ(asmstr(), "lfs (%rax), %ax");
    LFS(EAX, addr);
    EXPECT_EQ(asmstr(), "lfs (%rax), %eax");
    LFS(RAX, addr);
    EXPECT_EQ(asmstr(), "lfs (%rax), %rax");

    LGS(AX, addr);
    EXPECT_EQ(asmstr(), "lgs (%rax), %ax");
    LGS(EAX, addr);
    EXPECT_EQ(asmstr(), "lgs (%rax), %eax");
    LGS(RAX, addr);
    EXPECT_EQ(asmstr(), "lgs (%rax), %rax");

    LSS(AX, addr);
    EXPECT_EQ(asmstr(), "lss (%rax), %ax");
    LSS(EAX, addr);
    EXPECT_EQ(asmstr(), "lss (%rax), %eax");
    LSS(RAX, addr);
    EXPECT_EQ(asmstr(), "lss (%rax), %rax");

    LEA(AX, addr);
    EXPECT_EQ(asmstr(), "lea (%rax), %ax");
    LEA(EAX, addr);
    EXPECT_EQ(asmstr(), "lea (%rax), %eax");
    LEA(RAX, addr);
    EXPECT_EQ(asmstr(), "lea (%rax), %rax");
}

TEST(Instruction3, Type2)
{
    RDRAND(AX);
    EXPECT_EQ(asmstr(), "rdrand %ax");
    RDRAND(EAX);
    EXPECT_EQ(asmstr(), "rdrand %eax");
    RDRAND(RAX);
    EXPECT_EQ(asmstr(), "rdrand %rax");

    RDSEED(AX);
    EXPECT_EQ(asmstr(), "rdseed %ax");
    RDSEED(EAX);
    EXPECT_EQ(asmstr(), "rdseed %eax");
    RDSEED(RAX);
    EXPECT_EQ(asmstr(), "rdseed %rax");
}

TEST(Instruction3, Type3)
{
    m32 addr { RAX };

    MOVSS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "movss %xmm1, %xmm0");
    MOVSS(XMM0, addr);
    EXPECT_EQ(asmstr(), "movss (%rax), %xmm0");
    MOVSS(addr, XMM0);
    EXPECT_EQ(asmstr(), "movss %xmm0, (%rax)");
}

TEST(Instruction3, Type4)
{
    m64 addr { RAX };

    MOVSD_SSE2(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "movsd %xmm1, %xmm0");
    MOVSD_SSE2(XMM0, addr);
    EXPECT_EQ(asmstr(), "movsd (%rax), %xmm0");
    MOVSD_SSE2(addr, XMM0);
    EXPECT_EQ(asmstr(), "movsd %xmm0, (%rax)");
}

TEST(Instruction3, AllTypes)
{
    gen_Instruction3_Type5(MOVAPS);
    gen_Instruction3_Type5(MOVUPS);
    gen_Instruction3_Type5(MOVAPD);
    gen_Instruction3_Type5(MOVUPD);
    gen_Instruction3_Type5(MOVDQA);
    gen_Instruction3_Type5(MOVDQU);

    gen_Instruction3_Type6(FILD);
    gen_Instruction3_Type6(FISTP);
    gen_Instruction3_Type6(FISTTP);

    gen_Instruction3_Type7(FST);

    gen_Instruction3_Type8(FADD);
    gen_Instruction3_Type8(FSUB);
    gen_Instruction3_Type8(FSUBR);
    gen_Instruction3_Type8(FMUL);
    gen_Instruction3_Type8(FDIV);
    gen_Instruction3_Type8(FDIVR);

    gen_Instruction3_Type9(PEXTRB);

    gen_Instruction3_Type10(EXTRACTPS);
    gen_Instruction3_Type10(VEXTRACTPS);
}
