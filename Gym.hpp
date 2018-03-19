/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/17/2018
** Description: Gym header file
****************************************************/
#ifndef CS162_FINAL_PROJECT_GYM_HPP
#define CS162_FINAL_PROJECT_GYM_HPP

#include "Space.hpp"

class Gym : public Space {
private:

public:
    Gym(Player* player);
    ~Gym();
    void enter();
    void generateInventoryItems();
};


#endif //CS162_FINAL_PROJECT_GYM_HPP
