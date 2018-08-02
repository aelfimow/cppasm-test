#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

static void gen_Instruction2_Type9(Instruction2_Type9 &instr)
{
    m64 addr { RAX };
    instr(XMM0, addr);
    instr(addr, XMM0);
}

static void gen_Instruction2_Type10(Instruction2_Type10 &instr)
{
    m128 addr { RAX };
    instr(XMM0, XMM1);
    instr(XMM0, addr);
}

static void gen_Instruction2_Type11(Instruction2_Type11 &instr)
{
    m32 addr { RAX };
    instr(XMM0, XMM1);
    instr(XMM0, addr);
}

static void gen_Instruction2_Type12(Instruction2_Type12 &instr)
{
    m128 addr { RAX };
    imm8 mask { 255 };
    instr(XMM0, XMM1, mask);
    instr(XMM0, addr, mask);
}

static void gen_Instruction2_Type13(Instruction2_Type13 &instr)
{
    m32 addr { RAX };
    imm8 mask { 255 };
    instr(XMM0, XMM1, mask);
    instr(XMM0, addr, mask);
}

static void gen_Instruction2_Type14(Instruction2_Type14 &instr)
{
    m64 addr { RAX };
    instr(XMM0, XMM1);
    instr(XMM0, addr);
}

static void gen_Instruction2_Type15(Instruction2_Type15 &instr)
{
    m64 addr { RAX };
    imm8 mask { 255 };
    instr(XMM0, XMM1, mask);
    instr(XMM0, addr, mask);
}

static void gen_Instruction2_Type16(Instruction2_Type16 &instr)
{
    m16 addr1 { RAX };
    m32 addr2 { RBX };
    instr(addr1);
    instr(addr2);
}

static void gen_Instruction2_Type17(Instruction2_Type17 &instr)
{
    m64 addr { RAX };
    instr(XMM0, MM0);
    instr(XMM0, addr);
}

static void gen_Instruction2_Type18(Instruction2_Type18 &instr)
{
    m64 addr { RAX };
    instr(MM0, XMM0);
    instr(MM0, addr);
}

static void gen_Instruction2_Type19(Instruction2_Type19 &instr)
{
    m128 addr { RAX };
    instr(MM0, XMM0);
    instr(MM0, addr);
}

static void gen_Instruction2_Type20(Instruction2_Type20 &instr)
{
    instr();
    instr(ST(1), ST(0));
}

static void gen_Instruction2_Type21(Instruction2_Type21 &instr)
{
    m64 addr { RAX };
    imm8 mask { 255 };
    instr(MM0, MM1, mask);
    instr(MM0, addr, mask);
}

static void gen_Instruction2_Type22(Instruction2_Type22 &instr)
{
    m32 addr1 { RAX };
    m64 addr2 { RBX };
    instr(addr1, ECX);
    instr(addr2, RCX);
}

static void gen_Instruction2_Type23(Instruction2_Type23 &instr)
{
    m8 addr { RAX };
    imm8 mask { 255 };
    instr(XMM0, EAX, mask);
    instr(XMM0, addr, mask);
}

static void gen_Instruction2_Type24(Instruction2_Type24 &instr)
{
    m32 addr { RBX };
    imm8 mask { 255 };
    instr(XMM0, EAX, mask);
    instr(XMM0, addr, mask);
}

static void gen_Instruction2_Type25(Instruction2_Type25 &instr)
{
    m64 addr { RBX };
    imm8 mask { 255 };
    instr(XMM0, RAX, mask);
    instr(XMM0, addr, mask);
}

static void gen_Instruction2_Type26(Instruction2_Type26 &instr)
{
    m64 addr { RBX };
    imm8 mask { 255 };
    instr(RAX, XMM1, mask);
    instr(addr, XMM1, mask);
}

static void gen_Instruction2_Type27(Instruction2_Type27 &instr)
{
    m16 addr { RAX };
    instr(XMM0, XMM1);
    instr(XMM0, addr);
}

static void gen_Instruction2_Type28(Instruction2_Type28 &instr)
{
    m64 addr { RAX };
    instr(XMM0, XMM1, XMM2);
    instr(XMM0, XMM1, addr);
}

static void gen_Instruction2_Type29(Instruction2_Type29 &instr)
{
    m32 addr { RAX };
    instr(XMM0, XMM1, XMM2);
    instr(XMM0, XMM1, addr);
}

