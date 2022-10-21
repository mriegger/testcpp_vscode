#include <gtest/gtest.h>

struct TestFixtureExample : public ::testing::Test {

  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(TestFixtureExample, FixtureExample) {}

TEST(MKR, StandaloneExample) {}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
