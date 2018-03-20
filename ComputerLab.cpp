/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/18/2018
** Description: 
****************************************************/
#include "ComputerLab.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/****************************************************
** CONSTRUCTORS
****************************************************/

ComputerLab::ComputerLab(Player* player) : Space("Computer Lab", player) {
    // Create the ComputerLab menu
    vector<string> spaceMenuItems;
    spaceMenuItems.push_back("Do homework");
    spaceMenuItems.push_back(exitString);
    string promptText = "Welcome to the " + this->getName() + ". What would you like to do?";
    spaceMenu->setPromptText(promptText);
    spaceMenu->setMenuItems(spaceMenuItems);
    // Register the inventory items that can appear in this space (floppy disk and extra credit)
    Inventory* i = player->getInventory();
    i->registerItem("floppy disk", 20);
    i->registerItem("extra credit", 50);
    i->registerItem("homework", 100);
}

/****************************************************
** DESTRUCTORS
****************************************************/

ComputerLab::~ComputerLab() {

}

/****************************************************
** Description: The player enters the space
****************************************************/

void ComputerLab::enter() {
    Player* p = this->getPlayer();
    // Show the ComputerLab menu
    int menuChoice = spaceMenu->showMenu();
    if (menuChoice == 1) {
        if (p->getInventory()->getInventoryCount() < p->getInventory()->getMaxItems()) {
            cout << "Great work, homework has been added to your inventory! You spent 10 mental health points." << endl;
            p->adjustPoints(-10);
            p->getInventory()->addItem("homework");
            generateInventoryItems();
        } else {
            cout << "You can't do homework right now, your inventory is full. Use some items or turn in homework in the Classroom." << endl;
        }
    }
}

/****************************************************
** Description: Generate random inventory items
****************************************************/

void ComputerLab::generateInventoryItems() {
    // Apples and extra credit can be generated here
    // Get the player's inventory
    Inventory* i = player->getInventory();
    InventoryItem* floppyDisk = i->findItemByValue("floppy disk");
    InventoryItem* extraCredit = i->findItemByValue("extra credit");
    // See if we should generate a floppy disk
    if (i->getInventoryCount() < i->getMaxItems()) {
        int floppyDiskChance = rand() % 100 + 1;
        if (floppyDiskChance <= floppyDisk->getFrequency()) {
            i->addItem("floppy disk");
            // Only use plural if it's appropriate
            string fdPluralForm;
            if (floppyDisk->getCount() > 1) {
                fdPluralForm = " floppy disks";
            } else {
                fdPluralForm = " floppy disk";
            }
            cout << "Lucky you! You found a floppy disk in the " << this->getName() << ". You now have " << floppyDisk->getCount() << fdPluralForm << "." << endl;
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

