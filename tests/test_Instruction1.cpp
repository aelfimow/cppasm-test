#include <gtest/gtest.h>
#include <cppasm.h>
#include "asmstr.h"


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
    m64 addr { RAX };

    CLFLUSH(addr);
    EXPECT_EQ(asmstr(), "clflush (%rax)");

    CLFLUSHOPT(addr);
    EXPECT_EQ(asmstr(), "clflushopt (%rax)");

    XSAVE(addr);
    EXPECT_EQ(asmstr(), "xsave (%rax)");

    XSAVEC(addr);
    EXPECT_EQ(asmstr(), "xsavec (%rax)");

    XSAVEOPT(addr);
    EXPECT_EQ(asmstr(), "xsaveopt (%rax)");

    XRSTOR(addr);
    EXPECT_EQ(asmstr(), "xrstor (%rax)");

    FSTENV(addr);
    EXPECT_EQ(asmstr(), "fstenv (%rax)");

    FNSTENV(addr);
    EXPECT_EQ(asmstr(), "fnstenv (%rax)");

    FLDENV(addr);
    EXPECT_EQ(asmstr(), "fldenv (%rax)");

    FSAVE(addr);
    EXPECT_EQ(asmstr(), "fsave (%rax)");

    FNSAVE(addr);
    EXPECT_EQ(asmstr(), "fnsave (%rax)");

    FRSTOR(addr);
    EXPECT_EQ(asmstr(), "frstor (%rax)");

    FXSAVE(addr);
    EXPECT_EQ(asmstr(), "fxsave (%rax)");

    FXRSTOR(addr);
    EXPECT_EQ(asmstr(), "fxrstor (%rax)");

    PREFETCHT0(addr);
    EXPECT_EQ(asmstr(), "prefetcht0 (%rax)");

    PREFETCHT1(addr);
    EXPECT_EQ(asmstr(), "prefetcht1 (%rax)");

    PREFETCHT2(addr);
    EXPECT_EQ(asmstr(), "prefetcht2 (%rax)");

    PREFETCHNTA(addr);
    EXPECT_EQ(asmstr(), "prefetchnta (%rax)");

    PREFETCHW(addr);
    EXPECT_EQ(asmstr(), "prefetchw (%rax)");

    PREFETCHWT1(addr);
    EXPECT_EQ(asmstr(), "prefetchwt1 (%rax)");

    LGDT(addr);
    EXPECT_EQ(asmstr(), "lgdt (%rax)");

    LIDT(addr);
    EXPECT_EQ(asmstr(), "lidt (%rax)");

    SIDT(addr);
    EXPECT_EQ(asmstr(), "sidt (%rax)");

    INVLPG(addr);
    EXPECT_EQ(asmstr(), "invlpg (%rax)");

    XRSTORS(addr);
    EXPECT_EQ(asmstr(), "xrstors (%rax)");

    XRSTORS64(addr);
    EXPECT_EQ(asmstr(), "xrstors64 (%rax)");

    XSAVES(addr);
    EXPECT_EQ(asmstr(), "xsaves (%rax)");

    XSAVES64(addr);
    EXPECT_EQ(asmstr(), "xsaves64 (%rax)");
}

TEST(Instruction1, Type3)
{
    MOVLHPS(XMM1, XMM0);
    EXPECT_EQ(asmstr(), "movlhps %xmm0, %xmm1");

    MOVHLPS(XMM1, XMM0);
    EXPECT_EQ(asmstr(), "movhlps %xmm0, %xmm1");

    MASKMOVDQU(XMM1, XMM0);
    EXPECT_EQ(asmstr(), "maskmovdqu %xmm0, %xmm1");
}

