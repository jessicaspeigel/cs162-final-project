/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/17/2018
** Description: Gym implementation file
****************************************************/
#include "Gym.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/****************************************************
** CONSTRUCTORS
****************************************************/

Gym::Gym(Player* player) : Space("Gym", player) {
    // Create the gym menu
    vector<string> spaceMenuItems;
    spaceMenuItems.push_back("Fit in a workout between classes?");
    spaceMenuItems.push_back(exitString);
    string promptText = "You entered the " + this->getName() + ". What would you like to do?";
    spaceMenu->setPromptText(promptText);
    spaceMenu->setMenuItems(spaceMenuItems);
}

/****************************************************
** DESTRUCTORS
****************************************************/

Gym::~Gym() {

}

/****************************************************
** Description: the player enters the space
****************************************************/

void Gym::enter() {
    Player* p = this->getPlayer();
    // Show the gym menu
    int menuChoice = spaceMenu->showMenu();
    if (menuChoice == 1) {
        cout << "You had a great workout, you earned 10 mental health points!" << endl;
        p->adjustPoints(10);
    }
}

/****************************************************
** Description: Generate random inventory items
****************************************************/

void Gym::generateInventoryItems() {
    // The gym doesn't generate any inventory items
}
