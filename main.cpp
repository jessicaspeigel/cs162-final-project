/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/20/2018
** Description: CS Degree Simulator main
****************************************************/

#include <iostream>
#include <fstream>
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
using std::ifstream;

// Function prototypes for intro art
void introArtReader();
string getFileContents(ifstream &file);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    // Output the intro art and instructions
    introArtReader();
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

/****************************************************
** Citation: This code is modified from
** http://www.cplusplus.com/forum/general/58945/user
** TheMassiveChipmunk
**
** Reads the intro ascii art from a file using
** getFileContents(), then outputs the file lines
** to the console and closes the file
****************************************************/
void introArtReader()
{
    // Open file
    ifstream reader;
    reader.open("IntroArt.txt");

    // Get file
    string introArt = getFileContents(reader);

    //Print it to the screen
    if (introArt != "ERROR") {
        cout << introArt << endl;
    } else {
        cout << "Error" << endl;
    }

    //Close file
    reader.close();
}

/***************************************************
** Checks to make sure the file is available and if
** it is get the appropriately space and /n art
****************************************************/
string getFileContents(ifstream &file)
{
    //All lines
    string lines = "";

    //Check if everything is good
    if (file)
    {
        while (file.good())
        {
            string tempLine;                //Temp line
            getline(file, tempLine);        //Get temp line
            tempLine += "\n";               //Add newline character

            lines += tempLine;              //Add newline
        }
        return lines;
    }
    else                           //Return error
    {
        return "ERROR";
    }
}