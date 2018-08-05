#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

static void gen_Instruction4_Type13(Instruction4_Type13 &instr)
{
    m64 addr { RAX };
    instr(EAX, XMM0);
    instr(EAX, addr);
    instr(RAX, XMM0);
    instr(RAX, addr);
}

static void gen_Instruction4_Type14(Instruction4_Type14 &instr)
{
    m128 addr { RAX };
    instr(XMM0, XMM1);
    instr(XMM0, addr);
    instr(XMM0, XMM1, XMM2);
    instr(XMM0, addr, XMM1);
}

static void gen_Instruction4_Type15(Instruction4_Type15 &instr)
{
    m64 addr1 { RAX };
    m128 addr2 { RBX };
    instr(XMM0, XMM1);
    instr(XMM0, addr1);
    instr(YMM0, XMM0);
    instr(YMM0, addr2);
}

static void gen_Instruction4_Type16(Instruction4_Type16 &instr)
{
    m64 addr1 { RAX };
    m128 addr2 { RBX };
    imm8 mask { 255 };
    instr(XMM0, XMM1, mask);
    instr(addr1, XMM0, mask);
    instr(XMM0, YMM0, mask);
    instr(addr2, YMM0, mask);
}

static void gen_Instruction4_Type17(Instruction4_Type17 &instr)
{
    m128 addr1 { RAX };
    m256 addr2 { RBX };
    instr(XMM0, XMM1, XMM2);
    instr(XMM0, XMM1, addr1);
    instr(YMM0, YMM1, YMM2);
    instr(YMM0, YMM1, addr2);
}

static void gen_Instruction4_Type18(Instruction4_Type18 &instr)
{
    m128 addr1 { RAX };
    m256 addr2 { RBX };
    instr(XMM0, XMM1);
    instr(XMM0, addr1);
    instr(YMM0, YMM1);
    instr(YMM0, addr2);
}

static void gen_Instruction4_Type19(Instruction4_Type19 &instr)
{
    instr(XMM0, XMM1);
    //instr(XMM0, addr1);
    instr(XMM0, YMM1);
    //instr(XMM0, addr2);
}

static void gen_Instruction4_Type20(Instruction4_Type20 &instr)
{
    imm8 mask { 255 };
    m128 addr1 { RAX };
    m256 addr2 { RBX };
    instr(XMM0, XMM1, XMM2, mask);
    instr(XMM0, XMM1, addr1, mask);
    instr(YMM0, YMM1, YMM2, mask);
    instr(YMM0, YMM1, addr2, mask);
}

static void gen_Instruction4_Type21(Instruction4_Type21 &instr)
{
    imm8 mask { 255 };
    m128 addr1 { RAX };
    m256 addr2 { RBX };
    instr(XMM0, XMM1, mask);
    instr(XMM0, addr1, mask);
    instr(YMM0, YMM1, mask);
    instr(YMM0, addr2, mask);
}

static void gen_Instruction4_Type22(Instruction4_Type22 &instr)
{
    instr(EAX, XMM0);
    instr(RAX, XMM0);
    instr(EAX, YMM0);
    instr(RAX, YMM0);
}

static void gen_Instruction4_Type23(Instruction4_Type23 &instr)
{
    m128 addr { RAX };
    instr(XMM0, XMM1, XMM2, XMM3);
    instr(XMM0, XMM1, addr, XMM3);
    instr(YMM0, YMM1, YMM2, YMM3);
    instr(YMM0, YMM1, addr, YMM3);
}

static void gen_Instruction4_Type24(Instruction4_Type24 &instr)
{
    m128 addr1 { RAX };
    m256 addr2 { RBX };
    instr(XMM0, XMM1, addr1);
    instr(YMM0, YMM1, addr2);
    instr(addr1, XMM0, XMM1);
    instr(addr2, YMM0, YMM1);
}

static void gen_Instruction4_Type25(Instruction4_Type25 &instr)
{
    m32 addr1 { RAX };
    m64 addr2 { RBX };
    instr(XMM0, XMM1, EAX);
    instr(XMM0, XMM1, addr1);
    instr(XMM0, XMM1, RBX);
    instr(XMM0, XMM1, addr2);
}

static void gen_Instruction4_Type26(Instruction4_Type26 &instr)
{
    m64 addr2 { RDX };
    instr(RAX, RBX);
    instr(addr2, RBX);
}

static void gen_Instruction4_Type27(Instruction4_Type27 &instr)
{
    m64 addr2 { RDX };
    instr(RAX, RBX);
    instr(RBX, addr2);
}

static void gen_Instruction4_Type28(Instruction4_Type28 &instr)
{
    imm8 mask { 0x0F };
    m128 addr { RDX };
    instr(YMM0, YMM1, XMM0, mask);
    instr(YMM0.k1, YMM1, XMM0, mask);
    instr(YMM0.k1.z, YMM1, XMM0, mask);
    instr(YMM0, YMM1, addr, mask);
    instr(YMM0.k1, YMM1, addr, mask);
    instr(YMM0.k1.z, YMM1, addr, mask);
    instr(ZMM0, ZMM1, XMM0, mask);
    instr(ZMM0.k1, ZMM1, XMM0, mask);
    instr(ZMM0.k1.z, ZMM1, XMM0, mask);
    instr(ZMM0, ZMM1, addr, mask);
    instr(ZMM0.k1, ZMM1, addr, mask);
    instr(ZMM0.k1.z, ZMM1, addr, mask);
}

