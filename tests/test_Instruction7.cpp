#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

static void gen_Instruction7_Type3(Instruction7_Type3 &instr)
{
    m16 addr1 { RAX };
    m32 addr2 { RBX };
    m64 addr3 { RBX };
    std::string loc { "gen_Instruction7_Type3_label" };
    instr(loc);
    instr(addr1);
    instr(addr2);
    instr(addr3);
}

TEST(Instruction7, Type1)
{
    m16 addr1 { EAX };
    m32 addr2 { EBX };
    m16 addr3 { RAX };
    m32 addr4 { RBX };
    m64 addr5 { RBX };
    std::string loc { "label" };

    JMP(loc);
    EXPECT_EQ(asmstr(), "jmp label");
    JMP(AX);
    EXPECT_EQ(asmstr(), "jmp *%ax");
    JMP(EAX);
    EXPECT_EQ(asmstr(), "jmp *%eax");
    JMP(RAX);
    EXPECT_EQ(asmstr(), "jmp *%rax");
    JMP(addr1);
    EXPECT_EQ(asmstr(), "jmp *(%eax)");
    JMP(addr2);
    EXPECT_EQ(asmstr(), "jmp *(%ebx)");
    JMP(addr3);
    EXPECT_EQ(asmstr(), "jmp *(%rax)");
    JMP(addr4);
    EXPECT_EQ(asmstr(), "jmp *(%rbx)");
    JMP(addr5);
    EXPECT_EQ(asmstr(), "jmp *(%rbx)");

    CALL(loc);
    EXPECT_EQ(asmstr(), "call label");
    CALL(AX);
    EXPECT_EQ(asmstr(), "call *%ax");
    CALL(EAX);
    EXPECT_EQ(asmstr(), "call *%eax");
    CALL(RAX);
    EXPECT_EQ(asmstr(), "call *%rax");
    CALL(addr1);
    EXPECT_EQ(asmstr(), "call *(%eax)");
    CALL(addr2);
    EXPECT_EQ(asmstr(), "call *(%ebx)");
    CALL(addr3);
    EXPECT_EQ(asmstr(), "call *(%rax)");
    CALL(addr4);
    EXPECT_EQ(asmstr(), "call *(%rbx)");
    CALL(addr5);
    EXPECT_EQ(asmstr(), "call *(%rbx)");
}

TEST(Instruction7, Type2)
{
    m16 addr1 { RAX };
    m16 addr2 { EAX };
    m32 addr3 { EBX };
    m64 addr4 { RCX };

    POP(AX);
    EXPECT_EQ(asmstr(), "pop %ax");
    POP(addr1);
    EXPECT_EQ(asmstr(), "popw (%rax)");
    POP(addr2);
    EXPECT_EQ(asmstr(), "popw (%eax)");
    POP(EBX);
    EXPECT_EQ(asmstr(), "pop %ebx");
    POP(RCX);
    EXPECT_EQ(asmstr(), "pop %rcx");
    POP(addr3);
    EXPECT_EQ(asmstr(), "popl (%ebx)");
    POP(addr4);
    EXPECT_EQ(asmstr(), "popq (%rcx)");
    POP(FS);
    EXPECT_EQ(asmstr(), "pop %fs");
}

TEST(Instruction7, AllTypes)
{
    label("gen_Instruction7_Type3_label");
    gen_Instruction7_Type3(JMP_FAR);
    gen_Instruction7_Type3(CALL_FAR);
}
