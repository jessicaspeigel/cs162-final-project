/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/20/2018
** Description: Header for Game class
****************************************************/
#ifndef CS162_FINAL_PROJECT_GAME
#define CS162_FINAL_PROJECT_GAME

#include <iostream>
#include <vector>
#include "Menu.hpp"
#include "InputValidation.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include "Quad.hpp"

class Game {
    private:
        Space* gym;
        Space* advisorsOffice;
        Space* bar;
        Space* computerLab;
        Space* quad;
        Space* library;
        Space* taOffice;
        Space* classroom;
        Space* cafe;
        Player* student;
        void createBoard();
        void destroyBoard();
        void startGame();
        void endGame();
        void printBoard();

    public:
        Game();
        ~Game();
};

#endif //CS162_FINAL_PROJECT_GAME