#include "gamestate.hpp"

#include "bid.hpp"

#include <algorithm>
#include <cassert>

namespace QTacitGame
{

	GameState::GameState(const GameMap& map, const std::size_t number_of_players)
		: m_map(map)
		, m_number_of_players(number_of_players)
		, m_current_bids(map.numberOfStates())
	{
	}

	std::size_t GameState::numberOfPlayers() const { return m_number_of_players; }

	void GameState::resolve(const std::vector<Bid>& bids)
	{
        assert(bids.size() == m_number_of_players);
		for(std::size_t i = 0; i < bids.size(); i++)
		{
			addBidsForPlayer(i, bids[i]);
		}
        resolveCollisions();
	}

	auto GameState::currentBids() const -> CurrentBidsContainer_t
	{
		CurrentBidsContainer_t res(m_map.numberOfStates());
		for(std::size_t i = 0; i < m_current_bids.size(); i++)
		{
			const auto& current_bid = m_current_bids[i];
			if(current_bid.size() == 1)
			{
				res[i] = current_bid.front();
			}
		}
		assert(res.size() == m_map.numberOfStates());
		return res;
	}

	void GameState::resolveCollisions() {}

	void GameState::addBidsForPlayer(const std::size_t player_id, const Bid& bid)
    {
		assert(player_id < m_number_of_players);
		for(const auto& b : bid)
        {
			if(b.second > 0)
			{
				auto& bids_for_state = m_current_bids[b.first];
				auto it = std::find_if(
					begin(bids_for_state), end(bids_for_state),
					[player_id](const CurrentBid& cb) { return cb.player_id == player_id; });
				if(it != end(bids_for_state))
                {
					it->number_of_tokens += b.second;
				}
				else
                {
					bids_for_state.push_back({player_id, b.second});
				}
			}
        }
	}

	void GameState::checkInvariants() const
    {
		assert(m_current_bids.size() == m_map.numberOfStates());
		for(const auto& b : m_current_bids)
		{
			assert(b.size() < 2);
		}
	}

} // QTacitGame
