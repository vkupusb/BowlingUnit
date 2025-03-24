#pragma once

#include "Player.h"

namespace BowlingGame::Unit {

    class BowlingUnit{
        public:
        BowlingUnit()=default;
        ~BowlingUnit()=default;
        void addPlayer(std::string_view first_name,std::string_view last_name);
        void removePlayer(std::string_view first_name,std::string_view last_name);
        void startGame();
        private:
        std::vector<std::shared_ptr<BowlingGame::Players::Player>> players;
        
        
    };

}

