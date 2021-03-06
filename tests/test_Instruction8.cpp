#include <gtest/gtest.h>
#include <cppasm.h>
#include "asmstr.h"


TEST(Instruction8, Type1)
{
    m32 addr { EDX };

    MOVD(MM0, EAX);
    EXPECT_EQ(asmstr(), "movd %eax, %mm0");
    MOVD(MM0, addr);
    EXPECT_EQ(asmstr(), "movd (%edx), %mm0");
    MOVD(EAX, MM0);
    EXPECT_EQ(asmstr(), "movd %mm0, %eax");
    MOVD(addr, MM0);
    EXPECT_EQ(asmstr(), "movd %mm0, (%edx)");
    MOVD(XMM0, EAX);
    EXPECT_EQ(asmstr(), "movd %eax, %xmm0");
    MOVD(XMM0, addr);
    EXPECT_EQ(asmstr(), "movd (%edx), %xmm0");
    MOVD(EAX, XMM0);
    EXPECT_EQ(asmstr(), "movd %xmm0, %eax");
    MOVD(addr, XMM0);
    EXPECT_EQ(asmstr(), "movd %xmm0, (%edx)");
}

TEST(Instruction8, Type2)
{
    m64 addr { RDX };

    MOVQ(MM0, RAX);
    EXPECT_EQ(asmstr(), "movq %rax, %mm0");
    MOVQ(MM0, addr);
    EXPECT_EQ(asmstr(), "movq (%rdx), %mm0");
    MOVQ(RAX, MM0);
    EXPECT_EQ(asmstr(), "movq %mm0, %rax");
    MOVQ(addr, MM0);
    EXPECT_EQ(asmstr(), "movq %mm0, (%rdx)");
    MOVQ(XMM0, RAX);
    EXPECT_EQ(asmstr(), "movq %rax, %xmm0");
    MOVQ(XMM0, addr);
    EXPECT_EQ(asmstr(), "movq (%rdx), %xmm0");
    MOVQ(RAX, XMM0);
    EXPECT_EQ(asmstr(), "movq %xmm0, %rax");
    MOVQ(addr, XMM0);
    EXPECT_EQ(asmstr(), "movq %xmm0, (%rdx)");
}

