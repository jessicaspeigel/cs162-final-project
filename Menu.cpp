/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: menu class implementation
****************************************************/

#include "Menu.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/****************************************************
** Constructors
****************************************************/

Menu::Menu(vector<string> items)
{
    setMenuItems(items);
    // Set prompt text to null if it doesn't exist
    setPromptText("");
}

Menu::Menu(string text, vector<string> items)
{
    setMenuItems(items);
    setPromptText(text);
}

/****************************************************
** Getters / Setters
****************************************************/

void Menu::setMenuItems(vector<string> items)
{
    // If menu items exists, delete it before making a new array
    menuItems.clear();
    for (string i : items) {
        menuItems.push_back(i);
    }
}

void Menu::setPromptText(string text)
{
    promptText = text;
}

string Menu::getPromptText()
{
    return promptText;
}

/****************************************************
** PUBLIC FUNCTIONS
****************************************************/

/****************************************************
** Description: Show the menu items and return the
** index of selected item.
****************************************************/

int Menu::showMenu()
{
    // Create a variable to hold the user's menu choice
    int choice = 0;

    // Show the prompt, if there is one
    if (getPromptText() != "") {
        cout << "\n" << getPromptText() << "\n";
    }

    // Show the user the menu
    for (int i = 0; i < menuItems.size(); i++) {
        // Show the menu item
        cout << i + 1 << ". " << menuItems[i] << "\n";
    }
    // Get input from the user
    cin >> choice;
    // Loop while the input is bad until we get a valid data and a valid number
    while (cin.fail()|| (choice < 1 || choice > menuItems.size())) {
        cin.clear();
        cin.ignore(999,'\n');
        cout << "I'm sorry, that's not a valid choice. Please enter a choice between 1 and " << menuItems.size() << endl;
        // Get input from the user again
        cin >> choice;
    }
    return choice;
}
