/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: input validation implementation
****************************************************/

#include "InputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/****************************************************
** Description: Gets an integer from the user
****************************************************/

int getInteger(string prompt)
{
    // Variable to store the number entered by the user.
    int num;

    // Prompt the user to enter an integer.
    cout << prompt << endl;
    cin >> num;

    // While the input entered is not an integer, prompt the user to enter an integer.
    while (!cin) {
        cout << "That's not a valid integer. Please try again." << endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cin >> num;
    }
    return num;
}

int getIntegerWithMin(string prompt, int minVal)
{
    // Variable to store the number entered by the user.
    int num = getInteger(prompt);
    string newPrompt = "Please enter a valid integer.";
    while (num < minVal) {
        num = getInteger(newPrompt);
    }
    return num;
}

int getIntegerWithMinMax(string prompt, int minVal, int maxVal)
{
    // Variable to store the number entered by the user.
    int num = getInteger(prompt);
    string newPrompt = "Please enter a valid integer.";
    while (num < minVal || num > maxVal) {
        num = getInteger(newPrompt);
    }
    return num;
}

/****************************************************
** Description: Gets a string from the user
****************************************************/

string getString(string prompt, int minLength)
{
    // Clear cin
    cin.clear();
    cin.ignore();

    // Variable to store the string entered by the user.
    string str;
    str.empty();

    // Prompt the user to enter a string.
    cout << prompt << endl;
    getline(cin, str);
    unsigned long len = str.length();

    // While the input entered isn't long enough, prompt for another string.
    while (len < minLength) {
        str.empty();
        cin.clear();
        //cin.ignore();
        cout << "Please enter a string more than " << minLength << " characters long." << endl;
        getline(cin, str);
        len = str.length();
    }
    return str;
}