#pragma once
#include "CommonDef.h"

namespace BowlingGame::Frame {
	class Frame
	{
	public:
		Frame();
		virtual ~Frame() = default;
		virtual void setFirstRollScore(unsigned int);
		virtual unsigned int getFirstRollScore();
		virtual void setSecondRollScore(unsigned int);
		virtual unsigned int getSecondRollScore();
		virtual bool isStrike();
		virtual bool isSpare();
		virtual void setFrameScore(unsigned int);
		virtual unsigned int getFrameScore();
		virtual void setThirdRollScore(unsigned int score);
		virtual unsigned int getThirdRollScore();
	protected:
		unsigned int m_nFirstRoll;
		unsigned int m_nSecondRoll;
		unsigned int m_nFrameScore;
		bool m_bFrameStrike;
		bool m_bFrameSpare;

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
		void setThirdRollScore(unsigned int score);
		unsigned int getThirdRollScore();
	private:
		unsigned int m_nThirdRoll;
	};
};
