#include <gtest/gtest.h>
#include <cppasm.h>

static void gen_Instruction1_Type2(Instruction1_Type2 &instr)
{
    m64 addr { RAX };

    instr(addr);
}

static void gen_Instruction1_Type3(Instruction1_Type3 &instr)
{
    instr(XMM1, XMM0);
}

static void gen_Instruction1_Type4(Instruction1_Type4 &instr, std::string &L)
{
    instr(L);
}

static void gen_Instruction1_Type5(Instruction1_Type5 &instr)
{
    instr(ST(0), ST(1));
}

static void gen_Instruction1_Type6(Instruction1_Type6 &instr)
{
    m16 addr { RAX };

    instr(addr);
}

static void gen_Instruction1_Type7(Instruction1_Type7 &instr)
{
    m64 addr { RAX };

    instr(addr);
}

static void gen_Instruction1_Type8(Instruction1_Type8 &instr)
{
    m128 addr { RAX };

    instr(addr);
}

static void gen_Instruction1_Type9(Instruction1_Type9 &instr)
{
    imm16 param1 { 65535 };
    imm8 param2 { 255 };

    instr(param1, param2);
}

static void gen_Instruction1_Type10(Instruction1_Type10 &instr)
{
    imm8 param1 { 255 };

    instr(param1);
}

static void gen_Instruction1_Type11_1(Instruction1_Type11 &instr)
{
    instr();
    STOSB();
}

static void gen_Instruction1_Type11_2(Instruction1_Type11 &instr)
{
    instr();
    m64 addr { RBX };
    XCHG(RAX, addr);
}

static void gen_Instruction1_Type12(Instruction1_Type12 &instr)
{
    m80bcd addr { RAX };

    instr(addr);
}

static void gen_Instruction1_Type13(Instruction1_Type13 &instr)
{
    instr(ST(0));
}

static void gen_Instruction1_Type14(Instruction1_Type14 &instr)
{
    m32 addr { RAX };

    instr(addr);
}

static void gen_Instruction1_Type15(Instruction1_Type15 &instr)
{
    instr(MM1, MM0);
}

static void gen_Instruction1_Type16(Instruction1_Type16 &instr)
{
    m64 addr { RAX };

    instr(addr, MM0);
}

static void gen_Instruction1_Type17(Instruction1_Type17 &instr)
{
    m128 addr { EAX };

    instr(addr, XMM0);
}

static void gen_Instruction1_Type18(Instruction1_Type18 &instr)
{
    m64 addr { RAX };

    instr(XMM0, addr);
}

static void gen_Instruction1_Type19(Instruction1_Type19 &instr)
{
    m128 addr { RAX };

    instr(addr, XMM0);
}

static void gen_Instruction1_Type20(Instruction1_Type20 &instr)
{
    instr(XMM0, MM0);
}

static void gen_Instruction1_Type21(Instruction1_Type21 &instr)
{
    instr(MM0, XMM0);
}

static void gen_Instruction1_Type22(Instruction1_Type22 &instr)
{
    imm8 shift1 { 1U };
    imm8 shift2 { 128U };

    instr(XMM0, shift1);
    instr(XMM0, shift2);
}

static void gen_Instruction1_Type23(Instruction1_Type23 &instr)
{
    m128 addr { RAX };

    instr(XMM0, addr);
}

static void gen_Instruction1_Type24(Instruction1_Type24 &instr)
{
    m128 addr { RAX };

    instr(XMM0, addr);
}

static void gen_Instruction1_Type25(Instruction1_Type25 &instr)
{
    m256 addr { RBX };
    instr(ZMM0, addr);
    instr(ZMM0.k1, addr);
    instr(ZMM0.k1.z, addr);
}

static void gen_Instruction1_Type26(Instruction1_Type26 &instr)
{
    m128 addr { RAX };

    instr(YMM0, addr);
}

static void gen_Instruction1_Type27(Instruction1_Type27 &instr)
{
    instr(k1, k2, k3);
}

static void gen_Instruction1_Type28(Instruction1_Type28 &instr)
{
    instr(k1, k2);
}

