/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/15/2018
** Description: Quad implementation file
****************************************************/
#include "Quad.hpp"

using std::cin;
using std::cout;
using std::endl;

/****************************************************
** CONSTRUCTORS
****************************************************/

Quad::Quad(Player* player) : Space("Quad", player) {

}

/****************************************************
** DESTRUCTORS
****************************************************/

Quad::~Quad() {

}

/****************************************************
** Description: The player enters the space
****************************************************/

void Quad::enter() {
    cout << "Entered " << this->getName() << endl;
}

/****************************************************
** Description: Generate random inventory items
****************************************************/

void Quad::generateInventoryItems() {
    // The quad doesn't generate any items
}
