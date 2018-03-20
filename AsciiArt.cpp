/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_final_project
** Date: 03/19/2018
** Description: Implementation for AsciiArt class.
** Citation: This code is modified from
** http://www.cplusplus.com/forum/general/58945/user
** TheMassiveChipmunk
**
** Reads the intro ascii art from a file using
** getFileContents(), then outputs the file lines
** to the console and closes the file
****************************************************/

#include "AsciiArt.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

AsciiArt::AsciiArt(std::string fileName) {
    // Open file
    ifstream reader;
    reader.open(fileName);
    // Get file contents into a usable state
    string introArt = getFileContents(reader);
    // Print it to the screen
    if (introArt != "ERROR") {
        cout << introArt << endl;
    } else {
        cout << "Error" << endl;
    }
    // Close file
    reader.close();
}

string AsciiArt::getFileContents(ifstream &file) {
    // Define a string to hold the lines from the file
    string lines;
    // Make sure the file is in a good state
    if (file) {
        while (file.good()) {
            string tempLine;
            getline(file, tempLine);
            tempLine += "\n";
            lines += tempLine;
        }
        return lines;
    } else {
        return "ERROR";
    }
}