TEST(Instruction4, Type1)
{
    m64 addr1 { RAX };
    m128 addr2 { RBX };

    PACKSSWB(MM0, MM1);
    EXPECT_EQ(asmstr(), "packsswb %mm1, %mm0");
    PACKSSWB(MM0, addr1);
    EXPECT_EQ(asmstr(), "packsswb (%rax), %mm0");
    PACKSSWB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "packsswb %xmm1, %xmm0");
    PACKSSWB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "packsswb (%rbx), %xmm0");

    PACKUSWB(MM0, MM1);
    EXPECT_EQ(asmstr(), "packuswb %mm1, %mm0");
    PACKUSWB(MM0, addr1);
    EXPECT_EQ(asmstr(), "packuswb (%rax), %mm0");
    PACKUSWB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "packuswb %xmm1, %xmm0");
    PACKUSWB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "packuswb (%rbx), %xmm0");

    PACKSSDW(MM0, MM1);
    EXPECT_EQ(asmstr(), "packssdw %mm1, %mm0");
    PACKSSDW(MM0, addr1);
    EXPECT_EQ(asmstr(), "packssdw (%rax), %mm0");
    PACKSSDW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "packssdw %xmm1, %xmm0");
    PACKSSDW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "packssdw (%rbx), %xmm0");

    PUNPCKHBW(MM0, MM1);
    EXPECT_EQ(asmstr(), "punpckhbw %mm1, %mm0");
    PUNPCKHBW(MM0, addr1);
    EXPECT_EQ(asmstr(), "punpckhbw (%rax), %mm0");
    PUNPCKHBW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "punpckhbw %xmm1, %xmm0");
    PUNPCKHBW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "punpckhbw (%rbx), %xmm0");

    PUNPCKHWD(MM0, MM1);
    EXPECT_EQ(asmstr(), "punpckhwd %mm1, %mm0");
    PUNPCKHWD(MM0, addr1);
    EXPECT_EQ(asmstr(), "punpckhwd (%rax), %mm0");
    PUNPCKHWD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "punpckhwd %xmm1, %xmm0");
    PUNPCKHWD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "punpckhwd (%rbx), %xmm0");

    PUNPCKHDQ(MM0, MM1);
    EXPECT_EQ(asmstr(), "punpckhdq %mm1, %mm0");
    PUNPCKHDQ(MM0, addr1);
    EXPECT_EQ(asmstr(), "punpckhdq (%rax), %mm0");
    PUNPCKHDQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "punpckhdq %xmm1, %xmm0");
    PUNPCKHDQ(XMM0, addr2);
    EXPECT_EQ(asmstr(), "punpckhdq (%rbx), %xmm0");

    PUNPCKLBW(MM0, MM1);
    EXPECT_EQ(asmstr(), "punpcklbw %mm1, %mm0");
    PUNPCKLBW(MM0, addr1);
    EXPECT_EQ(asmstr(), "punpcklbw (%rax), %mm0");
    PUNPCKLBW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "punpcklbw %xmm1, %xmm0");
    PUNPCKLBW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "punpcklbw (%rbx), %xmm0");

    PUNPCKLWD(MM0, MM1);
    EXPECT_EQ(asmstr(), "punpcklwd %mm1, %mm0");
    PUNPCKLWD(MM0, addr1);
    EXPECT_EQ(asmstr(), "punpcklwd (%rax), %mm0");
    PUNPCKLWD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "punpcklwd %xmm1, %xmm0");
    PUNPCKLWD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "punpcklwd (%rbx), %xmm0");

    PUNPCKLDQ(MM0, MM1);
    EXPECT_EQ(asmstr(), "punpckldq %mm1, %mm0");
    PUNPCKLDQ(MM0, addr1);
    EXPECT_EQ(asmstr(), "punpckldq (%rax), %mm0");
    PUNPCKLDQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "punpckldq %xmm1, %xmm0");
    PUNPCKLDQ(XMM0, addr2);
    EXPECT_EQ(asmstr(), "punpckldq (%rbx), %xmm0");

    PADDB(MM0, MM1);
    EXPECT_EQ(asmstr(), "paddb %mm1, %mm0");
    PADDB(MM0, addr1);
    EXPECT_EQ(asmstr(), "paddb (%rax), %mm0");
    PADDB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "paddb %xmm1, %xmm0");
    PADDB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "paddb (%rbx), %xmm0");

    PADDW(MM0, MM1);
    EXPECT_EQ(asmstr(), "paddw %mm1, %mm0");
    PADDW(MM0, addr1);
    EXPECT_EQ(asmstr(), "paddw (%rax), %mm0");
    PADDW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "paddw %xmm1, %xmm0");
    PADDW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "paddw (%rbx), %xmm0");

    PADDD(MM0, MM1);
    EXPECT_EQ(asmstr(), "paddd %mm1, %mm0");
    PADDD(MM0, addr1);
    EXPECT_EQ(asmstr(), "paddd (%rax), %mm0");
    PADDD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "paddd %xmm1, %xmm0");
    PADDD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "paddd (%rbx), %xmm0");

    PADDSB(MM0, MM1);
    EXPECT_EQ(asmstr(), "paddsb %mm1, %mm0");
    PADDSB(MM0, addr1);
    EXPECT_EQ(asmstr(), "paddsb (%rax), %mm0");
    PADDSB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "paddsb %xmm1, %xmm0");
    PADDSB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "paddsb (%rbx), %xmm0");

    PADDSW(MM0, MM1);
    EXPECT_EQ(asmstr(), "paddsw %mm1, %mm0");
    PADDSW(MM0, addr1);
    EXPECT_EQ(asmstr(), "paddsw (%rax), %mm0");
    PADDSW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "paddsw %xmm1, %xmm0");
    PADDSW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "paddsw (%rbx), %xmm0");

    PADDUSB(MM0, MM1);
    EXPECT_EQ(asmstr(), "paddusb %mm1, %mm0");
    PADDUSB(MM0, addr1);
    EXPECT_EQ(asmstr(), "paddusb (%rax), %mm0");
    PADDUSB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "paddusb %xmm1, %xmm0");
    PADDUSB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "paddusb (%rbx), %xmm0");

    PADDUSW(MM0, MM1);
    EXPECT_EQ(asmstr(), "paddusw %mm1, %mm0");
    PADDUSW(MM0, addr1);
    EXPECT_EQ(asmstr(), "paddusw (%rax), %mm0");
    PADDUSW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "paddusw %xmm1, %xmm0");
    PADDUSW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "paddusw (%rbx), %xmm0");

    PSUBB(MM0, MM1);
    EXPECT_EQ(asmstr(), "psubb %mm1, %mm0");
    PSUBB(MM0, addr1);
    EXPECT_EQ(asmstr(), "psubb (%rax), %mm0");
    PSUBB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psubb %xmm1, %xmm0");
    PSUBB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psubb (%rbx), %xmm0");

    PSUBW(MM0, MM1);
    EXPECT_EQ(asmstr(), "psubw %mm1, %mm0");
    PSUBW(MM0, addr1);
    EXPECT_EQ(asmstr(), "psubw (%rax), %mm0");
    PSUBW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psubw %xmm1, %xmm0");
    PSUBW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psubw (%rbx), %xmm0");

    PSUBD(MM0, MM1);
    EXPECT_EQ(asmstr(), "psubd %mm1, %mm0");
    PSUBD(MM0, addr1);
    EXPECT_EQ(asmstr(), "psubd (%rax), %mm0");
    PSUBD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psubd %xmm1, %xmm0");
    PSUBD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psubd (%rbx), %xmm0");

    PSUBSB(MM0, MM1);
    EXPECT_EQ(asmstr(), "psubsb %mm1, %mm0");
    PSUBSB(MM0, addr1);
    EXPECT_EQ(asmstr(), "psubsb (%rax), %mm0");
    PSUBSB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psubsb %xmm1, %xmm0");
    PSUBSB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psubsb (%rbx), %xmm0");

    PSUBSW(MM0, MM1);
    EXPECT_EQ(asmstr(), "psubsw %mm1, %mm0");
    PSUBSW(MM0, addr1);
    EXPECT_EQ(asmstr(), "psubsw (%rax), %mm0");
    PSUBSW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psubsw %xmm1, %xmm0");
    PSUBSW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psubsw (%rbx), %xmm0");

    PSUBUSB(MM0, MM1);
    EXPECT_EQ(asmstr(), "psubusb %mm1, %mm0");
    PSUBUSB(MM0, addr1);
    EXPECT_EQ(asmstr(), "psubusb (%rax), %mm0");
    PSUBUSB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psubusb %xmm1, %xmm0");
    PSUBUSB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psubusb (%rbx), %xmm0");

    PSUBUSW(MM0, MM1);
    EXPECT_EQ(asmstr(), "psubusw %mm1, %mm0");
    PSUBUSW(MM0, addr1);
    EXPECT_EQ(asmstr(), "psubusw (%rax), %mm0");
    PSUBUSW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psubusw %xmm1, %xmm0");
    PSUBUSW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psubusw (%rbx), %xmm0");

    PMULHW(MM0, MM1);
    EXPECT_EQ(asmstr(), "pmulhw %mm1, %mm0");
    PMULHW(MM0, addr1);
    EXPECT_EQ(asmstr(), "pmulhw (%rax), %mm0");
    PMULHW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmulhw %xmm1, %xmm0");
    PMULHW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pmulhw (%rbx), %xmm0");

    PMULLW(MM0, MM1);
    EXPECT_EQ(asmstr(), "pmullw %mm1, %mm0");
    PMULLW(MM0, addr1);
    EXPECT_EQ(asmstr(), "pmullw (%rax), %mm0");
    PMULLW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmullw %xmm1, %xmm0");
    PMULLW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pmullw (%rbx), %xmm0");

    PMADDWD(MM0, MM1);
    EXPECT_EQ(asmstr(), "pmaddwd %mm1, %mm0");
    PMADDWD(MM0, addr1);
    EXPECT_EQ(asmstr(), "pmaddwd (%rax), %mm0");
    PMADDWD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmaddwd %xmm1, %xmm0");
    PMADDWD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pmaddwd (%rbx), %xmm0");

    PCMPEQB(MM0, MM1);
    EXPECT_EQ(asmstr(), "pcmpeqb %mm1, %mm0");
    PCMPEQB(MM0, addr1);
    EXPECT_EQ(asmstr(), "pcmpeqb (%rax), %mm0");
    PCMPEQB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pcmpeqb %xmm1, %xmm0");
    PCMPEQB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pcmpeqb (%rbx), %xmm0");

    PCMPEQW(MM0, MM1);
    EXPECT_EQ(asmstr(), "pcmpeqw %mm1, %mm0");
    PCMPEQW(MM0, addr1);
    EXPECT_EQ(asmstr(), "pcmpeqw (%rax), %mm0");
    PCMPEQW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pcmpeqw %xmm1, %xmm0");
    PCMPEQW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pcmpeqw (%rbx), %xmm0");

    PCMPEQD(MM0, MM1);
    EXPECT_EQ(asmstr(), "pcmpeqd %mm1, %mm0");
    PCMPEQD(MM0, addr1);
    EXPECT_EQ(asmstr(), "pcmpeqd (%rax), %mm0");
    PCMPEQD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pcmpeqd %xmm1, %xmm0");
    PCMPEQD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pcmpeqd (%rbx), %xmm0");

    PCMPGTB(MM0, MM1);
    EXPECT_EQ(asmstr(), "pcmpgtb %mm1, %mm0");
    PCMPGTB(MM0, addr1);
    EXPECT_EQ(asmstr(), "pcmpgtb (%rax), %mm0");
    PCMPGTB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pcmpgtb %xmm1, %xmm0");
    PCMPGTB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pcmpgtb (%rbx), %xmm0");

    PCMPGTW(MM0, MM1);
    EXPECT_EQ(asmstr(), "pcmpgtw %mm1, %mm0");
    PCMPGTW(MM0, addr1);
    EXPECT_EQ(asmstr(), "pcmpgtw (%rax), %mm0");
    PCMPGTW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pcmpgtw %xmm1, %xmm0");
    PCMPGTW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pcmpgtw (%rbx), %xmm0");

    PCMPGTD(MM0, MM1);
    EXPECT_EQ(asmstr(), "pcmpgtd %mm1, %mm0");
    PCMPGTD(MM0, addr1);
    EXPECT_EQ(asmstr(), "pcmpgtd (%rax), %mm0");
    PCMPGTD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pcmpgtd %xmm1, %xmm0");
    PCMPGTD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pcmpgtd (%rbx), %xmm0");

    PAND(MM0, MM1);
    EXPECT_EQ(asmstr(), "pand %mm1, %mm0");
    PAND(MM0, addr1);
    EXPECT_EQ(asmstr(), "pand (%rax), %mm0");
    PAND(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pand %xmm1, %xmm0");
    PAND(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pand (%rbx), %xmm0");

    PANDN(MM0, MM1);
    EXPECT_EQ(asmstr(), "pandn %mm1, %mm0");
    PANDN(MM0, addr1);
    EXPECT_EQ(asmstr(), "pandn (%rax), %mm0");
    PANDN(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pandn %xmm1, %xmm0");
    PANDN(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pandn (%rbx), %xmm0");

    POR(MM0, MM1);
    EXPECT_EQ(asmstr(), "por %mm1, %mm0");
    POR(MM0, addr1);
    EXPECT_EQ(asmstr(), "por (%rax), %mm0");
    POR(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "por %xmm1, %xmm0");
    POR(XMM0, addr2);
    EXPECT_EQ(asmstr(), "por (%rbx), %xmm0");

    PXOR(MM0, MM1);
    EXPECT_EQ(asmstr(), "pxor %mm1, %mm0");
    PXOR(MM0, addr1);
    EXPECT_EQ(asmstr(), "pxor (%rax), %mm0");
    PXOR(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pxor %xmm1, %xmm0");
    PXOR(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pxor (%rbx), %xmm0");

    PAVGB(MM0, MM1);
    EXPECT_EQ(asmstr(), "pavgb %mm1, %mm0");
    PAVGB(MM0, addr1);
    EXPECT_EQ(asmstr(), "pavgb (%rax), %mm0");
    PAVGB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pavgb %xmm1, %xmm0");
    PAVGB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pavgb (%rbx), %xmm0");

    PAVGW(MM0, MM1);
    EXPECT_EQ(asmstr(), "pavgw %mm1, %mm0");
    PAVGW(MM0, addr1);
    EXPECT_EQ(asmstr(), "pavgw (%rax), %mm0");
    PAVGW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pavgw %xmm1, %xmm0");
    PAVGW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pavgw (%rbx), %xmm0");

    PMAXUB(MM0, MM1);
    EXPECT_EQ(asmstr(), "pmaxub %mm1, %mm0");
    PMAXUB(MM0, addr1);
    EXPECT_EQ(asmstr(), "pmaxub (%rax), %mm0");
    PMAXUB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmaxub %xmm1, %xmm0");
    PMAXUB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pmaxub (%rbx), %xmm0");

    PMAXSW(MM0, MM1);
    EXPECT_EQ(asmstr(), "pmaxsw %mm1, %mm0");
    PMAXSW(MM0, addr1);
    EXPECT_EQ(asmstr(), "pmaxsw (%rax), %mm0");
    PMAXSW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmaxsw %xmm1, %xmm0");
    PMAXSW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pmaxsw (%rbx), %xmm0");

    PMINUB(MM0, MM1);
    EXPECT_EQ(asmstr(), "pminub %mm1, %mm0");
    PMINUB(MM0, addr1);
    EXPECT_EQ(asmstr(), "pminub (%rax), %mm0");
    PMINUB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pminub %xmm1, %xmm0");
    PMINUB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pminub (%rbx), %xmm0");

    PMINSW(MM0, MM1);
    EXPECT_EQ(asmstr(), "pminsw %mm1, %mm0");
    PMINSW(MM0, addr1);
    EXPECT_EQ(asmstr(), "pminsw (%rax), %mm0");
    PMINSW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pminsw %xmm1, %xmm0");
    PMINSW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pminsw (%rbx), %xmm0");

    PMULUDQ(MM0, MM1);
    EXPECT_EQ(asmstr(), "pmuludq %mm1, %mm0");
    PMULUDQ(MM0, addr1);
    EXPECT_EQ(asmstr(), "pmuludq (%rax), %mm0");
    PMULUDQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmuludq %xmm1, %xmm0");
    PMULUDQ(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pmuludq (%rbx), %xmm0");

    PADDQ(MM0, MM1);
    EXPECT_EQ(asmstr(), "paddq %mm1, %mm0");
    PADDQ(MM0, addr1);
    EXPECT_EQ(asmstr(), "paddq (%rax), %mm0");
    PADDQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "paddq %xmm1, %xmm0");
    PADDQ(XMM0, addr2);
    EXPECT_EQ(asmstr(), "paddq (%rbx), %xmm0");

    PSUBQ(MM0, MM1);
    EXPECT_EQ(asmstr(), "psubq %mm1, %mm0");
    PSUBQ(MM0, addr1);
    EXPECT_EQ(asmstr(), "psubq (%rax), %mm0");
    PSUBQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psubq %xmm1, %xmm0");
    PSUBQ(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psubq (%rbx), %xmm0");

    PHADDW(MM0, MM1);
    EXPECT_EQ(asmstr(), "phaddw %mm1, %mm0");
    PHADDW(MM0, addr1);
    EXPECT_EQ(asmstr(), "phaddw (%rax), %mm0");
    PHADDW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "phaddw %xmm1, %xmm0");
    PHADDW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "phaddw (%rbx), %xmm0");

    PHADDSW(MM0, MM1);
    EXPECT_EQ(asmstr(), "phaddsw %mm1, %mm0");
    PHADDSW(MM0, addr1);
    EXPECT_EQ(asmstr(), "phaddsw (%rax), %mm0");
    PHADDSW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "phaddsw %xmm1, %xmm0");
    PHADDSW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "phaddsw (%rbx), %xmm0");

    PHADDD(MM0, MM1);
    EXPECT_EQ(asmstr(), "phaddd %mm1, %mm0");
    PHADDD(MM0, addr1);
    EXPECT_EQ(asmstr(), "phaddd (%rax), %mm0");
    PHADDD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "phaddd %xmm1, %xmm0");
    PHADDD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "phaddd (%rbx), %xmm0");

    PHSUBW(MM0, MM1);
    EXPECT_EQ(asmstr(), "phsubw %mm1, %mm0");
    PHSUBW(MM0, addr1);
    EXPECT_EQ(asmstr(), "phsubw (%rax), %mm0");
    PHSUBW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "phsubw %xmm1, %xmm0");
    PHSUBW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "phsubw (%rbx), %xmm0");

    PHSUBSW(MM0, MM1);
    EXPECT_EQ(asmstr(), "phsubsw %mm1, %mm0");
    PHSUBSW(MM0, addr1);
    EXPECT_EQ(asmstr(), "phsubsw (%rax), %mm0");
    PHSUBSW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "phsubsw %xmm1, %xmm0");
    PHSUBSW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "phsubsw (%rbx), %xmm0");

    PHSUBD(MM0, MM1);
    EXPECT_EQ(asmstr(), "phsubd %mm1, %mm0");
    PHSUBD(MM0, addr1);
    EXPECT_EQ(asmstr(), "phsubd (%rax), %mm0");
    PHSUBD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "phsubd %xmm1, %xmm0");
    PHSUBD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "phsubd (%rbx), %xmm0");

    PABSB(MM0, MM1);
    EXPECT_EQ(asmstr(), "pabsb %mm1, %mm0");
    PABSB(MM0, addr1);
    EXPECT_EQ(asmstr(), "pabsb (%rax), %mm0");
    PABSB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pabsb %xmm1, %xmm0");
    PABSB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pabsb (%rbx), %xmm0");

    PABSW(MM0, MM1);
    EXPECT_EQ(asmstr(), "pabsw %mm1, %mm0");
    PABSW(MM0, addr1);
    EXPECT_EQ(asmstr(), "pabsw (%rax), %mm0");
    PABSW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pabsw %xmm1, %xmm0");
    PABSW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pabsw (%rbx), %xmm0");

    PABSD(MM0, MM1);
    EXPECT_EQ(asmstr(), "pabsd %mm1, %mm0");
    PABSD(MM0, addr1);
    EXPECT_EQ(asmstr(), "pabsd (%rax), %mm0");
    PABSD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pabsd %xmm1, %xmm0");
    PABSD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pabsd (%rbx), %xmm0");

    PMADDUBSW(MM0, MM1);
    EXPECT_EQ(asmstr(), "pmaddubsw %mm1, %mm0");
    PMADDUBSW(MM0, addr1);
    EXPECT_EQ(asmstr(), "pmaddubsw (%rax), %mm0");
    PMADDUBSW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmaddubsw %xmm1, %xmm0");
    PMADDUBSW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pmaddubsw (%rbx), %xmm0");

    PMULHRSW(MM0, MM1);
    EXPECT_EQ(asmstr(), "pmulhrsw %mm1, %mm0");
    PMULHRSW(MM0, addr1);
    EXPECT_EQ(asmstr(), "pmulhrsw (%rax), %mm0");
    PMULHRSW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmulhrsw %xmm1, %xmm0");
    PMULHRSW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pmulhrsw (%rbx), %xmm0");

    PSHUFB(MM0, MM1);
    EXPECT_EQ(asmstr(), "pshufb %mm1, %mm0");
    PSHUFB(MM0, addr1);
    EXPECT_EQ(asmstr(), "pshufb (%rax), %mm0");
    PSHUFB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pshufb %xmm1, %xmm0");
    PSHUFB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pshufb (%rbx), %xmm0");

    PSIGNB(MM0, MM1);
    EXPECT_EQ(asmstr(), "psignb %mm1, %mm0");
    PSIGNB(MM0, addr1);
    EXPECT_EQ(asmstr(), "psignb (%rax), %mm0");
    PSIGNB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psignb %xmm1, %xmm0");
    PSIGNB(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psignb (%rbx), %xmm0");

    PSIGNW(MM0, MM1);
    EXPECT_EQ(asmstr(), "psignw %mm1, %mm0");
    PSIGNW(MM0, addr1);
    EXPECT_EQ(asmstr(), "psignw (%rax), %mm0");
    PSIGNW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psignw %xmm1, %xmm0");
    PSIGNW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psignw (%rbx), %xmm0");

    PSIGND(MM0, MM1);
    EXPECT_EQ(asmstr(), "psignd %mm1, %mm0");
    PSIGND(MM0, addr1);
    EXPECT_EQ(asmstr(), "psignd (%rax), %mm0");
    PSIGND(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psignd %xmm1, %xmm0");
    PSIGND(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psignd (%rbx), %xmm0");

    PMULHUW(MM0, MM1);
    EXPECT_EQ(asmstr(), "pmulhuw %mm1, %mm0");
    PMULHUW(MM0, addr1);
    EXPECT_EQ(asmstr(), "pmulhuw (%rax), %mm0");
    PMULHUW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pmulhuw %xmm1, %xmm0");
    PMULHUW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pmulhuw (%rbx), %xmm0");

    PSADBW(MM0, MM1);
    EXPECT_EQ(asmstr(), "psadbw %mm1, %mm0");
    PSADBW(MM0, addr1);
    EXPECT_EQ(asmstr(), "psadbw (%rax), %mm0");
    PSADBW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psadbw %xmm1, %xmm0");
    PSADBW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psadbw (%rbx), %xmm0");
}

TEST(Instruction4, Type2)
{
    m32fp addr1 { EAX };
    m64fp addr2 { EBX };
    m80fp addr3 { ECX };

    FLD(addr1);
    EXPECT_EQ(asmstr(), "flds (%eax)");
    FLD(addr2);
    EXPECT_EQ(asmstr(), "fldl (%ebx)");
    FLD(addr3);
    EXPECT_EQ(asmstr(), "fldt (%ecx)");
    FLD(ST(0));
    EXPECT_EQ(asmstr(), "fld %st(0)");

    FSTP(addr1);
    EXPECT_EQ(asmstr(), "fstps (%eax)");
    FSTP(addr2);
    EXPECT_EQ(asmstr(), "fstpl (%ebx)");
    FSTP(addr3);
    EXPECT_EQ(asmstr(), "fstpt (%ecx)");
    FSTP(ST(0));
    EXPECT_EQ(asmstr(), "fstp %st(0)");
}

TEST(Instruction4, Type3)
{
    m64 addr { RBX };

    VBROADCASTSD(YMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcastsd (%rbx), %ymm0");
    VBROADCASTSD(YMM0, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastsd %xmm0, %ymm0");
    VBROADCASTSD(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcastsd (%rbx), %zmm0");
    VBROADCASTSD(ZMM0, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastsd %xmm0, %zmm0");
    VBROADCASTSD(YMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcastsd (%rbx), %ymm0{%k1}");
    VBROADCASTSD(YMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastsd %xmm0, %ymm0{%k1}");
    VBROADCASTSD(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcastsd (%rbx), %zmm0{%k1}");
    VBROADCASTSD(ZMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastsd %xmm0, %zmm0{%k1}");
    VBROADCASTSD(YMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcastsd (%rbx), %ymm0{%k1}{z}");
    VBROADCASTSD(YMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastsd %xmm0, %ymm0{%k1}{z}");
    VBROADCASTSD(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcastsd (%rbx), %zmm0{%k1}{z}");
    VBROADCASTSD(ZMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastsd %xmm0, %zmm0{%k1}{z}");

    VBROADCASTF32X2(YMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 (%rbx), %ymm0");
    VBROADCASTF32X2(YMM0, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 %xmm0, %ymm0");
    VBROADCASTF32X2(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 (%rbx), %zmm0");
    VBROADCASTF32X2(ZMM0, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 %xmm0, %zmm0");
    VBROADCASTF32X2(YMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 (%rbx), %ymm0{%k1}");
    VBROADCASTF32X2(YMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 %xmm0, %ymm0{%k1}");
    VBROADCASTF32X2(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 (%rbx), %zmm0{%k1}");
    VBROADCASTF32X2(ZMM0.k1, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 %xmm0, %zmm0{%k1}");
    VBROADCASTF32X2(YMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 (%rbx), %ymm0{%k1}{z}");
    VBROADCASTF32X2(YMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 %xmm0, %ymm0{%k1}{z}");
    VBROADCASTF32X2(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 (%rbx), %zmm0{%k1}{z}");
    VBROADCASTF32X2(ZMM0.k1.z, XMM0);
    EXPECT_EQ(asmstr(), "vbroadcastf32x2 %xmm0, %zmm0{%k1}{z}");
}

TEST(Instruction4, Type4)
{
    m64 addr1 { EAX };
    m128 addr2 { EBX };
    imm8 mask { 255 };

    PALIGNR(MM0, MM1, mask);
    EXPECT_EQ(asmstr(), "palignr $0xFF, %mm1, %mm0");
    PALIGNR(MM0, addr1, mask);
    EXPECT_EQ(asmstr(), "palignr $0xFF, (%eax), %mm0");
    PALIGNR(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "palignr $0xFF, %xmm1, %xmm0");
    PALIGNR(XMM0, addr2, mask);
    EXPECT_EQ(asmstr(), "palignr $0xFF, (%ebx), %xmm0");
}

TEST(Instruction4, Type5)
{
    m32 addr { RAX };

    VMOVD(XMM0, EAX);
    EXPECT_EQ(asmstr(), "vmovd %eax, %xmm0");
    VMOVD(XMM0, addr);
    EXPECT_EQ(asmstr(), "vmovd (%rax), %xmm0");
    VMOVD(EAX, XMM0);
    EXPECT_EQ(asmstr(), "vmovd %xmm0, %eax");
    VMOVD(addr, XMM0);
    EXPECT_EQ(asmstr(), "vmovd %xmm0, (%rax)");
}

TEST(Instruction4, Type6)
{
    m64 addr { RAX };

    VMOVQ(XMM0, RAX);
    EXPECT_EQ(asmstr(), "vmovq %rax, %xmm0");
    VMOVQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "vmovq (%rax), %xmm0");
    VMOVQ(RAX, XMM0);
    EXPECT_EQ(asmstr(), "vmovq %xmm0, %rax");
    VMOVQ(addr, XMM0);
    EXPECT_EQ(asmstr(), "vmovq %xmm0, (%rax)");
}

TEST(Instruction4, Type7)
{
    m32 addr1 { EAX };
    m64 addr2 { EBX };

    ADCX(EAX, EBX);
    EXPECT_EQ(asmstr(), "adcx %ebx, %eax");
    ADCX(EAX, addr1);
    EXPECT_EQ(asmstr(), "adcx (%eax), %eax");
    ADCX(RAX, RBX);
    EXPECT_EQ(asmstr(), "adcx %rbx, %rax");
    ADCX(RAX, addr2);
    EXPECT_EQ(asmstr(), "adcx (%ebx), %rax");

    ADOX(EAX, EBX);
    EXPECT_EQ(asmstr(), "adox %ebx, %eax");
    ADOX(EAX, addr1);
    EXPECT_EQ(asmstr(), "adox (%eax), %eax");
    ADOX(RAX, RBX);
    EXPECT_EQ(asmstr(), "adox %rbx, %rax");
    ADOX(RAX, addr2);
    EXPECT_EQ(asmstr(), "adox (%ebx), %rax");
}

TEST(Instruction4, Type8)
{
    m32 addr1 { RAX };
    m64 addr2 { RBX };

    CVTSI2SS(XMM0, EAX);
    EXPECT_EQ(asmstr(), "cvtsi2ss %eax, %xmm0");
    CVTSI2SS(XMM0, addr1);
    EXPECT_EQ(asmstr(), "cvtsi2ssl (%rax), %xmm0");
    CVTSI2SS(XMM0, RAX);
    EXPECT_EQ(asmstr(), "cvtsi2ss %rax, %xmm0");
    CVTSI2SS(XMM0, addr2);
    EXPECT_EQ(asmstr(), "cvtsi2ssq (%rbx), %xmm0");

    CVTSI2SD(XMM0, EAX);
    EXPECT_EQ(asmstr(), "cvtsi2sd %eax, %xmm0");
    CVTSI2SD(XMM0, addr1);
    EXPECT_EQ(asmstr(), "cvtsi2sdl (%rax), %xmm0");
    CVTSI2SD(XMM0, RAX);
    EXPECT_EQ(asmstr(), "cvtsi2sd %rax, %xmm0");
    CVTSI2SD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "cvtsi2sdq (%rbx), %xmm0");
}

TEST(Instruction4, Type9)
{
    m32 addr { EAX };

    CVTSS2SI(EAX, XMM0);
    EXPECT_EQ(asmstr(), "cvtss2si %xmm0, %eax");
    CVTSS2SI(EAX, addr);
    EXPECT_EQ(asmstr(), "cvtss2si (%eax), %eax");
    CVTSS2SI(RAX, XMM0);
    EXPECT_EQ(asmstr(), "cvtss2si %xmm0, %rax");
    CVTSS2SI(RAX, addr);
    EXPECT_EQ(asmstr(), "cvtss2si (%eax), %rax");

    CVTTSS2SI(EAX, XMM0);
    EXPECT_EQ(asmstr(), "cvttss2si %xmm0, %eax");
    CVTTSS2SI(EAX, addr);
    EXPECT_EQ(asmstr(), "cvttss2si (%eax), %eax");
    CVTTSS2SI(RAX, XMM0);
    EXPECT_EQ(asmstr(), "cvttss2si %xmm0, %rax");
    CVTTSS2SI(RAX, addr);
    EXPECT_EQ(asmstr(), "cvttss2si (%eax), %rax");

    VCVTTSS2SI(EAX, XMM0);
    EXPECT_EQ(asmstr(), "vcvttss2si %xmm0, %eax");
    VCVTTSS2SI(EAX, addr);
    EXPECT_EQ(asmstr(), "vcvttss2si (%eax), %eax");
    VCVTTSS2SI(RAX, XMM0);
    EXPECT_EQ(asmstr(), "vcvttss2si %xmm0, %rax");
    VCVTTSS2SI(RAX, addr);
    EXPECT_EQ(asmstr(), "vcvttss2si (%eax), %rax");

    VCVTSS2SI(EAX, XMM0);
    EXPECT_EQ(asmstr(), "vcvtss2si %xmm0, %eax");
    VCVTSS2SI(EAX, addr);
    EXPECT_EQ(asmstr(), "vcvtss2si (%eax), %eax");
    VCVTSS2SI(RAX, XMM0);
    EXPECT_EQ(asmstr(), "vcvtss2si %xmm0, %rax");
    VCVTSS2SI(RAX, addr);
    EXPECT_EQ(asmstr(), "vcvtss2si (%eax), %rax");
}

TEST(Instruction4, Type10)
{
    m32fp addr1 { RAX };
    m64fp addr2 { RBX };

    FCOM();
    EXPECT_EQ(asmstr(), "fcom");
    FCOM(ST(1));
    EXPECT_EQ(asmstr(), "fcom %st(1)");
    FCOM(addr1);
    EXPECT_EQ(asmstr(), "fcoms (%rax)");
    FCOM(addr2);
    EXPECT_EQ(asmstr(), "fcoml (%rbx)");

    FCOMP();
    EXPECT_EQ(asmstr(), "fcomp");
    FCOMP(ST(1));
    EXPECT_EQ(asmstr(), "fcomp %st(1)");
    FCOMP(addr1);
    EXPECT_EQ(asmstr(), "fcomps (%rax)");
    FCOMP(addr2);
    EXPECT_EQ(asmstr(), "fcompl (%rbx)");
}

TEST(Instruction4, Type11)
{
    m16 addr { RAX };
    imm8 mask { 255 };

    PINSRW(MM0, EAX, mask);
    EXPECT_EQ(asmstr(), "pinsrw $0xFF, %eax, %mm0");
    PINSRW(MM0, addr, mask);
    EXPECT_EQ(asmstr(), "pinsrw $0xFF, (%rax), %mm0");
    PINSRW(XMM0, EAX, mask);
    EXPECT_EQ(asmstr(), "pinsrw $0xFF, %eax, %xmm0");
    PINSRW(XMM0, addr, mask);
    EXPECT_EQ(asmstr(), "pinsrw $0xFF, (%rax), %xmm0");
}

TEST(Instruction4, Type12)
{
    PMOVMSKB(EAX, MM0);
    EXPECT_EQ(asmstr(), "pmovmskb %mm0, %eax");
    PMOVMSKB(RAX, MM0);
    EXPECT_EQ(asmstr(), "pmovmskb %mm0, %rax");
    PMOVMSKB(EAX, XMM0);
    EXPECT_EQ(asmstr(), "pmovmskb %xmm0, %eax");
    PMOVMSKB(RAX, XMM0);
    EXPECT_EQ(asmstr(), "pmovmskb %xmm0, %rax");
}

TEST(Instruction4, AllTypes)
{
    gen_Instruction4_Type13(CVTSD2SI);
    gen_Instruction4_Type13(CVTTSD2SI);
    gen_Instruction4_Type13(VCVTSD2SI);
    gen_Instruction4_Type13(VCVTTSD2SI);

    gen_Instruction4_Type14(BLENDVPD);
    gen_Instruction4_Type14(BLENDVPS);
    gen_Instruction4_Type14(PBLENDVB);

    gen_Instruction4_Type15(VCVTPH2PS);
    gen_Instruction4_Type15(VCVTPS2PD);
    gen_Instruction4_Type15(VCVTDQ2PD);

    gen_Instruction4_Type16(VCVTPS2PH);

    gen_Instruction4_Type17(VFMADD132PD);
    gen_Instruction4_Type17(VFMADD213PD);
    gen_Instruction4_Type17(VFMADD231PD);
    gen_Instruction4_Type17(VFMADD132PS);
    gen_Instruction4_Type17(VFMADD213PS);
    gen_Instruction4_Type17(VFMADD231PS);
    gen_Instruction4_Type17(VFMADDSUB132PD);
    gen_Instruction4_Type17(VFMADDSUB213PD);
    gen_Instruction4_Type17(VFMADDSUB231PD);
    gen_Instruction4_Type17(VFMADDSUB132PS);
    gen_Instruction4_Type17(VFMADDSUB213PS);
    gen_Instruction4_Type17(VFMADDSUB231PS);
    gen_Instruction4_Type17(VFMSUBADD132PD);
    gen_Instruction4_Type17(VFMSUBADD213PD);
    gen_Instruction4_Type17(VFMSUBADD231PD);
    gen_Instruction4_Type17(VFMSUBADD132PS);
    gen_Instruction4_Type17(VFMSUBADD213PS);
    gen_Instruction4_Type17(VFMSUBADD231PS);
    gen_Instruction4_Type17(VFMSUB132PD);
    gen_Instruction4_Type17(VFMSUB213PD);
    gen_Instruction4_Type17(VFMSUB231PD);
    gen_Instruction4_Type17(VFMSUB132PS);
    gen_Instruction4_Type17(VFMSUB213PS);
    gen_Instruction4_Type17(VFMSUB231PS);
    gen_Instruction4_Type17(VFNMADD132PD);
    gen_Instruction4_Type17(VFNMADD213PD);
    gen_Instruction4_Type17(VFNMADD231PD);
    gen_Instruction4_Type17(VFNMADD132PS);
    gen_Instruction4_Type17(VFNMADD213PS);
    gen_Instruction4_Type17(VFNMADD231PS);
    gen_Instruction4_Type17(VFNMSUB132PD);
    gen_Instruction4_Type17(VFNMSUB213PD);
    gen_Instruction4_Type17(VFNMSUB231PD);
    gen_Instruction4_Type17(VFNMSUB132PS);
    gen_Instruction4_Type17(VFNMSUB213PS);
    gen_Instruction4_Type17(VFNMSUB231PS);
    gen_Instruction4_Type17(VADDPD);
    gen_Instruction4_Type17(VADDPS);
    gen_Instruction4_Type17(VSUBPD);
    gen_Instruction4_Type17(VSUBPS);
    gen_Instruction4_Type17(VMULPD);
    gen_Instruction4_Type17(VMULPS);
    gen_Instruction4_Type17(VDIVPD);
    gen_Instruction4_Type17(VDIVPS);
    gen_Instruction4_Type17(VMINPS);
    gen_Instruction4_Type17(VMINPD);
    gen_Instruction4_Type17(VMAXPS);
    gen_Instruction4_Type17(VMAXPD);
    gen_Instruction4_Type17(VHADDPS);
    gen_Instruction4_Type17(VHADDPD);
    gen_Instruction4_Type17(VHSUBPS);
    gen_Instruction4_Type17(VHSUBPD);
    gen_Instruction4_Type17(VADDSUBPS);
    gen_Instruction4_Type17(VADDSUBPD);
    gen_Instruction4_Type17(VUNPCKHPD);
    gen_Instruction4_Type17(VUNPCKLPD);
    gen_Instruction4_Type17(VUNPCKHPS);
    gen_Instruction4_Type17(VUNPCKLPS);
    gen_Instruction4_Type17(VXORPS);
    gen_Instruction4_Type17(VXORPD);
    gen_Instruction4_Type17(VORPS);
    gen_Instruction4_Type17(VORPD);
    gen_Instruction4_Type17(VANDPS);
    gen_Instruction4_Type17(VANDPD);
    gen_Instruction4_Type17(VANDNPS);
    gen_Instruction4_Type17(VANDNPD);

    gen_Instruction4_Type18(VSQRTPD);
    gen_Instruction4_Type18(VSQRTPS);
    gen_Instruction4_Type18(VRSQRTPS);
    gen_Instruction4_Type18(VRCPPS);
    gen_Instruction4_Type18(VCVTPS2DQ);
    gen_Instruction4_Type18(VCVTDQ2PS);
    gen_Instruction4_Type18(VCVTTPS2DQ);
    gen_Instruction4_Type18(VPTEST);
    gen_Instruction4_Type18(VTESTPS);
    gen_Instruction4_Type18(VTESTPD);
    gen_Instruction4_Type18(VMOVSHDUP);
    gen_Instruction4_Type18(VMOVSLDUP);
    gen_Instruction4_Type18(VMOVDDUP);

    gen_Instruction4_Type19(VCVTPD2PS);
    gen_Instruction4_Type19(VCVTTPD2DQ);
    gen_Instruction4_Type19(VCVTPD2DQ);

    gen_Instruction4_Type20(VCMPPS);
    gen_Instruction4_Type20(VCMPPD);
    gen_Instruction4_Type20(VDPPS);
    gen_Instruction4_Type20(VBLENDPS);
    gen_Instruction4_Type20(VBLENDPD);
    gen_Instruction4_Type20(VSHUFPS);
    gen_Instruction4_Type20(VSHUFPD);

    gen_Instruction4_Type21(VROUNDPS);
    gen_Instruction4_Type21(VROUNDPD);

    gen_Instruction4_Type22(VMOVMSKPS);
    gen_Instruction4_Type22(VMOVMSKPD);

    gen_Instruction4_Type23(VBLENDVPD);
    gen_Instruction4_Type23(VBLENDVPS);

    gen_Instruction4_Type24(VMASKMOVPS);
    gen_Instruction4_Type24(VMASKMOVPD);
    gen_Instruction4_Type24(VPMASKMOVD);
    gen_Instruction4_Type24(VPMASKMOVQ);

    gen_Instruction4_Type25(VCVTSI2SS);
    gen_Instruction4_Type25(VCVTSI2SD);

    gen_Instruction4_Type26(VMREAD);

    gen_Instruction4_Type27(VMWRITE);

    gen_Instruction4_Type28(VINSERTI32X4);
    gen_Instruction4_Type28(VINSERTI64X2);
}
