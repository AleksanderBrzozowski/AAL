//
// Created by Aleksander on 12.11.2016.
//

#include "gtest/gtest.h"
#include "SkipList.h"


class SkipListTest : public ::testing::Test {
public:
    SkipList skipList;
};


TEST_F(SkipListTest, insertAndTakeFromFront) {
    const unsigned long SIZE = 10000;

    //insert values
    for (int i = 1; i <= SIZE; i++) {
        std::ostringstream os;
        os << i;
        skipList.insertOrUpdate(i, os.str());
        ASSERT_FALSE(skipList.isEmpty());
        ASSERT_EQ(i, skipList.size());
    }

    //find and delete
    for (int i = 1; i <= SIZE; i++) {
        std::ostringstream os;
        os << i;
        ASSERT_FALSE(skipList.isEmpty());
        ASSERT_EQ(skipList.front(), os.str());
        ASSERT_EQ(SIZE - i, skipList.size());
    }
    ASSERT_TRUE(skipList.isEmpty());
    EXPECT_THROW(skipList.front(), std::runtime_error);
}


TEST_F(SkipListTest, updateValues) {
    const unsigned long SIZE = 10000;

    //insert values
    for (int i = 1; i <= SIZE; i++) {
        std::ostringstream os;
        os << i;
        skipList.insertOrUpdate(i, os.str());
        ASSERT_FALSE(skipList.isEmpty());
        ASSERT_EQ(i, skipList.size());
    }

    //update values
    for (int i = 1; i <= SIZE; i++) {
        std::ostringstream os;
        os << i;
        skipList.insertOrUpdate(i, os.str());
        ASSERT_FALSE(skipList.isEmpty());
        ASSERT_EQ(SIZE, skipList.size());
    }

    //find and delete
    for (int i = 1; i <= SIZE; i++) {
        std::ostringstream os;
        os << i << i;
        ASSERT_FALSE(skipList.isEmpty());
        ASSERT_EQ(skipList.front(), os.str());
        ASSERT_EQ(SIZE - i, skipList.size());
    }
    ASSERT_TRUE(skipList.isEmpty());
    EXPECT_THROW(skipList.front(), std::runtime_error);
}

TEST_F(SkipListTest, EmptyList) {
    ASSERT_TRUE(skipList.isEmpty());
    ASSERT_EQ(0, skipList.size());
    EXPECT_THROW(skipList.front(), std::runtime_error);
}
