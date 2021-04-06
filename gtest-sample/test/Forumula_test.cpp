#include "gtest/gtest.h"
#include "Formula.h"

// Tests factorial of 0.
TEST(FactorialTest, HandlesZeroInput111111111111111111111)
{
        EXPECT_EQ(Factorial(0), 1);
        EXPECT_EQ(1, 1);
}

TEST(FactorialTest, HandlesZeroInput1111211111111)
{
        EXPECT_EQ(0, 1);
}

// // Tests factorial of positive numbers.
// TEST(FactorialTest, HandlesPositiveInput)
// {
//         EXPECT_EQ(Factorial(1), 1);
//         EXPECT_EQ(Factorial(2), 2);
//         EXPECT_EQ(Factorial(3), 6);
//         // EXPECT_EQ(Factorial(8), 40320);
// }
