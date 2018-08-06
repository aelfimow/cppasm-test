#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

static void gen_Instruction5_Type4(Instruction5_Type4 &instr)
{
    m16 addr { RDX };
    instr(k1, k2);
    instr(k1, addr);
    instr(addr, k1);
    instr(k1, EAX);
    instr(EAX, k2);
}

static void gen_Instruction5_Type5(Instruction5_Type5 &instr)
{
    m32 addr { RDX };
    instr(k1, k2);
    instr(k1, addr);
    instr(addr, k1);
    instr(k1, EAX);
    instr(EAX, k2);
}

static void gen_Instruction5_Type6(Instruction5_Type6 &instr)
{
    m64 addr { RDX };
    instr(k1, k2);
    instr(k1, addr);
    instr(addr, k1);
    instr(k1, RAX);
    instr(RAX, k2);
}

TEST(Instruction5, Type1)
{
    m16 addr1 { RAX };
    m32 addr2 { RBX };

    NOP();
    EXPECT_EQ(asmstr(), "nop");
    NOP(AX);
    EXPECT_EQ(asmstr(), "nop %ax");
    NOP(addr1);
    EXPECT_EQ(asmstr(), "nopw (%rax)");
    NOP(EAX);
    EXPECT_EQ(asmstr(), "nop %eax");
    NOP(addr2);
    EXPECT_EQ(asmstr(), "nopl (%rbx)");
}

TEST(Instruction5, Type2)
{
    imm8 mask { 255 };
    m16 addr { EAX };

    PEXTRW(EAX, MM0, mask);
    EXPECT_EQ(asmstr(), "pextrw $0xFF, %mm0, %eax");
    PEXTRW(RAX, MM0, mask);
    EXPECT_EQ(asmstr(), "pextrw $0xFF, %mm0, %rax");
    PEXTRW(EAX, XMM0, mask);
    EXPECT_EQ(asmstr(), "pextrw $0xFF, %xmm0, %eax");
    PEXTRW(RAX, XMM0, mask);
    EXPECT_EQ(asmstr(), "pextrw $0xFF, %xmm0, %rax");
    PEXTRW(addr, XMM0, mask);
    EXPECT_EQ(asmstr(), "pextrw $0xFF, %xmm0, (%eax)");
}

TEST(Instruction5, Type3)
{
    m8 addr { RDX };

    KMOVB(k1, k2);
    EXPECT_EQ(asmstr(), "kmovb %k2, %k1");
    KMOVB(k1, addr);
    EXPECT_EQ(asmstr(), "kmovb (%rdx), %k1");
    KMOVB(addr, k1);
    EXPECT_EQ(asmstr(), "kmovb %k1, (%rdx)");
    KMOVB(k1, EAX);
    EXPECT_EQ(asmstr(), "kmovb %eax, %k1");
    KMOVB(EAX, k2);
    EXPECT_EQ(asmstr(), "kmovb %k2, %eax");
}

TEST(Instruction5, AllTypes)
{
    gen_Instruction5_Type4(KMOVW);
    gen_Instruction5_Type5(KMOVD);
    gen_Instruction5_Type6(KMOVQ);
}
