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

enum InventoryItem {APPLE, EXTRA_CREDIT, HOMEWORK, DIPLOMA};

class Player {
    private:
        int points;
        int credits;
        std::vector<InventoryItem> inventory;

    public:
        Player(int points = 100, int credits = 0);
        virtual ~Player();

};


#endif //CS162_FINAL_PROJECT_PLAYER_HPP