TEST(Instruction8, Type3)
{
    m8  addr1 { RDX };
    m16 addr2 { RDX };
    m32 addr3 { RDX };
    m64 addr4 { RDX };

    MUL(AL);
    EXPECT_EQ(asmstr(), "mul %al");
    MUL(AX);
    EXPECT_EQ(asmstr(), "mul %ax");
    MUL(EAX);
    EXPECT_EQ(asmstr(), "mul %eax");
    MUL(RAX);
    EXPECT_EQ(asmstr(), "mul %rax");
    MUL(addr1);
    EXPECT_EQ(asmstr(), "mulb (%rdx)");
    MUL(addr2);
    EXPECT_EQ(asmstr(), "mulw (%rdx)");
    MUL(addr3);
    EXPECT_EQ(asmstr(), "mull (%rdx)");
    MUL(addr4);
    EXPECT_EQ(asmstr(), "mulq (%rdx)");

    IMUL(AL);
    EXPECT_EQ(asmstr(), "imul %al");
    IMUL(AX);
    EXPECT_EQ(asmstr(), "imul %ax");
    IMUL(EAX);
    EXPECT_EQ(asmstr(), "imul %eax");
    IMUL(RAX);
    EXPECT_EQ(asmstr(), "imul %rax");
    IMUL(addr1);
    EXPECT_EQ(asmstr(), "imulb (%rdx)");
    IMUL(addr2);
    EXPECT_EQ(asmstr(), "imulw (%rdx)");
    IMUL(addr3);
    EXPECT_EQ(asmstr(), "imull (%rdx)");
    IMUL(addr4);
    EXPECT_EQ(asmstr(), "imulq (%rdx)");

    DIV(AL);
    EXPECT_EQ(asmstr(), "div %al");
    DIV(AX);
    EXPECT_EQ(asmstr(), "div %ax");
    DIV(EAX);
    EXPECT_EQ(asmstr(), "div %eax");
    DIV(RAX);
    EXPECT_EQ(asmstr(), "div %rax");
    DIV(addr1);
    EXPECT_EQ(asmstr(), "divb (%rdx)");
    DIV(addr2);
    EXPECT_EQ(asmstr(), "divw (%rdx)");
    DIV(addr3);
    EXPECT_EQ(asmstr(), "divl (%rdx)");
    DIV(addr4);
    EXPECT_EQ(asmstr(), "divq (%rdx)");

    IDIV(AL);
    EXPECT_EQ(asmstr(), "idiv %al");
    IDIV(AX);
    EXPECT_EQ(asmstr(), "idiv %ax");
    IDIV(EAX);
    EXPECT_EQ(asmstr(), "idiv %eax");
    IDIV(RAX);
    EXPECT_EQ(asmstr(), "idiv %rax");
    IDIV(addr1);
    EXPECT_EQ(asmstr(), "idivb (%rdx)");
    IDIV(addr2);
    EXPECT_EQ(asmstr(), "idivw (%rdx)");
    IDIV(addr3);
    EXPECT_EQ(asmstr(), "idivl (%rdx)");
    IDIV(addr4);
    EXPECT_EQ(asmstr(), "idivq (%rdx)");

    NEG(AL);
    EXPECT_EQ(asmstr(), "neg %al");
    NEG(AX);
    EXPECT_EQ(asmstr(), "neg %ax");
    NEG(EAX);
    EXPECT_EQ(asmstr(), "neg %eax");
    NEG(RAX);
    EXPECT_EQ(asmstr(), "neg %rax");
    NEG(addr1);
    EXPECT_EQ(asmstr(), "negb (%rdx)");
    NEG(addr2);
    EXPECT_EQ(asmstr(), "negw (%rdx)");
    NEG(addr3);
    EXPECT_EQ(asmstr(), "negl (%rdx)");
    NEG(addr4);
    EXPECT_EQ(asmstr(), "negq (%rdx)");

    INC(AL);
    EXPECT_EQ(asmstr(), "inc %al");
    INC(AX);
    EXPECT_EQ(asmstr(), "inc %ax");
    INC(EAX);
    EXPECT_EQ(asmstr(), "inc %eax");
    INC(RAX);
    EXPECT_EQ(asmstr(), "inc %rax");
    INC(addr1);
    EXPECT_EQ(asmstr(), "incb (%rdx)");
    INC(addr2);
    EXPECT_EQ(asmstr(), "incw (%rdx)");
    INC(addr3);
    EXPECT_EQ(asmstr(), "incl (%rdx)");
    INC(addr4);
    EXPECT_EQ(asmstr(), "incq (%rdx)");

    DEC(AL);
    EXPECT_EQ(asmstr(), "dec %al");
    DEC(AX);
    EXPECT_EQ(asmstr(), "dec %ax");
    DEC(EAX);
    EXPECT_EQ(asmstr(), "dec %eax");
    DEC(RAX);
    EXPECT_EQ(asmstr(), "dec %rax");
    DEC(addr1);
    EXPECT_EQ(asmstr(), "decb (%rdx)");
    DEC(addr2);
    EXPECT_EQ(asmstr(), "decw (%rdx)");
    DEC(addr3);
    EXPECT_EQ(asmstr(), "decl (%rdx)");
    DEC(addr4);
    EXPECT_EQ(asmstr(), "decq (%rdx)");

    NOT(AL);
    EXPECT_EQ(asmstr(), "not %al");
    NOT(AX);
    EXPECT_EQ(asmstr(), "not %ax");
    NOT(EAX);
    EXPECT_EQ(asmstr(), "not %eax");
    NOT(RAX);
    EXPECT_EQ(asmstr(), "not %rax");
    NOT(addr1);
    EXPECT_EQ(asmstr(), "notb (%rdx)");
    NOT(addr2);
    EXPECT_EQ(asmstr(), "notw (%rdx)");
    NOT(addr3);
    EXPECT_EQ(asmstr(), "notl (%rdx)");
    NOT(addr4);
    EXPECT_EQ(asmstr(), "notq (%rdx)");
}

