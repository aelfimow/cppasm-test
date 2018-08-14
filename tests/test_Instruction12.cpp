#include <gtest/gtest.h>
#include <cppasm.h>
#include "asmstr.h"


TEST(Instruction12, Type1)
{
    m16 addr1 { RDX };
    m32 addr2 { RDX };
    m64 addr3 { RDX };
    imm8 value { 1 };

    BT(AX, BX);
    EXPECT_EQ(asmstr(), "bt %bx, %ax");
    BT(addr1, AX);
    EXPECT_EQ(asmstr(), "bt %ax, (%rdx)");
    BT(EAX, EBX);
    EXPECT_EQ(asmstr(), "bt %ebx, %eax");
    BT(addr2, EAX);
    EXPECT_EQ(asmstr(), "bt %eax, (%rdx)");
    BT(RAX, RBX);
    EXPECT_EQ(asmstr(), "bt %rbx, %rax");
    BT(addr3, RAX);
    EXPECT_EQ(asmstr(), "bt %rax, (%rdx)");
    BT(AX, value);
    EXPECT_EQ(asmstr(), "bt $0x01, %ax");
    BT(EAX, value);
    EXPECT_EQ(asmstr(), "bt $0x01, %eax");
    BT(RAX, value);
    EXPECT_EQ(asmstr(), "bt $0x01, %rax");
    BT(addr1, value);
    EXPECT_EQ(asmstr(), "btw $0x01, (%rdx)");
    BT(addr2, value);
    EXPECT_EQ(asmstr(), "btl $0x01, (%rdx)");
    BT(addr3, value);
    EXPECT_EQ(asmstr(), "btq $0x01, (%rdx)");

    BTC(AX, BX);
    EXPECT_EQ(asmstr(), "btc %bx, %ax");
    BTC(addr1, AX);
    EXPECT_EQ(asmstr(), "btc %ax, (%rdx)");
    BTC(EAX, EBX);
    EXPECT_EQ(asmstr(), "btc %ebx, %eax");
    BTC(addr2, EAX);
    EXPECT_EQ(asmstr(), "btc %eax, (%rdx)");
    BTC(RAX, RBX);
    EXPECT_EQ(asmstr(), "btc %rbx, %rax");
    BTC(addr3, RAX);
    EXPECT_EQ(asmstr(), "btc %rax, (%rdx)");
    BTC(AX, value);
    EXPECT_EQ(asmstr(), "btc $0x01, %ax");
    BTC(EAX, value);
    EXPECT_EQ(asmstr(), "btc $0x01, %eax");
    BTC(RAX, value);
    EXPECT_EQ(asmstr(), "btc $0x01, %rax");
    BTC(addr1, value);
    EXPECT_EQ(asmstr(), "btcw $0x01, (%rdx)");
    BTC(addr2, value);
    EXPECT_EQ(asmstr(), "btcl $0x01, (%rdx)");
    BTC(addr3, value);
    EXPECT_EQ(asmstr(), "btcq $0x01, (%rdx)");

    BTR(AX, BX);
    EXPECT_EQ(asmstr(), "btr %bx, %ax");
    BTR(addr1, AX);
    EXPECT_EQ(asmstr(), "btr %ax, (%rdx)");
    BTR(EAX, EBX);
    EXPECT_EQ(asmstr(), "btr %ebx, %eax");
    BTR(addr2, EAX);
    EXPECT_EQ(asmstr(), "btr %eax, (%rdx)");
    BTR(RAX, RBX);
    EXPECT_EQ(asmstr(), "btr %rbx, %rax");
    BTR(addr3, RAX);
    EXPECT_EQ(asmstr(), "btr %rax, (%rdx)");
    BTR(AX, value);
    EXPECT_EQ(asmstr(), "btr $0x01, %ax");
    BTR(EAX, value);
    EXPECT_EQ(asmstr(), "btr $0x01, %eax");
    BTR(RAX, value);
    EXPECT_EQ(asmstr(), "btr $0x01, %rax");
    BTR(addr1, value);
    EXPECT_EQ(asmstr(), "btrw $0x01, (%rdx)");
    BTR(addr2, value);
    EXPECT_EQ(asmstr(), "btrl $0x01, (%rdx)");
    BTR(addr3, value);
    EXPECT_EQ(asmstr(), "btrq $0x01, (%rdx)");

    BTS(AX, BX);
    EXPECT_EQ(asmstr(), "bts %bx, %ax");
    BTS(addr1, AX);
    EXPECT_EQ(asmstr(), "bts %ax, (%rdx)");
    BTS(EAX, EBX);
    EXPECT_EQ(asmstr(), "bts %ebx, %eax");
    BTS(addr2, EAX);
    EXPECT_EQ(asmstr(), "bts %eax, (%rdx)");
    BTS(RAX, RBX);
    EXPECT_EQ(asmstr(), "bts %rbx, %rax");
    BTS(addr3, RAX);
    EXPECT_EQ(asmstr(), "bts %rax, (%rdx)");
    BTS(AX, value);
    EXPECT_EQ(asmstr(), "bts $0x01, %ax");
    BTS(EAX, value);
    EXPECT_EQ(asmstr(), "bts $0x01, %eax");
    BTS(RAX, value);
    EXPECT_EQ(asmstr(), "bts $0x01, %rax");
    BTS(addr1, value);
    EXPECT_EQ(asmstr(), "btsw $0x01, (%rdx)");
    BTS(addr2, value);
    EXPECT_EQ(asmstr(), "btsl $0x01, (%rdx)");
    BTS(addr3, value);
    EXPECT_EQ(asmstr(), "btsq $0x01, (%rdx)");
}

