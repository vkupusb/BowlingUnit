#include "BowlingUnit.h"
#include <algorithm>

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Unit::BowlingUnit::addPlayer(std::string_view firstName, std::string_view lastName)
{
    auto player{std::make_shared<BowlingGame::Players::Player>()};
    player->setPlayerName(firstName, lastName);
    m_players.push_back(std::move(player));

    return true;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
bool BowlingGame::Unit::BowlingUnit::removePlayer(std::string_view firstName, std::string_view lastName)
{
    return false;
}

/*
BowlingGame~COD~Trace
@VRF_SRS: NA
@VRF_SDD: NA
*/
void BowlingGame::Unit::BowlingUnit::startGame()
{
    std::for_each(m_players.begin(), m_players.end(), [](auto player)
                  {
        player->createFrames();
        player->getRollScore();
        player->calculateTotalScore(); });
}