TEST(Instruction8, Type4)
{
    m8  addr1 { RDX };
    m16 addr2 { RDX };
    m32 addr3 { RDX };
    m64 addr4 { RDX };

    XADD(AL, BL);
    EXPECT_EQ(asmstr(), "xadd %bl, %al");
    XADD(addr1, CL);
    EXPECT_EQ(asmstr(), "xadd %cl, (%rdx)");
    XADD(AX, BX);
    EXPECT_EQ(asmstr(), "xadd %bx, %ax");
    XADD(addr2, CX);
    EXPECT_EQ(asmstr(), "xadd %cx, (%rdx)");
    XADD(EAX, EBX);
    EXPECT_EQ(asmstr(), "xadd %ebx, %eax");
    XADD(addr3, ECX);
    EXPECT_EQ(asmstr(), "xadd %ecx, (%rdx)");
    XADD(RAX, RBX);
    EXPECT_EQ(asmstr(), "xadd %rbx, %rax");
    XADD(addr4, RCX);
    EXPECT_EQ(asmstr(), "xadd %rcx, (%rdx)");

    CMPXCHG(AL, BL);
    EXPECT_EQ(asmstr(), "cmpxchg %bl, %al");
    CMPXCHG(addr1, CL);
    EXPECT_EQ(asmstr(), "cmpxchg %cl, (%rdx)");
    CMPXCHG(AX, BX);
    EXPECT_EQ(asmstr(), "cmpxchg %bx, %ax");
    CMPXCHG(addr2, CX);
    EXPECT_EQ(asmstr(), "cmpxchg %cx, (%rdx)");
    CMPXCHG(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmpxchg %ebx, %eax");
    CMPXCHG(addr3, ECX);
    EXPECT_EQ(asmstr(), "cmpxchg %ecx, (%rdx)");
    CMPXCHG(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmpxchg %rbx, %rax");
    CMPXCHG(addr4, RCX);
    EXPECT_EQ(asmstr(), "cmpxchg %rcx, (%rdx)");
}

TEST(Instruction8, Type5)
{
    m128 addr1 { RDX };
    m256 addr2 { RDX };
    imm8 mask { 255 };

    VPERMILPD(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vpermilpd %xmm2, %xmm1, %xmm0");
    VPERMILPD(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vpermilpd (%rdx), %xmm1, %xmm0");
    VPERMILPD(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vpermilpd %ymm2, %ymm1, %ymm0");
    VPERMILPD(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vpermilpd (%rdx), %ymm1, %ymm0");
    VPERMILPD(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "vpermilpd $0xFF, %xmm1, %xmm0");
    VPERMILPD(XMM0, addr1, mask);
    EXPECT_EQ(asmstr(), "vpermilpd $0xFF, (%rdx), %xmm0");
    VPERMILPD(YMM0, YMM1, mask);
    EXPECT_EQ(asmstr(), "vpermilpd $0xFF, %ymm1, %ymm0");
    VPERMILPD(YMM0, addr2, mask);
    EXPECT_EQ(asmstr(), "vpermilpd $0xFF, (%rdx), %ymm0");

    VPERMILPS(XMM0, XMM1, XMM2);
    EXPECT_EQ(asmstr(), "vpermilps %xmm2, %xmm1, %xmm0");
    VPERMILPS(XMM0, XMM1, addr1);
    EXPECT_EQ(asmstr(), "vpermilps (%rdx), %xmm1, %xmm0");
    VPERMILPS(YMM0, YMM1, YMM2);
    EXPECT_EQ(asmstr(), "vpermilps %ymm2, %ymm1, %ymm0");
    VPERMILPS(YMM0, YMM1, addr2);
    EXPECT_EQ(asmstr(), "vpermilps (%rdx), %ymm1, %ymm0");
    VPERMILPS(XMM0, XMM1, mask);
    EXPECT_EQ(asmstr(), "vpermilps $0xFF, %xmm1, %xmm0");
    VPERMILPS(XMM0, addr1, mask);
    EXPECT_EQ(asmstr(), "vpermilps $0xFF, (%rdx), %xmm0");
    VPERMILPS(YMM0, YMM1, mask);
    EXPECT_EQ(asmstr(), "vpermilps $0xFF, %ymm1, %ymm0");
    VPERMILPS(YMM0, addr2, mask);
    EXPECT_EQ(asmstr(), "vpermilps $0xFF, (%rdx), %ymm0");
}
