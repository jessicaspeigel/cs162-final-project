/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/17/2018
** Description: Cafe implementation file
****************************************************/
#include "Cafe.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/****************************************************
** CONSTRUCTORS
****************************************************/

Cafe::Cafe(Player *player) : Space("Cafe", player) {
    // Create the Cafe menu
    vector<string> spaceMenuItems;
    spaceMenuItems.push_back("Buy coffee?");
    spaceMenuItems.push_back(exitString);
    string promptText = "Welcome to the " + this->getName() + ". What would you like to do?";
    spaceMenu->setPromptText(promptText);
    spaceMenu->setMenuItems(spaceMenuItems);
}

/****************************************************
** DESTRUCTORS
****************************************************/

Cafe::~Cafe() {

}

/****************************************************
** Description: the player enters the space
****************************************************/

void Cafe::enter() {
    Player* p = this->getPlayer();
    // Show the Cafe menu
    int menuChoice = spaceMenu->showMenu();
    if (menuChoice == 1) {
        cout << "That coffee woke you right up, you earned 5 mental health points!" << endl;
        p->adjustPoints(5);
    }
}

/****************************************************
** Description: Generate random inventory items
****************************************************/

void Cafe::generateInventoryItems() {
    // The cafe doesn't generate inventory items
}
