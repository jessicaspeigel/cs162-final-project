/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/20/2018
** Description: CS Degree Simulator main
****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Menu.hpp"
#include "InputValidation.hpp"
#include "Game.hpp"
#include "AsciiArt.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

int main() {
    // Seed the random number generator
    srand(time(NULL));
    // Output the intro art and instructions
    AsciiArt introArt("IntroArt.txt");
    // Get the main menu ready
    vector<string> mainMenuItems = {"Play", "Exit"};
    Menu mainMenu(mainMenuItems);
    int menuChoice = 1;
    // Start the program
    do {
        // Show the menu and get a choice
        menuChoice = mainMenu.showMenu();
        if (menuChoice != 2) {
            // Start a new game
            Game degreeSimulator;

            // Update the menu text once the game has run once
            mainMenuItems[0] = "Play again";
            mainMenuItems[1] = "Exit";
            mainMenu.setMenuItems(mainMenuItems);
        }
    } while (menuChoice != 2); // Choosing 2 equals quit

    return 0;
}