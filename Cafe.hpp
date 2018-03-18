/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/17/2018
** Description: Cafe header file
****************************************************/
#ifndef CS162_FINAL_PROJECT_CAFE_HPP
#define CS162_FINAL_PROJECT_CAFE_HPP

#include "Space.hpp"

class Cafe : public Space {
private:

public:
    Cafe(Player *player = nullptr);
    ~Cafe();
    void enter();
};

#endif //CS162_FINAL_PROJECT_CAFE_HPP