TEST(Instruction12, Type2)
{
    m8 addr1 { RDX };
    m16 addr2 { RDX };
    m32 addr3 { RDX };
    m64 addr4 { RDX };

    XCHG(AL, BL);
    EXPECT_EQ(asmstr(), "xchg %bl, %al");
    XCHG(addr1, CL);
    EXPECT_EQ(asmstr(), "xchg %cl, (%rdx)");
    XCHG(CL, addr1);
    EXPECT_EQ(asmstr(), "xchg (%rdx), %cl");
    XCHG(AX, BX);
    EXPECT_EQ(asmstr(), "xchg %bx, %ax");
    XCHG(addr2, CX);
    EXPECT_EQ(asmstr(), "xchg %cx, (%rdx)");
    XCHG(CX, addr2);
    EXPECT_EQ(asmstr(), "xchg (%rdx), %cx");
    XCHG(EAX, EBX);
    EXPECT_EQ(asmstr(), "xchg %ebx, %eax");
    XCHG(addr3, ECX);
    EXPECT_EQ(asmstr(), "xchg %ecx, (%rdx)");
    XCHG(ECX, addr3);
    EXPECT_EQ(asmstr(), "xchg (%rdx), %ecx");
    XCHG(RAX, RBX);
    EXPECT_EQ(asmstr(), "xchg %rbx, %rax");
    XCHG(addr4, RCX);
    EXPECT_EQ(asmstr(), "xchg %rcx, (%rdx)");
    XCHG(RCX, addr4);
    EXPECT_EQ(asmstr(), "xchg (%rdx), %rcx");
}

TEST(Instruction12, Type3)
{
    m8 addr1 { RDX };
    m16 addr2 { RDX };

    MOVSX(AX, BL);
    EXPECT_EQ(asmstr(), "movsbw %bl, %ax");
    MOVSX(AX, addr1);
    EXPECT_EQ(asmstr(), "movsbw (%rdx), %ax");
    MOVSX(EAX, BL);
    EXPECT_EQ(asmstr(), "movsbl %bl, %eax");
    MOVSX(EAX, addr1);
    EXPECT_EQ(asmstr(), "movsbl (%rdx), %eax");
    MOVSX(RAX, BL);
    EXPECT_EQ(asmstr(), "movsbq %bl, %rax");
    MOVSX(RAX, addr1);
    EXPECT_EQ(asmstr(), "movsbq (%rdx), %rax");
    MOVSX(EAX, AX);
    EXPECT_EQ(asmstr(), "movswl %ax, %eax");
    MOVSX(EAX, addr2);
    EXPECT_EQ(asmstr(), "movswl (%rdx), %eax");
    MOVSX(RAX, BX);
    EXPECT_EQ(asmstr(), "movswq %bx, %rax");
    MOVSX(RAX, addr2);
    EXPECT_EQ(asmstr(), "movswq (%rdx), %rax");

    MOVZX(AX, BL);
    EXPECT_EQ(asmstr(), "movzbw %bl, %ax");
    MOVZX(AX, addr1);
    EXPECT_EQ(asmstr(), "movzbw (%rdx), %ax");
    MOVZX(EAX, BL);
    EXPECT_EQ(asmstr(), "movzbl %bl, %eax");
    MOVZX(EAX, addr1);
    EXPECT_EQ(asmstr(), "movzbl (%rdx), %eax");
    MOVZX(RAX, BL);
    EXPECT_EQ(asmstr(), "movzbq %bl, %rax");
    MOVZX(RAX, addr1);
    EXPECT_EQ(asmstr(), "movzbq (%rdx), %rax");
    MOVZX(EAX, AX);
    EXPECT_EQ(asmstr(), "movzwl %ax, %eax");
    MOVZX(EAX, addr2);
    EXPECT_EQ(asmstr(), "movzwl (%rdx), %eax");
    MOVZX(RAX, BX);
    EXPECT_EQ(asmstr(), "movzwq %bx, %rax");
    MOVZX(RAX, addr2);
    EXPECT_EQ(asmstr(), "movzwq (%rdx), %rax");
}

