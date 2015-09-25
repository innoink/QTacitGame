#include "gamemapbuilder.hpp"

#include "utils/json_helper.hpp"

namespace QTacitGame
{

	using namespace Utils::JsonHelper;

	GameMap GameMapBuilder::fromJson(const std::string& str)
	{
		const auto js = json::parse(str);
		const auto s = getAndCheckType<json::array_t>(js, "states", json::value_t::array);
		GameMap res;
		for(const auto& state : s)
		{
			res.m_states.push_back(state);
		}
		return res;
	}

} // QTacitGame