static void gen_Instruction2_Type30(Instruction2_Type30 &instr)
{
    imm8 mask { 255 };
    m128 addr { RAX };
    instr(XMM0, XMM1, XMM2, mask);
    instr(XMM0, XMM1, addr, mask);
}

static void gen_Instruction2_Type31(Instruction2_Type31 &instr)
{
    m128 addr1 { RAX };
    m256 addr2 { RBX };
    instr(XMM0, addr1);
    instr(YMM0, addr2);
}

static void gen_Instruction2_Type32(Instruction2_Type32 &instr)
{
    m128 addr1 { RAX };
    m256 addr2 { RBX };
    instr(addr1, XMM0);
    instr(addr2, YMM0);
}

static void gen_Instruction2_Type33(Instruction2_Type33 &instr)
{
    imm8 mask { 255 };
    m256 addr { RBX };
    instr(YMM0, ZMM0, mask);
    instr(YMM0.k1, ZMM0, mask);
    instr(YMM0.k1.z, ZMM0, mask);
    instr(addr, ZMM0, mask);
}

static void gen_Instruction2_Type34(Instruction2_Type34 &instr)
{
    imm8 mask { 255 };
    m128 addr { RAX };
    instr(XMM0, YMM0, mask);
    instr(addr, YMM0, mask);
}

static void gen_Instruction2_Type35(Instruction2_Type35 &instr)
{
    imm8 mask { 255 };
    m128 addr { RAX };
    instr(YMM0, YMM1, XMM0, mask);
    instr(YMM0, YMM1, addr, mask);
}

static void gen_Instruction2_Type36(Instruction2_Type36 &instr)
{
    imm8 mask { 255 };
    m256 addr { RAX };
    instr(YMM0, YMM1, YMM2, mask);
    instr(YMM0, YMM1, addr, mask);
}

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

