#include <gtest/gtest.h>
#include <cppasm.h>
#include "asmstr.h"


TEST(CpuRegister, r8)
{
    EXPECT_EQ(AL.name(), "%al");
    EXPECT_EQ(AH.name(), "%ah");
    EXPECT_EQ(BL.name(), "%bl");
    EXPECT_EQ(BH.name(), "%bh");
    EXPECT_EQ(CL.name(), "%cl");
    EXPECT_EQ(CH.name(), "%ch");
    EXPECT_EQ(DL.name(), "%dl");
    EXPECT_EQ(DH.name(), "%dh");
    EXPECT_EQ(SIL.name(), "%sil");
    EXPECT_EQ(DIL.name(), "%dil");
    EXPECT_EQ(SPL.name(), "%spl");
    EXPECT_EQ(R8L.name(), "%r8b");
    EXPECT_EQ(R9L.name(), "%r9b");
    EXPECT_EQ(R10L.name(), "%r10b");
    EXPECT_EQ(R11L.name(), "%r11b");
    EXPECT_EQ(R12L.name(), "%r12b");
    EXPECT_EQ(R13L.name(), "%r13b");
    EXPECT_EQ(R14L.name(), "%r14b");
    EXPECT_EQ(R15L.name(), "%r15b");
}

TEST(CpuRegister, r16)
{
    EXPECT_EQ(AX.name(), "%ax");
    EXPECT_EQ(BX.name(), "%bx");
    EXPECT_EQ(CX.name(), "%cx");
    EXPECT_EQ(DX.name(), "%dx");
    EXPECT_EQ(BP.name(), "%bp");
    EXPECT_EQ(SI.name(), "%si");
    EXPECT_EQ(DI.name(), "%di");
    EXPECT_EQ(SP.name(), "%sp");
    EXPECT_EQ(R8W.name(), "%r8w");
    EXPECT_EQ(R9W.name(), "%r9w");
    EXPECT_EQ(R10W.name(), "%r10w");
    EXPECT_EQ(R11W.name(), "%r11w");
    EXPECT_EQ(R12W.name(), "%r12w");
    EXPECT_EQ(R13W.name(), "%r13w");
    EXPECT_EQ(R14W.name(), "%r14w");
    EXPECT_EQ(R15W.name(), "%r15w");
}
