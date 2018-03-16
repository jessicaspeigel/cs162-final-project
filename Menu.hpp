/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: menu class header
****************************************************/
#ifndef CS162_FANTASY_COMBAT_GAME_MENU_HPP
#define CS162_FANTASY_COMBAT_GAME_MENU_HPP


#include <iostream>
#include <string>
#include <vector>

class Menu {

private:
    std::vector<std::string> menuItems;
    std::string promptText;

public:
    Menu(std::vector<std::string> menuItems);
    Menu(std::string promptText, std::vector<std::string> menuItems);
    int showMenu();
    void setPromptText(std::string text);
    std::string getPromptText();
    void setMenuItems(std::vector<std::string> menuItems);
};


#endif //CS162_FANTASY_COMBAT_GAME_MENU_HPP
