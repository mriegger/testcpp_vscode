#include <gmock/gmock.h>
#include <gtest/gtest.h>

struct TestFixtureExample : public ::testing::Test {

  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(TestFixtureExample, FixtureExample) {

  EXPECT_TRUE(1);
  EXPECT_EQ(1, 1);
  EXPECT_NE(-1, 1);
  EXPECT_FLOAT_EQ(1.0001f, 1.0001f);
  EXPECT_DOUBLE_EQ(1.0001, 1.0001);
  EXPECT_NEAR(1.0f, 1.001f, 0.01f);
}

TEST(MKR, StandaloneExample) {}

struct Cook {
  virtual ~Cook() = default;
  virtual void prepareOrder(const std::string_view) = 0;
};

// Waiter is the thing we are testing
struct Waiter final {
  void update(const std::string_view order, Cook *cook) {
    cook->prepareOrder(order);
  }
};

struct MockCook : public Cook {

  MOCK_METHOD(void, prepareOrder, (const std::string_view), (override));
};

TEST(MKR, MockWaiter) {
  using ::testing::AtLeast;
  const std::string_view order = "hambaga";
  MockCook mockCook;
  EXPECT_CALL(mockCook, prepareOrder(testing::_)).Times(AtLeast(1));

  Waiter w;
  w.update(order, &mockCook);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
