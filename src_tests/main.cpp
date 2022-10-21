#include <gtest/gtest.h>

TEST(A, B)
{
    EXPECT_TRUE(1);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

