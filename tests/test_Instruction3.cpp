#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

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

TEST(Instruction3, Type5)
{
    m128 addr { RAX };

    MOVAPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "movaps %xmm1, %xmm0");
    MOVAPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "movaps (%rax), %xmm0");
    MOVAPS(addr, XMM0);
    EXPECT_EQ(asmstr(), "movaps %xmm0, (%rax)");

    MOVUPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "movups %xmm1, %xmm0");
    MOVUPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "movups (%rax), %xmm0");
    MOVUPS(addr, XMM0);
    EXPECT_EQ(asmstr(), "movups %xmm0, (%rax)");

    MOVAPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "movapd %xmm1, %xmm0");
    MOVAPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "movapd (%rax), %xmm0");
    MOVAPD(addr, XMM0);
    EXPECT_EQ(asmstr(), "movapd %xmm0, (%rax)");

    MOVUPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "movupd %xmm1, %xmm0");
    MOVUPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "movupd (%rax), %xmm0");
    MOVUPD(addr, XMM0);
    EXPECT_EQ(asmstr(), "movupd %xmm0, (%rax)");

    MOVDQA(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "movdqa %xmm1, %xmm0");
    MOVDQA(XMM0, addr);
    EXPECT_EQ(asmstr(), "movdqa (%rax), %xmm0");
    MOVDQA(addr, XMM0);
    EXPECT_EQ(asmstr(), "movdqa %xmm0, (%rax)");

    MOVDQU(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "movdqu %xmm1, %xmm0");
    MOVDQU(XMM0, addr);
    EXPECT_EQ(asmstr(), "movdqu (%rax), %xmm0");
    MOVDQU(addr, XMM0);
    EXPECT_EQ(asmstr(), "movdqu %xmm0, (%rax)");
}

TEST(Instruction3, Type6)
{
    m16 addr1 { RAX };
    m32 addr2 { RBX };
    m64 addr3 { RCX };

    FILD(addr1);
    EXPECT_EQ(asmstr(), "fild (%rax)");
    FILD(addr2);
    EXPECT_EQ(asmstr(), "fildl (%rbx)");
    FILD(addr3);
    EXPECT_EQ(asmstr(), "fildll (%rcx)");

    FISTP(addr1);
    EXPECT_EQ(asmstr(), "fistp (%rax)");
    FISTP(addr2);
    EXPECT_EQ(asmstr(), "fistpl (%rbx)");
    FISTP(addr3);
    EXPECT_EQ(asmstr(), "fistpll (%rcx)");

    FISTTP(addr1);
    EXPECT_EQ(asmstr(), "fisttp (%rax)");
    FISTTP(addr2);
    EXPECT_EQ(asmstr(), "fisttpl (%rbx)");
    FISTTP(addr3);
    EXPECT_EQ(asmstr(), "fisttpll (%rcx)");
}

TEST(Instruction3, Type7)
{
    m32fp addr1 { RAX };
    m64fp addr2 { RBX };

    FST(addr1);
    EXPECT_EQ(asmstr(), "fsts (%rax)");
    FST(addr2);
    EXPECT_EQ(asmstr(), "fstl (%rbx)");
    FST(ST(0));
    EXPECT_EQ(asmstr(), "fst %st(0)");
}

TEST(Instruction3, Type8)
{
    m32fp addr1 { RAX };
    m64fp addr2 { RBX };

    FADD(addr1);
    EXPECT_EQ(asmstr(), "fadds (%rax)");
    FADD(addr2);
    EXPECT_EQ(asmstr(), "faddl (%rbx)");
    FADD(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "fadd %st(0), %st(1)");

    FSUB(addr1);
    EXPECT_EQ(asmstr(), "fsubs (%rax)");
    FSUB(addr2);
    EXPECT_EQ(asmstr(), "fsubl (%rbx)");
    FSUB(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "fsub %st(0), %st(1)");

    FSUBR(addr1);
    EXPECT_EQ(asmstr(), "fsubrs (%rax)");
    FSUBR(addr2);
    EXPECT_EQ(asmstr(), "fsubrl (%rbx)");
    FSUBR(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "fsubr %st(0), %st(1)");

    FMUL(addr1);
    EXPECT_EQ(asmstr(), "fmuls (%rax)");
    FMUL(addr2);
    EXPECT_EQ(asmstr(), "fmull (%rbx)");
    FMUL(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "fmul %st(0), %st(1)");

    FDIV(addr1);
    EXPECT_EQ(asmstr(), "fdivs (%rax)");
    FDIV(addr2);
    EXPECT_EQ(asmstr(), "fdivl (%rbx)");
    FDIV(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "fdiv %st(0), %st(1)");

    FDIVR(addr1);
    EXPECT_EQ(asmstr(), "fdivrs (%rax)");
    FDIVR(addr2);
    EXPECT_EQ(asmstr(), "fdivrl (%rbx)");
    FDIVR(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "fdivr %st(0), %st(1)");
}

TEST(Instruction3, Type9)
{
    imm8 mask { 255 };
    m8 addr { RAX };

    PEXTRB(EAX, XMM0, mask);
    EXPECT_EQ(asmstr(), "pextrb $0xFF, %xmm0, %eax");
    PEXTRB(RAX, XMM0, mask);
    EXPECT_EQ(asmstr(), "pextrb $0xFF, %xmm0, %rax");
    PEXTRB(addr, XMM0, mask);
    EXPECT_EQ(asmstr(), "pextrb $0xFF, %xmm0, (%rax)");
}

TEST(Instruction3, AllTypes)
{
    gen_Instruction3_Type10(EXTRACTPS);
    gen_Instruction3_Type10(VEXTRACTPS);
}
