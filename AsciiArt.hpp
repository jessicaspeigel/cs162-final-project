/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_final_project
** Date: 03/19/2018
** Description: Declaration for AsciiArt class.
****************************************************/

#ifndef CS162_FINAL_PROJECT_ASCIIART_HPP
#define CS162_FINAL_PROJECT_ASCIIART_HPP

#include <iostream>
#include <fstream>
#include <string>

class AsciiArt {

private:
    std::string getFileContents(std::ifstream &file);

public:
    AsciiArt(std::string fileName);
};


#endif //CS162_FINAL_PROJECT_ASCIIART_HPP
