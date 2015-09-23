#pragma once

#include <string>
#include <vector>

namespace QTacitGame
{
    class GameMapBuilder;

    class GameMap
    {
    public:
        using StateContainer = std::vector<std::string>;
        using StateIndexType = std::size_t;

        friend class GameMapBuilder;

        GameMap() = default;
        ~GameMap() = default;

        std::size_t numberOfSates() const;

        /**
         * @brief stateName Return the name of a state given its indentifier.
         * @param index The index of the state
         * @return The name of the state
         * @pre exists(index)
         */
        std::string stateName(const StateIndexType index) const;

        bool exists(const StateIndexType index) const;
        bool exists(const std::string& name) const;

    private:
         StateContainer m_states;
    };

} //QTacitGame
