/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/18/2018
** Description: 
****************************************************/
#include "TAOffice.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/****************************************************
** CONSTRUCTORS
****************************************************/

TAOffice::TAOffice(Player* player) : Space("TA's Office", player) {
    // Create the TAOffice menu
    vector<string> spaceMenuItems;
    spaceMenuItems.push_back("Attend office hours");
    spaceMenuItems.push_back(exitString);
    string promptText = "Welcome to the " + this->getName() + ". What would you like to do?";
    spaceMenu->setPromptText(promptText);
    spaceMenu->setMenuItems(spaceMenuItems);
    // Register the inventory items that can appear in this space (apple and extra credit)
    Inventory* i = player->getInventory();
    i->registerItem("apple", 50);
    i->registerItem("extra credit", 50);
}

/****************************************************
** DESTRUCTORS
****************************************************/

TAOffice::~TAOffice() {

}

/****************************************************
** Description: The player enters the space
****************************************************/

void TAOffice::enter() {
    Player* p = this->getPlayer();
    // Show the TAOffice menu
    int menuChoice = spaceMenu->showMenu();
    if (menuChoice == 1) {
        cout << "Your TA answered all your questions, but you're exhausted and lost 5 mental health points." << endl;
        p->adjustPoints(-5);
        generateInventoryItems();
    }
}

/****************************************************
** Description: Generate random inventory items
****************************************************/

void TAOffice::generateInventoryItems() {
    // Apples and extra credit can be generated here
    // Get the player's inventory
    Inventory* i = player->getInventory();
    InventoryItem* apples = i->findItemByValue("apple");
    InventoryItem* extraCredit = i->findItemByValue("extra credit");
    // See if we should generate an apple
    if (i->getInventoryCount() < i->getMaxItems()) {
        int appleChance = rand() % 100 + 1;
        if (appleChance <= apples->getFrequency()) {
            i->addItem("apple");
            // Only use plural if it's appropriate
            string applePluralForm;
            if (apples->getCount() > 1) {
                applePluralForm = " apples";
            } else {
                applePluralForm = " apple";
            }
            cout << "Lucky you! You found an apple in the " << this->getName() << ". You now have " << apples->getCount() << applePluralForm << "." << endl;
        }
    }
    // See if we should generate extra credit
    if (i->getInventoryCount() < i->getMaxItems()) {
        int extraCreditChance = rand() % 100 + 1;
        if (extraCreditChance <= extraCredit->getFrequency()) {
            i->addItem("extra credit");
            // Only use plural if it's appropriate
            string ecPluralForm;
            if (extraCredit->getCount() > 1) {
                ecPluralForm = " chances";
            } else {
                ecPluralForm = " chance";
            }
            cout << "Lucky you! You found extra credit in the " << this->getName() << ". You now have " << extraCredit->getCount() << ecPluralForm << " at extra credit." << endl;
        }
    }
}
