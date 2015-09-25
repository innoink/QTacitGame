#pragma once

#include "gamemap.hpp"

#include <map>

namespace QTacitGame
{

    class Bid
    {
    public:
        using StateIndexType = GameMap::StateIndexType;

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

    private:
        const GameMap& m_map;
        std::map<StateIndexType, std::size_t> m_bids;
    };

} //QTacitGame
