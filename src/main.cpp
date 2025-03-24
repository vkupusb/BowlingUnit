// BowlingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "BowlingUnit.h"

int main()
{
    std::cout << "Bowling Game!!!\n";
    BowlingGame::Unit::BowlingUnit unit;
    unit.addPlayer("xzy","xyz"); // first name, second name of the player
    unit.startGame(); 
}