static void gen_Instruction1_Type29(Instruction1_Type29 &instr)
{
    imm8 value { 0 };
    instr(k1, k2, value);
}

extern std::string asmstr();

TEST(Instruction1, Type1)
{
    CWD();
    EXPECT_EQ(asmstr(), "cwtd");

    CDQ();
    EXPECT_EQ(asmstr(), "cltd");

    CQO();
    EXPECT_EQ(asmstr(), "cqto");

    LEAVE();
    EXPECT_EQ(asmstr(), "leave");

    IRET();
    EXPECT_EQ(asmstr(), "iret");

    IRETD();
    EXPECT_EQ(asmstr(), "iretl");

    IRETQ();
    EXPECT_EQ(asmstr(), "iretq");

    MOVSB();
    EXPECT_EQ(asmstr(), "movsb");

    MOVSW();
    EXPECT_EQ(asmstr(), "movsw");

    MOVSD();
    EXPECT_EQ(asmstr(), "movsl");

    MOVSQ();
    EXPECT_EQ(asmstr(), "movsq");

    CMPSB();
    EXPECT_EQ(asmstr(), "cmpsb");

    CMPSW();
    EXPECT_EQ(asmstr(), "cmpsw");

    CMPSD();
    EXPECT_EQ(asmstr(), "cmpsl");

    CMPSQ();
    EXPECT_EQ(asmstr(), "cmpsq");

    SCASB();
    EXPECT_EQ(asmstr(), "scasb");

    SCASW();
    EXPECT_EQ(asmstr(), "scasw");

    SCASD();
    EXPECT_EQ(asmstr(), "scasl");

    SCASQ();
    EXPECT_EQ(asmstr(), "scasq");

    LODSB();
    EXPECT_EQ(asmstr(), "lodsb");

    LODSW();
    EXPECT_EQ(asmstr(), "lodsw");

    LODSD();
    EXPECT_EQ(asmstr(), "lodsl");

    LODSQ();
    EXPECT_EQ(asmstr(), "lodsq");

    STOSB();
    EXPECT_EQ(asmstr(), "stosb");

    STOSW();
    EXPECT_EQ(asmstr(), "stosw");

    STOSD();
    EXPECT_EQ(asmstr(), "stosl");

    STOSQ();
    EXPECT_EQ(asmstr(), "stosq");

    INSB();
    EXPECT_EQ(asmstr(), "insb");

    INSW();
    EXPECT_EQ(asmstr(), "insw");

    INSD();
    EXPECT_EQ(asmstr(), "insl");

    OUTSB();
    EXPECT_EQ(asmstr(), "outsb");

    OUTSW();
    EXPECT_EQ(asmstr(), "outsw");

    OUTSD();
    EXPECT_EQ(asmstr(), "outsl");

    CLC();
    EXPECT_EQ(asmstr(), "clc");

    CLD();
    EXPECT_EQ(asmstr(), "cld");

    CLI();
    EXPECT_EQ(asmstr(), "cli");

    CMC();
    EXPECT_EQ(asmstr(), "cmc");

    LAHF();
    EXPECT_EQ(asmstr(), "lahf");

    SAHF();
    EXPECT_EQ(asmstr(), "sahf");

    PUSHF();
    EXPECT_EQ(asmstr(), "pushf");

    POPF();
    EXPECT_EQ(asmstr(), "popf");

    POPFQ();
    EXPECT_EQ(asmstr(), "popfq");

    STC();
    EXPECT_EQ(asmstr(), "stc");

    STI();
    EXPECT_EQ(asmstr(), "sti");

    STD();
    EXPECT_EQ(asmstr(), "std");

    UD();
    EXPECT_EQ(asmstr(), ".byte 0x0F, 0xFF");

    UD1();
    EXPECT_EQ(asmstr(), "ud1");

    UD2();
    EXPECT_EQ(asmstr(), "ud2");

    CPUID();
    EXPECT_EQ(asmstr(), "cpuid");

    XLAT();
    EXPECT_EQ(asmstr(), "xlat");

    XGETBV();
    EXPECT_EQ(asmstr(), "xgetbv");

    FPREM();
    EXPECT_EQ(asmstr(), "fprem");

    FPREM1();
    EXPECT_EQ(asmstr(), "fprem1");

    FABS();
    EXPECT_EQ(asmstr(), "fabs");

    FCHS();
    EXPECT_EQ(asmstr(), "fchs");

    FRNDINT();
    EXPECT_EQ(asmstr(), "frndint");

    FSCALE();
    EXPECT_EQ(asmstr(), "fscale");

    FSQRT();
    EXPECT_EQ(asmstr(), "fsqrt");

    FXTRACT();
    EXPECT_EQ(asmstr(), "fxtract");

    FCOMPP();
    EXPECT_EQ(asmstr(), "fcompp");

    FUCOMPP();
    EXPECT_EQ(asmstr(), "fucompp");

    FTST();
    EXPECT_EQ(asmstr(), "ftst");

    FXAM();
    EXPECT_EQ(asmstr(), "fxam");

    FSIN();
    EXPECT_EQ(asmstr(), "fsin");

    FSINCOS();
    EXPECT_EQ(asmstr(), "fsincos");

    FCOS();
    EXPECT_EQ(asmstr(), "fcos");

    FPTAN();
    EXPECT_EQ(asmstr(), "fptan");

    FPATAN();
    EXPECT_EQ(asmstr(), "fpatan");

    F2XM1();
    EXPECT_EQ(asmstr(), "f2xm1");

    FYL2X();
    EXPECT_EQ(asmstr(), "fyl2x");

    FYL2XP1();
    EXPECT_EQ(asmstr(), "fyl2xp1");

    FLD1();
    EXPECT_EQ(asmstr(), "fld1");

    FLDL2T();
    EXPECT_EQ(asmstr(), "fldl2t");

    FLDL2E();
    EXPECT_EQ(asmstr(), "fldl2e");

    FLDPI();
    EXPECT_EQ(asmstr(), "fldpi");

    FLDLG2();
    EXPECT_EQ(asmstr(), "fldlg2");

    FLDLN2();
    EXPECT_EQ(asmstr(), "fldln2");

    FLDZ();
    EXPECT_EQ(asmstr(), "fldz");

    FINCSTP();
    EXPECT_EQ(asmstr(), "fincstp");

    FDECSTP();
    EXPECT_EQ(asmstr(), "fdecstp");

    FINIT();
    EXPECT_EQ(asmstr(), "finit");

    FNINIT();
    EXPECT_EQ(asmstr(), "fninit");

    FCLEX();
    EXPECT_EQ(asmstr(), "fclex");

    FNCLEX();
    EXPECT_EQ(asmstr(), "fnclex");

    FNOP();
    EXPECT_EQ(asmstr(), "fnop");

    FWAIT();
    EXPECT_EQ(asmstr(), "fwait");

    WAIT();
    EXPECT_EQ(asmstr(), "wait");

    EMMS();
    EXPECT_EQ(asmstr(), "emms");

    SFENCE();
    EXPECT_EQ(asmstr(), "sfence");

    LFENCE();
    EXPECT_EQ(asmstr(), "lfence");

    MFENCE();
    EXPECT_EQ(asmstr(), "mfence");

    PAUSE();
    EXPECT_EQ(asmstr(), "pause");

    MONITOR();
    EXPECT_EQ(asmstr(), "monitor");

    MWAIT();
    EXPECT_EQ(asmstr(), "mwait");

    VZEROALL();
    EXPECT_EQ(asmstr(), "vzeroall");

    VZEROUPPER();
    EXPECT_EQ(asmstr(), "vzeroupper");

    CLAC();
    EXPECT_EQ(asmstr(), "clac");

    STAC();
    EXPECT_EQ(asmstr(), "stac");

    CLTS();
    EXPECT_EQ(asmstr(), "clts");

    INVD();
    EXPECT_EQ(asmstr(), "invd");

    WBINVD();
    EXPECT_EQ(asmstr(), "wbinvd");

    HLT();
    EXPECT_EQ(asmstr(), "hlt");

    RSM();
    EXPECT_EQ(asmstr(), "rsm");

    RDMSR();
    EXPECT_EQ(asmstr(), "rdmsr");

    WRMSR();
    EXPECT_EQ(asmstr(), "wrmsr");

    RDPMC();
    EXPECT_EQ(asmstr(), "rdpmc");

    RDTSC();
    EXPECT_EQ(asmstr(), "rdtsc");

    RDTSCP();
    EXPECT_EQ(asmstr(), "rdtscp");

    SYSENTER();
    EXPECT_EQ(asmstr(), "sysenter");

    SYSEXIT();
    EXPECT_EQ(asmstr(), "sysexit");

    XSETBV();
    EXPECT_EQ(asmstr(), "xsetbv");

    SYSCALL();
    EXPECT_EQ(asmstr(), "syscall");

    SYSRET();
    EXPECT_EQ(asmstr(), "sysret");

    XEND();
    EXPECT_EQ(asmstr(), "xend");

    XTEST();
    EXPECT_EQ(asmstr(), "xtest");

    VMCALL();
    EXPECT_EQ(asmstr(), "vmcall");

    VMFUNC();
    EXPECT_EQ(asmstr(), "vmfunc");

    VMLAUNCH();
    EXPECT_EQ(asmstr(), "vmlaunch");

    VMRESUME();
    EXPECT_EQ(asmstr(), "vmresume");

    VMXOFF();
    EXPECT_EQ(asmstr(), "vmxoff");

    GETSEC();
    EXPECT_EQ(asmstr(), "getsec");
}

