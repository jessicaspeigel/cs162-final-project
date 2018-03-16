/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: input validation header file
****************************************************/
#ifndef CS162_FANTASY_COMBAT_GAME_INPUTVALIDATION_HPP
#define CS162_FANTASY_COMBAT_GAME_INPUTVALIDATION_HPP

#include <iostream>
#include <string>

int getInteger(std::string promptText);

int getIntegerWithMin(std::string promptText, int minVal);

int getIntegerWithMinMax(std::string promptText, int minVal, int maxVal);

std::string getString(std::string promptText, int minLength = 1);

#endif //CS162_FANTASY_COMBAT_GAME_INPUTVALIDATION_HPP
