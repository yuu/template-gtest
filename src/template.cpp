#include <gtest/gtest.h>

class Test : public testing::Test {
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(Test, fist) {
    EXPECT_EQ(1 + 1, 2);
}
