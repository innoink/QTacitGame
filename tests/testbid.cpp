#include <gtest/gtest.h>

#include "bid.hpp"
#include "gamemap.hpp"
#include "gamemapbuilder.hpp"

constexpr std::size_t operator "" _sz(unsigned long long n)
{
    return n;
}

struct TestBid : public ::testing::Test
{
    static const std::string state1name;
    static const std::string state2name;
    static const std::string state3name;
    QTacitGame::GameMap map;
    QTacitGame::Bid bid;
    QTacitGame::GameMap::StateIndexType state1;
    QTacitGame::GameMap::StateIndexType state2;
    QTacitGame::GameMap::StateIndexType state3;

    static QTacitGame::GameMap createMap()
    {
        return QTacitGame::GameMapBuilder::fromJson(R"STR({ "states" : [ ")STR"+state1name+R"STR(", ")STR"+state2name+R"STR(", ")STR"+state3name+R"STR(" ] })STR");
    }

    TestBid(): map(createMap()), bid(map), state1(map.indexOf(state1name)), state2(map.indexOf(state2name)), state3(map.indexOf(state3name))
    {}
};

const std::string TestBid::state1name = "State1";
const std::string TestBid::state2name = "State2";
const std::string TestBid::state3name = "State3";

TEST_F(TestBid, NoBidsAfterConstruction)
{
    ASSERT_EQ(0_sz, bid.count(state1));
    ASSERT_EQ(0_sz, bid.count(state2));
    ASSERT_EQ(0_sz, bid.count(state3));
}

TEST_F(TestBid, PlaceOneBidOnAState)
{
    bid.place(state1);
    ASSERT_EQ(1_sz, bid.count(state1));
    ASSERT_EQ(0_sz, bid.count(state2));
    ASSERT_EQ(0_sz, bid.count(state3));
}

TEST_F(TestBid, PlaceTwoBidsOnASingleState)
{
    bid.place(state1);
    bid.place(state1);
    ASSERT_EQ(2_sz, bid.count(state1));
    ASSERT_EQ(0_sz, bid.count(state2));
    ASSERT_EQ(0_sz, bid.count(state3));
}

TEST_F(TestBid, PlaceOneBidOnTwoStates)
{
    bid.place(state1);
    bid.place(state2);
    ASSERT_EQ(1_sz, bid.count(state1));
    ASSERT_EQ(1_sz, bid.count(state2));
    ASSERT_EQ(0_sz, bid.count(state3));
}
