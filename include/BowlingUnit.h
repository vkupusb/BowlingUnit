#pragma once

#include "Player.h"

namespace BowlingGame::Unit {

    class BowlingUnit{
        public:
        BowlingUnit()=default;
        ~BowlingUnit()=default;

        /*
		\brief	add player name in the bowling unit
		\author	Vishvanathan K
		\param	player first and last name as string
		\return None
		*/
        void addPlayer(std::string_view first_name,std::string_view last_name);

         /*
		\brief	remove player name from the bowling unit
		\author	Vishvanathan K
		\param	player first and last name as string
		\return None
		*/
        void removePlayer(std::string_view first_name,std::string_view last_name);

         /*
		\brief	start the bowling game
		\author	Vishvanathan K
		\param	player first and last name as string
		\return None
		*/
        void startGame();

        private:
        std::vector<std::shared_ptr<BowlingGame::Players::Player>> players; /*!< third roll value */
        
        
    };

}

