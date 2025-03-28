#pragma once
#include "CommonDef.h"

namespace BowlingGame::Frame
{
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
		virtual bool setFirstRollScore(const uint16_t &rollScore);

		/*
		\brief	return score value of frist roll for each frame
		\author	Vishvanathan K
		\param	None
		\return score data as unsigned int
		*/
		virtual const uint16_t &getFirstRollScore() const;

		/*
		\brief	store the second roll score for each frame
		\author	Vishvanathan K
		\param	score data as unsigned int
		\return None
		*/
		virtual bool setSecondRollScore(const uint16_t &rollScore);

		/*
		\brief	return score value of second roll for each frame
		\author	Vishvanathan K
		\param	None
		\return score data as unsigned int
		*/
		virtual const uint16_t &getSecondRollScore() const;

		/*
		\brief	check if strike in each frame
		\author	Vishvanathan K
		\param	None
		\return true if stike, otherwise false
		*/
		virtual const bool &isStrike() const;

		/*
		\brief	check if spare in each frame
		\author	Vishvanathan K
		\param	None
		\return true if spare, otherwise false
		*/
		virtual const bool &isSpare() const;

		/*
		\brief	store the frame score
		\author	Vishvanathan K
		\param	score data as unsigned int
		\return None
		*/
		virtual bool setFrameScore(const uint16_t &frameScore);

		/*
		\brief	return score value of frame
		\author	Vishvanathan K
		\param	None
		\return frame score data as unsigned int
		*/
		virtual const uint16_t &getFrameScore() const;

		/*
		\brief	store the third roll score of frame10
		\author	Vishvanathan K
		\param	score data as unsigned int
		\return None
		*/
		virtual bool setThirdRollScore(const uint16_t &rollScore);

		/*
		\brief	return score value of third roll of frame 10
		\author	Vishvanathan K
		\param	None
		\return score data as unsigned int
		*/
		virtual uint16_t getThirdRollScore() const;

		/*
		\brief	check the roll score is valid or not
		\author	Vishvanathan K
		\param	score of roll
		\return true if valid, otherwise false
		*/
		bool isValidRollScore(const uint8_t &rollScore);

	protected:
		uint16_t m_firstRoll;  /*!< first roll value */
		uint16_t m_secondRoll; /*!< second roll value */
		uint16_t m_frameScore; /*!< frame score value */
		bool m_isFrameStrike;  /*!< strike of frame value */
		bool m_isFrameSpare;   /*!< spare of frame value */
	};

	class NormalFrame : public Frame
	{
	public:
		NormalFrame() = default;
		~NormalFrame() = default;
	};

	class FinalFrame : public Frame
	{
	public:
		FinalFrame();
		~FinalFrame() = default;

		/*
		\brief	store the third roll score of frame 10
		\author	Vishvanathan K
		\param	score data as unsigned int
		\return None
		*/
		bool setThirdRollScore(const uint16_t &rollScore);

		/*
		\brief	return score value of third roll of frame 10
		\author	Vishvanathan K
		\param	None
		\return score data as unsigned int
		*/
		uint16_t getThirdRollScore() const;

	private:
		uint16_t m_thirdRoll; /*!< third roll value */
	};
};
