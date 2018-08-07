#include <gtest/gtest.h>
#include <cppasm.h>

extern std::string asmstr();

TEST(Instruction6, Type1)
{
    m64 addr1 { RAX };
    m128 addr2 { RBX };
    imm8 mask { 255 };

    PSLLW(MM0, MM1);
    EXPECT_EQ(asmstr(), "psllw %mm1, %mm0");
    PSLLW(MM0, addr1);
    EXPECT_EQ(asmstr(), "psllw (%rax), %mm0");
    PSLLW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psllw %xmm1, %xmm0");
    PSLLW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psllw (%rbx), %xmm0");
    PSLLW(MM0, mask);
    EXPECT_EQ(asmstr(), "psllw $0xFF, %mm0");
    PSLLW(XMM0, mask);
    EXPECT_EQ(asmstr(), "psllw $0xFF, %xmm0");

    PSLLD(MM0, MM1);
    EXPECT_EQ(asmstr(), "pslld %mm1, %mm0");
    PSLLD(MM0, addr1);
    EXPECT_EQ(asmstr(), "pslld (%rax), %mm0");
    PSLLD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "pslld %xmm1, %xmm0");
    PSLLD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "pslld (%rbx), %xmm0");
    PSLLD(MM0, mask);
    EXPECT_EQ(asmstr(), "pslld $0xFF, %mm0");
    PSLLD(XMM0, mask);
    EXPECT_EQ(asmstr(), "pslld $0xFF, %xmm0");

    PSLLQ(MM0, MM1);
    EXPECT_EQ(asmstr(), "psllq %mm1, %mm0");
    PSLLQ(MM0, addr1);
    EXPECT_EQ(asmstr(), "psllq (%rax), %mm0");
    PSLLQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psllq %xmm1, %xmm0");
    PSLLQ(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psllq (%rbx), %xmm0");
    PSLLQ(MM0, mask);
    EXPECT_EQ(asmstr(), "psllq $0xFF, %mm0");
    PSLLQ(XMM0, mask);
    EXPECT_EQ(asmstr(), "psllq $0xFF, %xmm0");

    PSRLW(MM0, MM1);
    EXPECT_EQ(asmstr(), "psrlw %mm1, %mm0");
    PSRLW(MM0, addr1);
    EXPECT_EQ(asmstr(), "psrlw (%rax), %mm0");
    PSRLW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psrlw %xmm1, %xmm0");
    PSRLW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psrlw (%rbx), %xmm0");
    PSRLW(MM0, mask);
    EXPECT_EQ(asmstr(), "psrlw $0xFF, %mm0");
    PSRLW(XMM0, mask);
    EXPECT_EQ(asmstr(), "psrlw $0xFF, %xmm0");

    PSRLD(MM0, MM1);
    EXPECT_EQ(asmstr(), "psrld %mm1, %mm0");
    PSRLD(MM0, addr1);
    EXPECT_EQ(asmstr(), "psrld (%rax), %mm0");
    PSRLD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psrld %xmm1, %xmm0");
    PSRLD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psrld (%rbx), %xmm0");
    PSRLD(MM0, mask);
    EXPECT_EQ(asmstr(), "psrld $0xFF, %mm0");
    PSRLD(XMM0, mask);
    EXPECT_EQ(asmstr(), "psrld $0xFF, %xmm0");

    PSRLQ(MM0, MM1);
    EXPECT_EQ(asmstr(), "psrlq %mm1, %mm0");
    PSRLQ(MM0, addr1);
    EXPECT_EQ(asmstr(), "psrlq (%rax), %mm0");
    PSRLQ(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psrlq %xmm1, %xmm0");
    PSRLQ(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psrlq (%rbx), %xmm0");
    PSRLQ(MM0, mask);
    EXPECT_EQ(asmstr(), "psrlq $0xFF, %mm0");
    PSRLQ(XMM0, mask);
    EXPECT_EQ(asmstr(), "psrlq $0xFF, %xmm0");

    PSRAW(MM0, MM1);
    EXPECT_EQ(asmstr(), "psraw %mm1, %mm0");
    PSRAW(MM0, addr1);
    EXPECT_EQ(asmstr(), "psraw (%rax), %mm0");
    PSRAW(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psraw %xmm1, %xmm0");
    PSRAW(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psraw (%rbx), %xmm0");
    PSRAW(MM0, mask);
    EXPECT_EQ(asmstr(), "psraw $0xFF, %mm0");
    PSRAW(XMM0, mask);
    EXPECT_EQ(asmstr(), "psraw $0xFF, %xmm0");

    PSRAD(MM0, MM1);
    EXPECT_EQ(asmstr(), "psrad %mm1, %mm0");
    PSRAD(MM0, addr1);
    EXPECT_EQ(asmstr(), "psrad (%rax), %mm0");
    PSRAD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "psrad %xmm1, %xmm0");
    PSRAD(XMM0, addr2);
    EXPECT_EQ(asmstr(), "psrad (%rbx), %xmm0");
    PSRAD(MM0, mask);
    EXPECT_EQ(asmstr(), "psrad $0xFF, %mm0");
    PSRAD(XMM0, mask);
    EXPECT_EQ(asmstr(), "psrad $0xFF, %xmm0");
}

TEST(Instruction6, Type2)
{
    m16 addr1 { RAX };
    m32 addr2 { RBX };
    m64 addr3 { RCX };

    CMOVA(AX, BX);
    EXPECT_EQ(asmstr(), "cmova %bx, %ax");
    CMOVA(AX, addr1);
    EXPECT_EQ(asmstr(), "cmova (%rax), %ax");
    CMOVA(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmova %ebx, %eax");
    CMOVA(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmova (%rbx), %eax");
    CMOVA(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmova %rbx, %rax");
    CMOVA(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmova (%rcx), %rax");

    CMOVAE(AX, BX);
    EXPECT_EQ(asmstr(), "cmovae %bx, %ax");
    CMOVAE(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovae (%rax), %ax");
    CMOVAE(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovae %ebx, %eax");
    CMOVAE(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovae (%rbx), %eax");
    CMOVAE(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovae %rbx, %rax");
    CMOVAE(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovae (%rcx), %rax");

    CMOVB(AX, BX);
    EXPECT_EQ(asmstr(), "cmovb %bx, %ax");
    CMOVB(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovb (%rax), %ax");
    CMOVB(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovb %ebx, %eax");
    CMOVB(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovb (%rbx), %eax");
    CMOVB(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovb %rbx, %rax");
    CMOVB(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovb (%rcx), %rax");

    CMOVBE(AX, BX);
    EXPECT_EQ(asmstr(), "cmovbe %bx, %ax");
    CMOVBE(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovbe (%rax), %ax");
    CMOVBE(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovbe %ebx, %eax");
    CMOVBE(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovbe (%rbx), %eax");
    CMOVBE(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovbe %rbx, %rax");
    CMOVBE(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovbe (%rcx), %rax");

    CMOVC(AX, BX);
    EXPECT_EQ(asmstr(), "cmovc %bx, %ax");
    CMOVC(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovc (%rax), %ax");
    CMOVC(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovc %ebx, %eax");
    CMOVC(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovc (%rbx), %eax");
    CMOVC(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovc %rbx, %rax");
    CMOVC(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovc (%rcx), %rax");

    CMOVE(AX, BX);
    EXPECT_EQ(asmstr(), "cmove %bx, %ax");
    CMOVE(AX, addr1);
    EXPECT_EQ(asmstr(), "cmove (%rax), %ax");
    CMOVE(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmove %ebx, %eax");
    CMOVE(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmove (%rbx), %eax");
    CMOVE(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmove %rbx, %rax");
    CMOVE(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmove (%rcx), %rax");

    CMOVG(AX, BX);
    EXPECT_EQ(asmstr(), "cmovg %bx, %ax");
    CMOVG(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovg (%rax), %ax");
    CMOVG(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovg %ebx, %eax");
    CMOVG(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovg (%rbx), %eax");
    CMOVG(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovg %rbx, %rax");
    CMOVG(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovg (%rcx), %rax");

    CMOVGE(AX, BX);
    EXPECT_EQ(asmstr(), "cmovge %bx, %ax");
    CMOVGE(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovge (%rax), %ax");
    CMOVGE(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovge %ebx, %eax");
    CMOVGE(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovge (%rbx), %eax");
    CMOVGE(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovge %rbx, %rax");
    CMOVGE(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovge (%rcx), %rax");

    CMOVL(AX, BX);
    EXPECT_EQ(asmstr(), "cmovl %bx, %ax");
    CMOVL(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovl (%rax), %ax");
    CMOVL(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovl %ebx, %eax");
    CMOVL(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovl (%rbx), %eax");
    CMOVL(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovl %rbx, %rax");
    CMOVL(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovl (%rcx), %rax");

    CMOVLE(AX, BX);
    EXPECT_EQ(asmstr(), "cmovle %bx, %ax");
    CMOVLE(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovle (%rax), %ax");
    CMOVLE(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovle %ebx, %eax");
    CMOVLE(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovle (%rbx), %eax");
    CMOVLE(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovle %rbx, %rax");
    CMOVLE(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovle (%rcx), %rax");

    CMOVNA(AX, BX);
    EXPECT_EQ(asmstr(), "cmovna %bx, %ax");
    CMOVNA(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovna (%rax), %ax");
    CMOVNA(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovna %ebx, %eax");
    CMOVNA(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovna (%rbx), %eax");
    CMOVNA(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovna %rbx, %rax");
    CMOVNA(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovna (%rcx), %rax");

    CMOVNAE(AX, BX);
    EXPECT_EQ(asmstr(), "cmovnae %bx, %ax");
    CMOVNAE(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovnae (%rax), %ax");
    CMOVNAE(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovnae %ebx, %eax");
    CMOVNAE(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovnae (%rbx), %eax");
    CMOVNAE(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovnae %rbx, %rax");
    CMOVNAE(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovnae (%rcx), %rax");

    CMOVNBE(AX, BX);
    EXPECT_EQ(asmstr(), "cmovnbe %bx, %ax");
    CMOVNBE(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovnbe (%rax), %ax");
    CMOVNBE(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovnbe %ebx, %eax");
    CMOVNBE(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovnbe (%rbx), %eax");
    CMOVNBE(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovnbe %rbx, %rax");
    CMOVNBE(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovnbe (%rcx), %rax");

    CMOVNC(AX, BX);
    EXPECT_EQ(asmstr(), "cmovnc %bx, %ax");
    CMOVNC(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovnc (%rax), %ax");
    CMOVNC(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovnc %ebx, %eax");
    CMOVNC(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovnc (%rbx), %eax");
    CMOVNC(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovnc %rbx, %rax");
    CMOVNC(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovnc (%rcx), %rax");

    CMOVNE(AX, BX);
    EXPECT_EQ(asmstr(), "cmovne %bx, %ax");
    CMOVNE(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovne (%rax), %ax");
    CMOVNE(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovne %ebx, %eax");
    CMOVNE(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovne (%rbx), %eax");
    CMOVNE(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovne %rbx, %rax");
    CMOVNE(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovne (%rcx), %rax");

    CMOVNG(AX, BX);
    EXPECT_EQ(asmstr(), "cmovng %bx, %ax");
    CMOVNG(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovng (%rax), %ax");
    CMOVNG(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovng %ebx, %eax");
    CMOVNG(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovng (%rbx), %eax");
    CMOVNG(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovng %rbx, %rax");
    CMOVNG(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovng (%rcx), %rax");

    CMOVNGE(AX, BX);
    EXPECT_EQ(asmstr(), "cmovnge %bx, %ax");
    CMOVNGE(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovnge (%rax), %ax");
    CMOVNGE(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovnge %ebx, %eax");
    CMOVNGE(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovnge (%rbx), %eax");
    CMOVNGE(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovnge %rbx, %rax");
    CMOVNGE(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovnge (%rcx), %rax");

    CMOVNL(AX, BX);
    EXPECT_EQ(asmstr(), "cmovnl %bx, %ax");
    CMOVNL(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovnl (%rax), %ax");
    CMOVNL(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovnl %ebx, %eax");
    CMOVNL(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovnl (%rbx), %eax");
    CMOVNL(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovnl %rbx, %rax");
    CMOVNL(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovnl (%rcx), %rax");

    CMOVNLE(AX, BX);
    EXPECT_EQ(asmstr(), "cmovnle %bx, %ax");
    CMOVNLE(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovnle (%rax), %ax");
    CMOVNLE(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovnle %ebx, %eax");
    CMOVNLE(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovnle (%rbx), %eax");
    CMOVNLE(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovnle %rbx, %rax");
    CMOVNLE(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovnle (%rcx), %rax");

    CMOVNO(AX, BX);
    EXPECT_EQ(asmstr(), "cmovno %bx, %ax");
    CMOVNO(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovno (%rax), %ax");
    CMOVNO(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovno %ebx, %eax");
    CMOVNO(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovno (%rbx), %eax");
    CMOVNO(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovno %rbx, %rax");
    CMOVNO(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovno (%rcx), %rax");

    CMOVNP(AX, BX);
    EXPECT_EQ(asmstr(), "cmovnp %bx, %ax");
    CMOVNP(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovnp (%rax), %ax");
    CMOVNP(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovnp %ebx, %eax");
    CMOVNP(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovnp (%rbx), %eax");
    CMOVNP(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovnp %rbx, %rax");
    CMOVNP(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovnp (%rcx), %rax");

    CMOVNS(AX, BX);
    EXPECT_EQ(asmstr(), "cmovns %bx, %ax");
    CMOVNS(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovns (%rax), %ax");
    CMOVNS(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovns %ebx, %eax");
    CMOVNS(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovns (%rbx), %eax");
    CMOVNS(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovns %rbx, %rax");
    CMOVNS(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovns (%rcx), %rax");

    CMOVNZ(AX, BX);
    EXPECT_EQ(asmstr(), "cmovnz %bx, %ax");
    CMOVNZ(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovnz (%rax), %ax");
    CMOVNZ(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovnz %ebx, %eax");
    CMOVNZ(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovnz (%rbx), %eax");
    CMOVNZ(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovnz %rbx, %rax");
    CMOVNZ(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovnz (%rcx), %rax");

    CMOVO(AX, BX);
    EXPECT_EQ(asmstr(), "cmovo %bx, %ax");
    CMOVO(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovo (%rax), %ax");
    CMOVO(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovo %ebx, %eax");
    CMOVO(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovo (%rbx), %eax");
    CMOVO(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovo %rbx, %rax");
    CMOVO(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovo (%rcx), %rax");

    CMOVP(AX, BX);
    EXPECT_EQ(asmstr(), "cmovp %bx, %ax");
    CMOVP(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovp (%rax), %ax");
    CMOVP(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovp %ebx, %eax");
    CMOVP(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovp (%rbx), %eax");
    CMOVP(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovp %rbx, %rax");
    CMOVP(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovp (%rcx), %rax");

    CMOVPE(AX, BX);
    EXPECT_EQ(asmstr(), "cmovpe %bx, %ax");
    CMOVPE(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovpe (%rax), %ax");
    CMOVPE(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovpe %ebx, %eax");
    CMOVPE(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovpe (%rbx), %eax");
    CMOVPE(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovpe %rbx, %rax");
    CMOVPE(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovpe (%rcx), %rax");

    CMOVPO(AX, BX);
    EXPECT_EQ(asmstr(), "cmovpo %bx, %ax");
    CMOVPO(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovpo (%rax), %ax");
    CMOVPO(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovpo %ebx, %eax");
    CMOVPO(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovpo (%rbx), %eax");
    CMOVPO(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovpo %rbx, %rax");
    CMOVPO(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovpo (%rcx), %rax");

    CMOVS(AX, BX);
    EXPECT_EQ(asmstr(), "cmovs %bx, %ax");
    CMOVS(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovs (%rax), %ax");
    CMOVS(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovs %ebx, %eax");
    CMOVS(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovs (%rbx), %eax");
    CMOVS(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovs %rbx, %rax");
    CMOVS(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovs (%rcx), %rax");

    CMOVZ(AX, BX);
    EXPECT_EQ(asmstr(), "cmovz %bx, %ax");
    CMOVZ(AX, addr1);
    EXPECT_EQ(asmstr(), "cmovz (%rax), %ax");
    CMOVZ(EAX, EBX);
    EXPECT_EQ(asmstr(), "cmovz %ebx, %eax");
    CMOVZ(EAX, addr2);
    EXPECT_EQ(asmstr(), "cmovz (%rbx), %eax");
    CMOVZ(RAX, RBX);
    EXPECT_EQ(asmstr(), "cmovz %rbx, %rax");
    CMOVZ(RAX, addr3);
    EXPECT_EQ(asmstr(), "cmovz (%rcx), %rax");

    BSF(AX, BX);
    EXPECT_EQ(asmstr(), "bsf %bx, %ax");
    BSF(AX, addr1);
    EXPECT_EQ(asmstr(), "bsf (%rax), %ax");
    BSF(EAX, EBX);
    EXPECT_EQ(asmstr(), "bsf %ebx, %eax");
    BSF(EAX, addr2);
    EXPECT_EQ(asmstr(), "bsf (%rbx), %eax");
    BSF(RAX, RBX);
    EXPECT_EQ(asmstr(), "bsf %rbx, %rax");
    BSF(RAX, addr3);
    EXPECT_EQ(asmstr(), "bsf (%rcx), %rax");

    BSR(AX, BX);
    EXPECT_EQ(asmstr(), "bsr %bx, %ax");
    BSR(AX, addr1);
    EXPECT_EQ(asmstr(), "bsr (%rax), %ax");
    BSR(EAX, EBX);
    EXPECT_EQ(asmstr(), "bsr %ebx, %eax");
    BSR(EAX, addr2);
    EXPECT_EQ(asmstr(), "bsr (%rbx), %eax");
    BSR(RAX, RBX);
    EXPECT_EQ(asmstr(), "bsr %rbx, %rax");
    BSR(RAX, addr3);
    EXPECT_EQ(asmstr(), "bsr (%rcx), %rax");

    POPCNT(AX, BX);
    EXPECT_EQ(asmstr(), "popcnt %bx, %ax");
    POPCNT(AX, addr1);
    EXPECT_EQ(asmstr(), "popcnt (%rax), %ax");
    POPCNT(EAX, EBX);
    EXPECT_EQ(asmstr(), "popcnt %ebx, %eax");
    POPCNT(EAX, addr2);
    EXPECT_EQ(asmstr(), "popcnt (%rbx), %eax");
    POPCNT(RAX, RBX);
    EXPECT_EQ(asmstr(), "popcnt %rbx, %rax");
    POPCNT(RAX, addr3);
    EXPECT_EQ(asmstr(), "popcnt (%rcx), %rax");
}

TEST(Instruction6, Type3)
{
    imm8 addr { 0 };

    IN(AL, addr);
    EXPECT_EQ(asmstr(), "in $0x00, %al");
    IN(AX, addr);
    EXPECT_EQ(asmstr(), "in $0x00, %ax");
    IN(EAX, addr);
    EXPECT_EQ(asmstr(), "in $0x00, %eax");
    IN(AL, DX);
    EXPECT_EQ(asmstr(), "in %dx, %al");
    IN(AX, DX);
    EXPECT_EQ(asmstr(), "in %dx, %ax");
    IN(EAX, DX);
    EXPECT_EQ(asmstr(), "in %dx, %eax");
}

TEST(Instruction6, Type4)
{
    imm8 addr { 0 };

    OUT(addr, AL);
    EXPECT_EQ(asmstr(), "out %al, $0x00");
    OUT(addr, AX);
    EXPECT_EQ(asmstr(), "out %ax, $0x00");
    OUT(addr, EAX);
    EXPECT_EQ(asmstr(), "out %eax, $0x00");
    OUT(DX, AL);
    EXPECT_EQ(asmstr(), "out %al, %dx");
    OUT(DX, AX);
    EXPECT_EQ(asmstr(), "out %ax, %dx");
    OUT(DX, EAX);
    EXPECT_EQ(asmstr(), "out %eax, %dx");
}

TEST(Instruction6, Type5)
{
    m128 addr1 { RAX };
    m256 addr2 { RBX };

    VMOVAPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vmovaps %xmm1, %xmm0");
    VMOVAPS(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vmovaps (%rax), %xmm0");
    VMOVAPS(addr1, XMM0);
    EXPECT_EQ(asmstr(), "vmovaps %xmm0, (%rax)");
    VMOVAPS(YMM0, YMM2);
    EXPECT_EQ(asmstr(), "vmovaps %ymm2, %ymm0");
    VMOVAPS(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vmovaps (%rbx), %ymm0");
    VMOVAPS(addr2, YMM0);
    EXPECT_EQ(asmstr(), "vmovaps %ymm0, (%rbx)");

    VMOVAPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vmovapd %xmm1, %xmm0");
    VMOVAPD(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vmovapd (%rax), %xmm0");
    VMOVAPD(addr1, XMM0);
    EXPECT_EQ(asmstr(), "vmovapd %xmm0, (%rax)");
    VMOVAPD(YMM0, YMM2);
    EXPECT_EQ(asmstr(), "vmovapd %ymm2, %ymm0");
    VMOVAPD(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vmovapd (%rbx), %ymm0");
    VMOVAPD(addr2, YMM0);
    EXPECT_EQ(asmstr(), "vmovapd %ymm0, (%rbx)");

    VMOVDQA(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vmovdqa %xmm1, %xmm0");
    VMOVDQA(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vmovdqa (%rax), %xmm0");
    VMOVDQA(addr1, XMM0);
    EXPECT_EQ(asmstr(), "vmovdqa %xmm0, (%rax)");
    VMOVDQA(YMM0, YMM2);
    EXPECT_EQ(asmstr(), "vmovdqa %ymm2, %ymm0");
    VMOVDQA(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vmovdqa (%rbx), %ymm0");
    VMOVDQA(addr2, YMM0);
    EXPECT_EQ(asmstr(), "vmovdqa %ymm0, (%rbx)");

    VMOVUPS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vmovups %xmm1, %xmm0");
    VMOVUPS(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vmovups (%rax), %xmm0");
    VMOVUPS(addr1, XMM0);
    EXPECT_EQ(asmstr(), "vmovups %xmm0, (%rax)");
    VMOVUPS(YMM0, YMM2);
    EXPECT_EQ(asmstr(), "vmovups %ymm2, %ymm0");
    VMOVUPS(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vmovups (%rbx), %ymm0");
    VMOVUPS(addr2, YMM0);
    EXPECT_EQ(asmstr(), "vmovups %ymm0, (%rbx)");

    VMOVUPD(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vmovupd %xmm1, %xmm0");
    VMOVUPD(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vmovupd (%rax), %xmm0");
    VMOVUPD(addr1, XMM0);
    EXPECT_EQ(asmstr(), "vmovupd %xmm0, (%rax)");
    VMOVUPD(YMM0, YMM2);
    EXPECT_EQ(asmstr(), "vmovupd %ymm2, %ymm0");
    VMOVUPD(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vmovupd (%rbx), %ymm0");
    VMOVUPD(addr2, YMM0);
    EXPECT_EQ(asmstr(), "vmovupd %ymm0, (%rbx)");

    VMOVDQU(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vmovdqu %xmm1, %xmm0");
    VMOVDQU(XMM0, addr1);
    EXPECT_EQ(asmstr(), "vmovdqu (%rax), %xmm0");
    VMOVDQU(addr1, XMM0);
    EXPECT_EQ(asmstr(), "vmovdqu %xmm0, (%rax)");
    VMOVDQU(YMM0, YMM2);
    EXPECT_EQ(asmstr(), "vmovdqu %ymm2, %ymm0");
    VMOVDQU(YMM0, addr2);
    EXPECT_EQ(asmstr(), "vmovdqu (%rbx), %ymm0");
    VMOVDQU(addr2, YMM0);
    EXPECT_EQ(asmstr(), "vmovdqu %ymm0, (%rbx)");
}

TEST(Instruction6, Type6)
{
    m32 addr { RBX };

    VBROADCASTSS(XMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcastss (%rbx), %xmm0");
    VBROADCASTSS(YMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcastss (%rbx), %ymm0");
    VBROADCASTSS(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcastss (%rbx), %zmm0");
    VBROADCASTSS(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcastss %xmm1, %xmm0");
    VBROADCASTSS(YMM0, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcastss %xmm1, %ymm0");
    VBROADCASTSS(ZMM0, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcastss %xmm1, %zmm0");
    VBROADCASTSS(XMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcastss (%rbx), %xmm0{%k1}");
    VBROADCASTSS(YMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcastss (%rbx), %ymm0{%k1}");
    VBROADCASTSS(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcastss (%rbx), %zmm0{%k1}");
    VBROADCASTSS(XMM0.k1, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcastss %xmm1, %xmm0{%k1}");
    VBROADCASTSS(YMM0.k1, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcastss %xmm1, %ymm0{%k1}");
    VBROADCASTSS(ZMM0.k1, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcastss %xmm1, %zmm0{%k1}");
    VBROADCASTSS(XMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcastss (%rbx), %xmm0{%k1}{z}");
    VBROADCASTSS(YMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcastss (%rbx), %ymm0{%k1}{z}");
    VBROADCASTSS(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcastss (%rbx), %zmm0{%k1}{z}");
    VBROADCASTSS(XMM0.k1.z, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcastss %xmm1, %xmm0{%k1}{z}");
    VBROADCASTSS(YMM0.k1.z, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcastss %xmm1, %ymm0{%k1}{z}");
    VBROADCASTSS(ZMM0.k1.z, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcastss %xmm1, %zmm0{%k1}{z}");
}

TEST(Instruction6, Type7)
{
    m64 addr { EBX };

    VBROADCASTI32X2(XMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 (%ebx), %xmm0");
    VBROADCASTI32X2(YMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 (%ebx), %ymm0");
    VBROADCASTI32X2(ZMM0, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 (%ebx), %zmm0");
    VBROADCASTI32X2(XMM0, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 %xmm1, %xmm0");
    VBROADCASTI32X2(YMM0, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 %xmm1, %ymm0");
    VBROADCASTI32X2(ZMM0, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 %xmm1, %zmm0");
    VBROADCASTI32X2(XMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 (%ebx), %xmm0{%k1}");
    VBROADCASTI32X2(YMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 (%ebx), %ymm0{%k1}");
    VBROADCASTI32X2(ZMM0.k1, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 (%ebx), %zmm0{%k1}");
    VBROADCASTI32X2(XMM0.k1, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 %xmm1, %xmm0{%k1}");
    VBROADCASTI32X2(YMM0.k1, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 %xmm1, %ymm0{%k1}");
    VBROADCASTI32X2(ZMM0.k1, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 %xmm1, %zmm0{%k1}");
    VBROADCASTI32X2(XMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 (%ebx), %xmm0{%k1}{z}");
    VBROADCASTI32X2(YMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 (%ebx), %ymm0{%k1}{z}");
    VBROADCASTI32X2(ZMM0.k1.z, addr);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 (%ebx), %zmm0{%k1}{z}");
    VBROADCASTI32X2(XMM0.k1.z, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 %xmm1, %xmm0{%k1}{z}");
    VBROADCASTI32X2(YMM0.k1.z, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 %xmm1, %ymm0{%k1}{z}");
    VBROADCASTI32X2(ZMM0.k1.z, XMM1);
    EXPECT_EQ(asmstr(), "vbroadcasti32x2 %xmm1, %zmm0{%k1}{z}");
}
