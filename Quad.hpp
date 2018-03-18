/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/15/2018
** Description: Quad header file
****************************************************/
#ifndef CS162_FINAL_PROJECT_QUAD_HPP
#define CS162_FINAL_PROJECT_QUAD_HPP

#include "Space.hpp"

class Quad: public Space {
private:

public:
    Quad(Player* player);
    ~Quad();
    void enter();
};


#endif //CS162_FINAL_PROJECT_QUAD_HPP
