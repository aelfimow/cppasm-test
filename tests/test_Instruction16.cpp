#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

static void gen_Instruction16_Type2(Instruction16_Type2 &instr)
{
    imm8 value { 1 };
    m8 addr1 { RDX };
    m16 addr2 { RDX };
    m32 addr3 { RDX };
    m64 addr4 { RDX };
    instr(AL, value);
    instr(addr1, value);
    instr(AL, CL);
    instr(addr1, CL);
    instr(AX, value);
    instr(addr2, value);
    instr(AX, CL);
    instr(addr2, CL);
    instr(EAX, value);
    instr(addr3, value);
    instr(EAX, CL);
    instr(addr3, CL);
    instr(RAX, value);
    instr(addr4, value);
    instr(RAX, CL);
    instr(addr4, CL);
}

TEST(Instruction16, Type1)
{
#if 0
    imm8 value1 { 0xAA };
    imm16 value2 { 0xAABB };
    imm32 value3 { 0xAABBCCDD };
    m8 addr1 { RDX };
    m16 addr2 { RDX };
    m32 addr3 { RDX };
    m64 addr4 { RDX };

    TEST(AL, value1);
    EXPECT_EQ(asmstr(), "test $0xAA, %al");
    TEST(addr1, value1);
    EXPECT_EQ(asmstr(), "testb $0xAA, (%rdx)");
    TEST(AX, value2);
    EXPECT_EQ(asmstr(), "test $0xAABB, %ax");
    TEST(addr2, value2);
    EXPECT_EQ(asmstr(), "testw $0xAABB, (%rdx)");
    TEST(EAX, value3);
    EXPECT_EQ(asmstr(), "test $0xAABBCCDD, %eax");
    TEST(addr3, value3);
    EXPECT_EQ(asmstr(), "testl $0xAABBCCDD, (%rdx)");
    //instr(RAX, value3);
    //instr(addr4, value3);
    TEST(AL, AH);
    EXPECT_EQ(asmstr(), "test %ah, %al");
    TEST(addr1, AL);
    EXPECT_EQ(asmstr(), "test %al, (%rdx)");
    TEST(AX, BX);
    EXPECT_EQ(asmstr(), "test %bx, %ax");
    TEST(addr2, AX);
    EXPECT_EQ(asmstr(), "test %ax, (%rdx)");
    TEST(EAX, EBX);
    EXPECT_EQ(asmstr(), "test %ebx, %eax");
    TEST(addr3, EAX);
    EXPECT_EQ(asmstr(), "test %eax, (%rdx)");
    TEST(RAX, RBX);
    EXPECT_EQ(asmstr(), "test %rbx, %rax");
    TEST(addr4, RAX);
    EXPECT_EQ(asmstr(), "test %rax, (%rdx)");
#endif
}

TEST(Instruction16, TypeX)
{
    gen_Instruction16_Type2(SAL);
    gen_Instruction16_Type2(SAR);
    gen_Instruction16_Type2(SHL);
    gen_Instruction16_Type2(SHR);
    gen_Instruction16_Type2(RCL);
    gen_Instruction16_Type2(RCR);
    gen_Instruction16_Type2(ROL);
    gen_Instruction16_Type2(ROR);
}
