#pragma once
#include <vector>
#include <memory>
#include <string>
#include <string_view>

#include "Frame.h"

namespace BowlingGame::Players {
	class Player
	{
	public:
		Player();
		~Player() = default;

		/*
		\brief	create frames for a player
		\author	Vishvanathan K
		\param	None
		\return None
		*/
		void createFrames();

		/*
		\brief	set player name 
		\author	Vishvanathan K
		\param	None
		\return None
		*/
		void setPlayerName(std::string_view first_name, std::string_view last_name);

		/*
		\brief	return player full name
		\author	Vishvanathan K
		\param	None
		\return player name as string
		*/
		std::string getPlayerName();

		/*
		\brief	calculate the total score from each frame
		\author	Vishvanathan K
		\param	None
		\return None
		*/
		void calculateTotalScore();

		/*
		\brief	return total score of the player
		\author	Vishvanathan K
		\param	None
		\return total score data as unsigned int
		*/
		uint16_t getTotalScore();

		/*
		\brief	get the each roll data from console window
		\author	Vishvanathan K
		\param	None
		\return None
		*/
		void getRollScore();
	private:
		std::vector<std::shared_ptr<BowlingGame::Frame::Frame>> mFrames; /*!< array of frames */
		uint16_t mTotalScore; /*!< total score value */
		std::string mFirstName; /*!< player first name */
		std::string mLastName; /*!< player last name */

		/*
		\brief	get the each roll data from console window
		\author	Vishvanathan K
		\param	frame number, roll number, first roll score
		\return score value
		*/
		int getScorFromConsole(int index, int rollNum, int prevScore);
	};
}