TEST(Instruction1, Type2)
{
    gen_Instruction1_Type2(CLFLUSH);
    gen_Instruction1_Type2(CLFLUSHOPT);
    gen_Instruction1_Type2(XSAVE);
    gen_Instruction1_Type2(XSAVEC);
    gen_Instruction1_Type2(XSAVEOPT);
    gen_Instruction1_Type2(XRSTOR);
    gen_Instruction1_Type2(FSTENV);
    gen_Instruction1_Type2(FNSTENV);
    gen_Instruction1_Type2(FLDENV);
    gen_Instruction1_Type2(FSAVE);
    gen_Instruction1_Type2(FNSAVE);
    gen_Instruction1_Type2(FRSTOR);
    gen_Instruction1_Type2(FXSAVE);
    gen_Instruction1_Type2(FXRSTOR);
    gen_Instruction1_Type2(PREFETCHT0);
    gen_Instruction1_Type2(PREFETCHT1);
    gen_Instruction1_Type2(PREFETCHT2);
    gen_Instruction1_Type2(PREFETCHNTA);
    gen_Instruction1_Type2(PREFETCHW);
    gen_Instruction1_Type2(PREFETCHWT1);
    gen_Instruction1_Type2(LGDT);
    gen_Instruction1_Type2(LIDT);
    gen_Instruction1_Type2(SIDT);
    gen_Instruction1_Type2(INVLPG);
    gen_Instruction1_Type2(XRSTORS);
    gen_Instruction1_Type2(XRSTORS64);
    gen_Instruction1_Type2(XSAVES);
    gen_Instruction1_Type2(XSAVES64);
}

