#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

static void gen_Instruction2_Type37(Instruction2_Type37 &instr)
{
    m32 addr { RAX };
    imm8 mask { 255 };
    instr(EAX, XMM0, mask);
    instr(addr, XMM0, mask);
}

static void gen_Instruction2_Type38(Instruction2_Type38 &instr)
{
    m128 addr { RDX };
    instr(XMM2, XMM1, XMM0);
    instr(XMM1, addr, XMM0);
}

static void gen_Instruction2_Type39(Instruction2_Type39 &instr)
{
    m128 addr { RBX };
    instr(RAX, addr);
}

static void gen_Instruction2_Type40(Instruction2_Type40 &instr)
{
    m32 addr1 { EBX };
    m64 addr2 { RBX };
    instr(addr1);
    instr(addr2);
}

static void gen_Instruction2_Type41(Instruction2_Type41 &instr)
{
    m128 addr { RBX };
    instr(YMM0, addr);
    instr(ZMM0, addr);
    instr(YMM0.k1, addr);
    instr(ZMM0.k1, addr);
    instr(YMM0.k1.z, addr);
    instr(ZMM0.k1.z, addr);
}

static void gen_Instruction2_Type42(Instruction2_Type42 &instr)
{
    m256 addr { RBX };
    imm8 mask { 0x0F };
    instr(ZMM0, ZMM1, YMM0, mask);
    instr(ZMM0.k1, ZMM1, YMM0, mask);
    instr(ZMM0.k1.z, ZMM1, YMM0, mask);
    instr(ZMM0, ZMM1, addr, mask);
    instr(ZMM0.k1, ZMM1, addr, mask);
    instr(ZMM0.k1.z, ZMM1, addr, mask);
}

TEST(Instruction2, Type2)
{
    imm16 value { 65535 };

    RET();
    EXPECT_EQ(asmstr(), "ret");
    RET(value);
    EXPECT_EQ(asmstr(), "ret $0xFFFF");

    RET_FAR();
    EXPECT_EQ(asmstr(), "lret");
    RET_FAR(value);
    EXPECT_EQ(asmstr(), "lret $0xFFFF");
}

TEST(Instruction2, Type3)
{
    RDFSBASE(EAX);
    EXPECT_EQ(asmstr(), "rdfsbase %eax");
    RDFSBASE(RAX);
    EXPECT_EQ(asmstr(), "rdfsbase %rax");

    RDGSBASE(EAX);
    EXPECT_EQ(asmstr(), "rdgsbase %eax");
    RDGSBASE(RAX);
    EXPECT_EQ(asmstr(), "rdgsbase %rax");

    WRFSBASE(EAX);
    EXPECT_EQ(asmstr(), "wrfsbase %eax");
    WRFSBASE(RAX);
    EXPECT_EQ(asmstr(), "wrfsbase %rax");

    WRGSBASE(EAX);
    EXPECT_EQ(asmstr(), "wrgsbase %eax");
    WRGSBASE(RAX);
    EXPECT_EQ(asmstr(), "wrgsbase %rax");

    BSWAP(EAX);
    EXPECT_EQ(asmstr(), "bswap %eax");
    BSWAP(RAX);
    EXPECT_EQ(asmstr(), "bswap %rax");
}

TEST(Instruction2, Type4)
{
    MOVMSKPS(EAX, XMM0);
    EXPECT_EQ(asmstr(), "movmskps %xmm0, %eax");
    MOVMSKPS(RAX, XMM0);
    EXPECT_EQ(asmstr(), "movmskps %xmm0, %rax");

    MOVMSKPD(EAX, XMM0);
    EXPECT_EQ(asmstr(), "movmskpd %xmm0, %eax");
    MOVMSKPD(RAX, XMM0);
    EXPECT_EQ(asmstr(), "movmskpd %xmm0, %rax");
}

TEST(Instruction2, Type5)
{
    FXCH();
    EXPECT_EQ(asmstr(), "fxch");
    FXCH(ST(1));
    EXPECT_EQ(asmstr(), "fxch %st(1)");

    FUCOM();
    EXPECT_EQ(asmstr(), "fucom");
    FUCOM(ST(1));
    EXPECT_EQ(asmstr(), "fucom %st(1)");

    FUCOMP();
    EXPECT_EQ(asmstr(), "fucomp");
    FUCOMP(ST(1));
    EXPECT_EQ(asmstr(), "fucomp %st(1)");
}

TEST(Instruction2, Type6)
{
    m16 addr { RAX };

    FSTSW(AX);
    EXPECT_EQ(asmstr(), "fstsw %ax");
    FSTSW(addr);
    EXPECT_EQ(asmstr(), "fstsw (%rax)");

    FNSTSW(AX);
    EXPECT_EQ(asmstr(), "fnstsw %ax");
    FNSTSW(addr);
    EXPECT_EQ(asmstr(), "fnstsw (%rax)");

    LLDT(AX);
    EXPECT_EQ(asmstr(), "lldt %ax");
    LLDT(addr);
    EXPECT_EQ(asmstr(), "lldt (%rax)");

    LMSW(AX);
    EXPECT_EQ(asmstr(), "lmsw %ax");
    LMSW(addr);
    EXPECT_EQ(asmstr(), "lmsw (%rax)");

    VERR(AX);
    EXPECT_EQ(asmstr(), "verr %ax");
    VERR(addr);
    EXPECT_EQ(asmstr(), "verr (%rax)");

    VERW(AX);
    EXPECT_EQ(asmstr(), "verw %ax");
    VERW(addr);
    EXPECT_EQ(asmstr(), "verw (%rax)");

    LTR(AX);
    EXPECT_EQ(asmstr(), "ltr %ax");
    LTR(addr);
    EXPECT_EQ(asmstr(), "ltr (%rax)");
}

