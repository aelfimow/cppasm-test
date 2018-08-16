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
