/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/20/2018
** Description: Implementation for Game class
****************************************************/

#include "Game.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;

/****************************************************
** CONSTRUCTORS
****************************************************/

Game::Game() {
    // Create the player
    student = new Player;
    // Generate the board
    createBoard();
    // Create the game menu
    vector<string> gameMenuItems;
    gameMenuItems.push_back("See the campus map");
    gameMenuItems.push_back("See inventory");
    gameMenuItems.push_back("See degree progress");
    gameMenuItems.push_back("Move spaces");
    gameMenuItems.push_back("Drop out");
    gameMenu = new Menu("What would you like to do?", gameMenuItems);
    // Create a bare bones space menu
    vector<string> spaceMenuItems;
    spaceMenuItems.push_back("Return to main menu");
    spaceMenu = new Menu("Where would you like to go?", spaceMenuItems);
    // Start the game
    startGame();
}

/****************************************************
** DESTRUCTORS
****************************************************/

Game::~Game() {
    // Kill the student
    delete student;
    // Delete the menus
    delete gameMenu;
    delete spaceMenu;
    // Destroy the board
    destroyBoard();
}

/****************************************************
** Description: starts the game
****************************************************/

void Game::startGame() {
    // Set the player's current location
    currentLocation = quad;
    // Show the menu
    int menuChoice = 0;
    // Bools to hold win and lose conditions
    bool win = false;
    bool lose = false;
    // Start the program
    do {
        // Show the menu and get a choice
        menuChoice = gameMenu->showMenu();
        if (menuChoice != 5) {
            switch (menuChoice) {
                case 1 : // Show campus map
                    printBoard();
                    break;
                case 2 : // Show inventory
                    student->getInventory()->printInventory();
                    break;
                case 3 : // Show degree progress
                    showProgress();
                    break;
                case 4 : // Move spaces
                    takeTurn();
                    break;
            }
        }
        // Update stats
        InventoryItem* diploma = student->getInventory()->findItemByValue("diploma");
        win = diploma->getCount() > 0;
        lose = student->getPoints() <= 0;
    } while (menuChoice != 5 && !(win || lose)); // Choosing 5 equals quit
    endGame();
}

/****************************************************
** Description: Takes a turn by moving spaces
****************************************************/

void Game::takeTurn() {
    // Construct the menu for the space
    vector<string> spaceMenuItems;
    // Create a vector with pointers at the same indices
    vector<Space*> spaces;
    // Get the top pointer
    if (currentLocation->getTop() != nullptr) {
        spaceMenuItems.push_back(currentLocation->getTop()->getName());
        spaces.push_back(currentLocation->getTop());
    }
    // Get the right pointer
    if (currentLocation->getRight() != nullptr) {
        spaceMenuItems.push_back(currentLocation->getRight()->getName());
        spaces.push_back(currentLocation->getRight());
    }
    // Get the bottom pointer
    if (currentLocation->getBottom() != nullptr) {
        spaceMenuItems.push_back(currentLocation->getBottom()->getName());
        spaces.push_back(currentLocation->getBottom());
    }
    // Get the left pointer
    if (currentLocation->getLeft() != nullptr) {
        spaceMenuItems.push_back(currentLocation->getLeft()->getName());
        spaces.push_back(currentLocation->getLeft());
    }
    spaceMenuItems.push_back("Return to main menu");
    // Set the menu items
    spaceMenu->setMenuItems(spaceMenuItems);
    // Show the menu and get a choice
    int menuChoice = spaceMenu->showMenu();
    if (menuChoice != spaceMenuItems.size()) {
        // Remove 5 mental health points for taking a move
        student->adjustPoints(-5);
        // Move spaces (menu is 1 based, I know this is dumb)
        spaces.at(menuChoice - 1)->enter();
        // Update the location
        currentLocation = spaces.at(menuChoice - 1);
    }
}

/****************************************************
** Description: Ends the game
****************************************************/

void Game::endGame() {
    InventoryItem* diploma = student->getInventory()->findItemByValue("diploma");
    if (diploma->getCount() > 0) {
        AsciiArt winArt("WinArt.txt");
    } else if (student->getPoints() <= 0) {
        cout << "Game over" << endl;
    }
}

/****************************************************
** Description: Prints the user's progress
****************************************************/

void Game::showProgress() {
    cout << "Your degree progress:" << endl;
    cout << "Mental health points: " << student->getPoints() << endl;
    cout << "Credits: " << student->getCredits() << endl << endl;
}

/****************************************************
** Description: Private function to build the game
** board of linked spaces.
****************************************************/

void Game::createBoard() {
    // Create the spaces
    gym = new Gym(student);
    advisorsOffice = new AdvisorsOffice(student);
    advisorsOffice->setName("Advisor's Office");
    bar = new Bar(student);
    computerLab = new ComputerLab(student);
    quad = new Quad(student);
    library = new Library(student);
    taOffice = new TAOffice(student);
    classroom = new Classroom(student);
    cafe = new Cafe(student);
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
    // Link the cafe
    cafe->setTop(library);
    cafe->setLeft(classroom);
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
    // Constant for column width
    const int COL_WIDTH = 21;
    const char EDGE_CHAR = '|';
    // Start with the gym in the top right
    Space* start = gym;
    Space* nextCol;
    Space* nextRow = start;
    // Print the first separator line
    cout << "*--------------------------------------------------------------------*" << endl;
    while (nextRow != nullptr) {
        // Loop through the rows
        nextCol = nextRow;
        while (nextCol != nullptr) {
            // Loop through the columns
            // Print the name of the room
            string outputName;
            if (currentLocation == nextCol) {
                // We'll add an asterisk to mark the player's current location
                outputName = nextCol->getName() + " (*)";
            } else {
                outputName = nextCol->getName();
            }
            cout << EDGE_CHAR << left << " " << setw(COL_WIDTH) << outputName;
            // Print a spacer line
            // Set the next column
            nextCol = nextCol->getRight();
        }
        // Print the edge char for the last column and print a separator line
        cout << EDGE_CHAR << endl;
        cout << "*--------------------------------------------------------------------*" << endl;
        // Set the next row
        nextRow = nextRow->getBottom();
    }
    cout << "(*) You are in the " << currentLocation->getName() << endl;
    cout << endl;
}

/*

*-----------------------------------------------------------------*
|                     |                     |                     |
| Gym                 | Advisor's Office    | Bar                 |
| (you are here)      |                     |                     |
*-----------------------------------------------------------------*
|                     |                     |                     |
| Computer Lab        | Quad                | Library             |
|                     |                     |                     |
*-----------------------------------------------------------------*
|                     |                     |                     |
| TA's Office         | Classroom           | Cafe                |
|                     |                     |                     |
*-----------------------------------------------------------------*

 */