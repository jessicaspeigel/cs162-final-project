/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_final_project
** Date: 03/19/2018
** Description: Declaration for AdvisorsOffice class.
****************************************************/

#ifndef CS162_FINAL_PROJECT_ADVISORSOFFICE_HPP
#define CS162_FINAL_PROJECT_ADVISORSOFFICE_HPP

#include "Space.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include "AsciiArt.hpp"

class AdvisorsOffice : public Space {

private:
    // struct for random events
    struct RandomEvent {
        std::string eventName;
        int creditImpact;
        int pointImpact;
        int probability;
        // Define a constructor
        RandomEvent(std::string n, int credits, int points, int p) {
            eventName = n;
            creditImpact = credits;
            pointImpact = points;
            probability = p;
        }
    };
    std::vector<RandomEvent> randomEvents;
    bool appleFlag;
    void winGame();

public:
    AdvisorsOffice(Player* player);
    ~AdvisorsOffice();
    void enter();
    void generateInventoryItems();
    void useApple();
    void applyForGraduation();

};

#endif //CS162_FINAL_PROJECT_ADVISORSOFFICE_HPP
