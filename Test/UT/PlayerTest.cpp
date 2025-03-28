#include <gtest/gtest.h>
#include "../../include/CommonDef.h"
#include "../../include/Player.h"

using namespace BowlingGame::Players;

class PlayerTest : public ::testing::Test
{
public:
    std::unique_ptr<BowlingGame::Players::Player> player{nullptr};

protected:
    virtual void SetUp() override
    {
        player = std::make_unique<BowlingGame::Players::Player>();
    }

    virtual void TearDown() override
    {
    }
};

/*
@NAME : SWUT_checkPlayerCreation_0001
@DES : Test whether Player object is created or not
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : NA
@TSA : NA
@TSE : check reserved frame count for the current player
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(PlayerTest, SWUT_checkPlayerCreation_0001)
{
    printf("*********** SWUT_checkPlayerCreation_0001 \n");
    // Precondition

    // Action
    bool frames = player->createFrames();

    // Expected
    EXPECT_TRUE(frames);
}

/*
@NAME : SWUT_checkPlayerCreation_0002
@DES : Test whether Player object is created or not
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : NA
@TSA : call createFrames function
@TSE : check reserved frame count for the current player
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(PlayerTest, SWUT_checkPlayerCreation_0002)
{
    printf("*********** SWUT_checkPlayerCreation_0002 \n");
    // Precondition

    // Action
    bool frames = player->createFrames();

    // Expected
    EXPECT_TRUE(frames);
    EXPECT_EQ(player->getFrameCount(), MAX_FRAME_COUNT);
}

/*
@NAME : SWUT_setPlayerName_0001
@DES : Test whether Player name is set properly
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set player first name, last name
@TSA : call setPlayerName function
@TSE : check full name of player
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(PlayerTest, SWUT_setPlayerName_0001)
{
    printf("*********** SWUT_setPlayerName_0001 \n");
    // Precondition
    std::string firstName = "Joshua";
    std::string lastName = "Kimmich";
    std::string name = firstName;
    name.append(" ");
    name.append(lastName);

    // Action
    bool isName = player->setPlayerName(firstName, lastName);

    // Expected
    EXPECT_TRUE(isName);
    EXPECT_EQ(player->getPlayerName(), name);
}

/*
@NAME : SWUT_setPlayerName_0002
@DES : Test Player first name is set properly
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set player first name, last name
@TSA : call setPlayerName function
@TSE : check first name of player
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(PlayerTest, SWUT_setPlayerName_0002)
{
    printf("*********** SWUT_setPlayerName_0002 \n");
    // Precondition
    std::string firstName = "Joshua";
    std::string lastName = "Kimmich";

    // Action
    bool isName = player->setPlayerName(firstName, lastName);

    // Expected
    EXPECT_TRUE(isName);
    EXPECT_EQ(player->getPlayerFirstName(), firstName);
}

/*
@NAME : SWUT_setPlayerName_0003
@DES : Test Player last name is set properly
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set player first name, last name
@TSA : call setPlayerName function
@TSE : check last name of player
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(PlayerTest, SWUT_setPlayerName_0003)
{
    printf("*********** SWUT_setPlayerName_0003 \n");
    // Precondition
    std::string firstName = "Joshua";
    std::string lastName = "Kimmich";

    // Action
    bool isName = player->setPlayerName(firstName, lastName);

    // Expected
    EXPECT_TRUE(isName);
    EXPECT_EQ(player->getPlayerLastName(), lastName);
}

/*
@NAME : SWUT_checkAllZero_0001
@DES : Test all roll scored zero
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set player frameindex, scoreindex, score[]
@TSA : call calculateTotalScore function
@TSE : check total score based on input
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(PlayerTest, SWUT_checkAllZero_0001)
{
    printf("*********** SWUT_checkAllZero_0001 \n");
    // Precondition
    std::vector<int> score{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int rollNumer{1};
    int frameIndex{0};
    int roll1Score{0}, roll2Score{0}, roll3Score{0};
    bool success{false};
    uint16_t scoreIndex{0};
    uint16_t totalScore{0};

    // Action
    ASSERT_TRUE(player->createFrames());

    for (; frameIndex < MAX_FRAME_COUNT - 1; frameIndex++)
    {
        roll1Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll1Score);
        EXPECT_TRUE(success);
        if (roll1Score < MAX_ROLL_SCORE)
        {
            scoreIndex++;
            rollNumer++;
            roll2Score = score[scoreIndex];
            success = player->setRollScore(rollNumer, frameIndex, roll2Score);
            EXPECT_TRUE(success);
        }
        scoreIndex++;
        rollNumer = 1;
    }

    if (frameIndex == (MAX_FRAME_COUNT - 1))
    {
        roll1Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll1Score);
        EXPECT_TRUE(success);
        scoreIndex++;
        rollNumer++;
        roll2Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll2Score);
        EXPECT_TRUE(success);

        if (roll1Score == MAX_ROLL_SCORE || (roll2Score + roll1Score) == MAX_ROLL_SCORE)
        {
            scoreIndex++;
            rollNumer++;
            roll3Score = score[scoreIndex];
            success = player->setRollScore(rollNumer, frameIndex, roll3Score);
            EXPECT_TRUE(success);
        }
    }
    totalScore = player->calculateTotalScore();

    // Expected
    EXPECT_EQ(totalScore, 0);
}

/*
@NAME : SWUT_checkAllStrike_0001
@DES : Test all roll scored strike
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set player frameindex, scoreindex, score[]
@TSA : call calculateTotalScore function
@TSE : check total score based on input
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(PlayerTest, SWUT_checkAllStrike_0001)
{
    printf("*********** SWUT_checkAllStrike_0001 \n");
    // Precondition
    std::vector<int> score{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int rollNumer{1};
    int frameIndex{0};
    int roll1Score{0}, roll2Score{0}, roll3Score{0};
    bool success{false};
    uint16_t scoreIndex{0};
    uint16_t totalScore{0};

    // Action
    ASSERT_TRUE(player->createFrames());

    for (; frameIndex < MAX_FRAME_COUNT - 1; frameIndex++)
    {
        roll1Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll1Score);
        EXPECT_TRUE(success);
        if (roll1Score < MAX_ROLL_SCORE)
        {
            scoreIndex++;
            rollNumer++;
            roll2Score = score[scoreIndex];
            success = player->setRollScore(rollNumer, frameIndex, roll2Score);
            EXPECT_TRUE(success);
        }
        scoreIndex++;
        rollNumer = 1;
    }

    if (frameIndex == (MAX_FRAME_COUNT - 1))
    {
        roll1Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll1Score);
        EXPECT_TRUE(success);
        scoreIndex++;
        rollNumer++;
        roll2Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll2Score);
        EXPECT_TRUE(success);

        if (roll1Score == MAX_ROLL_SCORE || (roll2Score + roll1Score) == MAX_ROLL_SCORE)
        {
            scoreIndex++;
            rollNumer++;
            roll3Score = score[scoreIndex];
            success = player->setRollScore(rollNumer, frameIndex, roll3Score);
            EXPECT_TRUE(success);
        }
    }
    totalScore = player->calculateTotalScore();

    // Expected
    EXPECT_EQ(totalScore, MAX_TOTAL_SCORE);
}

/*
@NAME : SWUT_calculateTotalScore_0001
@DES : Test roll score with different values
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set player frameindex, scoreindex, score[]
@TSA : call calculateTotalScore function
@TSE : check total score based on input
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(PlayerTest, SWUT_calculateTotalScore_0001)
{
    printf("*********** SWUT_calculateTotalScore_0001 \n");
    // Precondition
    std::vector<int> score{1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6};
    int rollNumer{1};
    int frameIndex{0};
    int roll1Score{0}, roll2Score{0}, roll3Score{0};
    bool success{false};
    uint16_t scoreIndex{0};
    uint16_t totalScore{0};

    // Action
    ASSERT_TRUE(player->createFrames());

    for (; frameIndex < MAX_FRAME_COUNT - 1; frameIndex++)
    {
        roll1Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll1Score);
        EXPECT_TRUE(success);
        if (roll1Score < MAX_ROLL_SCORE)
        {
            scoreIndex++;
            rollNumer++;
            roll2Score = score[scoreIndex];
            success = player->setRollScore(rollNumer, frameIndex, roll2Score);
            EXPECT_TRUE(success);
        }
        scoreIndex++;
        rollNumer = 1;
    }

    if (frameIndex == (MAX_FRAME_COUNT - 1))
    {
        roll1Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll1Score);
        EXPECT_TRUE(success);
        scoreIndex++;
        rollNumer++;
        roll2Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll2Score);
        EXPECT_TRUE(success);

        if (roll1Score == MAX_ROLL_SCORE || (roll2Score + roll1Score) == MAX_ROLL_SCORE)
        {
            scoreIndex++;
            rollNumer++;
            roll3Score = score[scoreIndex];
            success = player->setRollScore(rollNumer, frameIndex, roll3Score);
            EXPECT_TRUE(success);
        }
    }
    totalScore = player->calculateTotalScore();

    // Expected
    EXPECT_EQ(totalScore, 133);
}

/*
@NAME : SWUT_calculateTotalScore_0002
@DES : Test roll score with different values
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set player frameindex, scoreindex, score[]
@TSA : call calculateTotalScore function
@TSE : check total score based on input
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(PlayerTest, SWUT_calculateTotalScore_0002)
{
    printf("*********** SWUT_calculateTotalScore_0002 \n");
    // Precondition
    std::vector<int> score{8, 1, 6, 4, 8, 2, 4, 0, 10, 6, 3, 8, 2, 7, 2, 2, 0, 5, 4};
    int rollNumer{1};
    int frameIndex{0};
    int roll1Score{0}, roll2Score{0}, roll3Score{0};
    bool success{false};
    uint16_t scoreIndex{0};
    uint16_t totalScore{0};

    // Action
    ASSERT_TRUE(player->createFrames());

    for (; frameIndex < MAX_FRAME_COUNT - 1; frameIndex++)
    {
        roll1Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll1Score);
        EXPECT_TRUE(success);
        if (roll1Score < MAX_ROLL_SCORE)
        {
            scoreIndex++;
            rollNumer++;
            roll2Score = score[scoreIndex];
            success = player->setRollScore(rollNumer, frameIndex, roll2Score);
            EXPECT_TRUE(success);
        }
        scoreIndex++;
        rollNumer = 1;
    }

    if (frameIndex == (MAX_FRAME_COUNT - 1))
    {
        roll1Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll1Score);
        EXPECT_TRUE(success);
        scoreIndex++;
        rollNumer++;
        roll2Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll2Score);
        EXPECT_TRUE(success);

        if (roll1Score == MAX_ROLL_SCORE || (roll2Score + roll1Score) == MAX_ROLL_SCORE)
        {
            scoreIndex++;
            rollNumer++;
            roll3Score = score[scoreIndex];
            success = player->setRollScore(rollNumer, frameIndex, roll3Score);
            EXPECT_TRUE(success);
        }
    }
    totalScore = player->calculateTotalScore();

    // Expected
    EXPECT_EQ(totalScore, 110);
}

/*
@NAME : SWUT_calculateTotalScore_0003
@DES : Test roll score with different values
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set player frameindex, scoreindex, score[]
@TSA : call calculateTotalScore function
@TSE : check total score based on input
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(PlayerTest, SWUT_calculateTotalScore_0003)
{
    printf("*********** SWUT_calculateTotalScore_0003 \n");
    // Precondition
    std::vector<int> score{10, 10, 7, 3, 8, 1, 10, 4, 2, 5, 4, 7, 3, 9, 0, 10, 10, 7};
    int rollNumer{1};
    int frameIndex{0};
    int roll1Score{0}, roll2Score{0}, roll3Score{0};
    bool success{false};
    uint16_t scoreIndex{0};
    uint16_t totalScore{0};

    // Action
    ASSERT_TRUE(player->createFrames());

    for (; frameIndex < MAX_FRAME_COUNT - 1; frameIndex++)
    {
        roll1Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll1Score);
        EXPECT_TRUE(success);
        if (roll1Score < MAX_ROLL_SCORE)
        {
            scoreIndex++;
            rollNumer++;
            roll2Score = score[scoreIndex];
            success = player->setRollScore(rollNumer, frameIndex, roll2Score);
            EXPECT_TRUE(success);
        }
        scoreIndex++;
        rollNumer = 1;
    }

    if (frameIndex == (MAX_FRAME_COUNT - 1))
    {
        roll1Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll1Score);
        EXPECT_TRUE(success);
        scoreIndex++;
        rollNumer++;
        roll2Score = score[scoreIndex];
        success = player->setRollScore(rollNumer, frameIndex, roll2Score);
        EXPECT_TRUE(success);

        if (roll1Score == MAX_ROLL_SCORE || (roll2Score + roll1Score) == MAX_ROLL_SCORE)
        {
            scoreIndex++;
            rollNumer++;
            roll3Score = score[scoreIndex];
            success = player->setRollScore(rollNumer, frameIndex, roll3Score);
            EXPECT_TRUE(success);
        }
    }
    totalScore = player->calculateTotalScore();

    // Expected
    EXPECT_EQ(totalScore, 160);
}