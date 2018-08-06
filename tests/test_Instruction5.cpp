#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

static void gen_Instruction5_Type2(Instruction5_Type2 &instr)
{
    imm8 mask { 255 };
    m16 addr { EAX };
    instr(EAX, MM0, mask);
    instr(RAX, MM0, mask);
    instr(EAX, XMM0, mask);
    instr(RAX, XMM0, mask);
    instr(addr, XMM0, mask);
}

static void gen_Instruction5_Type3(Instruction5_Type3 &instr)
{
    m8 addr { RDX };
    instr(k1, k2);
    instr(k1, addr);
    instr(addr, k1);
    instr(k1, EAX);
    instr(EAX, k2);
}

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

TEST(Instruction5, AllTypes)
{
    gen_Instruction5_Type2(PEXTRW);

    gen_Instruction5_Type3(KMOVB);
    gen_Instruction5_Type4(KMOVW);
    gen_Instruction5_Type5(KMOVD);
    gen_Instruction5_Type6(KMOVQ);
}