TEST(Instruction1, Type3)
{
    gen_Instruction1_Type3(MOVLHPS);
    gen_Instruction1_Type3(MOVHLPS);
    gen_Instruction1_Type3(MASKMOVDQU);
}

TEST(Instruction1, Type4)
{
    std::string L { "Instruction1_Type4_Label" };
    label(L);
    gen_Instruction1_Type4(JA, L);
    gen_Instruction1_Type4(JAE, L);
    gen_Instruction1_Type4(JB, L);
    gen_Instruction1_Type4(JBE, L);
    gen_Instruction1_Type4(JC, L);
    gen_Instruction1_Type4(JECXZ, L);
    gen_Instruction1_Type4(JRCXZ, L);
    gen_Instruction1_Type4(JE, L);
    gen_Instruction1_Type4(JG, L);
    gen_Instruction1_Type4(JGE, L);
    gen_Instruction1_Type4(JL, L);
    gen_Instruction1_Type4(JLE, L);
    gen_Instruction1_Type4(JNA, L);
    gen_Instruction1_Type4(JNAE, L);
    gen_Instruction1_Type4(JNB, L);
    gen_Instruction1_Type4(JNBE, L);
    gen_Instruction1_Type4(JNC, L);
    gen_Instruction1_Type4(JNE, L);
    gen_Instruction1_Type4(JNG, L);
    gen_Instruction1_Type4(JNGE, L);
    gen_Instruction1_Type4(JNL, L);
    gen_Instruction1_Type4(JNLE, L);
    gen_Instruction1_Type4(JNO, L);
    gen_Instruction1_Type4(JNP, L);
    gen_Instruction1_Type4(JNS, L);
    gen_Instruction1_Type4(JNZ, L);
    gen_Instruction1_Type4(JO, L);
    gen_Instruction1_Type4(JP, L);
    gen_Instruction1_Type4(JPE, L);
    gen_Instruction1_Type4(JPO, L);
    gen_Instruction1_Type4(JS, L);
    gen_Instruction1_Type4(JZ, L);
    gen_Instruction1_Type4(LOOP, L);
    gen_Instruction1_Type4(LOOPE, L);
    gen_Instruction1_Type4(LOOPNE, L);
    gen_Instruction1_Type4(LOOPZ, L);
    gen_Instruction1_Type4(LOOPNZ, L);
    gen_Instruction1_Type4(XBEGIN, L);
}

