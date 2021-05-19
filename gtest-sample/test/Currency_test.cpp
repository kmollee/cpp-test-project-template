#include "gtest/gtest.h"
#include "gtest/gtest-message.h"
#include "Currency.h"

#include <string>

using ::testing::Message;

TEST(CurrencyTest, Create)
{
        struct {
                std::string description;
                int input;
                int expected;
        } tt[] = {
                { "case 1", 5, 10 },
                { "case 2", 1, 2 },
                { "case 3", 4, 8 },
                { "case 4", 6, 12 },
        };

        for (const auto &tc : tt) {
                // Message() << "Hello world\n";
                Money obj = MoneyFactory::Dollar(tc.input);
                EXPECT_EQ(obj, obj);
                EXPECT_EQ(obj.times(2), MoneyFactory::Dollar(tc.expected));
        }
}

TEST(CurrencyTest, Multiplication)
{
        struct {
                std::string description;
                int input;
                int multiply_2;
                int multiply_3;
        } tt[] = {
                { "case 1", 5, 10, 15 },
                { "case 2", 1, 2, 3 },
                { "case 3", 4, 8, 12 },
                { "case 4", 6, 12, 18 },
        };

        for (const auto &tc : tt) {
                Money obj = MoneyFactory::Dollar(tc.input);
                EXPECT_EQ(obj.times(2), MoneyFactory::Dollar(tc.multiply_2));
                EXPECT_EQ(obj.times(3), MoneyFactory::Dollar(tc.multiply_3));
        }
}

TEST(CurrencyTest, Equal)
{
        struct {
                std::string description;
                int num1;
                int num2;
                bool expected;
        } tt[] = {
                { "case 1", 5, 5, true },
                { "case 2", 6, 5, false },
                { "case 3", 0, 0, true },
        };

        for (const auto &tc : tt) {
                EXPECT_EQ(MoneyFactory::Dollar(tc.num1) ==
                                  MoneyFactory::Dollar(tc.num2),
                          tc.expected);
                EXPECT_EQ(MoneyFactory::Franc(tc.num1) ==
                                  MoneyFactory::Franc(tc.num2),
                          tc.expected);
        }

        EXPECT_NE(MoneyFactory::Franc(5), MoneyFactory::Dollar(5))
                << "5 MoneyFactory::Dollar != 5 MoneyFactory::Franc";
        EXPECT_NE(MoneyFactory::Franc(6), MoneyFactory::Dollar(6))
                << "6 MoneyFactory::Dollar != 6 MoneyFactory::Franc";
}

TEST(CurrencyTest, FrancMultiply)
{
        struct {
                std::string description;
                int input;
                int multiply_2;
                int multiply_3;
        } tt[] = {
                { "case 1", 5, 10, 15 },
                { "case 2", 1, 2, 3 },
                { "case 3", 4, 8, 12 },
                { "case 4", 6, 12, 18 },
        };

        for (const auto &tc : tt) {
                Money obj = MoneyFactory::Franc(tc.input);
                EXPECT_EQ(obj.times(2), MoneyFactory::Franc(tc.multiply_2));
                EXPECT_EQ(obj.times(3), MoneyFactory::Franc(tc.multiply_3));
        }
}

TEST(CurrencyTest, GetCurrency)
{
        EXPECT_EQ(MoneyFactory::Dollar(2).currency(), "USD");
        EXPECT_EQ(MoneyFactory::Franc(0).currency(), "Franc");
}

TEST(CurrencyTest, Addition)
{
        EXPECT_EQ(MoneyFactory::Dollar(2) + MoneyFactory::Dollar(3),
                  MoneyFactory::Dollar(5));

        EXPECT_EQ(MoneyFactory::Franc(6) + MoneyFactory::Franc(7),
                  MoneyFactory::Franc(13));
}