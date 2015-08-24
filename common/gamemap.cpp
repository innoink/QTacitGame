#include "gamemap.hpp"

#include <cassert>

std::size_t GameMap::numberOfSates() const
{
    return m_states.size();
}

std::string GameMap::stateName(const StateIndexType index) const
{
    assert(index < numberOfSates());
    return m_states[index];
}

