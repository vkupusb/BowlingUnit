#include "Frame.h"

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
BowlingGame::Frame::Frame::Frame() : m_firstRoll{0}, m_secondRoll{0}, m_frameScore{0},
									 m_isFrameSpare{false}, m_isFrameStrike{false}
{
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Frame::Frame::setFirstRollScore(const uint16_t &rollScore)
{
	if (m_firstRoll != rollScore)
	{
		m_firstRoll = rollScore;
		if (rollScore == MAX_ROLL_SCORE)
		{
			m_isFrameStrike = true; // if 10 pin cleared in first roll, set strike in that frame
		}
		return true;
	}
	return false;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
const uint16_t &BowlingGame::Frame::Frame::getFirstRollScore() const
{
	return m_firstRoll;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Frame::Frame::setSecondRollScore(const uint16_t &rollScore)
{
	if (m_secondRoll != rollScore)
	{
		m_secondRoll = rollScore;
		if (m_firstRoll == MIN_ROLL_SCORE && m_secondRoll == MAX_ROLL_SCORE)
		{
			m_isFrameStrike = true; // if 10 pin cleared in first roll, set strike in that frame
		}
		else if (auto value{m_firstRoll + m_secondRoll}; value == MAX_ROLL_SCORE)
		{
			m_isFrameSpare = true; // if 10 pin cleared in first and second roll, set spare in that frame
		}
		return true;
	}
	return false;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
const uint16_t &BowlingGame::Frame::Frame::getSecondRollScore() const
{
	return m_secondRoll;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
const bool &BowlingGame::Frame::Frame::isStrike() const
{
	return m_isFrameStrike;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
const bool &BowlingGame::Frame::Frame::isSpare() const
{
	return m_isFrameSpare;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Frame::Frame::setFrameScore(const uint16_t &frameScore)
{
	if (m_frameScore != frameScore)
	{
		m_frameScore = frameScore;
		return true;
	}
	return false;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
const uint16_t &BowlingGame::Frame::Frame::getFrameScore() const
{
	return m_frameScore;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Frame::Frame::setThirdRollScore(const uint16_t &rollScore)
{
	return false;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
const uint16_t &BowlingGame::Frame::Frame::getThirdRollScore() const
{
	return m_secondRoll;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
BowlingGame::Frame::FinalFrame::FinalFrame() : m_thirdRoll{0}
{
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Frame::FinalFrame::setThirdRollScore(const uint16_t &rollScore)
{
	if (m_thirdRoll != rollScore)
	{
		m_thirdRoll = rollScore;
		if (rollScore == MAX_ROLL_SCORE)
		{
			m_isFrameStrike = true; // if 10 pin cleared in first roll, set strike in that frame
		}
		return true;
	}
	return false;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
const uint16_t &BowlingGame::Frame::FinalFrame::getThirdRollScore() const
{
	return m_thirdRoll;
}
