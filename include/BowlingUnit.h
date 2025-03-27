#pragma once

#include "Player.h"
#include "CommonDef.h"

namespace BowlingGame::Unit
{

	class BowlingUnit
	{
	public:
		BowlingUnit() = default;
		~BowlingUnit() = default;

		/*
		\brief	add player name in the bowling unit
		\author	Vishvanathan K
		\param	player first and last name as string
		\return None
		*/
		bool addPlayer(std::string_view firstName, std::string_view lastName);

		/*
	   \brief	remove player name from the bowling unit
	   \author	Vishvanathan K
	   \param	player first and last name as string
	   \return None
	   */
		bool removePlayer(std::string_view firstName, const std::string_view lastName);

		/*
	   \brief	start the bowling game
	   \author	Vishvanathan K
	   \param	player first and last name as string
	   \return None
	   */
		void startGame();

	private:
		std::vector<std::shared_ptr<BowlingGame::Players::Player>> m_players; /*!< third roll value */
	};

}
