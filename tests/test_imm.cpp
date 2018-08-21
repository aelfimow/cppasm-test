#include <gtest/gtest.h>
#include <cppasm.h>


TEST(Immediate, imm8)
{
    imm8 v0 { 0 };
    EXPECT_EQ(v0.to_str(), "$0x00");

    imm8 v1 { 255 };
    EXPECT_EQ(v1.to_str(), "$0xFF");
}

TEST(Immediate, imm16)
{
    imm16 v0 { 0 };
    EXPECT_EQ(v0.to_str(), "$0x0000");

    imm16 v1 { 65535 };
    EXPECT_EQ(v1.to_str(), "$0xFFFF");
}

TEST(Immediate, imm32)
{
    imm32 v0 { 0 };
    EXPECT_EQ(v0.to_str(), "$0x00000000");

    imm32 v1 { 0xFFFFFFFF };
    EXPECT_EQ(v1.to_str(), "$0xFFFFFFFF");
}

TEST(Immediate, imm64)
{
    imm64 v0 { 0 };
    EXPECT_EQ(v0.to_str(), "$0x0000000000000000");

    imm64 v1 { 0xFFFFFFFFFFFFFFFF };
    EXPECT_EQ(v1.to_str(), "$0xFFFFFFFFFFFFFFFF");
}