TEST(Instruction1, Type5)
{
    gen_Instruction1_Type5(FCMOVB);
    gen_Instruction1_Type5(FCMOVE);
    gen_Instruction1_Type5(FCMOVBE);
    gen_Instruction1_Type5(FCMOVU);
    gen_Instruction1_Type5(FCMOVNB);
    gen_Instruction1_Type5(FCMOVNE);
    gen_Instruction1_Type5(FCMOVNBE);
    gen_Instruction1_Type5(FCMOVNU);
    gen_Instruction1_Type5(FCOMI);
    gen_Instruction1_Type5(FCOMIP);
    gen_Instruction1_Type5(FUCOMI);
    gen_Instruction1_Type5(FUCOMIP);
}

TEST(Instruction1, Type6)
{
    gen_Instruction1_Type6(FSTCW);
    gen_Instruction1_Type6(FNSTCW);
    gen_Instruction1_Type6(FLDCW);
}

TEST(Instruction1, Type7)
{
    gen_Instruction1_Type7(CMPXCHG8B);
}

TEST(Instruction1, Type8)
{
    gen_Instruction1_Type8(CMPXCHG16B);
}

TEST(Instruction1, Type9)
{
    gen_Instruction1_Type9(ENTER);
}

TEST(Instruction1, Type10)
{
    gen_Instruction1_Type10(INT);
    gen_Instruction1_Type10(XABORT);
}

TEST(Instruction1, Type11)
{
    gen_Instruction1_Type11_1(REP);
    gen_Instruction1_Type11_1(REPE);
    gen_Instruction1_Type11_1(REPZ);
    gen_Instruction1_Type11_1(REPNE);
    gen_Instruction1_Type11_1(REPNZ);

    gen_Instruction1_Type11_2(XRELEASE);
    gen_Instruction1_Type11_2(XACQUIRE);
}

TEST(Instruction1, Type12)
{
    gen_Instruction1_Type12(FBLD);
    gen_Instruction1_Type12(FBSTP);
}

TEST(Instruction1, Type13)
{
    gen_Instruction1_Type13(FFREE);
}

TEST(Instruction1, Type14)
{
    gen_Instruction1_Type14(LDMXCSR);
    gen_Instruction1_Type14(STMXCSR);
    gen_Instruction1_Type14(VLDMXCSR);
    gen_Instruction1_Type14(VSTMXCSR);
}

TEST(Instruction1, Type15)
{
    gen_Instruction1_Type15(MASKMOVQ);
}

TEST(Instruction1, Type16)
{
    gen_Instruction1_Type16(MOVNTQ);
}

TEST(Instruction1, Type17)
{
    gen_Instruction1_Type17(MOVNTPS);
}

