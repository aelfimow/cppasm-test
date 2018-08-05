#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

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

TEST(Instruction4, Type13)
{
    m64 addr { RAX };

    CVTSD2SI(EAX, XMM0);
    EXPECT_EQ(asmstr(), "cvtsd2si %xmm0, %eax");
    CVTSD2SI(EAX, addr);
    EXPECT_EQ(asmstr(), "cvtsd2si (%rax), %eax");
    CVTSD2SI(RAX, XMM0);
    EXPECT_EQ(asmstr(), "cvtsd2si %xmm0, %rax");
    CVTSD2SI(RAX, addr);
    EXPECT_EQ(asmstr(), "cvtsd2si (%rax), %rax");

    CVTTSD2SI(EAX, XMM0);
    EXPECT_EQ(asmstr(), "cvttsd2si %xmm0, %eax");
    CVTTSD2SI(EAX, addr);
    EXPECT_EQ(asmstr(), "cvttsd2si (%rax), %eax");
    CVTTSD2SI(RAX, XMM0);
    EXPECT_EQ(asmstr(), "cvttsd2si %xmm0, %rax");
    CVTTSD2SI(RAX, addr);
    EXPECT_EQ(asmstr(), "cvttsd2si (%rax), %rax");

    VCVTSD2SI(EAX, XMM0);
    EXPECT_EQ(asmstr(), "vcvtsd2si %xmm0, %eax");
    VCVTSD2SI(EAX, addr);
    EXPECT_EQ(asmstr(), "vcvtsd2si (%rax), %eax");
    VCVTSD2SI(RAX, XMM0);
    EXPECT_EQ(asmstr(), "vcvtsd2si %xmm0, %rax");
    VCVTSD2SI(RAX, addr);
    EXPECT_EQ(asmstr(), "vcvtsd2si (%rax), %rax");

    VCVTTSD2SI(EAX, XMM0);
    EXPECT_EQ(asmstr(), "vcvttsd2si %xmm0, %eax");
    VCVTTSD2SI(EAX, addr);
    EXPECT_EQ(asmstr(), "vcvttsd2si (%rax), %eax");
    VCVTTSD2SI(RAX, XMM0);
    EXPECT_EQ(asmstr(), "vcvttsd2si %xmm0, %rax");
    VCVTTSD2SI(RAX, addr);
    EXPECT_EQ(asmstr(), "vcvttsd2si (%rax), %rax");
}

TEST(Instruction4, Type14)
{
    m128 addr { RAX };

    BLENDVPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "blendvpd %xmm1, %xmm0");
    BLENDVPD(XMM0, addr);
    EXPECT_EQ(asmstr(), "blendvpd (%rax), %xmm0");
    BLENDVPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "blendvpd %xmm0, %xmm1, %xmm2");
    BLENDVPD(XMM0, addr, XMM1);
    EXPECT_EQ(asmstr(), "blendvpd %xmm0, (%rax), %xmm1");

    BLENDVPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "blendvps %xmm1, %xmm0");
    BLENDVPS(XMM0, addr);
    EXPECT_EQ(asmstr(), "blendvps (%rax), %xmm0");
    BLENDVPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "blendvps %xmm0, %xmm1, %xmm2");
    BLENDVPS(XMM0, addr, XMM1);
    EXPECT_EQ(asmstr(), "blendvps %xmm0, (%rax), %xmm1");

    PBLENDVB(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pblendvb %xmm1, %xmm0");
    PBLENDVB(XMM0, addr);
    EXPECT_EQ(asmstr(), "pblendvb (%rax), %xmm0");
    PBLENDVB(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "pblendvb %xmm0, %xmm1, %xmm2");
    PBLENDVB(XMM0, addr, XMM1);
    EXPECT_EQ(asmstr(), "pblendvb %xmm0, (%rax), %xmm1");
}

