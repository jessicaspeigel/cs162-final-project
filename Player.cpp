/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/15/2018
** Description: 
****************************************************/
#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

/****************************************************
** CONSTRUCTORS
****************************************************/

Player::Player(int points, int credits) {
    this->points = points;
    this->credits = credits;
}

/****************************************************
** DESTRUCTORS
****************************************************/

Player::~Player() {

}

/****************************************************
** GETTERS / SETTERS
****************************************************/

int Player::getPoints() {
    return points;
}

int Player::getCredits() {
    return credits;
}

/****************************************************
** Description: Adjusts points by either a positive
** or negative amount.
****************************************************/

void Player::adjustPoints(int offset) {
    this->points += offset;
}

/****************************************************
** Description: Adjusts credits by either a positive
** or negative amount.
****************************************************/

void Player::adjustCredits(int offset) {
    this->credits += offset;
}