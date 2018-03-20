/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_final_project
** Date: 03/19/2018
** Description: Implementation for AdvisorsOffice class.
****************************************************/
#include "AdvisorsOffice.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::abs;

/****************************************************
** CONSTRUCTORS
****************************************************/

AdvisorsOffice::AdvisorsOffice(Player* player) : Space("Advisor's Office", player) {
    // Create the Advisors Office menu
    vector<string> spaceMenuItems;
    spaceMenuItems.push_back("Offer your advisor an apple to help your chances at graduating");
    spaceMenuItems.push_back("Apply for graduation");
    spaceMenuItems.push_back(exitString);
    string promptText = "Welcome to the " + this->getName() + ". What would you like to do?";
    spaceMenu->setPromptText(promptText);
    spaceMenu->setMenuItems(spaceMenuItems);
    // Create the vector for the random events and their probabilities/impacts
    randomEvents.push_back(RandomEvent("credits didn't transfer", -20, -20, 20));
    randomEvents.push_back(RandomEvent("GPA is too low", -5, -10, 30));
    randomEvents.push_back(RandomEvent("graduation", 0, 100, 50));
    // Initialize inventory item flags
    appleFlag = false;
    // Register the inventory items that can appear in this space (apple, diploma)
    Inventory* i = player->getInventory();
    i->registerItem("apple", 50);
    i->registerItem("diploma", 100);
}

/****************************************************
** DESTRUCTORS
****************************************************/

AdvisorsOffice::~AdvisorsOffice() {

}

/****************************************************
** Description: The player enters the space
****************************************************/

void AdvisorsOffice::enter() {
    Player* p = this->getPlayer();
    // Show the Advisors Office menu
    int menuChoice = spaceMenu->showMenu();
    switch (menuChoice) {
        case 1 : // Give the TA an apple
            useApple();
            break;
        case 2 : // Apply for graduation
            applyForGraduation();
            break;
    }
}

/****************************************************
** Description: Uses an apple to make the TA more
** likely to have a good day.
****************************************************/

void AdvisorsOffice::useApple() {
    // Check to see if the user has already used the apple
    if (appleFlag) {
        cout << "You already used an apple." << endl;
    } else {
        // Check to make sure the user has an apple
        InventoryItem* item = getPlayer()->getInventory()->findItemByValue("apple");
        if (item->getCount() > 0) {
            // The user has an apple to use
            appleFlag = true;
            cout << "You gave your advisor an apple. Now they're twice as likely to approve your application to graduate." << endl;
            item->setCount(item->getCount() - 1);
        } else {
            cout << "Sorry, but you don't have any apples right now." << endl;
        }
    }
    // Show the menu again
    enter();
}

/****************************************************
** Description: Attempt to get a diploma
****************************************************/

void AdvisorsOffice::applyForGraduation() {
    // Check to make sure the user has 60 credits
    if (getPlayer()->getCredits() >= 60) {
        // Loop through the random events, storing the ones that happen in a vector
        vector<RandomEvent> events;
        for (int i = 0; i < randomEvents.size(); i++) {
            int chance = rand() % 100 + 1;
            // If the user used an apple, set the probability of TA good day to double
            if (randomEvents.at(i).eventName == "graduation") {
                if (appleFlag) {
                    randomEvents.at(i).probability *= 2;
                    appleFlag = false;
                } else {
                    randomEvents.at(i).probability = 50;
                }
            }
            if (chance <= randomEvents.at(i).probability) {
                // The event happened, push it into the vector
                events.push_back(randomEvents.at(i));
                //cout << "Random event possible: " << randomEvents.at(i).eventName << endl;
            }
        }
        // Choose one event to go with (but only if events.size() > 0)
        RandomEvent finalEvent("advisor is out of office", 0, 0, 0);
        if (!events.empty()) {
            finalEvent = events.at(rand() % events.size());
        }
        if ((finalEvent.creditImpact <= 0 || finalEvent.pointImpact <= 0) && finalEvent.eventName != "graduation") {
            // It's a negative event
            cout << "Uh oh, you had the following event: " << finalEvent.eventName << "." << endl;
            if (finalEvent.creditImpact < 0) {
                player->adjustCredits(finalEvent.creditImpact);
                cout << "You lost " << abs(finalEvent.creditImpact) << " credits and have " << player->getCredits() << " left." << endl;
            }
            if (finalEvent.pointImpact < 0) {
                player->adjustPoints(finalEvent.pointImpact);
                cout << "You lost " << abs(finalEvent.pointImpact) << " mental health points and have " << player->getPoints() << " left." << endl;
            }
            // Generate an inventory item
            generateInventoryItems();
        } else if (finalEvent.eventName == "graduation") {
            // It's diploma time!
            cout << "Good news! Your advisor has approved your request to graduate." << endl;
            // Add the diploma to the user's inventory
            player->getInventory()->addItem("diploma");
        }
    } else {
        cout << "Sorry, but you don't have enough credits to apply for graduation. Visit the Computer Lab to do homework and the Classroom to turn it in for credits." << endl;
    }
}

/****************************************************
** Description: Generate random inventory items
****************************************************/

void AdvisorsOffice::generateInventoryItems() {
    // Apples can be generated here
    // Get the player's inventory
    Inventory* i = player->getInventory();
    InventoryItem* apples = i->findItemByValue("apple");
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
}
