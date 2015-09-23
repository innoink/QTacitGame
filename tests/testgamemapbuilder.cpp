#include <gtest/gtest.h>

#include "gamemapbuilder.hpp"

TEST(TestGameMapBuilder, MapNoState)
{
    const auto map = QTacitGame::GameMapBuilder::fromJson(R"STR({ "states" : [] })STR");
    ASSERT_EQ(std::size_t{}, map.numberOfSates());
}

TEST(TestGameMapBuilder, MapWithOneState)
{
    const std::string state_name = "State";
    const auto map = QTacitGame::GameMapBuilder::fromJson(R"STR({ "states" : [ ")STR" + state_name + R"STR("] })STR");
    ASSERT_EQ(std::size_t{1}, map.numberOfSates());
    EXPECT_EQ(state_name, map.stateName(0));
}

TEST(TestGameMapBuilder, ThrowOnMapNoStateField)
{
    EXPECT_THROW(QTacitGame::GameMapBuilder::fromJson(R"STR({ })STR"), std::runtime_error);
}

TEST(TestGameMapBuilder, ThrowOnMapInvalidStateType)
{
    EXPECT_THROW(QTacitGame::GameMapBuilder::fromJson(R"STR({ "states" : [ .1 ] })STR"), std::invalid_argument);
}

