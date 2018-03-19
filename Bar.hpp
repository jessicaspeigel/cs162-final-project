/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/18/2018
** Description: 
****************************************************/
#ifndef CS162_FINAL_PROJECT_BAR_HPP
#define CS162_FINAL_PROJECT_BAR_HPP

#include "Space.hpp"

class Bar : public Space {
private:

public:
    Bar(Player* player);
    ~Bar();
    void enter();
    void generateInventoryItems();
};

#endif //CS162_FINAL_PROJECT_BAR_HPP
