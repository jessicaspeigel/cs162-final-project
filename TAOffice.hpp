/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/18/2018
** Description: 
****************************************************/
#ifndef CS162_FINAL_PROJECT_TAOFFICE_HPP
#define CS162_FINAL_PROJECT_TAOFFICE_HPP

#include "Space.hpp"

class TAOffice : public Space {
private:

public:
    TAOffice(Player* player);
    ~TAOffice();
    void enter();
    void generateInventoryItems();
};

#endif //CS162_FINAL_PROJECT_TAOFFICE_HPP
