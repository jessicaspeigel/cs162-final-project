/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/18/2018
** Description: 
****************************************************/
#ifndef CS162_FINAL_PROJECT_LIBRARY_HPP
#define CS162_FINAL_PROJECT_LIBRARY_HPP

#include "Space.hpp"

class Library : public Space {
private:

public:
    Library(Player* player);
    ~Library();
    void enter();
    void generateInventoryItems();
};

#endif //CS162_FINAL_PROJECT_LIBRARY_HPP
