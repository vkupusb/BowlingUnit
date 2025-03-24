#include "BowlingUnit.h"
#include <algorithm>

void BowlingGame::Unit::BowlingUnit::addPlayer(std::string_view first_name,std::string_view last_name)
{
    auto player{ std::make_shared<BowlingGame::Players::Player>() };
    player->setPlayerName(first_name, last_name);
    players.push_back(std::move(player));

}

void BowlingGame::Unit::BowlingUnit::removePlayer(std::string_view first_name,std::string_view last_name)
{
   
}

void BowlingGame::Unit::BowlingUnit::startGame()
{
    std::for_each(players.begin(),players.end(),[](auto player){
        player->createFrames();
        player->getRollScore();
        player->calculateTotalScore();
    });
}
