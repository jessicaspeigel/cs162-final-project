/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_final_project
** Date: 03/19/2018
** Description: Declaration for Classroom class.
****************************************************/

#ifndef CS162_FINAL_PROJECT_CLASSROOM_HPP
#define CS162_FINAL_PROJECT_CLASSROOM_HPP

#include "Space.hpp"
#include <iostream>
#include <vector>
#include <cmath>

// struct for random events
struct RandomEvent {
    std::string eventName;
    double gradeImpact;
    int probability;
    // Define a constructor
    RandomEvent(std::string n, double i, int p) {
        eventName = n;
        gradeImpact = i;
        probability = p;
    }
};

class Classroom : public Space {

private:
    std::vector<RandomEvent> randomEvents;
    bool appleFlag;
    bool extraCreditFlag;

public:
    Classroom(Player* player);
    ~Classroom();
    void enter();
    void generateInventoryItems();
    void useApple();
    void useExtraCredit();
    void turnInHomework();

};

#endif //CS162_FINAL_PROJECT_CLASSROOM_HPP
