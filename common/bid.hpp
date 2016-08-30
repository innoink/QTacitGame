#pragma once

#include "gamemap.hpp"

#include <map>

namespace QTacitGame
{

	class Bid
	{
	public:
		using StateIndexType = GameMap::StateIndexType;
		using Container_t = std::map<StateIndexType, std::size_t>;
		using ConstIterator_t = Container_t::const_iterator;

		Bid(const GameMap& map_);
		~Bid() = default;

		/**
		 * @brief count
		 * @param state
		 * @return
		 * @pre state exists in m_map
		 */
		std::size_t count(const StateIndexType state) const;

		/**
		 * @brief place
		 * @param state
		 * @pre state exists in m_map
		 */
		void place(const StateIndexType state);

		ConstIterator_t begin() const;
		ConstIterator_t end() const;

	private:
		const GameMap& m_map;
		Container_t m_bids;
	};

} // QTacitGame
