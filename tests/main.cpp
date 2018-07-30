#include <gtest/gtest.h>
#include <cppasm.h>
#include <streamdest.h>
#include "streamdest_buf.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    asmout.set(new streamdest_buf);

    return RUN_ALL_TESTS();
}
