#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Filesystem.h"
#include <string>

using namespace testing;

/*
 * 1.10 version has new macro MOCK_METHOD which can use any function specifier (const, noexcept, override, final, ...)
 * MOCK_METHOD macro usage:

 * struct MockI: public I
 * {
 *    MOCK_METHOD(void, f, (), (override));
 * };
 * Old macros MOCK_METHODx can still be used, but one should prefer to write new mocks using new method when using 1.10.x
 **/

class MockFoo : public IFileSystem {
    public:
        MOCK_METHOD(bool, checkFileExist, (const std::string &),
                    (const override));
};

static bool isPathExist_(IFileSystem *fs, const std::string &path)
{
        return fs->checkFileExist(path);
}

TEST(BarTest, DoesThis)
{
        MockFoo fakefs; // #2

        // The underscore (_) is a matcher that says the argument can be anything
        ON_CALL(fakefs, checkFileExist(_)) // #3
                .WillByDefault(Return(true));
        // // ... other default actions ...

        // // EXPECT_CALL(foo, Describe(5)) // #4
        // //         .Times(3)
        // //         .WillRepeatedly(Return("Category 5"));
        // // // ... other expectations ...

        EXPECT_EQ(true, isPathExist_(&fakefs, "/123")); // #5
} // #6
