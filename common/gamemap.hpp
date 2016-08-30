#pragma once

#include <string>
#include <vector>

namespace QTacitGame
{
	class GameMapBuilder;

	/**
	 * @brief The GameMap class represents the map of states in the game.
	 *
	 * Once the map is constructed, it is ensured that no state will be added or removed,
	 * so the indexes remain valid for the whole map life span.
	 */
	class GameMap
	{
	public:
		using StateContainer = std::vector<std::string>;
		using StateIndexType = std::size_t;

		friend class GameMapBuilder;

		GameMap() = default;
		~GameMap() = default;

		std::size_t numberOfStates() const;

		/**
		 * @brief stateName Return the name of a state given its indentifier.
		 * @param index The index of the state
		 * @return The name of the state
		 * @pre exists(index)
		 */
		std::string stateName(const StateIndexType index) const;

		/**
		 * @brief indexOf
		 * @param state_name
		 * @return
		 * @pre exists(state_name)
		 */
		StateIndexType indexOf(const std::string state_name) const;

		bool exists(const StateIndexType index) const;
		bool exists(const std::string& name) const;

		std::vector<StateIndexType> indexes() const;

	private:
		StateContainer m_states;
	};

} // QTacitGame
