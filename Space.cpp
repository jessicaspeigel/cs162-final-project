/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/15/2018
** Description: 
****************************************************/
#include "Space.hpp"

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

/****************************************************
** CONSTRUCTORS
****************************************************/

Space::Space(std::string name) {
    setName(name);
    top = nullptr, bottom = nullptr, left = nullptr, right = nullptr;
}

/****************************************************
** DESTRUCTORS
****************************************************/

Space::~Space() {

}

/****************************************************
** GETTERS / SETTERS
****************************************************/

string Space::getName() {
    return name;
}

void Space::setName(string name) {
    this->name = name;
}

void Space::setTop(Space *ptr) {
    top = ptr;
}

void Space::setBottom(Space *ptr) {
    bottom = ptr;
}

void Space::setRight(Space *ptr) {
    right = ptr;
}

void Space::setLeft(Space *ptr) {
    left = ptr;
}

Space *Space::getTop() {
    return top;
}

Space *Space::getBottom() {
    return bottom;
}

Space *Space::getRight() {
    return right;
}

Space *Space::getLeft() {
    return left;
}
