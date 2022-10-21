#include <gtest/gtest.h>

struct TestFixtureExample : public ::testing::Test {

  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(TestFixtureExample, Hello) {}

TEST(A, B) {}
TEST(A, C) {}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
