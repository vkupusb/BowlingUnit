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
    auto itr = m_players.erase(std::remove_if(m_players.begin(), m_players.end(), [&](auto player) -> bool
                                              {
        if ((player->getPlayerFirstName() == firstName) && (player->getPlayerLastName() == lastName)){
            return true;
        }
        else
        {
            return false;
        } }),
                               m_players.end());

    if (itr == m_players.end())
    {
        return true;
    }

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
            std::cout<<"\n"<<player->getPlayerName()<<" starts game...\n";
            player->createFrames();
            player->getRollScore();
            if (player->calculateTotalScore() == MAX_TOTAL_SCORE)
            {
                std::cout<<"\nPrefect score !!!\n";
            }
            else
            {
                std::cout<<"\nGood score, keep it up !!!\n";
            }
            std::cout<<"\n"<<player->getPlayerName()<<" finished game. \n"; });
}
