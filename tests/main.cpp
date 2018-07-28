#include <gtest/gtest.h>
#include <cppasm.h>

TEST(CppAsmTest, Section)
{
    section(".text");
    section(".data");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
