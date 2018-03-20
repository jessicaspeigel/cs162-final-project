/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/18/2018
** Description: 
****************************************************/
#include "Bar.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/****************************************************
** CONSTRUCTORS
****************************************************/

Bar::Bar(Player* player) : Space("Bar", player) {
    // Create the Bar menu
    vector<string> spaceMenuItems;
    spaceMenuItems.push_back("Get happy hour");
    spaceMenuItems.push_back(exitString);
    string promptText = "Welcome to the " + this->getName() + ". What would you like to do?";
    spaceMenu->setPromptText(promptText);
    spaceMenu->setMenuItems(spaceMenuItems);
}

/****************************************************
** DESTRUCTORS
****************************************************/

Bar::~Bar() {

}

/****************************************************
** Description: The player enters the space
****************************************************/

void Bar::enter() {
    Player* p = this->getPlayer();
    // Show the Bar menu
    int menuChoice = spaceMenu->showMenu();
    if (menuChoice == 1) {
        cout << "You had a great time at happy hour, plus 20 mental health points!" << endl;
        p->adjustPoints(20);
        // Check to see if the player has extra credit we should remove
        Inventory* i = p->getInventory();
        InventoryItem* extraCredit = i->findItemByValue("extra credit");
        if (extraCredit->getCount() > 0) {
            cout << "Unfortunately, you got a little drunk and lost one chance at extra credit." << endl;
            i->addItem("extra credit", -1);
        }
    }
}

/****************************************************
** Description: Generate random inventory items
****************************************************/

void Bar::generateInventoryItems() {
    // There are no inventory items generated in the bar
}
