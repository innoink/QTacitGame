#pragma once

#include <string>
#include <vector>

class GameMap
{
public:
    using StateContainer = std::vector<std::string>;
    using StateIndexType = std::size_t;

    GameMap() = default;
    ~GameMap() = default;

    std::size_t numberOfSates() const;

    /**
     * @brief stateName Return the name of a state given its indentifier.
     * @param index The index of the state
     * @return The name of the state
     * @pre index < numberOfSates()
     */
    std::string stateName(const StateIndexType index) const;

private:
     StateContainer m_states;
};