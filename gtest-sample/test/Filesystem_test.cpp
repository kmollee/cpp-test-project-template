#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Filesystem.h"

class MockFoo : public IFileSystem {
    public:
        MOCK_CONST_METHOD0(checkFileExist, bool(const std::string &) const);
};

static bool isPathExist_(IFileSystem *fs, const std::string &path)
{
        return fs->checkFileExist(path);
}

TEST(BarTest, DoesThis)
{
        MockFoo foo; // #2

        testing::ON_CALL(foo, checkFileExist) // #3
                .WillByDefault(testing::Return(true));
        // ... other default actions ...

        // EXPECT_CALL(foo, Describe(5)) // #4
        //         .Times(3)
        //         .WillRepeatedly(Return("Category 5"));
        // // ... other expectations ...

        EXPECT_EQ(true, isPathExist_(&foo, "/123")); // #5
} // #6
