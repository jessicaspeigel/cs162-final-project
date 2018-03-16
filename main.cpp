/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/20/2018
** Description: CS Degree Simulator main
****************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Menu.hpp"
#include "InputValidation.hpp"
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {
    // Seed the random number generator
    srand(time(NULL));
    // Say hi to the user
    cout << "Welcome to the Computer Science Degree Simulator. Earn your degree the hard way!" << endl << endl;
    cout << "Your goal is to get your degree without destroying your mental health." << endl << endl;
    cout << "Accomplish your goal by doing homework in the computer lab and turning it in in the classroom for credits." << endl;
    cout << "Once you have 60 credits, you can apply for graduation in your advisor's office, but watch out for hazards!" << endl;
    cout << "You begin the game with 100 mental health points which will deplete as you move through the spaces on campus and take certain actions." << endl << endl;
    cout << "Good luck!" << endl << endl;
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