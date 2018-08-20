#include <gtest/gtest.h>
#include <cppasm.h>
#include "asmstr.h"


TEST(Immediate, imm8)
{
    imm8 v0 { 0 };
    EXPECT_EQ(v0.to_str(), "0x00");

    imm8 v1 { 255 };
    EXPECT_EQ(v0.to_str(), "0xFF");
}
