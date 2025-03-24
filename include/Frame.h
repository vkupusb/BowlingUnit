#pragma once
#include "CommonDef.h"

namespace BowlingGame::Frame {
	class Frame
	{
	public:
		Frame();
		virtual ~Frame() = default;

		/*
		\brief	store the first roll score for each frame
		\author	Vishvanathan K
		\param	score data as unsigned int
		\return None
		*/
		virtual void setFirstRollScore(unsigned int);

		/*
		\brief	return score value of frist roll for each frame
		\author	Vishvanathan K
		\param	None
		\return score data as unsigned int
		*/
		virtual unsigned int getFirstRollScore();

		/*
		\brief	store the second roll score for each frame
		\author	Vishvanathan K
		\param	score data as unsigned int
		\return None
		*/
		virtual void setSecondRollScore(unsigned int);

		/*
		\brief	return score value of second roll for each frame
		\author	Vishvanathan K
		\param	None
		\return score data as unsigned int
		*/
		virtual unsigned int getSecondRollScore();

		/*
		\brief	check if strike in each frame
		\author	Vishvanathan K
		\param	None
		\return true if stike, otherwise false
		*/
		virtual bool isStrike();

		/*
		\brief	check if spare in each frame
		\author	Vishvanathan K
		\param	None
		\return true if spare, otherwise false
		*/
		virtual bool isSpare();

		/*
		\brief	store the frame score 
		\author	Vishvanathan K
		\param	score data as unsigned int
		\return None
		*/
		virtual void setFrameScore(unsigned int);

		/*
		\brief	return score value of frame
		\author	Vishvanathan K
		\param	None
		\return frame score data as unsigned int
		*/
		virtual unsigned int getFrameScore();

		/*
		\brief	store the third roll score of frame10
		\author	Vishvanathan K
		\param	score data as unsigned int
		\return None
		*/
		virtual void setThirdRollScore(unsigned int score);

		/*
		\brief	return score value of third roll of frame 10
		\author	Vishvanathan K
		\param	None
		\return score data as unsigned int
		*/
		virtual unsigned int getThirdRollScore();
	protected:
		unsigned int m_nFirstRoll; /*!< first roll value */
		unsigned int m_nSecondRoll; /*!< second roll value */
		unsigned int m_nFrameScore; /*!< frame score value */
		bool m_bFrameStrike; /*!< strike of frame value */
		bool m_bFrameSpare; /*!< spare of frame value */

	};

	class NormalFrame : public Frame {
	public:
		NormalFrame() = default;
		~NormalFrame() = default;
	};

	class FinalFrame : public Frame {
	public:
		FinalFrame();
		~FinalFrame() = default;

		/*
		\brief	store the third roll score of frame 10
		\author	Vishvanathan K
		\param	score data as unsigned int
		\return None
		*/
		void setThirdRollScore(unsigned int score);

		/*
		\brief	return score value of third roll of frame 10
		\author	Vishvanathan K
		\param	None
		\return score data as unsigned int
		*/
		unsigned int getThirdRollScore();
	private:
		unsigned int m_nThirdRoll; /*!< third roll value */
	};
};