TEST(Instruction2, Type7)
{
    m8 addr { RAX };

    SETA(AL);
    EXPECT_EQ(asmstr(), "seta %al");
    SETA(addr);
    EXPECT_EQ(asmstr(), "seta (%rax)");

    SETAE(AL);
    EXPECT_EQ(asmstr(), "setae %al");
    SETAE(addr);
    EXPECT_EQ(asmstr(), "setae (%rax)");

    SETB(AL);
    EXPECT_EQ(asmstr(), "setb %al");
    SETB(addr);
    EXPECT_EQ(asmstr(), "setb (%rax)");

    SETBE(AL);
    EXPECT_EQ(asmstr(), "setbe %al");
    SETBE(addr);
    EXPECT_EQ(asmstr(), "setbe (%rax)");

    SETC(AL);
    EXPECT_EQ(asmstr(), "setc %al");
    SETC(addr);
    EXPECT_EQ(asmstr(), "setc (%rax)");

    SETE(AL);
    EXPECT_EQ(asmstr(), "sete %al");
    SETE(addr);
    EXPECT_EQ(asmstr(), "sete (%rax)");

    SETG(AL);
    EXPECT_EQ(asmstr(), "setg %al");
    SETG(addr);
    EXPECT_EQ(asmstr(), "setg (%rax)");

    SETGE(AL);
    EXPECT_EQ(asmstr(), "setge %al");
    SETGE(addr);
    EXPECT_EQ(asmstr(), "setge (%rax)");

    SETL(AL);
    EXPECT_EQ(asmstr(), "setl %al");
    SETL(addr);
    EXPECT_EQ(asmstr(), "setl (%rax)");

    SETLE(AL);
    EXPECT_EQ(asmstr(), "setle %al");
    SETLE(addr);
    EXPECT_EQ(asmstr(), "setle (%rax)");

    SETNA(AL);
    EXPECT_EQ(asmstr(), "setna %al");
    SETNA(addr);
    EXPECT_EQ(asmstr(), "setna (%rax)");

    SETNAE(AL);
    EXPECT_EQ(asmstr(), "setnae %al");
    SETNAE(addr);
    EXPECT_EQ(asmstr(), "setnae (%rax)");

    SETNB(AL);
    EXPECT_EQ(asmstr(), "setnb %al");
    SETNB(addr);
    EXPECT_EQ(asmstr(), "setnb (%rax)");

    SETNBE(AL);
    EXPECT_EQ(asmstr(), "setnbe %al");
    SETNBE(addr);
    EXPECT_EQ(asmstr(), "setnbe (%rax)");

    SETNC(AL);
    EXPECT_EQ(asmstr(), "setnc %al");
    SETNC(addr);
    EXPECT_EQ(asmstr(), "setnc (%rax)");

    SETNE(AL);
    EXPECT_EQ(asmstr(), "setne %al");
    SETNE(addr);
    EXPECT_EQ(asmstr(), "setne (%rax)");

    SETNG(AL);
    EXPECT_EQ(asmstr(), "setng %al");
    SETNG(addr);
    EXPECT_EQ(asmstr(), "setng (%rax)");

    SETNGE(AL);
    EXPECT_EQ(asmstr(), "setnge %al");
    SETNGE(addr);
    EXPECT_EQ(asmstr(), "setnge (%rax)");

    SETNL(AL);
    EXPECT_EQ(asmstr(), "setnl %al");
    SETNL(addr);
    EXPECT_EQ(asmstr(), "setnl (%rax)");

    SETNLE(AL);
    EXPECT_EQ(asmstr(), "setle %al");
    SETNLE(addr);
    EXPECT_EQ(asmstr(), "setle (%rax)");

    SETNO(AL);
    EXPECT_EQ(asmstr(), "setno %al");
    SETNO(addr);
    EXPECT_EQ(asmstr(), "setno (%rax)");

    SETNP(AL);
    EXPECT_EQ(asmstr(), "setnp %al");
    SETNP(addr);
    EXPECT_EQ(asmstr(), "setnp (%rax)");

    SETNS(AL);
    EXPECT_EQ(asmstr(), "setns %al");
    SETNS(addr);
    EXPECT_EQ(asmstr(), "setns (%rax)");

    SETNZ(AL);
    EXPECT_EQ(asmstr(), "setnz %al");
    SETNZ(addr);
    EXPECT_EQ(asmstr(), "setnz (%rax)");

    SETO(AL);
    EXPECT_EQ(asmstr(), "seto %al");
    SETO(addr);
    EXPECT_EQ(asmstr(), "seto (%rax)");

    SETP(AL);
    EXPECT_EQ(asmstr(), "setp %al");
    SETP(addr);
    EXPECT_EQ(asmstr(), "setp (%rax)");

    SETPE(AL);
    EXPECT_EQ(asmstr(), "setpe %al");
    SETPE(addr);
    EXPECT_EQ(asmstr(), "setpe (%rax)");

    SETPO(AL);
    EXPECT_EQ(asmstr(), "setpo %al");
    SETPO(addr);
    EXPECT_EQ(asmstr(), "setpo (%rax)");

    SETS(AL);
    EXPECT_EQ(asmstr(), "sets %al");
    SETS(addr);
    EXPECT_EQ(asmstr(), "sets (%rax)");

    SETZ(AL);
    EXPECT_EQ(asmstr(), "setz %al");
    SETZ(addr);
    EXPECT_EQ(asmstr(), "setz (%rax)");
}

TEST(Instruction2, Type9)
{
    m64 addr { RAX };

    MOVHPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "movhps (%rax), %xmm0");
    MOVHPS(addr, XMM0);
    EXPECT_EQ(asmstr(), "movhps %xmm0, (%rax)");

    MOVLPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "movlps (%rax), %xmm0");
    MOVLPS(addr, XMM0);
    EXPECT_EQ(asmstr(), "movlps %xmm0, (%rax)");
}

