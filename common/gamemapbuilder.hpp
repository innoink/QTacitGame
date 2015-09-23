#pragma once

#include "gamemap.hpp"

namespace QTacitGame
{

    class GameMapBuilder
    {
    public:
        static GameMap fromJson(const std::string& str);

    };

} //QTacitGame
