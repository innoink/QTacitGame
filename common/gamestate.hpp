#pragma once

#include <vector>

namespace QTacitGame
{

	class Bid;
	class GameMap;

	/**
	* @brief The GameState class
	* @invariant m_current_bids.size() == map.numberOfSates()
	*/
	class GameState
	{
	public:
		struct CurrentBid
		{
			std::size_t player_id;
			std::size_t number_of_tokens;
		};

		using CurrentBidsContainer_t = std::vector<CurrentBid>;

		GameState(const GameMap& map, const std::size_t number_of_players);
		~GameState() = default;

		std::size_t numberOfPlayers() const;

		/**
		* @pre bids.size() == m_number_of_players
		*/
		void resolve(const std::vector<Bid>& bids);

		/**
		* @brief currentBids
		* @post res.size() == map.numberOfSates()
		* @return
		*/
		CurrentBidsContainer_t currentBids() const;

	private:
		const GameMap& m_map;
		const std::size_t m_number_of_players;
		CurrentBidsContainer_t m_current_bids;

		void resolveCollisions();
	};

} // QTacitGame
