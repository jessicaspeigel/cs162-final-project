/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/20/2018
** Description: 
****************************************************/
#ifndef CS162_FINAL_PROJECT_SPACE_HPP
#define CS162_FINAL_PROJECT_SPACE_HPP

#include <string>

#include "Player.hpp"

class Space {
    protected:
        std::string name;
        Space *top;
        Space *left;
        Space *right;
        Space *bottom;

    public:
        Space(std::string name = "Space");
        virtual ~Space();
        virtual void enter(Player *p) = 0;
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
};


#endif //CS162_FINAL_PROJECT_SPACE_HPP