TEST(Instruction4, Type15)
{
    m64 addr1 { RAX };
    m128 addr2 { RBX };

    VCVTPH2PS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vcvtph2ps %xmm1, %xmm0");
    VCVTPH2PS(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vcvtph2ps (%rax), %xmm0");
    VCVTPH2PS(YMM0, XMM0);
    EXPECT_EQ(asmstr(), "vcvtph2ps %xmm0, %ymm0");
    VCVTPH2PS(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vcvtph2ps (%rbx), %ymm0");

    VCVTPS2PD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vcvtps2pd %xmm1, %xmm0");
    VCVTPS2PD(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vcvtps2pd (%rax), %xmm0");
    VCVTPS2PD(YMM0, XMM0);
    EXPECT_EQ(asmstr(), "vcvtps2pd %xmm0, %ymm0");
    VCVTPS2PD(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vcvtps2pd (%rbx), %ymm0");

    VCVTDQ2PD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vcvtdq2pd %xmm1, %xmm0");
    VCVTDQ2PD(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vcvtdq2pd (%rax), %xmm0");
    VCVTDQ2PD(YMM0, XMM0);
    EXPECT_EQ(asmstr(), "vcvtdq2pd %xmm0, %ymm0");
    VCVTDQ2PD(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vcvtdq2pd (%rbx), %ymm0");
}

TEST(Instruction4, Type16)
{
    m64 addr1 { RAX };
    m128 addr2 { RBX };
    imm8 mask { 255 };

    VCVTPS2PH(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "vcvtps2ph $0xFF, %xmm1, %xmm0");
    VCVTPS2PH(addr1, XMM0, mask);
    EXPECT_EQ(asmstr(), "vcvtps2ph $0xFF, %xmm0, (%rax)");
    VCVTPS2PH(XMM0, YMM0, mask);
    EXPECT_EQ(asmstr(), "vcvtps2ph $0xFF, %ymm0, %xmm0");
    VCVTPS2PH(addr2, YMM0, mask);
    EXPECT_EQ(asmstr(), "vcvtps2ph $0xFF, %ymm0, (%rbx)");
}

TEST(Instruction4, Type17)
{
    m128 addr1 { RAX };
    m256 addr2 { RBX };

    VFMADD132PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd132pd %xmm2, %xmm1, %xmm0");
    VFMADD132PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmadd132pd (%rax), %xmm1, %xmm0");
    VFMADD132PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmadd132pd %ymm2, %ymm1, %ymm0");
    VFMADD132PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmadd132pd (%rbx), %ymm1, %ymm0");

    VFMADD213PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd213pd %xmm2, %xmm1, %xmm0");
    VFMADD213PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmadd213pd (%rax), %xmm1, %xmm0");
    VFMADD213PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmadd213pd %ymm2, %ymm1, %ymm0");
    VFMADD213PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmadd213pd (%rbx), %ymm1, %ymm0");

    VFMADD231PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd231pd %xmm2, %xmm1, %xmm0");
    VFMADD231PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmadd231pd (%rax), %xmm1, %xmm0");
    VFMADD231PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmadd231pd %ymm2, %ymm1, %ymm0");
    VFMADD231PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmadd231pd (%rbx), %ymm1, %ymm0");

    VFMADD132PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd132ps %xmm2, %xmm1, %xmm0");
    VFMADD132PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmadd132ps (%rax), %xmm1, %xmm0");
    VFMADD132PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmadd132ps %ymm2, %ymm1, %ymm0");
    VFMADD132PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmadd132ps (%rbx), %ymm1, %ymm0");

    VFMADD213PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd213ps %xmm2, %xmm1, %xmm0");
    VFMADD213PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmadd213ps (%rax), %xmm1, %xmm0");
    VFMADD213PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmadd213ps %ymm2, %ymm1, %ymm0");
    VFMADD213PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmadd213ps (%rbx), %ymm1, %ymm0");

    VFMADD231PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmadd231ps %xmm2, %xmm1, %xmm0");
    VFMADD231PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmadd231ps (%rax), %xmm1, %xmm0");
    VFMADD231PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmadd231ps %ymm2, %ymm1, %ymm0");
    VFMADD231PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmadd231ps (%rbx), %ymm1, %ymm0");

    VFMADDSUB132PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub132pd %xmm2, %xmm1, %xmm0");
    VFMADDSUB132PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmaddsub132pd (%rax), %xmm1, %xmm0");
    VFMADDSUB132PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub132pd %ymm2, %ymm1, %ymm0");
    VFMADDSUB132PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmaddsub132pd (%rbx), %ymm1, %ymm0");

    VFMADDSUB213PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub213pd %xmm2, %xmm1, %xmm0");
    VFMADDSUB213PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmaddsub213pd (%rax), %xmm1, %xmm0");
    VFMADDSUB213PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub213pd %ymm2, %ymm1, %ymm0");
    VFMADDSUB213PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmaddsub213pd (%rbx), %ymm1, %ymm0");

    VFMADDSUB231PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub231pd %xmm2, %xmm1, %xmm0");
    VFMADDSUB231PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmaddsub231pd (%rax), %xmm1, %xmm0");
    VFMADDSUB231PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub231pd %ymm2, %ymm1, %ymm0");
    VFMADDSUB231PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmaddsub231pd (%rbx), %ymm1, %ymm0");

    VFMADDSUB132PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub132ps %xmm2, %xmm1, %xmm0");
    VFMADDSUB132PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmaddsub132ps (%rax), %xmm1, %xmm0");
    VFMADDSUB132PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub132ps %ymm2, %ymm1, %ymm0");
    VFMADDSUB132PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmaddsub132ps (%rbx), %ymm1, %ymm0");

    VFMADDSUB213PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub213ps %xmm2, %xmm1, %xmm0");
    VFMADDSUB213PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmaddsub213ps (%rax), %xmm1, %xmm0");
    VFMADDSUB213PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub213ps %ymm2, %ymm1, %ymm0");
    VFMADDSUB213PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmaddsub213ps (%rbx), %ymm1, %ymm0");

    VFMADDSUB231PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub231ps %xmm2, %xmm1, %xmm0");
    VFMADDSUB231PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmaddsub231ps (%rax), %xmm1, %xmm0");
    VFMADDSUB231PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmaddsub231ps %ymm2, %ymm1, %ymm0");
    VFMADDSUB231PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmaddsub231ps (%rbx), %ymm1, %ymm0");

    VFMSUBADD132PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd132pd %xmm2, %xmm1, %xmm0");
    VFMSUBADD132PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsubadd132pd (%rax), %xmm1, %xmm0");
    VFMSUBADD132PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd132pd %ymm2, %ymm1, %ymm0");
    VFMSUBADD132PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsubadd132pd (%rbx), %ymm1, %ymm0");

    VFMSUBADD213PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd213pd %xmm2, %xmm1, %xmm0");
    VFMSUBADD213PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsubadd213pd (%rax), %xmm1, %xmm0");
    VFMSUBADD213PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd213pd %ymm2, %ymm1, %ymm0");
    VFMSUBADD213PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsubadd213pd (%rbx), %ymm1, %ymm0");

    VFMSUBADD231PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd231pd %xmm2, %xmm1, %xmm0");
    VFMSUBADD231PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsubadd231pd (%rax), %xmm1, %xmm0");
    VFMSUBADD231PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd231pd %ymm2, %ymm1, %ymm0");
    VFMSUBADD231PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsubadd231pd (%rbx), %ymm1, %ymm0");

    VFMSUBADD132PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd132ps %xmm2, %xmm1, %xmm0");
    VFMSUBADD132PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsubadd132ps (%rax), %xmm1, %xmm0");
    VFMSUBADD132PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd132ps %ymm2, %ymm1, %ymm0");
    VFMSUBADD132PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsubadd132ps (%rbx), %ymm1, %ymm0");

    VFMSUBADD213PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd213ps %xmm2, %xmm1, %xmm0");
    VFMSUBADD213PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsubadd213ps (%rax), %xmm1, %xmm0");
    VFMSUBADD213PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd213ps %ymm2, %ymm1, %ymm0");
    VFMSUBADD213PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsubadd213ps (%rbx), %ymm1, %ymm0");

    VFMSUBADD231PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd231ps %xmm2, %xmm1, %xmm0");
    VFMSUBADD231PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsubadd231ps (%rax), %xmm1, %xmm0");
    VFMSUBADD231PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsubadd231ps %ymm2, %ymm1, %ymm0");
    VFMSUBADD231PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsubadd231ps (%rbx), %ymm1, %ymm0");

    VFMSUB132PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub132pd %xmm2, %xmm1, %xmm0");
    VFMSUB132PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsub132pd (%rax), %xmm1, %xmm0");
    VFMSUB132PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsub132pd %ymm2, %ymm1, %ymm0");
    VFMSUB132PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsub132pd (%rbx), %ymm1, %ymm0");

    VFMSUB213PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub213pd %xmm2, %xmm1, %xmm0");
    VFMSUB213PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsub213pd (%rax), %xmm1, %xmm0");
    VFMSUB213PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsub213pd %ymm2, %ymm1, %ymm0");
    VFMSUB213PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsub213pd (%rbx), %ymm1, %ymm0");

    VFMSUB231PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub231pd %xmm2, %xmm1, %xmm0");
    VFMSUB231PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsub231pd (%rax), %xmm1, %xmm0");
    VFMSUB231PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsub231pd %ymm2, %ymm1, %ymm0");
    VFMSUB231PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsub231pd (%rbx), %ymm1, %ymm0");

    VFMSUB132PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub132ps %xmm2, %xmm1, %xmm0");
    VFMSUB132PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsub132ps (%rax), %xmm1, %xmm0");
    VFMSUB132PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsub132ps %ymm2, %ymm1, %ymm0");
    VFMSUB132PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsub132ps (%rbx), %ymm1, %ymm0");

    VFMSUB213PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub213ps %xmm2, %xmm1, %xmm0");
    VFMSUB213PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsub213ps (%rax), %xmm1, %xmm0");
    VFMSUB213PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsub213ps %ymm2, %ymm1, %ymm0");
    VFMSUB213PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsub213ps (%rbx), %ymm1, %ymm0");

    VFMSUB231PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfmsub231ps %xmm2, %xmm1, %xmm0");
    VFMSUB231PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfmsub231ps (%rax), %xmm1, %xmm0");
    VFMSUB231PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfmsub231ps %ymm2, %ymm1, %ymm0");
    VFMSUB231PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfmsub231ps (%rbx), %ymm1, %ymm0");

    VFNMADD132PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd132pd %xmm2, %xmm1, %xmm0");
    VFNMADD132PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmadd132pd (%rax), %xmm1, %xmm0");
    VFNMADD132PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmadd132pd %ymm2, %ymm1, %ymm0");
    VFNMADD132PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmadd132pd (%rbx), %ymm1, %ymm0");

    VFNMADD213PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd213pd %xmm2, %xmm1, %xmm0");
    VFNMADD213PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmadd213pd (%rax), %xmm1, %xmm0");
    VFNMADD213PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmadd213pd %ymm2, %ymm1, %ymm0");
    VFNMADD213PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmadd213pd (%rbx), %ymm1, %ymm0");

    VFNMADD231PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd231pd %xmm2, %xmm1, %xmm0");
    VFNMADD231PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmadd231pd (%rax), %xmm1, %xmm0");
    VFNMADD231PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmadd231pd %ymm2, %ymm1, %ymm0");
    VFNMADD231PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmadd231pd (%rbx), %ymm1, %ymm0");

    VFNMADD132PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd132ps %xmm2, %xmm1, %xmm0");
    VFNMADD132PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmadd132ps (%rax), %xmm1, %xmm0");
    VFNMADD132PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmadd132ps %ymm2, %ymm1, %ymm0");
    VFNMADD132PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmadd132ps (%rbx), %ymm1, %ymm0");

    VFNMADD213PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd213ps %xmm2, %xmm1, %xmm0");
    VFNMADD213PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmadd213ps (%rax), %xmm1, %xmm0");
    VFNMADD213PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmadd213ps %ymm2, %ymm1, %ymm0");
    VFNMADD213PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmadd213ps (%rbx), %ymm1, %ymm0");

    VFNMADD231PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmadd231ps %xmm2, %xmm1, %xmm0");
    VFNMADD231PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmadd231ps (%rax), %xmm1, %xmm0");
    VFNMADD231PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmadd231ps %ymm2, %ymm1, %ymm0");
    VFNMADD231PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmadd231ps (%rbx), %ymm1, %ymm0");

    VFNMSUB132PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub132pd %xmm2, %xmm1, %xmm0");
    VFNMSUB132PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmsub132pd (%rax), %xmm1, %xmm0");
    VFNMSUB132PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmsub132pd %ymm2, %ymm1, %ymm0");
    VFNMSUB132PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmsub132pd (%rbx), %ymm1, %ymm0");

    VFNMSUB213PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub213pd %xmm2, %xmm1, %xmm0");
    VFNMSUB213PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmsub213pd (%rax), %xmm1, %xmm0");
    VFNMSUB213PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmsub213pd %ymm2, %ymm1, %ymm0");
    VFNMSUB213PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmsub213pd (%rbx), %ymm1, %ymm0");

    VFNMSUB231PD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub231pd %xmm2, %xmm1, %xmm0");
    VFNMSUB231PD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmsub231pd (%rax), %xmm1, %xmm0");
    VFNMSUB231PD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmsub231pd %ymm2, %ymm1, %ymm0");
    VFNMSUB231PD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmsub231pd (%rbx), %ymm1, %ymm0");

    VFNMSUB132PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub132ps %xmm2, %xmm1, %xmm0");
    VFNMSUB132PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmsub132ps (%rax), %xmm1, %xmm0");
    VFNMSUB132PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmsub132ps %ymm2, %ymm1, %ymm0");
    VFNMSUB132PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmsub132ps (%rbx), %ymm1, %ymm0");

    VFNMSUB213PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub213ps %xmm2, %xmm1, %xmm0");
    VFNMSUB213PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmsub213ps (%rax), %xmm1, %xmm0");
    VFNMSUB213PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmsub213ps %ymm2, %ymm1, %ymm0");
    VFNMSUB213PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmsub213ps (%rbx), %ymm1, %ymm0");

    VFNMSUB231PS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vfnmsub231ps %xmm2, %xmm1, %xmm0");
    VFNMSUB231PS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vfnmsub231ps (%rax), %xmm1, %xmm0");
    VFNMSUB231PS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vfnmsub231ps %ymm2, %ymm1, %ymm0");
    VFNMSUB231PS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vfnmsub231ps (%rbx), %ymm1, %ymm0");

    VADDPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vaddpd %xmm2, %xmm1, %xmm0");
    VADDPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vaddpd (%rax), %xmm1, %xmm0");
    VADDPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vaddpd %ymm2, %ymm1, %ymm0");
    VADDPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vaddpd (%rbx), %ymm1, %ymm0");

    VADDPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vaddps %xmm2, %xmm1, %xmm0");
    VADDPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vaddps (%rax), %xmm1, %xmm0");
    VADDPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vaddps %ymm2, %ymm1, %ymm0");
    VADDPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vaddps (%rbx), %ymm1, %ymm0");

    VSUBPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vsubpd %xmm2, %xmm1, %xmm0");
    VSUBPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vsubpd (%rax), %xmm1, %xmm0");
    VSUBPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vsubpd %ymm2, %ymm1, %ymm0");
    VSUBPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vsubpd (%rbx), %ymm1, %ymm0");

    VSUBPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vsubps %xmm2, %xmm1, %xmm0");
    VSUBPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vsubps (%rax), %xmm1, %xmm0");
    VSUBPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vsubps %ymm2, %ymm1, %ymm0");
    VSUBPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vsubps (%rbx), %ymm1, %ymm0");

    VMULPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vmulpd %xmm2, %xmm1, %xmm0");
    VMULPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vmulpd (%rax), %xmm1, %xmm0");
    VMULPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vmulpd %ymm2, %ymm1, %ymm0");
    VMULPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vmulpd (%rbx), %ymm1, %ymm0");

    VMULPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vmulps %xmm2, %xmm1, %xmm0");
    VMULPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vmulps (%rax), %xmm1, %xmm0");
    VMULPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vmulps %ymm2, %ymm1, %ymm0");
    VMULPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vmulps (%rbx), %ymm1, %ymm0");

    VDIVPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vdivpd %xmm2, %xmm1, %xmm0");
    VDIVPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vdivpd (%rax), %xmm1, %xmm0");
    VDIVPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vdivpd %ymm2, %ymm1, %ymm0");
    VDIVPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vdivpd (%rbx), %ymm1, %ymm0");

    VDIVPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vdivps %xmm2, %xmm1, %xmm0");
    VDIVPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vdivps (%rax), %xmm1, %xmm0");
    VDIVPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vdivps %ymm2, %ymm1, %ymm0");
    VDIVPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vdivps (%rbx), %ymm1, %ymm0");

    VMINPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vminps %xmm2, %xmm1, %xmm0");
    VMINPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vminps (%rax), %xmm1, %xmm0");
    VMINPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vminps %ymm2, %ymm1, %ymm0");
    VMINPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vminps (%rbx), %ymm1, %ymm0");

    VMINPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vminpd %xmm2, %xmm1, %xmm0");
    VMINPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vminpd (%rax), %xmm1, %xmm0");
    VMINPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vminpd %ymm2, %ymm1, %ymm0");
    VMINPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vminpd (%rbx), %ymm1, %ymm0");

    VMAXPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vmaxps %xmm2, %xmm1, %xmm0");
    VMAXPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vmaxps (%rax), %xmm1, %xmm0");
    VMAXPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vmaxps %ymm2, %ymm1, %ymm0");
    VMAXPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vmaxps (%rbx), %ymm1, %ymm0");

    VMAXPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vmaxpd %xmm2, %xmm1, %xmm0");
    VMAXPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vmaxpd (%rax), %xmm1, %xmm0");
    VMAXPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vmaxpd %ymm2, %ymm1, %ymm0");
    VMAXPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vmaxpd (%rbx), %ymm1, %ymm0");

    VHADDPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vhaddps %xmm2, %xmm1, %xmm0");
    VHADDPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vhaddps (%rax), %xmm1, %xmm0");
    VHADDPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vhaddps %ymm2, %ymm1, %ymm0");
    VHADDPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vhaddps (%rbx), %ymm1, %ymm0");

    VHADDPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vhaddpd %xmm2, %xmm1, %xmm0");
    VHADDPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vhaddpd (%rax), %xmm1, %xmm0");
    VHADDPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vhaddpd %ymm2, %ymm1, %ymm0");
    VHADDPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vhaddpd (%rbx), %ymm1, %ymm0");

    VHSUBPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vhsubps %xmm2, %xmm1, %xmm0");
    VHSUBPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vhsubps (%rax), %xmm1, %xmm0");
    VHSUBPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vhsubps %ymm2, %ymm1, %ymm0");
    VHSUBPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vhsubps (%rbx), %ymm1, %ymm0");

    VHSUBPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vhsubpd %xmm2, %xmm1, %xmm0");
    VHSUBPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vhsubpd (%rax), %xmm1, %xmm0");
    VHSUBPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vhsubpd %ymm2, %ymm1, %ymm0");
    VHSUBPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vhsubpd (%rbx), %ymm1, %ymm0");

    VADDSUBPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vaddsubps %xmm2, %xmm1, %xmm0");
    VADDSUBPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vaddsubps (%rax), %xmm1, %xmm0");
    VADDSUBPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vaddsubps %ymm2, %ymm1, %ymm0");
    VADDSUBPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vaddsubps (%rbx), %ymm1, %ymm0");

    VADDSUBPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vaddsubpd %xmm2, %xmm1, %xmm0");
    VADDSUBPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vaddsubpd (%rax), %xmm1, %xmm0");
    VADDSUBPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vaddsubpd %ymm2, %ymm1, %ymm0");
    VADDSUBPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vaddsubpd (%rbx), %ymm1, %ymm0");

    VUNPCKHPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vunpckhpd %xmm2, %xmm1, %xmm0");
    VUNPCKHPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vunpckhpd (%rax), %xmm1, %xmm0");
    VUNPCKHPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vunpckhpd %ymm2, %ymm1, %ymm0");
    VUNPCKHPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vunpckhpd (%rbx), %ymm1, %ymm0");

    VUNPCKLPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vunpcklpd %xmm2, %xmm1, %xmm0");
    VUNPCKLPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vunpcklpd (%rax), %xmm1, %xmm0");
    VUNPCKLPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vunpcklpd %ymm2, %ymm1, %ymm0");
    VUNPCKLPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vunpcklpd (%rbx), %ymm1, %ymm0");

    VUNPCKHPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vunpckhps %xmm2, %xmm1, %xmm0");
    VUNPCKHPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vunpckhps (%rax), %xmm1, %xmm0");
    VUNPCKHPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vunpckhps %ymm2, %ymm1, %ymm0");
    VUNPCKHPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vunpckhps (%rbx), %ymm1, %ymm0");

    VUNPCKLPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vunpcklps %xmm2, %xmm1, %xmm0");
    VUNPCKLPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vunpcklps (%rax), %xmm1, %xmm0");
    VUNPCKLPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vunpcklps %ymm2, %ymm1, %ymm0");
    VUNPCKLPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vunpcklps (%rbx), %ymm1, %ymm0");

    VXORPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vxorps %xmm2, %xmm1, %xmm0");
    VXORPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vxorps (%rax), %xmm1, %xmm0");
    VXORPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vxorps %ymm2, %ymm1, %ymm0");
    VXORPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vxorps (%rbx), %ymm1, %ymm0");

    VXORPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vxorpd %xmm2, %xmm1, %xmm0");
    VXORPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vxorpd (%rax), %xmm1, %xmm0");
    VXORPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vxorpd %ymm2, %ymm1, %ymm0");
    VXORPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vxorpd (%rbx), %ymm1, %ymm0");

    VORPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vorps %xmm2, %xmm1, %xmm0");
    VORPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vorps (%rax), %xmm1, %xmm0");
    VORPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vorps %ymm2, %ymm1, %ymm0");
    VORPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vorps (%rbx), %ymm1, %ymm0");

    VORPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vorpd %xmm2, %xmm1, %xmm0");
    VORPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vorpd (%rax), %xmm1, %xmm0");
    VORPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vorpd %ymm2, %ymm1, %ymm0");
    VORPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vorpd (%rbx), %ymm1, %ymm0");

    VANDPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vandps %xmm2, %xmm1, %xmm0");
    VANDPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vandps (%rax), %xmm1, %xmm0");
    VANDPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vandps %ymm2, %ymm1, %ymm0");
    VANDPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vandps (%rbx), %ymm1, %ymm0");

    VANDPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vandpd %xmm2, %xmm1, %xmm0");
    VANDPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vandpd (%rax), %xmm1, %xmm0");
    VANDPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vandpd %ymm2, %ymm1, %ymm0");
    VANDPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vandpd (%rbx), %ymm1, %ymm0");

    VANDNPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vandnps %xmm2, %xmm1, %xmm0");
    VANDNPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vandnps (%rax), %xmm1, %xmm0");
    VANDNPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vandnps %ymm2, %ymm1, %ymm0");
    VANDNPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vandnps (%rbx), %ymm1, %ymm0");

    VANDNPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vandnpd %xmm2, %xmm1, %xmm0");
    VANDNPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vandnpd (%rax), %xmm1, %xmm0");
    VANDNPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vandnpd %ymm2, %ymm1, %ymm0");
    VANDNPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vandnpd (%rbx), %ymm1, %ymm0");
}

TEST(Instruction4, Type18)
{
    m128 addr1 { RAX };
    m256 addr2 { RBX };

    VSQRTPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vsqrtpd %xmm1, %xmm0");
    VSQRTPD(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vsqrtpd (%rax), %xmm0");
    VSQRTPD(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vsqrtpd %ymm1, %ymm0");
    VSQRTPD(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vsqrtpd (%rbx), %ymm0");

    VSQRTPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vsqrtps %xmm1, %xmm0");
    VSQRTPS(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vsqrtps (%rax), %xmm0");
    VSQRTPS(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vsqrtps %ymm1, %ymm0");
    VSQRTPS(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vsqrtps (%rbx), %ymm0");

    VRSQRTPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vrsqrtps %xmm1, %xmm0");
    VRSQRTPS(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vrsqrtps (%rax), %xmm0");
    VRSQRTPS(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vrsqrtps %ymm1, %ymm0");
    VRSQRTPS(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vrsqrtps (%rbx), %ymm0");

    VRCPPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vrcpps %xmm1, %xmm0");
    VRCPPS(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vrcpps (%rax), %xmm0");
    VRCPPS(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vrcpps %ymm1, %ymm0");
    VRCPPS(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vrcpps (%rbx), %ymm0");

    VCVTPS2DQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vcvtps2dq %xmm1, %xmm0");
    VCVTPS2DQ(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vcvtps2dq (%rax), %xmm0");
    VCVTPS2DQ(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vcvtps2dq %ymm1, %ymm0");
    VCVTPS2DQ(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vcvtps2dq (%rbx), %ymm0");

    VCVTDQ2PS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vcvtdq2ps %xmm1, %xmm0");
    VCVTDQ2PS(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vcvtdq2ps (%rax), %xmm0");
    VCVTDQ2PS(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vcvtdq2ps %ymm1, %ymm0");
    VCVTDQ2PS(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vcvtdq2ps (%rbx), %ymm0");

    VCVTTPS2DQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vcvttps2dq %xmm1, %xmm0");
    VCVTTPS2DQ(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vcvttps2dq (%rax), %xmm0");
    VCVTTPS2DQ(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vcvttps2dq %ymm1, %ymm0");
    VCVTTPS2DQ(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vcvttps2dq (%rbx), %ymm0");

    VPTEST(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vptest %xmm1, %xmm0");
    VPTEST(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vptest (%rax), %xmm0");
    VPTEST(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vptest %ymm1, %ymm0");
    VPTEST(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vptest (%rbx), %ymm0");

    VTESTPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vtestps %xmm1, %xmm0");
    VTESTPS(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vtestps (%rax), %xmm0");
    VTESTPS(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vtestps %ymm1, %ymm0");
    VTESTPS(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vtestps (%rbx), %ymm0");

    VTESTPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vtestpd %xmm1, %xmm0");
    VTESTPD(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vtestpd (%rax), %xmm0");
    VTESTPD(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vtestpd %ymm1, %ymm0");
    VTESTPD(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vtestpd (%rbx), %ymm0");

    VMOVSHDUP(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vmovshdup %xmm1, %xmm0");
    VMOVSHDUP(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vmovshdup (%rax), %xmm0");
    VMOVSHDUP(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vmovshdup %ymm1, %ymm0");
    VMOVSHDUP(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vmovshdup (%rbx), %ymm0");

    VMOVSLDUP(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vmovsldup %xmm1, %xmm0");
    VMOVSLDUP(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vmovsldup (%rax), %xmm0");
    VMOVSLDUP(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vmovsldup %ymm1, %ymm0");
    VMOVSLDUP(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vmovsldup (%rbx), %ymm0");

    VMOVDDUP(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vmovddup %xmm1, %xmm0");
    VMOVDDUP(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vmovddup (%rax), %xmm0");
    VMOVDDUP(YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vmovddup %ymm1, %ymm0");
    VMOVDDUP(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vmovddup (%rbx), %ymm0");
}

TEST(Instruction4, Type19)
{
    VCVTPD2PS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vcvtpd2ps %xmm1, %xmm0");
    VCVTPD2PS(XMM0, YMM1);
    EXPECT_EQ(asmstr(), "vcvtpd2ps %ymm1, %xmm0");

    VCVTTPD2DQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vcvttpd2dq %xmm1, %xmm0");
    VCVTTPD2DQ(XMM0, YMM1);
    EXPECT_EQ(asmstr(), "vcvttpd2dq %ymm1, %xmm0");

    VCVTPD2DQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vcvtpd2dq %xmm1, %xmm0");
    VCVTPD2DQ(XMM0, YMM1);
    EXPECT_EQ(asmstr(), "vcvtpd2dq %ymm1, %xmm0");
}

TEST(Instruction4, Type20)
{
    imm8 mask { 255 };
    m128 addr1 { RAX };
    m256 addr2 { RBX };

    VCMPPS(XMM0, XMM1, XMM2, mask);
    EXPECT_EQ(asmstr(), "vcmpps $0xFF, %xmm2, %xmm1, %xmm0");
    VCMPPS(XMM0, XMM1, addr1, mask);
    EXPECT_EQ(asmstr(), "vcmpps $0xFF, (%rax), %xmm1, %xmm0");
    VCMPPS(YMM0, YMM1, YMM2, mask);
    EXPECT_EQ(asmstr(), "vcmpps $0xFF, %ymm2, %ymm1, %ymm0");
    VCMPPS(YMM0, YMM1, addr2, mask);
    EXPECT_EQ(asmstr(), "vcmpps $0xFF, (%rbx), %ymm1, %ymm0");

    VCMPPD(XMM0, XMM1, XMM2, mask);
    EXPECT_EQ(asmstr(), "vcmppd $0xFF, %xmm2, %xmm1, %xmm0");
    VCMPPD(XMM0, XMM1, addr1, mask);
    EXPECT_EQ(asmstr(), "vcmppd $0xFF, (%rax), %xmm1, %xmm0");
    VCMPPD(YMM0, YMM1, YMM2, mask);
    EXPECT_EQ(asmstr(), "vcmppd $0xFF, %ymm2, %ymm1, %ymm0");
    VCMPPD(YMM0, YMM1, addr2, mask);
    EXPECT_EQ(asmstr(), "vcmppd $0xFF, (%rbx), %ymm1, %ymm0");

    VDPPS(XMM0, XMM1, XMM2, mask);
    EXPECT_EQ(asmstr(), "vdpps $0xFF, %xmm2, %xmm1, %xmm0");
    VDPPS(XMM0, XMM1, addr1, mask);
    EXPECT_EQ(asmstr(), "vdpps $0xFF, (%rax), %xmm1, %xmm0");
    VDPPS(YMM0, YMM1, YMM2, mask);
    EXPECT_EQ(asmstr(), "vdpps $0xFF, %ymm2, %ymm1, %ymm0");
    VDPPS(YMM0, YMM1, addr2, mask);
    EXPECT_EQ(asmstr(), "vdpps $0xFF, (%rbx), %ymm1, %ymm0");

    VBLENDPS(XMM0, XMM1, XMM2, mask);
    EXPECT_EQ(asmstr(), "vblendps $0xFF, %xmm2, %xmm1, %xmm0");
    VBLENDPS(XMM0, XMM1, addr1, mask);
    EXPECT_EQ(asmstr(), "vblendps $0xFF, (%rax), %xmm1, %xmm0");
    VBLENDPS(YMM0, YMM1, YMM2, mask);
    EXPECT_EQ(asmstr(), "vblendps $0xFF, %ymm2, %ymm1, %ymm0");
    VBLENDPS(YMM0, YMM1, addr2, mask);
    EXPECT_EQ(asmstr(), "vblendps $0xFF, (%rbx), %ymm1, %ymm0");

    VBLENDPD(XMM0, XMM1, XMM2, mask);
    EXPECT_EQ(asmstr(), "vblendpd $0xFF, %xmm2, %xmm1, %xmm0");
    VBLENDPD(XMM0, XMM1, addr1, mask);
    EXPECT_EQ(asmstr(), "vblendpd $0xFF, (%rax), %xmm1, %xmm0");
    VBLENDPD(YMM0, YMM1, YMM2, mask);
    EXPECT_EQ(asmstr(), "vblendpd $0xFF, %ymm2, %ymm1, %ymm0");
    VBLENDPD(YMM0, YMM1, addr2, mask);
    EXPECT_EQ(asmstr(), "vblendpd $0xFF, (%rbx), %ymm1, %ymm0");

    VSHUFPS(XMM0, XMM1, XMM2, mask);
    EXPECT_EQ(asmstr(), "vshufps $0xFF, %xmm2, %xmm1, %xmm0");
    VSHUFPS(XMM0, XMM1, addr1, mask);
    EXPECT_EQ(asmstr(), "vshufps $0xFF, (%rax), %xmm1, %xmm0");
    VSHUFPS(YMM0, YMM1, YMM2, mask);
    EXPECT_EQ(asmstr(), "vshufps $0xFF, %ymm2, %ymm1, %ymm0");
    VSHUFPS(YMM0, YMM1, addr2, mask);
    EXPECT_EQ(asmstr(), "vshufps $0xFF, (%rbx), %ymm1, %ymm0");

    VSHUFPD(XMM0, XMM1, XMM2, mask);
    EXPECT_EQ(asmstr(), "vshufpd $0xFF, %xmm2, %xmm1, %xmm0");
    VSHUFPD(XMM0, XMM1, addr1, mask);
    EXPECT_EQ(asmstr(), "vshufpd $0xFF, (%rax), %xmm1, %xmm0");
    VSHUFPD(YMM0, YMM1, YMM2, mask);
    EXPECT_EQ(asmstr(), "vshufpd $0xFF, %ymm2, %ymm1, %ymm0");
    VSHUFPD(YMM0, YMM1, addr2, mask);
    EXPECT_EQ(asmstr(), "vshufpd $0xFF, (%rbx), %ymm1, %ymm0");
}

TEST(Instruction4, Type21)
{
    imm8 mask { 255 };
    m128 addr1 { RAX };
    m256 addr2 { RBX };

    VROUNDPS(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "vroundps $0xFF, %xmm1, %xmm0");
    VROUNDPS(XMM0, addr1, mask);
    EXPECT_EQ(asmstr(), "vroundps $0xFF, (%rax), %xmm0");
    VROUNDPS(YMM0, YMM1, mask);
    EXPECT_EQ(asmstr(), "vroundps $0xFF, %ymm1, %ymm0");
    VROUNDPS(YMM0, addr2, mask);
    EXPECT_EQ(asmstr(), "vroundps $0xFF, (%rbx), %ymm0");

    VROUNDPD(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "vroundpd $0xFF, %xmm1, %xmm0");
    VROUNDPD(XMM0, addr1, mask);
    EXPECT_EQ(asmstr(), "vroundpd $0xFF, (%rax), %xmm0");
    VROUNDPD(YMM0, YMM1, mask);
    EXPECT_EQ(asmstr(), "vroundpd $0xFF, %ymm1, %ymm0");
    VROUNDPD(YMM0, addr2, mask);
    EXPECT_EQ(asmstr(), "vroundpd $0xFF, (%rbx), %ymm0");
}

TEST(Instruction4, Type22)
{
    VMOVMSKPS(EAX, XMM0);
    EXPECT_EQ(asmstr(), "vmovmskps %xmm0, %eax");
    VMOVMSKPS(RAX, XMM0);
    EXPECT_EQ(asmstr(), "vmovmskps %xmm0, %rax");
    VMOVMSKPS(EAX, YMM0);
    EXPECT_EQ(asmstr(), "vmovmskps %ymm0, %eax");
    VMOVMSKPS(RAX, YMM0);
    EXPECT_EQ(asmstr(), "vmovmskps %ymm0, %rax");

    VMOVMSKPD(EAX, XMM0);
    EXPECT_EQ(asmstr(), "vmovmskpd %xmm0, %eax");
    VMOVMSKPD(RAX, XMM0);
    EXPECT_EQ(asmstr(), "vmovmskpd %xmm0, %rax");
    VMOVMSKPD(EAX, YMM0);
    EXPECT_EQ(asmstr(), "vmovmskpd %ymm0, %eax");
    VMOVMSKPD(RAX, YMM0);
    EXPECT_EQ(asmstr(), "vmovmskpd %ymm0, %rax");
}

TEST(Instruction4, Type23)
{
    m128 addr { RAX };

    VBLENDVPD(XMM0, XMM1, XMM2, XMM3);
    EXPECT_EQ(asmstr(), "vblendvpd %xmm3, %xmm2, %xmm1, %xmm0");
    VBLENDVPD(XMM0, XMM1, addr, XMM3);
    EXPECT_EQ(asmstr(), "vblendvpd %xmm3, (%rax), %xmm1, %xmm0");
    VBLENDVPD(YMM0, YMM1, YMM2, YMM3);
    EXPECT_EQ(asmstr(), "vblendvpd %ymm3, %ymm2, %ymm1, %ymm0");
    VBLENDVPD(YMM0, YMM1, addr, YMM3);
    EXPECT_EQ(asmstr(), "vblendvpd %ymm3, (%rax), %ymm1, %ymm0");

    VBLENDVPS(XMM0, XMM1, XMM2, XMM3);
    EXPECT_EQ(asmstr(), "vblendvps %xmm3, %xmm2, %xmm1, %xmm0");
    VBLENDVPS(XMM0, XMM1, addr, XMM3);
    EXPECT_EQ(asmstr(), "vblendvps %xmm3, (%rax), %xmm1, %xmm0");
    VBLENDVPS(YMM0, YMM1, YMM2, YMM3);
    EXPECT_EQ(asmstr(), "vblendvps %ymm3, %ymm2, %ymm1, %ymm0");
    VBLENDVPS(YMM0, YMM1, addr, YMM3);
    EXPECT_EQ(asmstr(), "vblendvps %ymm3, (%rax), %ymm1, %ymm0");
}

TEST(Instruction4, Type24)
{
    m128 addr1 { RAX };
    m256 addr2 { RBX };

    VMASKMOVPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vmaskmovps (%rax), %xmm1, %xmm0");
    VMASKMOVPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vmaskmovps (%rbx), %ymm1, %ymm0");
    VMASKMOVPS(addr1, XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vmaskmovps %xmm1, %xmm0, (%rax)");
    VMASKMOVPS(addr2, YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vmaskmovps %ymm1, %ymm0, (%rbx)");

    VMASKMOVPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vmaskmovpd (%rax), %xmm1, %xmm0");
    VMASKMOVPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vmaskmovpd (%rbx), %ymm1, %ymm0");
    VMASKMOVPD(addr1, XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vmaskmovpd %xmm1, %xmm0, (%rax)");
    VMASKMOVPD(addr2, YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vmaskmovpd %ymm1, %ymm0, (%rbx)");

    VPMASKMOVD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vpmaskmovd (%rax), %xmm1, %xmm0");
    VPMASKMOVD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vpmaskmovd (%rbx), %ymm1, %ymm0");
    VPMASKMOVD(addr1, XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vpmaskmovd %xmm1, %xmm0, (%rax)");
    VPMASKMOVD(addr2, YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vpmaskmovd %ymm1, %ymm0, (%rbx)");

    VPMASKMOVQ(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vpmaskmovq (%rax), %xmm1, %xmm0");
    VPMASKMOVQ(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vpmaskmovq (%rbx), %ymm1, %ymm0");
    VPMASKMOVQ(addr1, XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vpmaskmovq %xmm1, %xmm0, (%rax)");
    VPMASKMOVQ(addr2, YMM0, YMM1);
    EXPECT_EQ(asmstr(), "vpmaskmovq %ymm1, %ymm0, (%rbx)");
}

TEST(Instruction4, AllTypes)
{
    gen_Instruction4_Type25(VCVTSI2SS);
    gen_Instruction4_Type25(VCVTSI2SD);

    gen_Instruction4_Type26(VMREAD);

    gen_Instruction4_Type27(VMWRITE);

    gen_Instruction4_Type28(VINSERTI32X4);
    gen_Instruction4_Type28(VINSERTI64X2);
}
