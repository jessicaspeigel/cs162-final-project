/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/20/2018
** Description: 
****************************************************/
#ifndef CS162_FINAL_PROJECT_SPACE_HPP
#define CS162_FINAL_PROJECT_SPACE_HPP

#include <iostream>
#include <string>

#include "Player.hpp"
#include "Menu.hpp"

class Inventory;

class Space {
    protected:
        std::string name;
        Space *top;
        Space *left;
        Space *right;
        Space *bottom;
        Menu* spaceMenu;
        Player* player;
        std::string exitString;

    public:
        Space(std::string name = "Space", Player* player = nullptr);
        virtual ~Space();
        virtual void enter() = 0;
        virtual void generateInventoryItems() = 0;
        void setTop(Space *ptr);
        void setBottom(Space *ptr);
        void setRight(Space *ptr);
        void setLeft(Space *ptr);
        Space *getTop();
        Space *getBottom();
        Space *getRight();
        Space *getLeft();
        std::string getName();
        void setName(std::string name);
        Player* getPlayer();
        void setPlayer(Player* p);
};


#endif //CS162_FINAL_PROJECT_SPACE_HPP
