/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/18/2018
** Description: 
****************************************************/
#include "InventoryItem.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

InventoryItem::InventoryItem(string val, int count, InventoryItem *next, InventoryItem *prev) {
    setValue(val);
    setCount(count);
    setNext(next);
    setPrev(prev);
}

InventoryItem::InventoryItem(string val, int count) {
    setValue(val);
    setCount(count);
    setNext(nullptr);
    setPrev(nullptr);
}

string InventoryItem::getValue() {
    return val;
}

void InventoryItem::setValue(string val) {
    this->val = val;
}

InventoryItem* InventoryItem::getNext() {
    return this->next;
}

void InventoryItem::setNext(InventoryItem *next) {
    this->next = next;
}

InventoryItem* InventoryItem::getPrev() {
    return this->prev;
}

void InventoryItem::setPrev(InventoryItem *prev) {
    this->prev = prev;
}

int InventoryItem::getCount() {
    return this->count;
}

void InventoryItem::setCount(int count) {
    this->count = count;
}
