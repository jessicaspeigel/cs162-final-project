/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/15/2018
** Description: Header for Player class
****************************************************/
#ifndef CS162_FINAL_PROJECT_PLAYER_HPP
#define CS162_FINAL_PROJECT_PLAYER_HPP

#include <iostream>
#include <vector>
#include "Inventory.hpp"

class Player {
    private:
        int points;
        int credits;
        Inventory* inventory;


    public:
        Player(int points = 100, int credits = 0);
        virtual ~Player();
        int getPoints();
        void adjustPoints(int offset);
        int getCredits();
        void adjustCredits(int offset);
        Inventory* getInventory();
};


#endif //CS162_FINAL_PROJECT_PLAYER_HPP
