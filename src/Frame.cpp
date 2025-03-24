#include "Frame.h"

BowlingGame::Frame::Frame::Frame():m_nFirstRoll{0},m_nSecondRoll{0},m_nFrameScore{0},
m_bFrameSpare {false},m_bFrameStrike{false}
{
}

void BowlingGame::Frame::Frame::setFirstRollScore(unsigned int score)
{
	if (m_nFirstRoll != score) {
		m_nFirstRoll = score;
		if (score == MAX_ROLL_SCORE) {
			m_bFrameStrike = true;
		}
	}
}

unsigned int BowlingGame::Frame::Frame::getFirstRollScore()
{
	return m_nFirstRoll;
}

void BowlingGame::Frame::Frame::setSecondRollScore(unsigned int score)
{
	if (m_nSecondRoll != score) {
		m_nSecondRoll = score;
		if (m_nFirstRoll == MIN_ROLL_SCORE && m_nSecondRoll == MAX_ROLL_SCORE){
			m_bFrameStrike = true;
		}
		else if (auto value{ m_nFirstRoll + m_nSecondRoll }; value == MAX_ROLL_SCORE) {
			m_bFrameSpare = true;
		}
	}
}

unsigned int BowlingGame::Frame::Frame::getSecondRollScore()
{
	return m_nSecondRoll;
}

bool BowlingGame::Frame::Frame::isStrike()
{
	return m_bFrameStrike;
}

bool BowlingGame::Frame::Frame::isSpare()
{
	return m_bFrameSpare;
}

void BowlingGame::Frame::Frame::setFrameScore(unsigned int score)
{
	if (m_nFrameScore != score) {
		m_nFrameScore = score;
	}
}

unsigned int BowlingGame::Frame::Frame::getFrameScore()
{
	return m_nFrameScore;
}

void BowlingGame::Frame::Frame::setThirdRollScore(unsigned int score)
{
	
}

unsigned int BowlingGame::Frame::Frame::getThirdRollScore()
{
    return 0;
}

BowlingGame::Frame::FinalFrame::FinalFrame():m_nThirdRoll{0}
{
	
}

void BowlingGame::Frame::FinalFrame::setThirdRollScore(unsigned int score)
{
	if (m_nThirdRoll != score) {
		m_nThirdRoll = score;
		if (score == MAX_ROLL_SCORE) {
			m_bFrameStrike = true;
		}
	}
}

unsigned int BowlingGame::Frame::FinalFrame::getThirdRollScore()
{
	return m_nThirdRoll;
}
