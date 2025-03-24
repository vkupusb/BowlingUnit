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
		void createFrames();
		void setPlayerName(std::string_view first_name, std::string_view last_name);
		std::string getPlayerName();
		void calculateTotalScore();
		uint16_t getTotalScore();
		void getRollScore();
	private:
		std::vector<std::shared_ptr<BowlingGame::Frame::Frame>> mFrames;
		uint16_t mTotalScore;
		std::string mFirstName;
		std::string mLastName;
		int getScorFromConsole(int index, int rollNum, int prevScore);
	};
}
