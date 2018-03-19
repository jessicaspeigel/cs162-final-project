/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/18/2018
** Description: Inventory header file
****************************************************/
#ifndef CS162_FINAL_PROJECT_INVENTORY_HPP
#define CS162_FINAL_PROJECT_INVENTORY_HPP

#include <iostream>
#include <string>
#include <vector>

#include "InventoryItem.hpp"

class Inventory {

private:
    int maxItems;
    InventoryItem* head;
    InventoryItem* tail;
    void setHead(InventoryItem* n);
    void setTail(InventoryItem* n);
    void addToTail(std::string val, int frequency);
    InventoryItem* getHead();
    InventoryItem* getTail();
    void clearList();

public:
    Inventory(int maxItems = 10);
    ~Inventory();
    void setMaxItems(int maxItems);
    int getMaxItems();
    int getInventoryCount();
    void printItem(InventoryItem* item);
    void printInventory();
    bool addItem(std::string val, int count = 1);
    bool registerItem(std::string item, int frequency = 50);
    InventoryItem* findItemByValue(std::string val);

};


#endif //CS162_FINAL_PROJECT_INVENTORY_HPP
