#include <gtest/gtest.h>

#include "bid.hpp"
#include "gamemapbuilder.hpp"
#include "gamestate.hpp"

namespace
{
	auto buildMapWithThreeStates()
	{
		return QTacitGame::GameMapBuilder::fromJson(
			R"STR({ "states" : [ "State1", "State2", "State3" ] })STR");
	}
}

TEST(TestGameState, TestConstruction)
{
	const auto map = buildMapWithThreeStates();
	QTacitGame::GameState game_state(map, 2);
	EXPECT_EQ(2, game_state.numberOfPlayers());
}

TEST(TestGameState, BasicBidsNoCollision)
{
	const auto map = buildMapWithThreeStates();
	QTacitGame::GameState game_state(map, 2);
	QTacitGame::Bid b1(map);
	b1.place(map.indexOf("State1"));
	QTacitGame::Bid b2(map);
	b2.place(map.indexOf("State3"));
	game_state.resolve({b1, b2});
	const auto current_bids = game_state.currentBids();
	ASSERT_EQ(map.numberOfStates(), current_bids.size());

	ASSERT_TRUE((bool)current_bids[0]);
	EXPECT_EQ(0, (*current_bids[0]).player_id);
	EXPECT_EQ(1, (*current_bids[0]).number_of_tokens);

	ASSERT_FALSE((bool)current_bids[1]);

	ASSERT_TRUE((bool)current_bids[2]);
	EXPECT_EQ(1, (*current_bids[2]).player_id);
	EXPECT_EQ(1, (*current_bids[2]).number_of_tokens);
}

TEST(TestGameState, BasicBidsWithCollision)
{
	const auto map = buildMapWithThreeStates();
	QTacitGame::GameState game_state(map, 2);
	QTacitGame::Bid b1(map);
	b1.place(map.indexOf("State1"));
	b1.place(map.indexOf("State2"));
	b1.place(map.indexOf("State2"));
	b1.place(map.indexOf("State2"));
	QTacitGame::Bid b2(map);
	b2.place(map.indexOf("State2"));
	b2.place(map.indexOf("State3"));
	game_state.resolve({b1, b2});
	const auto current_bids = game_state.currentBids();
	ASSERT_EQ(map.numberOfStates(), current_bids.size());

	ASSERT_TRUE((bool)current_bids[0]);
	EXPECT_EQ(0, (*current_bids[0]).player_id);
	EXPECT_EQ(1, (*current_bids[0]).number_of_tokens);

	ASSERT_TRUE((bool)current_bids[1]);
	EXPECT_EQ(0, (*current_bids[1]).player_id);
	EXPECT_EQ(2, (*current_bids[1]).number_of_tokens);

	ASSERT_TRUE((bool)current_bids[2]);
	EXPECT_EQ(1, (*current_bids[2]).player_id);
	EXPECT_EQ(1, (*current_bids[2]).number_of_tokens);
}
