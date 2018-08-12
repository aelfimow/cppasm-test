#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

static void gen_Instruction12_Type2(Instruction12_Type2 &instr)
{
    m8 addr1 { RDX };
    m16 addr2 { RDX };
    m32 addr3 { RDX };
    m64 addr4 { RDX };
    instr(AL, BL);
    instr(addr1, CL);
    instr(CL, addr1);
    instr(AX, BX);
    instr(addr2, CX);
    instr(CX, addr2);
    instr(EAX, EBX);
    instr(addr3, ECX);
    instr(ECX, addr3);
    instr(RAX, RBX);
    instr(addr4, RCX);
    instr(RCX, addr4);
}

static void gen_Instruction12_Type3(Instruction12_Type3 &instr)
{
    m8 addr1 { RDX };
    m16 addr2 { RDX };
    instr(AX, BL);
    instr(AX, addr1);
    instr(EAX, BL);
    instr(EAX, addr1);
    instr(RAX, BL);
    instr(RAX, addr1);
    instr(EAX, AX);
    instr(EAX, addr2);
    instr(RAX, BX);
    instr(RAX, addr2);
}

static void gen_Instruction12_Type4(Instruction12_Type4 &instr)
{
    imm8 value { 1 };
    m16 addr1 { RDX };
    m32 addr2 { RDX };
    m64 addr3 { RDX };
    instr(AX, BX, value);
    instr(addr1, BX, value);
    instr(AX, BX, CL);
    instr(addr1, BX, CL);
    instr(EAX, EBX, value);
    instr(addr2, EBX, value);
    instr(RAX, RBX, value);
    instr(addr3, RBX, value);
    instr(EAX, EBX, CL);
    instr(addr2, EBX, CL);
    instr(RAX, RBX, CL);
    instr(addr3, RBX, CL);
}

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

TEST(Instruction12, TypeX)
{
    gen_Instruction12_Type2(XCHG);

    gen_Instruction12_Type3(MOVSX);
    gen_Instruction12_Type3(MOVZX);

    gen_Instruction12_Type4(SHLD);
    gen_Instruction12_Type4(SHRD);
}
