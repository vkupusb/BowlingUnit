#include <algorithm>
#include <iostream>
#include <format>
#include <limits>

#include "Player.h"

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
BowlingGame::Players::Player::Player() : m_totalScore{0}, m_firstName{}, m_lastName{}
{
	m_frames.reserve(MAX_FRAME_COUNT); // reserver space for 10 frames
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Players::Player::createFrames()
{
	for (uint16_t frameIndex = 0; frameIndex < (MAX_FRAME_COUNT - 1); frameIndex++)
	{
		auto frame = std::make_shared<BowlingGame::Frame::NormalFrame>();
		m_frames.push_back(std::move(frame)); // add frame into vector
	}
	auto frame = std::make_unique<BowlingGame::Frame::FinalFrame>();
	m_frames.push_back(std::move(frame));

	return true;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Players::Player::setPlayerName(const std::string_view &first_name, const std::string_view &last_name)
{
	if ((m_firstName != first_name) || (m_lastName != last_name))
	{
		m_firstName = first_name;
		m_lastName = last_name;
		return true;
	}
	return false;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
std::string BowlingGame::Players::Player::getPlayerName()
{
	std::string playerName = m_firstName;
	playerName.append(" ");
	playerName.append(m_lastName);
	return playerName;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
uint16_t BowlingGame::Players::Player::calculateTotalScore()
{
	uint16_t frameIndex{0};

	calculateFirstToEightFrameScore(frameIndex);
	calculateNinthFrameScore(frameIndex);
	frameIndex++;
	calculateFinalFrameScore(frameIndex);

	return m_totalScore;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
uint16_t BowlingGame::Players::Player::getTotalScore()
{
	return m_totalScore;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Players::Player::getRollScore()
{
	uint16_t roll1Score{0}, roll2Score{0}, roll3Score{0}, rollNumber{1};
	uint16_t frameIndex{0};

	// get roll score from frame 1 to  frame 9
	for (; frameIndex < (MAX_FRAME_COUNT - 1); frameIndex++)
	{
		roll1Score = getRollScoreFromConsole(frameIndex, rollNumber++);
		m_frames[frameIndex]->setFirstRollScore(roll1Score); // roll 1 score
		if (roll1Score < MAX_ROLL_SCORE)
		{
			roll2Score = getRollScoreFromConsole(frameIndex, rollNumber, roll1Score);
			m_frames[frameIndex]->setSecondRollScore(roll2Score);
		}
		rollNumber = 1;
		m_frames[frameIndex]->setFrameScore((roll1Score + roll2Score));
	}

	// get roll score only for frame 10
	if (frameIndex == (MAX_FRAME_COUNT - 1))
	{
		roll1Score = getRollScoreFromConsole(frameIndex, rollNumber++);
		m_frames[frameIndex]->setFirstRollScore(roll1Score);

		// if frame 10 has strike, then get next roll score
		if (m_frames[frameIndex]->isStrike())
		{
			roll2Score = getRollScoreFromConsole(frameIndex, rollNumber++);
		}
		else
		{
			roll2Score = getRollScoreFromConsole(frameIndex, rollNumber++, roll1Score); // normal case
		}
		m_frames[frameIndex]->setSecondRollScore(roll2Score);

		// get extra roll score if strike or spare
		if (m_frames[frameIndex]->isStrike() || m_frames[frameIndex]->isSpare())
		{
			roll3Score = getRollScoreFromConsole(frameIndex, rollNumber);
			m_frames[frameIndex]->setThirdRollScore(roll3Score);
		}
		m_frames[frameIndex]->setFrameScore((roll1Score + roll2Score + roll3Score));
	}
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
uint16_t BowlingGame::Players::Player::getRollScoreFromConsole(const uint16_t &frameIndex, const uint16_t &rollNum, const uint16_t &prevRollScore)
{
	bool isValidScore{false};
	uint16_t rollScore{0};
	do
	{
		std::cout << std::format("Frame:{},Roll{}:", (frameIndex + 1), rollNum);
		std::cin >> rollScore;
		isValidScore = isValidRollScore((rollScore + prevRollScore));
		if (!isValidScore)
		{
			std::cout << "Please enter valid score (0-10)\n";
		}
	} while (!isValidScore);
	return rollScore;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Players::Player::isValidRollScore(const uint8_t &rollScore)
{
	if ((rollScore < MIN_ROLL_SCORE) || (rollScore > MAX_ROLL_SCORE))
	{
		return false;
	}
	return true;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Players::Player::calculateFirstToEightFrameScore(uint16_t &frameIndex)
{
	for (; frameIndex < (MAX_FRAME_COUNT - 2); frameIndex++)
	{
		m_totalScore += m_frames[frameIndex]->getFirstRollScore(); // get first rool score
		if (m_frames[frameIndex]->isStrike())
		{
			m_totalScore += m_frames[frameIndex + 1]->getFirstRollScore(); // if strike, next roll score from next frame
			if (m_frames[frameIndex + 1]->isStrike())
			{
				m_totalScore += m_frames[frameIndex + 2]->getFirstRollScore(); // if strike, next roll score from next frame
			}
			else
			{
				m_totalScore += m_frames[frameIndex+1]->getSecondRollScore();
			}
		}
		else if (m_frames[frameIndex]->isSpare())
		{
			m_totalScore += m_frames[frameIndex]->getSecondRollScore();
			m_totalScore += m_frames[frameIndex + 1]->getFirstRollScore();
		}
		else
		{
			m_totalScore += m_frames[frameIndex]->getSecondRollScore(); // if no strike, get score of the current frame
		}

		std::cout << std::format("Frame:{}", (frameIndex + 1)) << "=" << m_totalScore << " ";
	}
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Players::Player::calculateNinthFrameScore(uint16_t &frameIndex)
{
	if (frameIndex == MAX_FRAME_COUNT - 2)
	{
		m_totalScore += m_frames[frameIndex]->getFirstRollScore();
		if (m_frames[frameIndex]->isStrike())
		{
			m_totalScore += m_frames[MAX_FRAME_COUNT - 1]->getFirstRollScore();
			m_totalScore += m_frames[MAX_FRAME_COUNT - 1]->getSecondRollScore();
		}
		else if (m_frames[frameIndex]->isSpare())
		{
			m_totalScore += m_frames[frameIndex]->getSecondRollScore();
			m_totalScore += m_frames[MAX_FRAME_COUNT - 1]->getFirstRollScore();
		}
		else
		{
			m_totalScore += m_frames[frameIndex]->getSecondRollScore();
		}

		std::cout << std::format("Frame:{}", (frameIndex + 1)) << "=" << m_totalScore << " ";
	}
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Players::Player::calculateFinalFrameScore(uint16_t &frameIndex)
{
	if (frameIndex == MAX_FRAME_COUNT - 1)
	{
		m_totalScore += m_frames[frameIndex]->getFirstRollScore();
		m_totalScore += m_frames[frameIndex]->getSecondRollScore();

		if (m_frames[frameIndex]->isStrike() || m_frames[frameIndex]->isSpare())
		{
			m_totalScore += m_frames[frameIndex]->getThirdRollScore();
		}

		std::cout << std::format("Frame:{}", (frameIndex + 1)) << "=" << m_totalScore << " ";
	}
}
