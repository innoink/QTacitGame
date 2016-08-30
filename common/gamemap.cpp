#include "gamemap.hpp"

#include <algorithm>
#include <cassert>

namespace QTacitGame
{

	std::size_t GameMap::numberOfStates() const { return m_states.size(); }

	std::string GameMap::stateName(const StateIndexType index) const
	{
		assert(exists(index));
		return m_states[index];
	}

	auto GameMap::indexOf(const std::string state_name) const -> StateIndexType
	{
		assert(exists(state_name));
		return std::distance(begin(m_states),
							 std::find(begin(m_states), end(m_states), state_name));
	}

	bool GameMap::exists(const StateIndexType index) const { return index < numberOfStates(); }

	bool GameMap::exists(const std::string& name) const
	{
		return std::find(begin(m_states), end(m_states), name) != end(m_states);
	}

	auto GameMap::indexes() const -> std::vector<StateIndexType>
	{
		std::vector<StateIndexType> res;
		res.reserve(m_states.size());
		for(std::size_t i = 0; i < m_states.size(); i++)
			res.push_back(i);
		return res;
	}

} // QTacitGame