TEST(Instruction2, Type10)
{
    m128 addr { RAX };

    ADDPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "addps %xmm1, %xmm0");
    ADDPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "addps (%rax), %xmm0");

    SUBPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "subps %xmm1, %xmm0");
    SUBPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "subps (%rax), %xmm0");

    MULPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "mulps %xmm1, %xmm0");
    MULPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "mulps (%rax), %xmm0");

    DIVPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "divps %xmm1, %xmm0");
    DIVPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "divps (%rax), %xmm0");

    RCPPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "rcpps %xmm1, %xmm0");
    RCPPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "rcpps (%rax), %xmm0");

    SQRTPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "sqrtps %xmm1, %xmm0");
    SQRTPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "sqrtps (%rax), %xmm0");

    MAXPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "maxps %xmm1, %xmm0");
    MAXPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "maxps (%rax), %xmm0");

    MINPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "minps %xmm1, %xmm0");
    MINPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "minps (%rax), %xmm0");

    ANDPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "andps %xmm1, %xmm0");
    ANDPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "andps (%rax), %xmm0");

    ANDNPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "andnps %xmm1, %xmm0");
    ANDNPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "andnps (%rax), %xmm0");

    ORPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "orps %xmm1, %xmm0");
    ORPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "orps (%rax), %xmm0");

    XORPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "xorps %xmm1, %xmm0");
    XORPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "xorps (%rax), %xmm0");

    UNPCKHPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "unpckhps %xmm1, %xmm0");
    UNPCKHPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "unpckhps (%rax), %xmm0");

    UNPCKLPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "unpcklps %xmm1, %xmm0");
    UNPCKLPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "unpcklps (%rax), %xmm0");

    ADDPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "addpd %xmm1, %xmm0");
    ADDPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "addpd (%rax), %xmm0");

    SUBPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "subpd %xmm1, %xmm0");
    SUBPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "subpd (%rax), %xmm0");

    MULPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "mulpd %xmm1, %xmm0");
    MULPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "mulpd (%rax), %xmm0");

    DIVPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "divpd %xmm1, %xmm0");
    DIVPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "divpd (%rax), %xmm0");

    SQRTPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "sqrtpd %xmm1, %xmm0");
    SQRTPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "sqrtpd (%rax), %xmm0");

    MAXPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "maxpd %xmm1, %xmm0");
    MAXPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "maxpd (%rax), %xmm0");

    MINPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "minpd %xmm1, %xmm0");
    MINPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "minpd (%rax), %xmm0");

    ANDPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "andpd %xmm1, %xmm0");
    ANDPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "andpd (%rax), %xmm0");

    ANDNPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "andnpd %xmm1, %xmm0");
    ANDNPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "andnpd (%rax), %xmm0");

    ORPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "orpd %xmm1, %xmm0");
    ORPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "orpd (%rax), %xmm0");

    XORPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "xorpd %xmm1, %xmm0");
    XORPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "xorpd (%rax), %xmm0");

    UNPCKHPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "unpckhpd %xmm1, %xmm0");
    UNPCKHPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "unpckhpd (%rax), %xmm0");

    UNPCKLPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "unpcklpd %xmm1, %xmm0");
    UNPCKLPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "unpcklpd (%rax), %xmm0");

    CVTPD2DQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "cvtpd2dq %xmm1, %xmm0");
    CVTPD2DQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvtpd2dq (%rax), %xmm0");

    CVTTPD2DQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "cvttpd2dq %xmm1, %xmm0");
    CVTTPD2DQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvttpd2dq (%rax), %xmm0");

    CVTPD2PS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "cvtpd2ps %xmm1, %xmm0");
    CVTPD2PS(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvtpd2ps (%rax), %xmm0");

    CVTDQ2PS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "cvtdq2ps %xmm1, %xmm0");
    CVTDQ2PS(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvtdq2ps (%rax), %xmm0");

    CVTPS2DQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "cvtps2dq %xmm1, %xmm0");
    CVTPS2DQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvtps2dq (%rax), %xmm0");

    CVTTPS2DQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "cvttps2dq %xmm1, %xmm0");
    CVTTPS2DQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvttps2dq (%rax), %xmm0");

    PUNPCKHQDQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "punpckhqdq %xmm1, %xmm0");
    PUNPCKHQDQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "punpckhqdq (%rax), %xmm0");

    PUNPCKLQDQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "punpcklqdq %xmm1, %xmm0");
    PUNPCKLQDQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "punpcklqdq (%rax), %xmm0");

    ADDSUBPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "addsubps %xmm1, %xmm0");
    ADDSUBPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "addsubps (%rax), %xmm0");

    ADDSUBPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "addsubpd %xmm1, %xmm0");
    ADDSUBPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "addsubpd (%rax), %xmm0");

    HADDPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "haddps %xmm1, %xmm0");
    HADDPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "haddps (%rax), %xmm0");

    HSUBPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "hsubps %xmm1, %xmm0");
    HSUBPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "hsubps (%rax), %xmm0");

    HADDPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "haddpd %xmm1, %xmm0");
    HADDPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "haddpd (%rax), %xmm0");

    HSUBPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "hsubpd %xmm1, %xmm0");
    HSUBPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "hsubpd (%rax), %xmm0");

    MOVSHDUP(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "movshdup %xmm1, %xmm0");
    MOVSHDUP(XMM0, addr);
    EXPECT_EQ(asmstr(), "movshdup (%rax), %xmm0");

    MOVSLDUP(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "movsldup %xmm1, %xmm0");
    MOVSLDUP(XMM0, addr);
    EXPECT_EQ(asmstr(), "movsldup (%rax), %xmm0");

    PMULLD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmulld %xmm1, %xmm0");
    PMULLD(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmulld (%rax), %xmm0");

    PMULDQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmuldq %xmm1, %xmm0");
    PMULDQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmuldq (%rax), %xmm0");

    PMINUW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pminuw %xmm1, %xmm0");
    PMINUW(XMM0, addr);
    EXPECT_EQ(asmstr(), "pminuw (%rax), %xmm0");

    PMINUD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pminud %xmm1, %xmm0");
    PMINUD(XMM0, addr);
    EXPECT_EQ(asmstr(), "pminud (%rax), %xmm0");

    PMINSB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pminsb %xmm1, %xmm0");
    PMINSB(XMM0, addr);
    EXPECT_EQ(asmstr(), "pminsb (%rax), %xmm0");

    PMINSD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pminsd %xmm1, %xmm0");
    PMINSD(XMM0, addr);
    EXPECT_EQ(asmstr(), "pminsd (%rax), %xmm0");

    PMAXUW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmaxuw %xmm1, %xmm0");
    PMAXUW(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmaxuw (%rax), %xmm0");

    PMAXUD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmaxud %xmm1, %xmm0");
    PMAXUD(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmaxud (%rax), %xmm0");

    PMAXSB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmaxsb %xmm1, %xmm0");
    PMAXSB(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmaxsb (%rax), %xmm0");

    PMAXSD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmaxsd %xmm1, %xmm0");
    PMAXSD(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmaxsd (%rax), %xmm0");

    PCMPGTQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pcmpgtq %xmm1, %xmm0");
    PCMPGTQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "pcmpgtq (%rax), %xmm0");

    AESDEC(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "aesdec %xmm1, %xmm0");
    AESDEC(XMM0, addr);
    EXPECT_EQ(asmstr(), "aesdec (%rax), %xmm0");

    AESDECLAST(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "aesdeclast %xmm1, %xmm0");
    AESDECLAST(XMM0, addr);
    EXPECT_EQ(asmstr(), "aesdeclast (%rax), %xmm0");

    AESENC(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "aesenc %xmm1, %xmm0");
    AESENC(XMM0, addr);
    EXPECT_EQ(asmstr(), "aesenc (%rax), %xmm0");

    AESENCLAST(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "aesenclast %xmm1, %xmm0");
    AESENCLAST(XMM0, addr);
    EXPECT_EQ(asmstr(), "aesenclast (%rax), %xmm0");

    AESIMC(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "aesimc %xmm1, %xmm0");
    AESIMC(XMM0, addr);
    EXPECT_EQ(asmstr(), "aesimc (%rax), %xmm0");

    PHMINPOSUW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "phminposuw %xmm1, %xmm0");
    PHMINPOSUW(XMM0, addr);
    EXPECT_EQ(asmstr(), "phminposuw (%rax), %xmm0");

    PTEST(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "ptest %xmm1, %xmm0");
    PTEST(XMM0, addr);
    EXPECT_EQ(asmstr(), "ptest (%rax), %xmm0");

    PCMPEQQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pcmpeqq %xmm1, %xmm0");
    PCMPEQQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "pcmpeqq (%rax), %xmm0");

    PACKUSDW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "packusdw %xmm1, %xmm0");
    PACKUSDW(XMM0, addr);
    EXPECT_EQ(asmstr(), "packusdw (%rax), %xmm0");

    RSQRTPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "rsqrtps %xmm1, %xmm0");
    RSQRTPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "rsqrtps (%rax), %xmm0");

    SHA1MSG1(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "sha1msg1 %xmm1, %xmm0");
    SHA1MSG1(XMM0, addr);
    EXPECT_EQ(asmstr(), "sha1msg1 (%rax), %xmm0");

    SHA1MSG2(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "sha1msg2 %xmm1, %xmm0");
    SHA1MSG2(XMM0, addr);
    EXPECT_EQ(asmstr(), "sha1msg2 (%rax), %xmm0");

    SHA1NEXTE(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "sha1nexte %xmm1, %xmm0");
    SHA1NEXTE(XMM0, addr);
    EXPECT_EQ(asmstr(), "sha1nexte (%rax), %xmm0");

    SHA256MSG1(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "sha256msg1 %xmm1, %xmm0");
    SHA256MSG1(XMM0, addr);
    EXPECT_EQ(asmstr(), "sha256msg1 (%rax), %xmm0");

    SHA256MSG2(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "sha256msg2 %xmm1, %xmm0");
    SHA256MSG2(XMM0, addr);
    EXPECT_EQ(asmstr(), "sha256msg2 (%rax), %xmm0");
}