TEST(Instruction1, Type4)
{
    std::string L { "testlabel" };
    label(L);
    EXPECT_EQ(asmstr(), "testlabel:");

    JA(L);
    EXPECT_EQ(asmstr(), "ja testlabel");

    JAE(L);
    EXPECT_EQ(asmstr(), "jae testlabel");

    JB(L);
    EXPECT_EQ(asmstr(), "jb testlabel");

    JBE(L);
    EXPECT_EQ(asmstr(), "jbe testlabel");

    JC(L);
    EXPECT_EQ(asmstr(), "jc testlabel");

    JECXZ(L);
    EXPECT_EQ(asmstr(), "jecxz testlabel");

    JRCXZ(L);
    EXPECT_EQ(asmstr(), "jrcxz testlabel");

    JE(L);
    EXPECT_EQ(asmstr(), "je testlabel");

    JG(L);
    EXPECT_EQ(asmstr(), "jg testlabel");

    JGE(L);
    EXPECT_EQ(asmstr(), "jge testlabel");

    JL(L);
    EXPECT_EQ(asmstr(), "jl testlabel");

    JLE(L);
    EXPECT_EQ(asmstr(), "jle testlabel");

    JNA(L);
    EXPECT_EQ(asmstr(), "jna testlabel");

    JNAE(L);
    EXPECT_EQ(asmstr(), "jnae testlabel");

    JNB(L);
    EXPECT_EQ(asmstr(), "jnb testlabel");

    JNBE(L);
    EXPECT_EQ(asmstr(), "jnbe testlabel");

    JNC(L);
    EXPECT_EQ(asmstr(), "jnc testlabel");

    JNE(L);
    EXPECT_EQ(asmstr(), "jne testlabel");

    JNG(L);
    EXPECT_EQ(asmstr(), "jng testlabel");

    JNGE(L);
    EXPECT_EQ(asmstr(), "jnge testlabel");

    JNL(L);
    EXPECT_EQ(asmstr(), "jnl testlabel");

    JNLE(L);
    EXPECT_EQ(asmstr(), "jnle testlabel");

    JNO(L);
    EXPECT_EQ(asmstr(), "jno testlabel");

    JNP(L);
    EXPECT_EQ(asmstr(), "jnp testlabel");

    JNS(L);
    EXPECT_EQ(asmstr(), "jns testlabel");

    JNZ(L);
    EXPECT_EQ(asmstr(), "jnz testlabel");

    JO(L);
    EXPECT_EQ(asmstr(), "jo testlabel");

    JP(L);
    EXPECT_EQ(asmstr(), "jp testlabel");

    JPE(L);
    EXPECT_EQ(asmstr(), "jpe testlabel");

    JPO(L);
    EXPECT_EQ(asmstr(), "jpo testlabel");

    JS(L);
    EXPECT_EQ(asmstr(), "js testlabel");

    JZ(L);
    EXPECT_EQ(asmstr(), "jz testlabel");

    LOOP(L);
    EXPECT_EQ(asmstr(), "loop testlabel");

    LOOPE(L);
    EXPECT_EQ(asmstr(), "loope testlabel");

    LOOPNE(L);
    EXPECT_EQ(asmstr(), "loopne testlabel");

    LOOPZ(L);
    EXPECT_EQ(asmstr(), "loopz testlabel");

    LOOPNZ(L);
    EXPECT_EQ(asmstr(), "loopnz testlabel");

    XBEGIN(L);
    EXPECT_EQ(asmstr(), "xbegin testlabel");
}