TEST(Instruction1, Type18)
{
    gen_Instruction1_Type18(MOVHPD);
    gen_Instruction1_Type18(MOVLPD);
}

TEST(Instruction1, Type19)
{
    gen_Instruction1_Type19(MOVNTPD);
    gen_Instruction1_Type19(MOVNTDQ);
}

TEST(Instruction1, Type20)
{
    gen_Instruction1_Type20(MOVQ2DQ);
}

TEST(Instruction1, Type21)
{
    gen_Instruction1_Type21(MOVDQ2Q);
}

TEST(Instruction1, Type22)
{
    gen_Instruction1_Type22(PSLLDQ);
    gen_Instruction1_Type22(PSRLDQ);
}

TEST(Instruction1, Type23)
{
    gen_Instruction1_Type23(LDDQU);
}

TEST(Instruction1, Type24)
{
    gen_Instruction1_Type24(MOVNTDQA);
}

TEST(Instruction1, Type25)
{
    gen_Instruction1_Type25(VBROADCASTF32X8);
    gen_Instruction1_Type25(VBROADCASTI32X8);
    gen_Instruction1_Type25(VBROADCASTF64X4);
    gen_Instruction1_Type25(VBROADCASTI64X4);
}

TEST(Instruction1, Type26)
{
    gen_Instruction1_Type26(VBROADCASTF128);
    gen_Instruction1_Type26(VBROADCASTI128);
}

TEST(Instruction1, Type27)
{
    gen_Instruction1_Type27(KADDB);
    gen_Instruction1_Type27(KADDW);
    gen_Instruction1_Type27(KADDD);
    gen_Instruction1_Type27(KADDQ);
    gen_Instruction1_Type27(KANDB);
    gen_Instruction1_Type27(KANDW);
    gen_Instruction1_Type27(KANDD);
    gen_Instruction1_Type27(KANDQ);
    gen_Instruction1_Type27(KANDNB);
    gen_Instruction1_Type27(KANDNW);
    gen_Instruction1_Type27(KANDND);
    gen_Instruction1_Type27(KANDNQ);
    gen_Instruction1_Type27(KORB);
    gen_Instruction1_Type27(KORW);
    gen_Instruction1_Type27(KORD);
    gen_Instruction1_Type27(KORQ);
    gen_Instruction1_Type27(KUNPCKBW);
    gen_Instruction1_Type27(KUNPCKWD);
    gen_Instruction1_Type27(KUNPCKDQ);
    gen_Instruction1_Type27(KXNORB);
    gen_Instruction1_Type27(KXNORW);
    gen_Instruction1_Type27(KXNORD);
    gen_Instruction1_Type27(KXNORQ);
    gen_Instruction1_Type27(KXORB);
    gen_Instruction1_Type27(KXORW);
    gen_Instruction1_Type27(KXORD);
    gen_Instruction1_Type27(KXORQ);
}

TEST(Instruction1, Type28)
{
    gen_Instruction1_Type28(KNOTB);
    gen_Instruction1_Type28(KNOTW);
    gen_Instruction1_Type28(KNOTD);
    gen_Instruction1_Type28(KNOTQ);
    gen_Instruction1_Type28(KORTESTB);
    gen_Instruction1_Type28(KORTESTW);
    gen_Instruction1_Type28(KORTESTD);
    gen_Instruction1_Type28(KORTESTQ);
    gen_Instruction1_Type28(KTESTB);
    gen_Instruction1_Type28(KTESTW);
    gen_Instruction1_Type28(KTESTD);
    gen_Instruction1_Type28(KTESTQ);
}

TEST(Instruction1, Type29)
{
    gen_Instruction1_Type29(KSHIFTLB);
    gen_Instruction1_Type29(KSHIFTLW);
    gen_Instruction1_Type29(KSHIFTLD);
    gen_Instruction1_Type29(KSHIFTLQ);
    gen_Instruction1_Type29(KSHIFTRB);
    gen_Instruction1_Type29(KSHIFTRW);
    gen_Instruction1_Type29(KSHIFTRD);
    gen_Instruction1_Type29(KSHIFTRQ);
}
