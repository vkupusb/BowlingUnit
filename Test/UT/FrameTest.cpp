#include <gtest/gtest.h>
#include "../../include/CommonDef.h"
#include "../../include/Frame.h"

using namespace BowlingGame::Frame;

class FrameTest : public ::testing::Test
{
public:
    std::unique_ptr<BowlingGame::Frame::NormalFrame> simpleFrame{nullptr};
    std::unique_ptr<BowlingGame::Frame::FinalFrame> finalFrame{nullptr};

protected:
    virtual void SetUp() override
    {
        simpleFrame = std::make_unique<BowlingGame::Frame::NormalFrame>();
        finalFrame = std::make_unique<BowlingGame::Frame::FinalFrame>();
    }

    virtual void TearDown() override
    {
    }
};

/*
@NAME : SWUT_checkFrameCreation_0001
@DES : Test whether Frame object is created or not
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : NA
@TSA : NA
@TSE : check frame object is not null
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_checkFrameCreation_0001)
{
    printf("*********** SWUT_checkFrameCreation_0001 \n");
    // Precondition

    // Action

    // Expected
    EXPECT_NE(simpleFrame, nullptr) << "Object creation failed";
}

/*
@NAME : SWUT_setFirstRollScore_0001
@DES : Test set first roll score
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set rollS score value
@TSA : call setFirstRollScore
@TSE : check first roll score in the current frame
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setFirstRollScore_0001)
{
    printf("*********** SWUT_setFirstRollScore_0001 \n");

    // Precondition
    uint16_t rollScore{10};

    // Action
    simpleFrame->setFirstRollScore(rollScore);

    // Expected
    EXPECT_EQ(rollScore, simpleFrame->getFirstRollScore());
}

/*
@NAME : SWUT_setFirstRollScore_0002
@DES : Test set first roll score
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set rollS score value
@TSA : call setFirstRollScore
@TSE : check frame have strike or not
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setFirstRollScore_0002)
{
    printf("*********** SWUT_setFirstRollScore_0002 \n");

    // Precondition
    uint16_t rollScore{10};

    // Action
    simpleFrame->setFirstRollScore(rollScore);

    // Expected
    EXPECT_TRUE(simpleFrame->isStrike());
}

/*
@NAME : SWUT_setFirstRollScore_0003
@DES : Test set first roll score
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set rollS score value
@TSA : call setFirstRollScore
@TSE : check frame have strike or not
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setFirstRollScore_0003)
{
    printf("*********** SWUT_setFirstRollScore_0003 \n");

    // Precondition
    uint16_t rollScore{5};

    // Action
    simpleFrame->setFirstRollScore(rollScore);

    // Expected
    EXPECT_FALSE(simpleFrame->isStrike());
}

/*
@NAME : SWUT_setFirstRollScore_0004
@DES : Test roll score is valid or not
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set rollS score value as lower bound -1
@TSA : call setFirstRollScore
@TSE : check the score is valid
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setFirstRollScore_0004)
{
    printf("*********** SWUT_setFirstRollScore_0004 \n");

    // Precondition
    int16_t rollScore{-1};

    // Action
    bool isValidScore = simpleFrame->setFirstRollScore(rollScore);

    // Expected
    EXPECT_FALSE(isValidScore);
}

/*
@NAME : SWUT_setFirstRollScore_0005
@DES : Test roll score is valid or not
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set rollS score value as upper bound 100
@TSA : call setFirstRollScore
@TSE : check the score is valid
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setFirstRollScore_0005)
{
    printf("*********** SWUT_setFirstRollScore_0005 \n");

    // Precondition
    int16_t rollScore{100};

    // Action
    bool isValidScore = simpleFrame->setFirstRollScore(rollScore);

    // Expected
    EXPECT_FALSE(isValidScore);
}

/*
@NAME : SWUT_setSecondRollScore_0001
@DES : Test set second roll score
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set rollS score value
@TSA : call setFirstRollScore
@TSE : check frame have strike/spare or not
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setSecondRollScore_0001)
{
    printf("*********** SWUT_setSecondRollScore_0001 \n");

    // Precondition
    uint16_t rollScore{5};
    simpleFrame->setFirstRollScore(rollScore);

    // Action
    simpleFrame->setSecondRollScore(rollScore);

    // Expected
    EXPECT_FALSE(simpleFrame->isStrike());
    EXPECT_TRUE(simpleFrame->isSpare());
}

/*
@NAME : SWUT_setSecondRollScore_0002
@DES : Test roll score is valid or not
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set rollS score value as lower bound -1
@TSA : call setSecondRollScore
@TSE : check the score is valid
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setSecondRollScore_0002)
{
    printf("*********** SWUT_setSecondRollScore_0002 \n");

    // Precondition
    int16_t rollScore{-1};

    // Action
    bool isValidScore = simpleFrame->setSecondRollScore(rollScore);

    // Expected
    EXPECT_FALSE(isValidScore);
}

/*
@NAME : SWUT_setSecondRollScore_0003
@DES : Test roll score is valid or not
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set rollS score value as upper bound 100
@TSA : call setSecondRollScore
@TSE : check the score is valid
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setSecondRollScore_0003)
{
    printf("*********** SWUT_setSecondRollScore_0003 \n");

    // Precondition
    int16_t rollScore{100};

    // Action
    bool isValidScore = simpleFrame->setSecondRollScore(rollScore);

    // Expected
    EXPECT_FALSE(isValidScore);
}

/*
@NAME : SWUT_setFrameScore_0001
@DES : Test set Frame score
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set frame score value
@TSA : call setFrameScore
@TSE : check frame score
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setFrameScore_0001)
{
    printf("*********** SWUT_setFrameScore_0001 \n");

    // Precondition
    uint16_t rollScore{5};
    simpleFrame->setFirstRollScore(rollScore);
    rollScore = 4;
    simpleFrame->setSecondRollScore(rollScore);

    // Action
    uint16_t frameScore = simpleFrame->getFirstRollScore();
    frameScore += simpleFrame->getSecondRollScore();
    simpleFrame->setFrameScore(frameScore);

    // Expected
    EXPECT_EQ(frameScore, simpleFrame->getFrameScore());
}

/*
@NAME : SWUT_setThirdRollScore_0001
@DES : Test set third roll score
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set roll score value
@TSA : call setThirdRollScore
@TSE : check final frame third roll score
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setThirdRollScore_0001)
{
    printf("*********** SWUT_setThirdRollScore_0001 \n");

    // Precondition
    uint16_t rollScore{5};

    // Action
    finalFrame->setThirdRollScore(rollScore);

    // Expected
    EXPECT_EQ(rollScore, finalFrame->getThirdRollScore());
}

/*
@NAME : SWUT_setThirdRollScore_0002
@DES : Test roll score is valid or not
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set rollS score value as lower bound -1
@TSA : call setThirdRollScore
@TSE : check the score is valid
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setThirdRollScore_0002)
{
    printf("*********** SWUT_setThirdRollScore_0002 \n");

    // Precondition
    int16_t rollScore{-1};

    // Action
    bool isValidScore = finalFrame->setThirdRollScore(rollScore);

    // Expected
    EXPECT_FALSE(isValidScore);
}

/*
@NAME : SWUT_setThirdRollScore_0003
@DES : Test roll score is valid or not
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set rollS score value as upper bound 100
@TSA : call setThirdRollScore
@TSE : check the score is valid
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(FrameTest, SWUT_setThirdRollScore_0003)
{
    printf("*********** SWUT_setThirdRollScore_0003 \n");

    // Precondition
    int16_t rollScore{100};

    // Action
    bool isValidScore = finalFrame->setThirdRollScore(rollScore);

    // Expected
    EXPECT_FALSE(isValidScore);
}