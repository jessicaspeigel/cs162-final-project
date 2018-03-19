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

InventoryItem::InventoryItem(std::string val, int freq, int count, InventoryItem *next, InventoryItem *prev) {
    setValue(val);
    setCount(count);
    setFrequency(freq);
    setNext(next);
    setPrev(prev);
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

int InventoryItem::getFrequency() {
    return this->frequency;
}

void InventoryItem::setFrequency(int freq) {
    this->frequency = freq;
}
