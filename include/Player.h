#pragma once
#include "CommonDef.h"
#include "Frame.h"

namespace BowlingGame::Players
{
	class Player
	{
	public:
		Player();
		~Player() = default;

		/*
		\brief	create frames for a player
		\author	Vishvanathan K
		\param	None
		\return true if success, else false
		*/
		bool createFrames();

		/*
		\brief	set player name
		\author	Vishvanathan K
		\param	None
		\return true if success, else false
		*/
		bool setPlayerName(const std::string_view &first_name, const std::string_view &last_name);

		/*
		\brief	return player full name
		\author	Vishvanathan K
		\param	None
		\return player name as string
		*/
		std::string getPlayerName();

		/*
		\brief	return player first name
		\author	Vishvanathan K
		\param	None
		\return player first name as string
		*/
		const std::string &getPlayerFirstName() const;

		/*
		\brief	return player last name
		\author	Vishvanathan K
		\param	None
		\return player last name as string
		*/
		const std::string &getPlayerLastName() const;

		/*
		\brief	calculate the total score from each frame
		\author	Vishvanathan K
		\param	None
		\return None
		*/
		const uint16_t &calculateTotalScore();

		/*
		\brief	return total score of the player
		\author	Vishvanathan K
		\param	None
		\return total score data as unsigned int
		*/
		const uint16_t &getTotalScore();

		/*
		\brief	get the each roll data from console window
		\author	Vishvanathan K
		\param	None
		\return None
		*/
		void getRollScore();

		/*
		\brief	get the total number of frames created for the player
		\author	Vishvanathan K
		\param	None
		\return frame count
		*/
		const uint16_t &getFrameCount() const;

		/*
		\brief	set the roll score for uint testing
		\author	Vishvanathan K
		\param	uint16_t rollNumber,frameIndex,rollScore
		\return frame count
		*/
		bool setRollScore(const uint16_t &rollNumber, const uint16_t &frameIndex, const uint16_t &rollScore);

	private:
		std::vector<std::shared_ptr<BowlingGame::Frame::Frame>> m_frames; /*!< array of frames */
		uint16_t m_totalScore;
		uint16_t m_frameCount;	 /*!< total score value */
		std::string m_firstName; /*!< player first name */
		std::string m_lastName;	 /*!< player last name */

		/*
		\brief	get the each roll data from console window
		\author	Vishvanathan K
		\param	frame number, roll number, first roll score
		\return score value
		*/
		inline uint16_t getRollScoreFromConsole(const uint16_t &frameIndex, const uint16_t &rollNum, const uint16_t &prevRollScore = 0);

		/*
		\brief	check the roll score is valid or not
		\author	Vishvanathan K
		\param	score of roll
		\return true if valid, otherwise false
		*/
		inline bool isValidRollScore(const uint8_t &rollScore);

		/*
		\brief	calculate the total score from frame1 to frame8
		\author	Vishvanathan K
		\param	frame index
		\return None
		*/
		void calculateFirstToEightFrameScore(uint16_t &frameIndex);

		/*
		\brief	calculate the total score of frame 9
		\author	Vishvanathan K
		\param	frame index
		\return None
		*/
		void calculateNinthFrameScore(uint16_t &frameIndex);

		/*
		\brief	calculate the total score of frame 9
		\author	Vishvanathan K
		\param	frame index
		\return None
		*/
		void calculateFinalFrameScore(uint16_t &frameIndex);
	};
}
