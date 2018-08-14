#include <gtest/gtest.h>
#include <cppasm.h>
#include "asmstr.h"


TEST(Instruction10, Type1)
{
    m16 addr1 { EDX };
    m32 addr2 { EDX };
    m16 addr3 { RDX };
    m64 addr4 { RDX };
    imm8 v1 { 0xAA };
    imm16 v2 { 0xAABB };
    imm32 v3 { 0xAABBCCDD };

    PUSH(AX);
    EXPECT_EQ(asmstr(), "push %ax");
    PUSH(EAX);
    EXPECT_EQ(asmstr(), "push %eax");
    PUSH(RAX);
    EXPECT_EQ(asmstr(), "push %rax");
    PUSH(addr1);
    EXPECT_EQ(asmstr(), "pushw (%edx)");
    PUSH(addr2);
    EXPECT_EQ(asmstr(), "pushl (%edx)");
    PUSH(addr3);
    EXPECT_EQ(asmstr(), "pushw (%rdx)");
    PUSH(addr4);
    EXPECT_EQ(asmstr(), "pushq (%rdx)");
    PUSH(v1);
    EXPECT_EQ(asmstr(), "push $0xAA");
    PUSH(v2);
    EXPECT_EQ(asmstr(), "push $0xAABB");
    PUSH(v3);
    EXPECT_EQ(asmstr(), "push $0xAABBCCDD");
    PUSH(GS);
    EXPECT_EQ(asmstr(), "push %gs");
}

TEST(Instruction10, Type2)
{
    m8 addr1 { RDX };
    m16 addr2 { RDX };
    m32 addr3 { RDX };
    m64 addr4 { RDX };

    CRC32(ECX, AL);
    EXPECT_EQ(asmstr(), "crc32 %al, %ecx");
    CRC32(ECX, addr1);
    EXPECT_EQ(asmstr(), "crc32b (%rdx), %ecx");
    CRC32(ECX, AX);
    EXPECT_EQ(asmstr(), "crc32 %ax, %ecx");
    CRC32(ECX, addr2);
    EXPECT_EQ(asmstr(), "crc32w (%rdx), %ecx");
    CRC32(ECX, EAX);
    EXPECT_EQ(asmstr(), "crc32 %eax, %ecx");
    CRC32(ECX, addr3);
    EXPECT_EQ(asmstr(), "crc32l (%rdx), %ecx");
    CRC32(RCX, AL);
    EXPECT_EQ(asmstr(), "crc32 %al, %rcx");
    CRC32(RCX, addr1);
    EXPECT_EQ(asmstr(), "crc32b (%rdx), %rcx");
    CRC32(RCX, RAX);
    EXPECT_EQ(asmstr(), "crc32 %rax, %rcx");
    CRC32(RCX, addr4);
    EXPECT_EQ(asmstr(), "crc32q (%rdx), %rcx");
}
