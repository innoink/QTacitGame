#include <gtest/gtest.h>

#include "gamemap.hpp"

struct TestEmptyGameMap : public ::testing::Test
{
    QTacitGame::GameMap m;
};

TEST_F(TestEmptyGameMap, NumberOfStatesEqualsZero)
{
    ASSERT_EQ(std::size_t{}, m.numberOfSates());
}

TEST_F(TestEmptyGameMap, NothingExists)
{
    ASSERT_FALSE(m.exists(0));
    ASSERT_FALSE(m.exists(1));
    ASSERT_FALSE(m.exists("test"));
}

