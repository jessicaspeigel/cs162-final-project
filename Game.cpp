/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/20/2018
** Description: Implementation for Game class
****************************************************/

#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/****************************************************
** CONSTRUCTORS
****************************************************/

Game::Game() {
    // Generate the board
    createBoard();
    // Start the game
    startGame();
}

/****************************************************
** DESTRUCTORS
****************************************************/

Game::~Game() {
    destroyBoard();
}

/****************************************************
** Description: starts the game
****************************************************/

void Game::startGame() {
    printBoard();
}

/****************************************************
** Description: ends the game
****************************************************/

void Game::endGame() {
    // Print a separator

}

/****************************************************
** Description: Private function to build the game
** board of linked spaces.
****************************************************/

void Game::createBoard() {
    // Create the spaces
    gym = new Quad;
    gym->setName("Gym");
    advisorsOffice = new Quad;
    advisorsOffice->setName("Advisor's Office");
    bar = new Quad;
    bar->setName("Bar");
    computerLab = new Quad;
    computerLab->setName("Computer Lab");
    quad = new Quad;
    library = new Quad;
    library->setName("Library");
    taOffice = new Quad;
    taOffice->setName("TA's Office");
    classroom = new Quad;
    classroom->setName("classroom");
    cafe = new Quad;
    cafe->setName("Cafe");
    // Link the gym
    gym->setRight(advisorsOffice);
    gym->setBottom(computerLab);
    // Link the advisor's office
    advisorsOffice->setLeft(gym);
    advisorsOffice->setRight(bar);
    advisorsOffice->setBottom(quad);
    // Link the bar
    bar->setLeft(advisorsOffice);
    bar->setBottom(library);
    // Link the computer lab
    computerLab->setTop(gym);
    computerLab->setRight(quad);
    computerLab->setBottom(taOffice);
    // Link the quad
    quad->setTop(advisorsOffice);
    quad->setRight(library);
    quad->setBottom(classroom);
    quad->setLeft(computerLab);
    // Link the library
    library->setTop(bar);
    library->setBottom(cafe);
    library->setLeft(quad);
    // Link the TA's office
    taOffice->setTop(computerLab);
    taOffice->setRight(classroom);
    // Link the classroom
    classroom->setTop(quad);
    classroom->setRight(cafe);
    classroom->setLeft(taOffice);
}

/****************************************************
** Description: Private function to clean up the
** game board of linked spaces.
****************************************************/

void Game::destroyBoard() {
    delete gym;
    delete advisorsOffice;
    delete bar;
    delete computerLab;
    delete quad;
    delete library;
    delete taOffice;
    delete classroom;
    delete cafe;
}

/****************************************************
** Description: Prints the 3x3 grid of spaces.
****************************************************/

void Game::printBoard() {
    // Start with the gym in the top right
    Space* s = gym;
    Space* nextCol = s->getRight();
    Space* nextRow = s->getBottom();
    do {
        cout << s->getName() << endl;
        s = nextCol;
        if (s == nullptr) {
            // Move to the next row
            s = nextRow;
            nextCol = s->getRight();
            nextRow = s->getBottom();
        } else {
            nextCol = s->getRight();
        }
    } while (s != nullptr);
}
