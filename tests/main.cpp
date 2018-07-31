#include <gtest/gtest.h>
#include <cppasm.h>
#include <streamdest.h>
#include "streamdest_buf.h"

static streamdest_buf *test_buf = nullptr;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    test_buf = new streamdest_buf;

    asmout.set(test_buf);

    return RUN_ALL_TESTS();
}

std::string asmstr()
{
    const std::string str = test_buf->get();

    test_buf->clear();

    return str;
}