TEST(Instruction2, Type11)
{
    m32 addr { RAX };

    ADDSS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "addss %xmm1, %xmm0");
    ADDSS(XMM0, addr);
    EXPECT_EQ(asmstr(), "addss (%rax), %xmm0");

    SUBSS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "subss %xmm1, %xmm0");
    SUBSS(XMM0, addr);
    EXPECT_EQ(asmstr(), "subss (%rax), %xmm0");

    MULSS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "mulss %xmm1, %xmm0");
    MULSS(XMM0, addr);
    EXPECT_EQ(asmstr(), "mulss (%rax), %xmm0");

    DIVSS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "divss %xmm1, %xmm0");
    DIVSS(XMM0, addr);
    EXPECT_EQ(asmstr(), "divss (%rax), %xmm0");

    RCPSS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "rcpss %xmm1, %xmm0");
    RCPSS(XMM0, addr);
    EXPECT_EQ(asmstr(), "rcpss (%rax), %xmm0");

    SQRTSS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "sqrtss %xmm1, %xmm0");
    SQRTSS(XMM0, addr);
    EXPECT_EQ(asmstr(), "sqrtss (%rax), %xmm0");

    MAXSS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "maxss %xmm1, %xmm0");
    MAXSS(XMM0, addr);
    EXPECT_EQ(asmstr(), "maxss (%rax), %xmm0");

    MINSS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "minss %xmm1, %xmm0");
    MINSS(XMM0, addr);
    EXPECT_EQ(asmstr(), "minss (%rax), %xmm0");

    COMISS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "comiss %xmm1, %xmm0");
    COMISS(XMM0, addr);
    EXPECT_EQ(asmstr(), "comiss (%rax), %xmm0");

    UCOMISS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "ucomiss %xmm1, %xmm0");
    UCOMISS(XMM0, addr);
    EXPECT_EQ(asmstr(), "ucomiss (%rax), %xmm0");

    CVTSS2SD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "cvtss2sd %xmm1, %xmm0");
    CVTSS2SD(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvtss2sd (%rax), %xmm0");

    PMOVSXBD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovsxbd %xmm1, %xmm0");
    PMOVSXBD(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovsxbd (%rax), %xmm0");

    PMOVSXWQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovsxwq %xmm1, %xmm0");
    PMOVSXWQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovsxwq (%rax), %xmm0");

    PMOVZXBD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovzxbd %xmm1, %xmm0");
    PMOVZXBD(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovzxbd (%rax), %xmm0");

    PMOVZXWQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovzxwq %xmm1, %xmm0");
    PMOVZXWQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovzxwq (%rax), %xmm0");

    RSQRTSS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "rsqrtss %xmm1, %xmm0");
    RSQRTSS(XMM0, addr);
    EXPECT_EQ(asmstr(), "rsqrtss (%rax), %xmm0");
}

TEST(Instruction2, Type12)
{
    m128 addr { RAX };
    imm8 mask { 255 };

    CMPPS(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "cmpps $0xFF, %xmm1, %xmm0");
    CMPPS(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "cmpps $0xFF, (%rax), %xmm0");

    SHUFPS(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "shufps $0xFF, %xmm1, %xmm0");
    SHUFPS(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "shufps $0xFF, (%rax), %xmm0");

    CMPPD(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "cmppd $0xFF, %xmm1, %xmm0");
    CMPPD(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "cmppd $0xFF, (%rax), %xmm0");

    SHUFPD(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "shufpd $0xFF, %xmm1, %xmm0");
    SHUFPD(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "shufpd $0xFF, (%rax), %xmm0");

    PSHUFLW(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "pshuflw $0xFF, %xmm1, %xmm0");
    PSHUFLW(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pshuflw $0xFF, (%rax), %xmm0");

    PSHUFHW(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "pshufhw $0xFF, %xmm1, %xmm0");
    PSHUFHW(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pshufhw $0xFF, (%rax), %xmm0");

    PSHUFD(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "pshufd $0xFF, %xmm1, %xmm0");
    PSHUFD(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pshufd $0xFF, (%rax), %xmm0");

    DPPD(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "dppd $0xFF, %xmm1, %xmm0");
    DPPD(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "dppd $0xFF, (%rax), %xmm0");

    DPPS(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "dpps $0xFF, %xmm1, %xmm0");
    DPPS(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "dpps $0xFF, (%rax), %xmm0");

    BLENDPD(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "blendpd $0xFF, %xmm1, %xmm0");
    BLENDPD(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "blendpd $0xFF, (%rax), %xmm0");

    BLENDPS(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "blendps $0xFF, %xmm1, %xmm0");
    BLENDPS(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "blendps $0xFF, (%rax), %xmm0");

    PBLENDW(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "pblendw $0xFF, %xmm1, %xmm0");
    PBLENDW(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pblendw $0xFF, (%rax), %xmm0");

    ROUNDPS(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "roundps $0xFF, %xmm1, %xmm0");
    ROUNDPS(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "roundps $0xFF, (%rax), %xmm0");

    ROUNDPD(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "roundpd $0xFF, %xmm1, %xmm0");
    ROUNDPD(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "roundpd $0xFF, (%rax), %xmm0");

    MPSADBW(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "mpsadbw $0xFF, %xmm1, %xmm0");
    MPSADBW(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "mpsadbw $0xFF, (%rax), %xmm0");

    PCMPESTRI(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "pcmpestri $0xFF, %xmm1, %xmm0");
    PCMPESTRI(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pcmpestri $0xFF, (%rax), %xmm0");

    PCMPESTRM(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "pcmpestrm $0xFF, %xmm1, %xmm0");
    PCMPESTRM(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pcmpestrm $0xFF, (%rax), %xmm0");

    PCMPISTRI(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "pcmpistri $0xFF, %xmm1, %xmm0");
    PCMPISTRI(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pcmpistri $0xFF, (%rax), %xmm0");

    PCMPISTRM(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "pcmpistrm $0xFF, %xmm1, %xmm0");
    PCMPISTRM(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pcmpistrm $0xFF, (%rax), %xmm0");

    AESKEYGENASSIST(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "aeskeygenassist $0xFF, %xmm1, %xmm0");
    AESKEYGENASSIST(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "aeskeygenassist $0xFF, (%rax), %xmm0");

    PCLMULQDQ(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "pclmulqdq $0xFF, %xmm1, %xmm0");
    PCLMULQDQ(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pclmulqdq $0xFF, (%rax), %xmm0");
}

TEST(Instruction2, Type13)
{
    m32 addr { RAX };
    imm8 mask { 255 };

    CMPSS(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "cmpss $0xFF, %xmm1, %xmm0");
    CMPSS(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "cmpss $0xFF, (%rax), %xmm0");

    ROUNDSS(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "roundss $0xFF, %xmm1, %xmm0");
    ROUNDSS(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "roundss $0xFF, (%rax), %xmm0");

    INSERTPS(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "insertps $0xFF, %xmm1, %xmm0");
    INSERTPS(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "insertps $0xFF, (%rax), %xmm0");
}

TEST(Instruction2, Type14)
{
    m64 addr { RAX };

    ADDSD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "addsd %xmm1, %xmm0");
    ADDSD(XMM0, addr);
    EXPECT_EQ(asmstr(), "addsd (%rax), %xmm0");

    SUBSD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "subsd %xmm1, %xmm0");
    SUBSD(XMM0, addr);
    EXPECT_EQ(asmstr(), "subsd (%rax), %xmm0");

    MULSD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "mulsd %xmm1, %xmm0");
    MULSD(XMM0, addr);
    EXPECT_EQ(asmstr(), "mulsd (%rax), %xmm0");

    DIVSD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "divsd %xmm1, %xmm0");
    DIVSD(XMM0, addr);
    EXPECT_EQ(asmstr(), "divsd (%rax), %xmm0");

    SQRTSD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "sqrtsd %xmm1, %xmm0");
    SQRTSD(XMM0, addr);
    EXPECT_EQ(asmstr(), "sqrtsd (%rax), %xmm0");

    MAXSD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "maxsd %xmm1, %xmm0");
    MAXSD(XMM0, addr);
    EXPECT_EQ(asmstr(), "maxsd (%rax), %xmm0");

    MINSD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "minsd %xmm1, %xmm0");
    MINSD(XMM0, addr);
    EXPECT_EQ(asmstr(), "minsd (%rax), %xmm0");

    COMISD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "comisd %xmm1, %xmm0");
    COMISD(XMM0, addr);
    EXPECT_EQ(asmstr(), "comisd (%rax), %xmm0");

    UCOMISD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "ucomisd %xmm1, %xmm0");
    UCOMISD(XMM0, addr);
    EXPECT_EQ(asmstr(), "ucomisd (%rax), %xmm0");

    CVTDQ2PD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "cvtdq2pd %xmm1, %xmm0");
    CVTDQ2PD(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvtdq2pd (%rax), %xmm0");

    CVTPS2PD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "cvtps2pd %xmm1, %xmm0");
    CVTPS2PD(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvtps2pd (%rax), %xmm0");

    CVTSD2SS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "cvtsd2ss %xmm1, %xmm0");
    CVTSD2SS(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvtsd2ss (%rax), %xmm0");

    MOVDDUP(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "movddup %xmm1, %xmm0");
    MOVDDUP(XMM0, addr);
    EXPECT_EQ(asmstr(), "movddup (%rax), %xmm0");

    PMOVSXBW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovsxbw %xmm1, %xmm0");
    PMOVSXBW(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovsxbw (%rax), %xmm0");

    PMOVSXWD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovsxwd %xmm1, %xmm0");
    PMOVSXWD(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovsxwd (%rax), %xmm0");

    PMOVSXDQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovsxdq %xmm1, %xmm0");
    PMOVSXDQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovsxdq (%rax), %xmm0");

    PMOVZXBW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovzxbw %xmm1, %xmm0");
    PMOVZXBW(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovzxbw (%rax), %xmm0");

    PMOVZXWD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovzxwd %xmm1, %xmm0");
    PMOVZXWD(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovzxwd (%rax), %xmm0");

    PMOVZXDQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovzxdq %xmm1, %xmm0");
    PMOVZXDQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovzxdq (%rax), %xmm0");
}

TEST(Instruction2, Type15)
{
    m64 addr { RAX };
    imm8 mask { 255 };

    CMPSD_SSE2(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "cmpsd $0xFF, %xmm1, %xmm0");
    CMPSD_SSE2(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "cmpsd $0xFF, (%rax), %xmm0");

    ROUNDSD(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "roundsd $0xFF, %xmm1, %xmm0");
    ROUNDSD(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "roundsd $0xFF, (%rax), %xmm0");
}

TEST(Instruction2, Type16)
{
    m16 addr1 { RAX };
    m32 addr2 { RBX };

    FIST(addr1);
    EXPECT_EQ(asmstr(), "fist (%rax)");
    FIST(addr2);
    EXPECT_EQ(asmstr(), "fistl (%rbx)");

    FIADD(addr1);
    EXPECT_EQ(asmstr(), "fiadd (%rax)");
    FIADD(addr2);
    EXPECT_EQ(asmstr(), "fiaddl (%rbx)");

    FISUB(addr1);
    EXPECT_EQ(asmstr(), "fisub (%rax)");
    FISUB(addr2);
    EXPECT_EQ(asmstr(), "fisubl (%rbx)");

    FISUBR(addr1);
    EXPECT_EQ(asmstr(), "fisubr (%rax)");
    FISUBR(addr2);
    EXPECT_EQ(asmstr(), "fisubrl (%rbx)");

    FIMUL(addr1);
    EXPECT_EQ(asmstr(), "fimul (%rax)");
    FIMUL(addr2);
    EXPECT_EQ(asmstr(), "fimull (%rbx)");

    FIDIV(addr1);
    EXPECT_EQ(asmstr(), "fidiv (%rax)");
    FIDIV(addr2);
    EXPECT_EQ(asmstr(), "fidivl (%rbx)");

    FIDIVR(addr1);
    EXPECT_EQ(asmstr(), "fidivr (%rax)");
    FIDIVR(addr2);
    EXPECT_EQ(asmstr(), "fidivrl (%rbx)");

    FICOM(addr1);
    EXPECT_EQ(asmstr(), "ficom (%rax)");
    FICOM(addr2);
    EXPECT_EQ(asmstr(), "ficoml (%rbx)");

    FICOMP(addr1);
    EXPECT_EQ(asmstr(), "ficomp (%rax)");
    FICOMP(addr2);
    EXPECT_EQ(asmstr(), "ficompl (%rbx)");
}

TEST(Instruction2, Type17)
{
    m64 addr { RAX };

    CVTPI2PS(XMM0, MM0);
    EXPECT_EQ(asmstr(), "cvtpi2ps %mm0, %xmm0");
    CVTPI2PS(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvtpi2ps (%rax), %xmm0");

    CVTPI2PD(XMM0, MM0);
    EXPECT_EQ(asmstr(), "cvtpi2pd %mm0, %xmm0");
    CVTPI2PD(XMM0, addr);
    EXPECT_EQ(asmstr(), "cvtpi2pd (%rax), %xmm0");
}

TEST(Instruction2, Type18)
{
    m64 addr { RAX };

    CVTPS2PI(MM0, XMM0);
    EXPECT_EQ(asmstr(), "cvtps2pi %xmm0, %mm0");
    CVTPS2PI(MM0, addr);
    EXPECT_EQ(asmstr(), "cvtps2pi (%rax), %mm0");

    CVTTPS2PI(MM0, XMM0);
    EXPECT_EQ(asmstr(), "cvttps2pi %xmm0, %mm0");
    CVTTPS2PI(MM0, addr);
    EXPECT_EQ(asmstr(), "cvttps2pi (%rax), %mm0");
}

TEST(Instruction2, Type19)
{
    m128 addr { RAX };

    CVTPD2PI(MM0, XMM0);
    EXPECT_EQ(asmstr(), "cvtpd2pi %xmm0, %mm0");
    CVTPD2PI(MM0, addr);
    EXPECT_EQ(asmstr(), "cvtpd2pi (%rax), %mm0");

    CVTTPD2PI(MM0, XMM0);
    EXPECT_EQ(asmstr(), "cvttpd2pi %xmm0, %mm0");
    CVTTPD2PI(MM0, addr);
    EXPECT_EQ(asmstr(), "cvttpd2pi (%rax), %mm0");
}

TEST(Instruction2, Type20)
{
    FADDP();
    EXPECT_EQ(asmstr(), "faddp");
    FADDP(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "faddp %st(0), %st(1)");

    FSUBP();
    EXPECT_EQ(asmstr(), "fsubp");
    FSUBP(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "fsubp %st(0), %st(1)");

    FSUBRP();
    EXPECT_EQ(asmstr(), "fsubrp");
    FSUBRP(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "fsubrp %st(0), %st(1)");

    FMULP();
    EXPECT_EQ(asmstr(), "fmulp");
    FMULP(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "fmulp %st(0), %st(1)");

    FDIVP();
    EXPECT_EQ(asmstr(), "fdivp");
    FDIVP(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "fdivp %st(0), %st(1)");

    FDIVRP();
    EXPECT_EQ(asmstr(), "fdivrp");
    FDIVRP(ST(1), ST(0));
    EXPECT_EQ(asmstr(), "fdivrp %st(0), %st(1)");
}

TEST(Instruction2, Type21)
{
    m64 addr { RAX };
    imm8 mask { 255 };

    PSHUFW(MM0, MM1, mask);
    EXPECT_EQ(asmstr(), "pshufw $0xFF, %mm1, %mm0");
    PSHUFW(MM0, addr, mask);
    EXPECT_EQ(asmstr(), "pshufw $0xFF, (%rax), %mm0");
}

TEST(Instruction2, Type22)
{
    m32 addr1 { RAX };
    m64 addr2 { RBX };

    MOVNTI(addr1, ECX);
    EXPECT_EQ(asmstr(), "movnti %ecx, (%rax)");
    MOVNTI(addr2, RCX);
    EXPECT_EQ(asmstr(), "movnti %rcx, (%rbx)");
}

TEST(Instruction2, Type23)
{
    m8 addr { RAX };
    imm8 mask { 255 };

    PINSRB(XMM0, EAX, mask);
    EXPECT_EQ(asmstr(), "pinsrb $0xFF, %eax, %xmm0");
    PINSRB(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pinsrb $0xFF, (%rax), %xmm0");
}

TEST(Instruction2, Type24)
{
    m32 addr { RBX };
    imm8 mask { 255 };

    PINSRD(XMM0, EAX, mask);
    EXPECT_EQ(asmstr(), "pinsrd $0xFF, %eax, %xmm0");
    PINSRD(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pinsrd $0xFF, (%rbx), %xmm0");
}

TEST(Instruction2, Type25)
{
    m64 addr { RBX };
    imm8 mask { 255 };

    PINSRQ(XMM0, RAX, mask);
    EXPECT_EQ(asmstr(), "pinsrq $0xFF, %rax, %xmm0");
    PINSRQ(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pinsrq $0xFF, (%rbx), %xmm0");
}

TEST(Instruction2, Type26)
{
    m64 addr { RBX };
    imm8 mask { 255 };

    PEXTRQ(RAX, XMM1, mask);
    EXPECT_EQ(asmstr(), "pextrq $0xFF, %xmm1, %rax");
    PEXTRQ(addr, XMM1, mask);
    EXPECT_EQ(asmstr(), "pextrq $0xFF, %xmm1, (%rbx)");
}

TEST(Instruction2, Type27)
{
    m16 addr { RAX };

    PMOVSXBQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovsxbq %xmm1, %xmm0");
    PMOVSXBQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovsxbq (%rax), %xmm0");

    PMOVZXBQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmovzxbq %xmm1, %xmm0");
    PMOVZXBQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "pmovzxbq (%rax), %xmm0");
}

TEST(Instruction2, Type28)
{
    m64 addr { RAX };

    VFMADD132SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd132sd %xmm2, %xmm1, %xmm0");
    VFMADD132SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmadd132sd (%rax), %xmm1, %xmm0");

    VFMADD213SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd213sd %xmm2, %xmm1, %xmm0");
    VFMADD213SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmadd213sd (%rax), %xmm1, %xmm0");

    VFMADD231SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd231sd %xmm2, %xmm1, %xmm0");
    VFMADD231SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmadd231sd (%rax), %xmm1, %xmm0");

    VFMSUB132SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub132sd %xmm2, %xmm1, %xmm0");
    VFMSUB132SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmsub132sd (%rax), %xmm1, %xmm0");

    VFMSUB213SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub213sd %xmm2, %xmm1, %xmm0");
    VFMSUB213SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmsub213sd (%rax), %xmm1, %xmm0");

    VFMSUB231SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub231sd %xmm2, %xmm1, %xmm0");
    VFMSUB231SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmsub231sd (%rax), %xmm1, %xmm0");

    VFNMADD132SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd132sd %xmm2, %xmm1, %xmm0");
    VFNMADD132SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmadd132sd (%rax), %xmm1, %xmm0");

    VFNMADD213SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd213sd %xmm2, %xmm1, %xmm0");
    VFNMADD213SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmadd213sd (%rax), %xmm1, %xmm0");

    VFNMADD231SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd231sd %xmm2, %xmm1, %xmm0");
    VFNMADD231SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmadd231sd (%rax), %xmm1, %xmm0");

    VFNMSUB132SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub132sd %xmm2, %xmm1, %xmm0");
    VFNMSUB132SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmsub132sd (%rax), %xmm1, %xmm0");

    VFNMSUB213SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub213sd %xmm2, %xmm1, %xmm0");
    VFNMSUB213SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmsub213sd (%rax), %xmm1, %xmm0");

    VFNMSUB231SD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub231sd %xmm2, %xmm1, %xmm0");
    VFNMSUB231SD(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmsub231sd (%rax), %xmm1, %xmm0");
}

TEST(Instruction2, Type29)
{
    m32 addr { RAX };

    VFMADD132SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd132ss %xmm2, %xmm1, %xmm0");
    VFMADD132SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmadd132ss (%rax), %xmm1, %xmm0");

    VFMADD213SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd213ss %xmm2, %xmm1, %xmm0");
    VFMADD213SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmadd213ss (%rax), %xmm1, %xmm0");

    VFMADD231SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd231ss %xmm2, %xmm1, %xmm0");
    VFMADD231SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmadd231ss (%rax), %xmm1, %xmm0");

    VFMSUB132SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub132ss %xmm2, %xmm1, %xmm0");
    VFMSUB132SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmsub132ss (%rax), %xmm1, %xmm0");

    VFMSUB213SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub213ss %xmm2, %xmm1, %xmm0");
    VFMSUB213SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmsub213ss (%rax), %xmm1, %xmm0");

    VFMSUB231SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub231ss %xmm2, %xmm1, %xmm0");
    VFMSUB231SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfmsub231ss (%rax), %xmm1, %xmm0");

    VFNMADD132SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd132ss %xmm2, %xmm1, %xmm0");
    VFNMADD132SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmadd132ss (%rax), %xmm1, %xmm0");

    VFNMADD213SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd213ss %xmm2, %xmm1, %xmm0");
    VFNMADD213SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmadd213ss (%rax), %xmm1, %xmm0");

    VFNMADD231SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd231ss %xmm2, %xmm1, %xmm0");
    VFNMADD231SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmadd231ss (%rax), %xmm1, %xmm0");

    VFNMSUB132SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub132ss %xmm2, %xmm1, %xmm0");
    VFNMSUB132SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmsub132ss (%rax), %xmm1, %xmm0");

    VFNMSUB213SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub213ss %xmm2, %xmm1, %xmm0");
    VFNMSUB213SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmsub213ss (%rax), %xmm1, %xmm0");

    VFNMSUB231SS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub231ss %xmm2, %xmm1, %xmm0");
    VFNMSUB231SS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vfnmsub231ss (%rax), %xmm1, %xmm0");

    VRSQRTSS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vrsqrtss %xmm2, %xmm1, %xmm0");
    VRSQRTSS(XMM0, XMM1, addr);
    EXPECT_EQ(asmstr(), "vrsqrtss (%rax), %xmm1, %xmm0");
}

TEST(Instruction2, Type30)
{
    imm8 mask { 255 };
    m128 addr { RAX };

    VDPPD(XMM0, XMM1, XMM2, mask);
    EXPECT_EQ(asmstr(), "vdppd $0xFF, %xmm2, %xmm1, %xmm0");
    VDPPD(XMM0, XMM1, addr, mask);
    EXPECT_EQ(asmstr(), "vdppd $0xFF, (%rax), %xmm1, %xmm0");
}

TEST(Instruction2, Type31)
{
    m128 addr1 { RAX };
    m256 addr2 { RBX };

    VLDDQU(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vlddqu (%rax), %xmm0");
    VLDDQU(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vlddqu (%rbx), %ymm0");

    VMOVNTDQA(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vmovntdqa (%rax), %xmm0");
    VMOVNTDQA(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vmovntdqa (%rbx), %ymm0");
}

TEST(Instruction2, Test32)
{
    m128 addr1 { RAX };
    m256 addr2 { RBX };

    VMOVNTPS(addr1, XMM0);
    EXPECT_EQ(asmstr(), "vmovntps %xmm0, (%rax)");
    VMOVNTPS(addr2, YMM0);
    EXPECT_EQ(asmstr(), "vmovntps %ymm0, (%rbx)");

    VMOVNTDQ(addr1, XMM0);
    EXPECT_EQ(asmstr(), "vmovntdq %xmm0, (%rax)");
    VMOVNTDQ(addr2, YMM0);
    EXPECT_EQ(asmstr(), "vmovntdq %ymm0, (%rbx)");
}

TEST(Instruction2, Type33)
{
    imm8 mask { 255 };
    m256 addr { RBX };

    VEXTRACTF32X8(YMM0, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextractf32x8 $0xFF, %zmm0, %ymm0");
    VEXTRACTF32X8(YMM0.k1, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextractf32x8 $0xFF, %zmm0, %ymm0{%k1}");
    VEXTRACTF32X8(YMM0.k1.z, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextractf32x8 $0xFF, %zmm0, %ymm0{%k1}{z}");
    VEXTRACTF32X8(addr, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextractf32x8 $0xFF, %zmm0, (%rbx)");

    VEXTRACTF64X4(YMM0, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextractf64x4 $0xFF, %zmm0, %ymm0");
    VEXTRACTF64X4(YMM0.k1, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextractf64x4 $0xFF, %zmm0, %ymm0{%k1}");
    VEXTRACTF64X4(YMM0.k1.z, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextractf64x4 $0xFF, %zmm0, %ymm0{%k1}{z}");
    VEXTRACTF64X4(addr, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextractf64x4 $0xFF, %zmm0, (%rbx)");

    VEXTRACTI32X8(YMM0, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextracti32x8 $0xFF, %zmm0, %ymm0");
    VEXTRACTI32X8(YMM0.k1, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextracti32x8 $0xFF, %zmm0, %ymm0{%k1}");
    VEXTRACTI32X8(YMM0.k1.z, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextracti32x8 $0xFF, %zmm0, %ymm0{%k1}{z}");
    VEXTRACTI32X8(addr, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextracti32x8 $0xFF, %zmm0, (%rbx)");

    VEXTRACTI64X4(YMM0, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextracti64x4 $0xFF, %zmm0, %ymm0");
    VEXTRACTI64X4(YMM0.k1, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextracti64x4 $0xFF, %zmm0, %ymm0{%k1}");
    VEXTRACTI64X4(YMM0.k1.z, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextracti64x4 $0xFF, %zmm0, %ymm0{%k1}{z}");
    VEXTRACTI64X4(addr, ZMM0, mask);
    EXPECT_EQ(asmstr(), "vextracti64x4 $0xFF, %zmm0, (%rbx)");
}

TEST(Instruction2, Type34)
{
    imm8 mask { 255 };
    m128 addr { RAX };

    VEXTRACTF128(XMM0, YMM0, mask);
    EXPECT_EQ(asmstr(), "vextractf128 $0xFF, %ymm0, %xmm0");
    VEXTRACTF128(addr, YMM0, mask);
    EXPECT_EQ(asmstr(), "vextractf128 $0xFF, %ymm0, (%rax)");

    VEXTRACTI128(XMM0, YMM0, mask);
    EXPECT_EQ(asmstr(), "vextracti128 $0xFF, %ymm0, %xmm0");
    VEXTRACTI128(addr, YMM0, mask);
    EXPECT_EQ(asmstr(), "vextracti128 $0xFF, %ymm0, (%rax)");
}

TEST(Instruction2, Type35)
{
    imm8 mask { 255 };
    m128 addr { RAX };

    VINSERTF128(YMM0, YMM1, XMM0, mask);
    EXPECT_EQ(asmstr(), "vinsertf128 $0xFF, %xmm0, %ymm1, %ymm0");
    VINSERTF128(YMM0, YMM1, addr, mask);
    EXPECT_EQ(asmstr(), "vinsertf128 $0xFF, (%rax), %ymm1, %ymm0");

    VINSERTI128(YMM0, YMM1, XMM0, mask);
    EXPECT_EQ(asmstr(), "vinserti128 $0xFF, %xmm0, %ymm1, %ymm0");
    VINSERTI128(YMM0, YMM1, addr, mask);
    EXPECT_EQ(asmstr(), "vinserti128 $0xFF, (%rax), %ymm1, %ymm0");
}

TEST(Instruction2, Type36)
{
    imm8 mask { 255 };
    m256 addr { RAX };

    VPERM2F128(YMM0, YMM1, YMM2, mask);
    EXPECT_EQ(asmstr(), "vperm2f128 $0xFF, %ymm2, %ymm1, %ymm0");
    VPERM2F128(YMM0, YMM1, addr, mask);
    EXPECT_EQ(asmstr(), "vperm2f128 $0xFF, (%rax), %ymm1, %ymm0");
}

TEST(Instruction2, AllTypes)
{
    gen_Instruction2_Type37(PEXTRD);

    gen_Instruction2_Type38(SHA256RNDS2);

    gen_Instruction2_Type39(INVEPT);
    gen_Instruction2_Type39(INVVPID);

    gen_Instruction2_Type40(VMCLEAR);
    gen_Instruction2_Type40(VMPTRLD);
    gen_Instruction2_Type40(VMPTRST);

    gen_Instruction2_Type41(VBROADCASTF32X4);
    gen_Instruction2_Type41(VBROADCASTF64X2);
    gen_Instruction2_Type41(VBROADCASTI32X4);
    gen_Instruction2_Type41(VBROADCASTI64X2);

    gen_Instruction2_Type42(VINSERTI32X8);
    gen_Instruction2_Type42(VINSERTI64X4);
}
