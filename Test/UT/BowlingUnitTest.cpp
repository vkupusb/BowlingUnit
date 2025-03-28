#include <gtest/gtest.h>
#include "../../include/BowlingUnit.h"

using namespace BowlingGame::Unit;

class BowlingUnitTest : public ::testing::Test
{
public:
    BowlingUnit unit;

protected:
    virtual void SetUp() override
    {
    }

    virtual void TearDown() override
    {
    }
};

/*
@NAME : SWUT_addPlayer_0001
@DES : Test add player in the bowling unit
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set player name
@TSA : call addPlayer function
@TSE : check player added succussfully
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(BowlingUnitTest, SWUT_addPlayer_0001)
{
    printf("*********** SWUT_addPlayer_0001 \n");
    // Precondition
    std::string player1_firstName{"Albert"}, player1_lastName{"Einstein"};

    // Action
    bool success = unit.addPlayer(player1_firstName, player1_lastName);

    // Expected
    EXPECT_TRUE(success);
}

/*
@NAME : SWUT_removePlayer_0001
@DES : Test remove player from the bowling unit
@TDM : Requirement - based test
@PRR : P1
@VRF : [ISSUE:<SDD_ID>]
@PRE : set player name
@TSA : call removePlayer function
@TSE : check player removed succussfully
@ASN : Vishvanathan K
@RVE : Vishvanathan K
*/
TEST_F(BowlingUnitTest, SWUT_removePlayer_0001)
{
    printf("*********** SWUT_removePlayer_0001 \n");
    // Precondition
    std::string player1_firstName{"Albert"}, player1_lastName{"Einstein"};
    std::string player2_firstName{"Robert"}, player2_lastName{"Bosch"};
    bool success = unit.addPlayer(player1_firstName, player1_lastName);
    EXPECT_TRUE(success);
    success = unit.addPlayer(player2_firstName, player2_lastName);
    EXPECT_TRUE(success);

    // Action
    success = unit.removePlayer(player2_firstName, player2_lastName);

    // Expected
    EXPECT_TRUE(success);
}