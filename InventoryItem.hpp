/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/18/2018
** Description: 
****************************************************/
#ifndef CS162_FINAL_PROJECT_INVENTORYITEM_HPP
#define CS162_FINAL_PROJECT_INVENTORYITEM_HPP

#include <iostream>
#include <string>

class InventoryItem {

private:
    std::string val;
    int count;
    int frequency;
    InventoryItem* next;
    InventoryItem* prev;

public:
    InventoryItem(std::string val, int freq = 50, int count = 0, InventoryItem *next = nullptr, InventoryItem *prev = nullptr);
    std::string getValue();
    void setValue(std::string val);
    int getCount();
    void setCount(int count);
    int getFrequency();
    void setFrequency(int freq);
    InventoryItem* getNext();
    void setNext(InventoryItem *next);
    InventoryItem* getPrev();
    void setPrev(InventoryItem *prev);

};


#endif //CS162_FINAL_PROJECT_INVENTORYITEM_HPP
