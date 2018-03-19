/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/18/2018
** Description: 
****************************************************/
#ifndef CS162_FINAL_PROJECT_COMPUTERLAB_HPP
#define CS162_FINAL_PROJECT_COMPUTERLAB_HPP

#include "Space.hpp"

class ComputerLab : public Space {
private:

public:
    ComputerLab(Player* player);
    ~ComputerLab();
    void enter();
    void generateInventoryItems();
};

#endif //CS162_FINAL_PROJECT_COMPUTERLAB_HPP
