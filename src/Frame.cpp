#include "Frame.h"

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
BowlingGame::Frame::Frame::Frame():m_nFirstRoll{0},m_nSecondRoll{0},m_nFrameScore{0},
m_bFrameSpare {false},m_bFrameStrike{false}
{
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Frame::Frame::setFirstRollScore(unsigned int score)
{
	if (m_nFirstRoll != score) {
		m_nFirstRoll = score;
		if (score == MAX_ROLL_SCORE) {
			m_bFrameStrike = true; // if 10 pin cleared in first roll, set strike in that frame
		}
	}
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
unsigned int BowlingGame::Frame::Frame::getFirstRollScore()
{
	return m_nFirstRoll;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Frame::Frame::setSecondRollScore(unsigned int score)
{
	if (m_nSecondRoll != score) {
		m_nSecondRoll = score;
		if (m_nFirstRoll == MIN_ROLL_SCORE && m_nSecondRoll == MAX_ROLL_SCORE){
			m_bFrameStrike = true; // if 10 pin cleared in first roll, set strike in that frame
		}
		else if (auto value{ m_nFirstRoll + m_nSecondRoll }; value == MAX_ROLL_SCORE) {
			m_bFrameSpare = true; // if 10 pin cleared in first and second roll, set spare in that frame
		}
	}
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
unsigned int BowlingGame::Frame::Frame::getSecondRollScore()
{
	return m_nSecondRoll;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Frame::Frame::isStrike()
{
	return m_bFrameStrike;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Frame::Frame::isSpare()
{
	return m_bFrameSpare;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Frame::Frame::setFrameScore(unsigned int score)
{
	if (m_nFrameScore != score) {
		m_nFrameScore = score;
	}
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
unsigned int BowlingGame::Frame::Frame::getFrameScore()
{
	return m_nFrameScore;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Frame::Frame::setThirdRollScore(unsigned int score)
{
	
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
unsigned int BowlingGame::Frame::Frame::getThirdRollScore()
{
    return 0;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
BowlingGame::Frame::FinalFrame::FinalFrame():m_nThirdRoll{0}
{
	
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Frame::FinalFrame::setThirdRollScore(unsigned int score)
{
	if (m_nThirdRoll != score) {
		m_nThirdRoll = score;
		if (score == MAX_ROLL_SCORE) {
			m_bFrameStrike = true; // if 10 pin cleared in first roll, set strike in that frame
		}
	}
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
unsigned int BowlingGame::Frame::FinalFrame::getThirdRollScore()
{
	return m_nThirdRoll;
}
