/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_final_project
** Date: 03/19/2018
** Description: Implementation for Classroom class.
****************************************************/
#include "Classroom.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::abs;

/****************************************************
** CONSTRUCTORS
****************************************************/

Classroom::Classroom(Player* player) : Space("Classroom", player) {
    // Create the Classroom menu
    vector<string> spaceMenuItems;
    spaceMenuItems.push_back("Offer your TA an apple to try and help your grade");
    spaceMenuItems.push_back("Use extra credit to help your grade");
    spaceMenuItems.push_back("Turn in homework");
    spaceMenuItems.push_back(exitString);
    string promptText = "Welcome to the " + this->getName() + ". What would you like to do?";
    spaceMenu->setPromptText(promptText);
    spaceMenu->setMenuItems(spaceMenuItems);
    // Create the vector for the random events and their probabilities/impacts
    randomEvents.push_back(RandomEvent("segmentation fault", -1, 30));
    randomEvents.push_back(RandomEvent("lost your work", -1, 20));
    randomEvents.push_back(RandomEvent("memory leak", -.5, 40));
    randomEvents.push_back(RandomEvent("sloppy code", -.2, 60));
    randomEvents.push_back(RandomEvent("your TA had a bad day", -.2, 30));
    randomEvents.push_back(RandomEvent("your TA had a good day", .3, 50));
    // Initialize inventory item flags
    appleFlag = false;
    extraCreditFlag = false;
}

/****************************************************
** DESTRUCTORS
****************************************************/

Classroom::~Classroom() {

}

/****************************************************
** Description: The player enters the space
****************************************************/

void Classroom::enter() {
    Player* p = this->getPlayer();
    // Show the Classroom menu
    int menuChoice = spaceMenu->showMenu();
    switch (menuChoice) {
        case 1 : // Give the TA an apple
            useApple();
            break;
        case 2 : // Use extra credit
            useExtraCredit();
            break;
        case 3 : // Turn in homework
            turnInHomework();
            break;
    }
}

/****************************************************
** Description: Uses an apple to make the TA more
** likely to have a good day.
****************************************************/

void Classroom::useApple() {
    // Check to see if the user has already used the apple
    if (appleFlag) {
        cout << "You already used an apple." << endl;
    } else {
        // Check to make sure the user has an apple
        InventoryItem* item = getPlayer()->getInventory()->findItemByValue("apple");
        if (item->getCount() > 0) {
            // The user has an apple to use
            appleFlag = true;
            cout << "You gave your TA an apple. Now they're twice as likely to have a good day and give you a better grade." << endl;
            item->setCount(item->getCount() - 1);
        } else {
            cout << "Sorry, but you don't have any apples right now." << endl;
        }
    }
    // Show the menu again
    enter();
}

/****************************************************
** Description: Uses extra credit to earn more
** credits when homework is turned in.
****************************************************/

void Classroom::useExtraCredit() {
    // Check to see if the user has already used the extra credit
    if (extraCreditFlag) {
        cout << "You already used your extra credit." << endl;
    } else {
        // Check to make sure the user has an apple
        InventoryItem* item = getPlayer()->getInventory()->findItemByValue("extra credit");
        if (item->getCount() > 0) {
            // The user has an apple to use
            extraCreditFlag = true;
            cout << "You used your extra credit, now you'll get more credits when you turn in your homework." << endl;
            item->setCount(item->getCount() - 1);
        } else {
            cout << "Sorry, but you don't have any extra credit right now." << endl;
        }
    }
    // Show the menu again
    enter();
}

/****************************************************
** Description: Turns in homework.
****************************************************/

void Classroom::turnInHomework() {
    // Check to make sure the user has homework
    InventoryItem* item = getPlayer()->getInventory()->findItemByValue("homework");
    if (item->getCount() > 0) {
        // The user has homework to turn in
        item->setCount(item->getCount() - 1);
        // Generate base credits between 20 and 30
        int baseCredits = rand() % 20 + 10;
        cout << "You turned in homework for " << baseCredits << " credits." << endl;
        // Loop through the random events, storing the ones that happen in a vector
        vector<RandomEvent> events;
        for (int i = 0; i < randomEvents.size(); i++) {
            int chance = rand() % 100 + 1;
            // If the user used an apple, set the probability of TA good day to double
            if (randomEvents.at(i).eventName == "your TA had a good day") {
                if (appleFlag) {
                    randomEvents.at(i).probability *= 2;
                    appleFlag = false;
                } else {
                    randomEvents.at(i).probability = 30;
                }
            }
            if (chance <= randomEvents.at(i).probability) {
                // The event happened, push it into the vector
                events.push_back(randomEvents.at(i));
                //cout << "Random event possible: " << randomEvents.at(i).eventName << endl;
            }
        }
        // Choose one event to go with (but only if events.size() > 0)
        RandomEvent finalEvent("Default", 0, 0);
        if (!events.empty()) {
            finalEvent = events.at(rand() % events.size());
        }
        int creditImpact = baseCredits * finalEvent.gradeImpact;
        int credits = baseCredits + creditImpact;
        if (creditImpact < 0) {
            // It's a negative event
            cout << "Uh oh, you had the following event: " << finalEvent.eventName << ". You lost " << abs(creditImpact) << " credits for a total of " << credits << "." << endl;
            // Handle losing work if the user has a floppy disk
            if (finalEvent.eventName == "lost your work") {
                InventoryItem* floppyDisk = getPlayer()->getInventory()->findItemByValue("floppy disk");
                // DEBUG REMOVE
                if (floppyDisk->getCount() < 1) {
                    floppyDisk->setCount(1);
                }

                // DEBUG REMOVE
                if (floppyDisk->getCount() > 0) {
                    // Tell the user the good news
                    cout << "Good news, you backed up your work on your floppy disk! You saved your " << abs(creditImpact) << " credits." << endl;
                    // Remove a floppy disk from the inventory
                    floppyDisk->setCount(floppyDisk->getCount() - 1);
                    // Add the credits back
                    credits += abs(creditImpact);
                }
            }
        } else if (creditImpact > 0) {
            // It's a positive event
            cout << "Good news! You had the following event: " << finalEvent.eventName << ". You earned an extra " << creditImpact << " credits for a total of " << credits << "." << endl;
        }
        // Check for extra credit and add it
        if (extraCreditFlag) {
            int extraCredits = credits * .5;
            credits += extraCredits;
            cout << "You used your extra credit to earn an extra 50% for " << extraCredits << " extra credits." << endl;
            extraCreditFlag = false;
        }
        cout << "A total of " << credits << " credits has been added to your total." << endl;
        // Adjust the credits
        getPlayer()->adjustCredits(credits);
    } else {
        cout << "Sorry, but you don't have any homework to turn in. Visit the Computer Lab to do homework." << endl;
    }
}

/****************************************************
** Description: Generate random inventory items
****************************************************/

void Classroom::generateInventoryItems() {
    // No inventory items are generated in the classroom
}