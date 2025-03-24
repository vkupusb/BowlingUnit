#include <algorithm>
#include <iostream>
#include "Player.h"

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
BowlingGame::Players::Player::Player() :mTotalScore{ 0 }, mFirstName{},mLastName{}
{
	mFrames.reserve(MAX_FRAME_COUNT); // reserver space for 10 frames
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Players::Player::createFrames()
{
	for (auto count = 0; count < (MAX_FRAME_COUNT - 1); count++) {
		auto frame = std::make_shared<BowlingGame::Frame::NormalFrame>();
		mFrames.push_back(std::move(frame)); // add frame into vector
	}
	auto frame = std::make_unique<BowlingGame::Frame::FinalFrame>();
	mFrames.push_back(std::move(frame));
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Players::Player::setPlayerName(std::string_view first_name, std::string_view last_name)
{
	mFirstName = first_name;
	mLastName = last_name;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
std::string BowlingGame::Players::Player::getPlayerName()
{
	return mFirstName +" " + mLastName;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Players::Player::calculateTotalScore()
{
	for(auto index=0; index < MAX_FRAME_COUNT; index++){
		mTotalScore += mFrames[index]->getFirstRollScore(); // get first rool score
		if (mFrames[index]->isStrike() && index < (MAX_FRAME_COUNT-1)){
			mTotalScore += mFrames[index+1]->getFirstRollScore(); // if strike, next roll score from next frame
			if (mFrames[index+1]->isStrike()){
				mTotalScore += mFrames[index+2]->getFirstRollScore();// if strike, next roll score from next frame
			}
			else{
				mTotalScore += mFrames[index+1]->getSecondRollScore(); // if strike, next roll score from the same frame
			}
		}
		else if(mFrames[index]->isStrike() && index == (MAX_FRAME_COUNT-1)){ // Frame 10
			mTotalScore += mFrames[index]->getSecondRollScore();
			mTotalScore += mFrames[index]->getThirdRollScore();

		}
		else if (mFrames[index]->isSpare()){
			mTotalScore += mFrames[index]->getSecondRollScore(); // if spare, get the second roll score in the same frame
			if (index == (MAX_FRAME_COUNT-1)){
				mTotalScore += mFrames[index]->getThirdRollScore();// if spare, get the third roll score from the last frame

			}else{
				mTotalScore += mFrames[index+1]->getFirstRollScore();

			}
			
		}
		else{
			mTotalScore += mFrames[index]->getSecondRollScore(); //if no strike, get score of the current frame
		}

		std::cout<<"Frame:"<<(index+1)<<"="<<mTotalScore<<" ";

	}
	std::cout <<'\n'<< getPlayerName() << " scored " << mTotalScore << " points\n";
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
uint16_t BowlingGame::Players::Player::getTotalScore()
{
	return mTotalScore;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Players::Player::getRollScore()
{
	for (auto index = 1; index <= MAX_FRAME_COUNT; index++) {
		auto score1{ 0 }, score2{ 0 };
		auto rollNumber{ 1 };
		score1 = getScorFromConsole(index, rollNumber,score2);
		mFrames[index-1]->setFirstRollScore(score1); // roll 1 score
		if (score1 < MAX_ROLL_SCORE) { // if not strike or less pin, the allow second roll in the current frame
			rollNumber++;
			score2 = getScorFromConsole(index, rollNumber, score1);
			mFrames[index-1]->setSecondRollScore(score2);
		}
		if (index == MAX_FRAME_COUNT){ //Frame 10

			auto score3{0}, totalFrameScore{0};

			if (mFrames[index-1]->isStrike()){
				score2 = getScorFromConsole(index, ++rollNumber, 0);
				mFrames[index-1]->setSecondRollScore(score2);
				score3 = getScorFromConsole(index, ++rollNumber, 0);
				mFrames[index-1]->setThirdRollScore(score3);
				totalFrameScore = score1 + score2 + score3;
			}
			else if(mFrames[index-1]->isSpare()){
				auto score3 = getScorFromConsole(index, ++rollNumber, 0);
				mFrames[index-1]->setThirdRollScore(score3);
				totalFrameScore = score1 + score2 + score3;
			}
			mFrames[index - 1]->setFrameScore(totalFrameScore);
		}
		else{
			mFrames[index - 1]->setFrameScore(score1 + score2);
		}
		
	}
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
int BowlingGame::Players::Player::getScorFromConsole(int index, int rollNum, int prevScore)
{
	auto flag{ false };
	auto score{ 0 };
	do {
		flag = false;
		std::cout << "Frame:" << index << " ,Roll" << rollNum << ": ";
		std::cin >> score;
		if ((score + prevScore) > 10) {
			flag = true;
			std::cout << "Please enter valid score (0-10)\n";
		}
	} while (flag);
	return score;
}
