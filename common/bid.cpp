#include "bid.hpp"

#include <cassert>

namespace QTacitGame
{

	Bid::Bid(const GameMap& map_)
		: m_map(map_)
	{
		for(const auto index : m_map.indexes())
			m_bids[index] = 0;
	}

	std::size_t Bid::count(const GameMap::StateIndexType state) const
	{
		assert(m_map.exists(state));
		auto it = m_bids.find(state);
		assert(it != end(m_bids));
		return it->second;
	}

	void Bid::place(const GameMap::StateIndexType state)
	{
		assert(m_map.exists(state));
		auto it = m_bids.find(state);
		assert(it != end(m_bids));
		it->second++;
	}
}
