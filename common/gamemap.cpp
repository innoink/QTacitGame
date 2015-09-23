#include "gamemap.hpp"

#include <algorithm>
#include <cassert>

namespace QTacitGame
{

    std::size_t GameMap::numberOfSates() const
    {
        return m_states.size();
    }

    std::string GameMap::stateName(const StateIndexType index) const
    {
        assert(exists(index));
        return m_states[index];
    }

    bool GameMap::exists(const StateIndexType index) const
    {
        return index < numberOfSates();
    }

    bool GameMap::exists(const std::string& name) const
    {
        return std::find(begin(m_states), end(m_states), name) != end(m_states);
    }

} //QTacitGame