TEST(Instruction2, AllTypes)
{
    gen_Instruction2_Type9(MOVHPS);
    gen_Instruction2_Type9(MOVLPS);

    gen_Instruction2_Type10(ADDPS);
    gen_Instruction2_Type10(SUBPS);
    gen_Instruction2_Type10(MULPS);
    gen_Instruction2_Type10(DIVPS);
    gen_Instruction2_Type10(RCPPS);
    gen_Instruction2_Type10(SQRTPS);
    gen_Instruction2_Type10(MAXPS);
    gen_Instruction2_Type10(MINPS);
    gen_Instruction2_Type10(ANDPS);
    gen_Instruction2_Type10(ANDNPS);
    gen_Instruction2_Type10(ORPS);
    gen_Instruction2_Type10(XORPS);
    gen_Instruction2_Type10(UNPCKHPS);
    gen_Instruction2_Type10(UNPCKLPS);
    gen_Instruction2_Type10(ADDPD);
    gen_Instruction2_Type10(SUBPD);
    gen_Instruction2_Type10(MULPD);
    gen_Instruction2_Type10(DIVPD);
    gen_Instruction2_Type10(SQRTPD);
    gen_Instruction2_Type10(MAXPD);
    gen_Instruction2_Type10(MINPD);
    gen_Instruction2_Type10(ANDPD);
    gen_Instruction2_Type10(ANDNPD);
    gen_Instruction2_Type10(ORPD);
    gen_Instruction2_Type10(XORPD);
    gen_Instruction2_Type10(UNPCKHPD);
    gen_Instruction2_Type10(UNPCKLPD);
    gen_Instruction2_Type10(CVTPD2DQ);
    gen_Instruction2_Type10(CVTTPD2DQ);
    gen_Instruction2_Type10(CVTPD2PS);
    gen_Instruction2_Type10(CVTDQ2PS);
    gen_Instruction2_Type10(CVTPS2DQ);
    gen_Instruction2_Type10(CVTTPS2DQ);
    gen_Instruction2_Type10(PUNPCKHQDQ);
    gen_Instruction2_Type10(PUNPCKLQDQ);
    gen_Instruction2_Type10(ADDSUBPS);
    gen_Instruction2_Type10(ADDSUBPD);
    gen_Instruction2_Type10(HADDPS);
    gen_Instruction2_Type10(HSUBPS);
    gen_Instruction2_Type10(HADDPD);
    gen_Instruction2_Type10(HSUBPD);
    gen_Instruction2_Type10(MOVSHDUP);
    gen_Instruction2_Type10(MOVSLDUP);
    gen_Instruction2_Type10(PMULLD);
    gen_Instruction2_Type10(PMULDQ);
    gen_Instruction2_Type10(PMINUW);
    gen_Instruction2_Type10(PMINUD);
    gen_Instruction2_Type10(PMINSB);
    gen_Instruction2_Type10(PMINSD);
    gen_Instruction2_Type10(PMAXUW);
    gen_Instruction2_Type10(PMAXUD);
    gen_Instruction2_Type10(PMAXSB);
    gen_Instruction2_Type10(PMAXSD);
    gen_Instruction2_Type10(PCMPGTQ);
    gen_Instruction2_Type10(AESDEC);
    gen_Instruction2_Type10(AESDECLAST);
    gen_Instruction2_Type10(AESENC);
    gen_Instruction2_Type10(AESENCLAST);
    gen_Instruction2_Type10(AESIMC);
    gen_Instruction2_Type10(PHMINPOSUW);
    gen_Instruction2_Type10(PTEST);
    gen_Instruction2_Type10(PCMPEQQ);
    gen_Instruction2_Type10(PACKUSDW);
    gen_Instruction2_Type10(RSQRTPS);

    gen_Instruction2_Type10(SHA1MSG1);
    gen_Instruction2_Type10(SHA1MSG2);
    gen_Instruction2_Type10(SHA1NEXTE);
    gen_Instruction2_Type10(SHA256MSG1);
    gen_Instruction2_Type10(SHA256MSG2);

    gen_Instruction2_Type11(ADDSS);
    gen_Instruction2_Type11(SUBSS);
    gen_Instruction2_Type11(MULSS);
    gen_Instruction2_Type11(DIVSS);
    gen_Instruction2_Type11(RCPSS);
    gen_Instruction2_Type11(SQRTSS);
    gen_Instruction2_Type11(MAXSS);
    gen_Instruction2_Type11(MINSS);
    gen_Instruction2_Type11(COMISS);
    gen_Instruction2_Type11(UCOMISS);
    gen_Instruction2_Type11(CVTSS2SD);
    gen_Instruction2_Type11(PMOVSXBD);
    gen_Instruction2_Type11(PMOVSXWQ);
    gen_Instruction2_Type11(PMOVZXBD);
    gen_Instruction2_Type11(PMOVZXWQ);
    gen_Instruction2_Type11(RSQRTSS);

    gen_Instruction2_Type12(CMPPS);
    gen_Instruction2_Type12(SHUFPS);
    gen_Instruction2_Type12(CMPPD);
    gen_Instruction2_Type12(SHUFPD);
    gen_Instruction2_Type12(PSHUFLW);
    gen_Instruction2_Type12(PSHUFHW);
    gen_Instruction2_Type12(PSHUFD);
    gen_Instruction2_Type12(DPPD);
    gen_Instruction2_Type12(DPPS);
    gen_Instruction2_Type12(BLENDPD);
    gen_Instruction2_Type12(BLENDPS);
    gen_Instruction2_Type12(PBLENDW);
    gen_Instruction2_Type12(ROUNDPS);
    gen_Instruction2_Type12(ROUNDPD);
    gen_Instruction2_Type12(MPSADBW);
    gen_Instruction2_Type12(PCMPESTRI);
    gen_Instruction2_Type12(PCMPESTRM);
    gen_Instruction2_Type12(PCMPISTRI);
    gen_Instruction2_Type12(PCMPISTRM);
    gen_Instruction2_Type12(AESKEYGENASSIST);
    gen_Instruction2_Type12(PCLMULQDQ);

    gen_Instruction2_Type13(CMPSS);
    gen_Instruction2_Type13(ROUNDSS);
    gen_Instruction2_Type13(INSERTPS);

    gen_Instruction2_Type14(ADDSD);
    gen_Instruction2_Type14(SUBSD);
    gen_Instruction2_Type14(MULSD);
    gen_Instruction2_Type14(DIVSD);
    gen_Instruction2_Type14(SQRTSD);
    gen_Instruction2_Type14(MAXSD);
    gen_Instruction2_Type14(MINSD);
    gen_Instruction2_Type14(COMISD);
    gen_Instruction2_Type14(UCOMISD);
    gen_Instruction2_Type14(CVTDQ2PD);
    gen_Instruction2_Type14(CVTPS2PD);
    gen_Instruction2_Type14(CVTSD2SS);
    gen_Instruction2_Type14(MOVDDUP);
    gen_Instruction2_Type14(PMOVSXBW);
    gen_Instruction2_Type14(PMOVSXWD);
    gen_Instruction2_Type14(PMOVSXDQ);
    gen_Instruction2_Type14(PMOVZXBW);
    gen_Instruction2_Type14(PMOVZXWD);
    gen_Instruction2_Type14(PMOVZXDQ);

    gen_Instruction2_Type15(CMPSD_SSE2);
    gen_Instruction2_Type15(ROUNDSD);

    gen_Instruction2_Type16(FIST);
    gen_Instruction2_Type16(FIADD);
    gen_Instruction2_Type16(FISUB);
    gen_Instruction2_Type16(FISUBR);
    gen_Instruction2_Type16(FIMUL);
    gen_Instruction2_Type16(FIDIV);
    gen_Instruction2_Type16(FIDIVR);
    gen_Instruction2_Type16(FICOM);
    gen_Instruction2_Type16(FICOMP);

    gen_Instruction2_Type17(CVTPI2PS);
    gen_Instruction2_Type17(CVTPI2PD);

    gen_Instruction2_Type18(CVTPS2PI);
    gen_Instruction2_Type18(CVTTPS2PI);

    gen_Instruction2_Type19(CVTPD2PI);
    gen_Instruction2_Type19(CVTTPD2PI);

    gen_Instruction2_Type20(FADDP);
    gen_Instruction2_Type20(FSUBP);
    gen_Instruction2_Type20(FSUBRP);
    gen_Instruction2_Type20(FMULP);
    gen_Instruction2_Type20(FDIVP);
    gen_Instruction2_Type20(FDIVRP);

    gen_Instruction2_Type21(PSHUFW);

    gen_Instruction2_Type22(MOVNTI);

    gen_Instruction2_Type23(PINSRB);

    gen_Instruction2_Type24(PINSRD);

    gen_Instruction2_Type25(PINSRQ);

    gen_Instruction2_Type26(PEXTRQ);

    gen_Instruction2_Type27(PMOVSXBQ);
    gen_Instruction2_Type27(PMOVZXBQ);

    gen_Instruction2_Type28(VFMADD132SD);
    gen_Instruction2_Type28(VFMADD213SD);
    gen_Instruction2_Type28(VFMADD231SD);
    gen_Instruction2_Type28(VFMSUB132SD);
    gen_Instruction2_Type28(VFMSUB213SD);
    gen_Instruction2_Type28(VFMSUB231SD);
    gen_Instruction2_Type28(VFNMADD132SD);
    gen_Instruction2_Type28(VFNMADD213SD);
    gen_Instruction2_Type28(VFNMADD231SD);
    gen_Instruction2_Type28(VFNMSUB132SD);
    gen_Instruction2_Type28(VFNMSUB213SD);
    gen_Instruction2_Type28(VFNMSUB231SD);

    gen_Instruction2_Type29(VFMADD132SS);
    gen_Instruction2_Type29(VFMADD213SS);
    gen_Instruction2_Type29(VFMADD231SS);
    gen_Instruction2_Type29(VFMSUB132SS);
    gen_Instruction2_Type29(VFMSUB213SS);
    gen_Instruction2_Type29(VFMSUB231SS);
    gen_Instruction2_Type29(VFNMADD132SS);
    gen_Instruction2_Type29(VFNMADD213SS);
    gen_Instruction2_Type29(VFNMADD231SS);
    gen_Instruction2_Type29(VFNMSUB132SS);
    gen_Instruction2_Type29(VFNMSUB213SS);
    gen_Instruction2_Type29(VFNMSUB231SS);
    gen_Instruction2_Type29(VRSQRTSS);

    gen_Instruction2_Type30(VDPPD);

    gen_Instruction2_Type31(VLDDQU);
    gen_Instruction2_Type31(VMOVNTDQA);

    gen_Instruction2_Type32(VMOVNTPS);
    gen_Instruction2_Type32(VMOVNTDQ);

    gen_Instruction2_Type33(VEXTRACTF32X8);
    gen_Instruction2_Type33(VEXTRACTF64X4);
    gen_Instruction2_Type33(VEXTRACTI32X8);
    gen_Instruction2_Type33(VEXTRACTI64X4);

    gen_Instruction2_Type34(VEXTRACTF128);
    gen_Instruction2_Type34(VEXTRACTI128);

    gen_Instruction2_Type35(VINSERTF128);
    gen_Instruction2_Type35(VINSERTI128);

    gen_Instruction2_Type36(VPERM2F128);

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
