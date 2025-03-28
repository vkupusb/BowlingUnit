// BowlingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "BowlingUnit.h"
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    /*std::cout << "Bowling Game!!!\n";
    BowlingGame::Unit::BowlingUnit unit;
    std::string player1_firstName{"Albert"}, player1_lastName{"Einstein"};
    std::string player2_firstName{"Robert"}, player2_lastName{"Bosch"};
    if (unit.addPlayer(player1_firstName,player1_lastName))// first name, second name of the player
    {
        std::cout<<"\nPlayer "<<player1_firstName<<" "<<player1_lastName<<" added successfully\n";
    }

    if (unit.addPlayer(player2_firstName,player2_lastName))
    {
        std::cout<<"\nPlayer "<<player2_firstName<<" "<<player2_lastName<<" added successfully\n";
    }

    unit.startGame();
    if (unit.removePlayer(player2_firstName,player2_lastName)){
        std::cout<<"\nPlayer "<<player2_firstName<<" "<<player2_lastName<<" removed successfully\n";
    }*/

    return RUN_ALL_TESTS();
}
