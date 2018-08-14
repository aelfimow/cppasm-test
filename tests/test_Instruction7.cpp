#include <gtest/gtest.h>
#include <cppasm.h>
#include "asmstr.h"


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

TEST(Instruction7, Type3)
{
    m16 addr1 { EAX };
    m32 addr2 { EBX };
    m16 addr3 { RAX };
    m32 addr4 { RBX };
    m64 addr5 { RBX };
    std::string loc { "label" };

    JMP_FAR(loc);
    EXPECT_EQ(asmstr(), "ljmp *label");
    JMP_FAR(addr1);
    EXPECT_EQ(asmstr(), "ljmp *(%eax)");
    JMP_FAR(addr2);
    EXPECT_EQ(asmstr(), "ljmp *(%ebx)");
    JMP_FAR(addr3);
    EXPECT_EQ(asmstr(), "ljmp *(%rax)");
    JMP_FAR(addr4);
    EXPECT_EQ(asmstr(), "ljmp *(%rbx)");
    JMP_FAR(addr5);
    EXPECT_EQ(asmstr(), "ljmp *(%rbx)");

    CALL_FAR(loc);
    EXPECT_EQ(asmstr(), "lcall *label");
    CALL_FAR(addr1);
    EXPECT_EQ(asmstr(), "lcall *(%eax)");
    CALL_FAR(addr2);
    EXPECT_EQ(asmstr(), "lcall *(%ebx)");
    CALL_FAR(addr3);
    EXPECT_EQ(asmstr(), "lcall *(%rax)");
    CALL_FAR(addr4);
    EXPECT_EQ(asmstr(), "lcall *(%rbx)");
    CALL_FAR(addr5);
    EXPECT_EQ(asmstr(), "lcall *(%rbx)");
}
