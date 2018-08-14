#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

TEST(Instruction36, Type1)
{
    imm8 value1 { 0x42 };
    imm16 value2 { 0x4242 };
    imm32 value3 { 0x42424242 };
    imm64 value4 { 0x4242424242424242 };
    m8  addr1 { RDX };
    m16 addr2 { RDX };
    m32 addr3 { RDX };
    m64 addr4 { RDX };

    MOV(AL, CL);
    EXPECT_EQ(asmstr(), "mov %cl, %al");
    MOV(addr1, CL);
    EXPECT_EQ(asmstr(), "mov %cl, (%rdx)");
    MOV(AX, CX);
    EXPECT_EQ(asmstr(), "mov %cx, %ax");
    MOV(addr2, CX);
    EXPECT_EQ(asmstr(), "mov %cx, (%rdx)");
    MOV(EAX, ECX);
    EXPECT_EQ(asmstr(), "mov %ecx, %eax");
    MOV(addr3, ECX);
    EXPECT_EQ(asmstr(), "mov %ecx, (%rdx)");
    MOV(RAX, RCX);
    EXPECT_EQ(asmstr(), "mov %rcx, %rax");
    MOV(addr4, RCX);
    EXPECT_EQ(asmstr(), "mov %rcx, (%rdx)");
    MOV(AL, addr1);
    EXPECT_EQ(asmstr(), "mov (%rdx), %al");
    MOV(AX, addr2);
    EXPECT_EQ(asmstr(), "mov (%rdx), %ax");
    MOV(EAX, addr3);
    EXPECT_EQ(asmstr(), "mov (%rdx), %eax");
    MOV(RAX, addr4);
    EXPECT_EQ(asmstr(), "mov (%rdx), %rax");
    MOV(AX, DS);
    EXPECT_EQ(asmstr(), "mov %ds, %ax");
    MOV(addr2, DS);
    EXPECT_EQ(asmstr(), "mov %ds, (%rdx)");
    MOV(RAX, DS);
    EXPECT_EQ(asmstr(), "mov %ds, %rax");
    MOV(addr4, DS);
    EXPECT_EQ(asmstr(), "mov %ds, (%rdx)");
    MOV(DS, CX);
    EXPECT_EQ(asmstr(), "mov %cx, %ds");
    MOV(DS, addr2);
    EXPECT_EQ(asmstr(), "mov (%rdx), %ds");
    MOV(DS, RCX);
    EXPECT_EQ(asmstr(), "mov %rcx, %ds");
    MOV(DS, addr4);
    EXPECT_EQ(asmstr(), "mov (%rdx), %ds");
    MOV(AL, value1);
    EXPECT_EQ(asmstr(), "mov $0x42, %al");
    MOV(AX, value2);
    EXPECT_EQ(asmstr(), "mov $0x4242, %ax");
    MOV(EAX, value3);
    EXPECT_EQ(asmstr(), "mov $0x42424242, %eax");
    MOV(RAX, value4);
    EXPECT_EQ(asmstr(), "mov $0x4242424242424242, %rax");
    MOV(addr1, value1);
    EXPECT_EQ(asmstr(), "movb $0x42, (%rdx)");
    MOV(addr2, value2);
    EXPECT_EQ(asmstr(), "movw $0x4242, (%rdx)");
    MOV(addr3, value3);
    EXPECT_EQ(asmstr(), "movl $0x42424242, (%rdx)");
    MOV(addr4, value3);
    EXPECT_EQ(asmstr(), "movq $0x42424242, (%rdx)");
    MOV(RAX, CR0);
    EXPECT_EQ(asmstr(), "mov %cr0, %rax");
    MOV(CR0, RCX);
    EXPECT_EQ(asmstr(), "mov %rcx, %cr0");
    MOV(RAX, DR0);
    EXPECT_EQ(asmstr(), "mov %dr0, %rax");
    MOV(DR0, RCX);
    EXPECT_EQ(asmstr(), "mov %rcx, %dr0");
}
