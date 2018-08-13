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
    TEST(addr1, value1);
    TEST(AX, value2);
    TEST(addr2, value2);
    TEST(EAX, value3);
    TEST(addr3, value3);
    //instr(RAX, value3);
    //instr(addr4, value3);
    TEST(AL, AH);
    TEST(addr1, AL);
    TEST(AX, BX);
    TEST(addr2, AX);
    TEST(EAX, EBX);
    TEST(addr3, EAX);
    TEST(RAX, RBX);
    TEST(addr4, RAX);
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