TEST(Instruction12, Type4)
{
    imm8 value { 1 };
    m16 addr1 { RDX };
    m32 addr2 { RDX };
    m64 addr3 { RDX };

    SHLD(AX, BX, value);
    EXPECT_EQ(asmstr(), "shld $0x01, %bx, %ax");
    SHLD(addr1, BX, value);
    EXPECT_EQ(asmstr(), "shld $0x01, %bx, (%rdx)");
    SHLD(AX, BX, CL);
    EXPECT_EQ(asmstr(), "shld %cl, %bx, %ax");
    SHLD(addr1, BX, CL);
    EXPECT_EQ(asmstr(), "shld %cl, %bx, (%rdx)");
    SHLD(EAX, EBX, value);
    EXPECT_EQ(asmstr(), "shld $0x01, %ebx, %eax");
    SHLD(addr2, EBX, value);
    EXPECT_EQ(asmstr(), "shld $0x01, %ebx, (%rdx)");
    SHLD(RAX, RBX, value);
    EXPECT_EQ(asmstr(), "shld $0x01, %rbx, %rax");
    SHLD(addr3, RBX, value);
    EXPECT_EQ(asmstr(), "shld $0x01, %rbx, (%rdx)");
    SHLD(EAX, EBX, CL);
    EXPECT_EQ(asmstr(), "shld %cl, %ebx, %eax");
    SHLD(addr2, EBX, CL);
    EXPECT_EQ(asmstr(), "shld %cl, %ebx, (%rdx)");
    SHLD(RAX, RBX, CL);
    EXPECT_EQ(asmstr(), "shld %cl, %rbx, %rax");
    SHLD(addr3, RBX, CL);
    EXPECT_EQ(asmstr(), "shld %cl, %rbx, (%rdx)");

    SHRD(AX, BX, value);
    EXPECT_EQ(asmstr(), "shrd $0x01, %bx, %ax");
    SHRD(addr1, BX, value);
    EXPECT_EQ(asmstr(), "shrd $0x01, %bx, (%rdx)");
    SHRD(AX, BX, CL);
    EXPECT_EQ(asmstr(), "shrd %cl, %bx, %ax");
    SHRD(addr1, BX, CL);
    EXPECT_EQ(asmstr(), "shrd %cl, %bx, (%rdx)");
    SHRD(EAX, EBX, value);
    EXPECT_EQ(asmstr(), "shrd $0x01, %ebx, %eax");
    SHRD(addr2, EBX, value);
    EXPECT_EQ(asmstr(), "shrd $0x01, %ebx, (%rdx)");
    SHRD(RAX, RBX, value);
    EXPECT_EQ(asmstr(), "shrd $0x01, %rbx, %rax");
    SHRD(addr3, RBX, value);
    EXPECT_EQ(asmstr(), "shrd $0x01, %rbx, (%rdx)");
    SHRD(EAX, EBX, CL);
    EXPECT_EQ(asmstr(), "shrd %cl, %ebx, %eax");
    SHRD(addr2, EBX, CL);
    EXPECT_EQ(asmstr(), "shrd %cl, %ebx, (%rdx)");
    SHRD(RAX, RBX, CL);
    EXPECT_EQ(asmstr(), "shrd %cl, %rbx, %rax");
    SHRD(addr3, RBX, CL);
    EXPECT_EQ(asmstr(), "shrd %cl, %rbx, (%rdx)");
}