TEST(Instruction1, Type5)
{
    FCMOVB(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fcmovb %st(1), %st(0)");

    FCMOVE(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fcmove %st(1), %st(0)");

    FCMOVBE(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fcmovbe %st(1), %st(0)");

    FCMOVU(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fcmovu %st(1), %st(0)");

    FCMOVNB(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fcmovnb %st(1), %st(0)");

    FCMOVNE(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fcmovne %st(1), %st(0)");

    FCMOVNBE(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fcmovnbe %st(1), %st(0)");

    FCMOVNU(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fcmovnu %st(1), %st(0)");

    FCOMI(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fcomi %st(1), %st(0)");

    FCOMIP(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fcomip %st(1), %st(0)");

    FUCOMI(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fucomi %st(1), %st(0)");

    FUCOMIP(ST(0), ST(1));
    EXPECT_EQ(asmstr(), "fucomip %st(1), %st(0)");
}

TEST(Instruction1, Type6)
{
    m16 addr { RAX };

    FSTCW(addr);
    EXPECT_EQ(asmstr(), "fstcw (%rax)");

    FNSTCW(addr);
    EXPECT_EQ(asmstr(), "fnstcw (%rax)");

    FLDCW(addr);
    EXPECT_EQ(asmstr(), "fldcw (%rax)");
}

TEST(Instruction1, Type7)
{
    m64 addr { RAX };

    CMPXCHG8B(addr);
    EXPECT_EQ(asmstr(), "cmpxchg8b (%rax)");
}

TEST(Instruction1, Type8)
{
    m128 addr { RAX };

    CMPXCHG16B(addr);
    EXPECT_EQ(asmstr(), "cmpxchg16b (%rax)");
}

TEST(Instruction1, Type9)
{
    imm16 param1 { 65535 };
    imm8 param2 { 255 };

    ENTER(param1, param2);
    EXPECT_EQ(asmstr(), "enter $0xFFFF, $0xFF");
}

TEST(Instruction1, Type10)
{
    imm8 param1 { 255 };

    INT(param1);
    EXPECT_EQ(asmstr(), "int $0xFF");

    XABORT(param1);
    EXPECT_EQ(asmstr(), "xabort $0xFF");
}

TEST(Instruction1, Type11)
{
    REP();
    STOSB();
    EXPECT_EQ(asmstr(), "rep stosb");

    REPE();
    STOSB();
    EXPECT_EQ(asmstr(), "repe stosb");

    REPZ();
    STOSB();
    EXPECT_EQ(asmstr(), "repz stosb");

    REPNE();
    STOSB();
    EXPECT_EQ(asmstr(), "repne stosb");

    REPNZ();
    STOSB();
    EXPECT_EQ(asmstr(), "repnz stosb");

    m64 addr { RBX };

    XRELEASE();
    XCHG(RAX, addr);
    EXPECT_EQ(asmstr(), "xrelease xchg (%rbx), %rax");

    XACQUIRE();
    XCHG(RAX, addr);
    EXPECT_EQ(asmstr(), "xacquire xchg (%rbx), %rax");
}

TEST(Instruction1, Type12)
{
    m80bcd addr { RAX };

    FBLD(addr);
    EXPECT_EQ(asmstr(), "fbld (%rax)");

    FBSTP(addr);
    EXPECT_EQ(asmstr(), "fbstp (%rax)");
}

TEST(Instruction1, Type13)
{
    FFREE(ST(0));
    EXPECT_EQ(asmstr(), "ffree %st(0)");
}

TEST(Instruction1, Type14)
{
    m32 addr { RAX };

    LDMXCSR(addr);
    EXPECT_EQ(asmstr(), "ldmxcsr (%rax)");

    STMXCSR(addr);
    EXPECT_EQ(asmstr(), "stmxcsr (%rax)");

    VLDMXCSR(addr);
    EXPECT_EQ(asmstr(), "vldmxcsr (%rax)");

    VSTMXCSR(addr);
    EXPECT_EQ(asmstr(), "vstmxcsr (%rax)");
}

TEST(Instruction1, Type15)
{
    MASKMOVQ(MM1, MM0);
    EXPECT_EQ(asmstr(), "maskmovq %mm0, %mm1");
}

TEST(Instruction1, Type16)
{
    m64 addr { RAX };

    MOVNTQ(addr, MM0);
    EXPECT_EQ(asmstr(), "movntq %mm0, (%rax)");
}

TEST(Instruction1, Type17)
{
    m128 addr { EAX };

    MOVNTPS(addr, XMM0);
    EXPECT_EQ(asmstr(), "movntps %xmm0, (%eax)");
}

TEST(Instruction1, Type18)
{
    m64 addr { RAX };

    MOVHPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "movhpd (%rax), %xmm0");

    MOVLPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "movlpd (%rax), %xmm0");
}

TEST(Instruction1, Type19)
{
    m128 addr { RAX };

    MOVNTPD(addr, XMM0);
    EXPECT_EQ(asmstr(), "movntpd %xmm0, (%rax)");

    MOVNTDQ(addr, XMM0);
    EXPECT_EQ(asmstr(), "movntdq %xmm0, (%rax)");
}

TEST(Instruction1, Type20)
{
    MOVQ2DQ(XMM0, MM0);
    EXPECT_EQ(asmstr(), "movq2dq %mm0, %xmm0");
}

TEST(Instruction1, Type21)
{
    MOVDQ2Q(MM0, XMM0);
    EXPECT_EQ(asmstr(), "movdq2q %xmm0, %mm0");
}

TEST(Instruction1, Type22)
{
    imm8 shift1 { 1U };
    imm8 shift2 { 128U };

    PSLLDQ(XMM0, shift1);
    EXPECT_EQ(asmstr(), "pslldq $0x01, %xmm0");
    PSLLDQ(XMM0, shift2);
    EXPECT_EQ(asmstr(), "pslldq $0x80, %xmm0");

    PSRLDQ(XMM0, shift1);
    EXPECT_EQ(asmstr(), "psrldq $0x01, %xmm0");
    PSRLDQ(XMM0, shift2);
    EXPECT_EQ(asmstr(), "psrldq $0x80, %xmm0");
}

TEST(Instruction1, Type23)
{
    m128 addr { RAX };

    LDDQU(XMM0, addr);
    EXPECT_EQ(asmstr(), "lddqu (%rax), %xmm0");
}

TEST(Instruction1, Type24)
{
    m128 addr { RAX };

    MOVNTDQA(XMM0, addr);
    EXPECT_EQ(asmstr(), "movntdqa (%rax), %xmm0");
}

TEST(Instruction1, Type25)
{
    m256 addr { RBX };

    VBROADCASTF32X8(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf32x8 (%rbx), %zmm0");
    VBROADCASTF32X8(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf32x8 (%rbx), %zmm0{%k1}");
    VBROADCASTF32X8(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf32x8 (%rbx), %zmm0{%k1}{z}");

    VBROADCASTI32X8(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x8 (%rbx), %zmm0");
    VBROADCASTI32X8(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x8 (%rbx), %zmm0{%k1}");
    VBROADCASTI32X8(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x8 (%rbx), %zmm0{%k1}{z}");

    VBROADCASTF64X4(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf64x4 (%rbx), %zmm0");
    VBROADCASTF64X4(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf64x4 (%rbx), %zmm0{%k1}");
    VBROADCASTF64X4(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf64x4 (%rbx), %zmm0{%k1}{z}");

    VBROADCASTI64X4(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti64x4 (%rbx), %zmm0");
    VBROADCASTI64X4(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti64x4 (%rbx), %zmm0{%k1}");
    VBROADCASTI64X4(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti64x4 (%rbx), %zmm0{%k1}{z}");
}

TEST(Instruction1, Type26)
{
    m128 addr { RAX };

    VBROADCASTF128(YMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf128 (%rax), %ymm0");

    VBROADCASTI128(YMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti128 (%rax), %ymm0");
}

TEST(Instruction1, Type27)
{
    KADDB(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kaddb %k3, %k2, %k1");

    KADDW(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kaddw %k3, %k2, %k1");

    KADDD(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kaddd %k3, %k2, %k1");

    KADDQ(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kaddq %k3, %k2, %k1");

    KANDB(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kandb %k3, %k2, %k1");

    KANDW(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kandw %k3, %k2, %k1");

    KANDD(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kandd %k3, %k2, %k1");

    KANDQ(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kandq %k3, %k2, %k1");

    KANDNB(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kandnb %k3, %k2, %k1");

    KANDNW(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kandnw %k3, %k2, %k1");

    KANDND(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kandnd %k3, %k2, %k1");

    KANDNQ(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kandnq %k3, %k2, %k1");

    KORB(k1, k2, k3);
    EXPECT_EQ(asmstr(), "korb %k3, %k2, %k1");

    KORW(k1, k2, k3);
    EXPECT_EQ(asmstr(), "korw %k3, %k2, %k1");

    KORD(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kord %k3, %k2, %k1");

    KORQ(k1, k2, k3);
    EXPECT_EQ(asmstr(), "korq %k3, %k2, %k1");

    KUNPCKBW(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kunpckbw %k3, %k2, %k1");

    KUNPCKWD(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kunpckwd %k3, %k2, %k1");

    KUNPCKDQ(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kunpckdq %k3, %k2, %k1");

    KXNORB(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kxnorb %k3, %k2, %k1");

    KXNORW(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kxnorw %k3, %k2, %k1");

    KXNORD(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kxnord %k3, %k2, %k1");

    KXNORQ(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kxnorq %k3, %k2, %k1");

    KXORB(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kxorb %k3, %k2, %k1");

    KXORW(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kxorw %k3, %k2, %k1");

    KXORD(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kxord %k3, %k2, %k1");

    KXORQ(k1, k2, k3);
    EXPECT_EQ(asmstr(), "kxorq %k3, %k2, %k1");
}

TEST(Instruction1, Type28)
{
    KNOTB(k1, k2);
    EXPECT_EQ(asmstr(), "knotb %k2, %k1");

    KNOTW(k1, k2);
    EXPECT_EQ(asmstr(), "knotw %k2, %k1");

    KNOTD(k1, k2);
    EXPECT_EQ(asmstr(), "knotd %k2, %k1");

    KNOTQ(k1, k2);
    EXPECT_EQ(asmstr(), "knotq %k2, %k1");

    KORTESTB(k1, k2);
    EXPECT_EQ(asmstr(), "kortestb %k2, %k1");

    KORTESTW(k1, k2);
    EXPECT_EQ(asmstr(), "kortestw %k2, %k1");

    KORTESTD(k1, k2);
    EXPECT_EQ(asmstr(), "kortestd %k2, %k1");

    KORTESTQ(k1, k2);
    EXPECT_EQ(asmstr(), "kortestq %k2, %k1");

    KTESTB(k1, k2);
    EXPECT_EQ(asmstr(), "ktestb %k2, %k1");

    KTESTW(k1, k2);
    EXPECT_EQ(asmstr(), "ktestw %k2, %k1");

    KTESTD(k1, k2);
    EXPECT_EQ(asmstr(), "ktestd %k2, %k1");

    KTESTQ(k1, k2);
    EXPECT_EQ(asmstr(), "ktestq %k2, %k1");
}

TEST(Instruction1, Type29)
{
    imm8 value { 0 };

    KSHIFTLB(k1, k2, value);
    EXPECT_EQ(asmstr(), "kshiftlb $0x00, %k2, %k1");

    KSHIFTLW(k1, k2, value);
    EXPECT_EQ(asmstr(), "kshiftlw $0x00, %k2, %k1");

    KSHIFTLD(k1, k2, value);
    EXPECT_EQ(asmstr(), "kshiftld $0x00, %k2, %k1");

    KSHIFTLQ(k1, k2, value);
    EXPECT_EQ(asmstr(), "kshiftlq $0x00, %k2, %k1");

    KSHIFTRB(k1, k2, value);
    EXPECT_EQ(asmstr(), "kshiftrb $0x00, %k2, %k1");

    KSHIFTRW(k1, k2, value);
    EXPECT_EQ(asmstr(), "kshiftrw $0x00, %k2, %k1");

    KSHIFTRD(k1, k2, value);
    EXPECT_EQ(asmstr(), "kshiftrd $0x00, %k2, %k1");

    KSHIFTRQ(k1, k2, value);
    EXPECT_EQ(asmstr(), "kshiftrq $0x00, %k2, %k1");
}
