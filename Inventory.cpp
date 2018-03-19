/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_final_project
** Date: 03/18/2018
** Description: 
****************************************************/
#include "Inventory.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::toupper;

/****************************************************
** Constructors / Destructor
****************************************************/

Inventory::Inventory(int maxItems) {
    head = nullptr;
    tail = nullptr;
    setMaxItems(maxItems);
}

Inventory::~Inventory() {
    clearList();
}

/****************************************************
** Description: Deletes all items in the list.
****************************************************/

void Inventory::clearList() {
    InventoryItem* n = getHead();
    while(n != nullptr) {
        // Pointer to InventoryItem to be deleted
        InventoryItem* garbage = n;
        // Move on to the next
        n = n->getNext();
        // Delete the garbage InventoryItem
        delete garbage;
    }
}

/****************************************************
** Description: Prints a single item from the list.
** Takes a pointer to the item to print.
****************************************************/

void Inventory::printItem(InventoryItem *item) {
    if (item != nullptr) {
        cout << item->getValue() << ": " << item->getCount() << endl;
    }
}

/****************************************************
** Description: Prints the list from head to tail.
****************************************************/

void Inventory::printInventory() {
    InventoryItem* n = getHead();
    // Print a message if the list is empty
    if (n == nullptr) {
        cout << "Your inventory is empty." << endl;
    } else {
        cout << "Your inventory contains the following items:" << endl;
        while (n != nullptr) {
            // Print the value
            printItem(n);
            // Move on to the next
            n = n->getNext();
        }
        cout << "You have " << getInventoryCount() << " out of a possible " << getMaxItems() << " items." << endl;
    }
}

/****************************************************
** Description: Gets and sets the maximum amount of
** items allowed in the inventory.
****************************************************/

void Inventory::setMaxItems(int maxItems) {
    this->maxItems = maxItems;
}

int Inventory::getMaxItems() {
    return this->maxItems;
}

/****************************************************
** Description: Returns the count of the current
** inventory items.
****************************************************/

int Inventory::getInventoryCount() {
    int count = 0;
    // Loop through all the items in the inventory to get a total
    InventoryItem* inventoryItemPtr = nullptr;
    // Don't do anything if we're dealing with an empty list
    if (getHead() != nullptr) {
        // Initialize inventoryItemPtr to head
        inventoryItemPtr = getHead();
        while (inventoryItemPtr != nullptr) {
            // Update the count
            count += inventoryItemPtr->getCount();
            // Set the current pointer to the next one
            inventoryItemPtr = inventoryItemPtr->getNext();
        }
    }
    return count;
}

/****************************************************
** Description: Adds count to an existing inventory
** item. For example, if Apple already exists in
** the inventory, this method can be used to add
** additional Apples to the inventory.
****************************************************/

bool Inventory::addItem(string val, int count) {
    bool addResult = false;
    // Check to see if the item exists first
    InventoryItem* i = findItemByValue(val);
    if (i != nullptr) {
        // The item exists in the inventory
        i->setCount(i->getCount() + count);
        addResult = true;
    }
    // Return the result of the operation
    return addResult;
}

/****************************************************
** Description: Registers a new item type in the
** inventory.
****************************************************/

bool Inventory::registerItem(string item, int frequency) {
    bool registerResult = false;
    // Check to see if the item exists first
    InventoryItem* i = findItemByValue(item);
    if (i == nullptr) {
        // The item doesn't exist in the inventory
        addToTail(item, frequency);
        registerResult = true;
    }
    // Return the result of the operation
    return registerResult;
}

/****************************************************
** Description: Finds an item in the list. Returns
** the item if it exists, returns nullptr otherwise.
****************************************************/

InventoryItem* Inventory::findItemByValue(string val) {
    // Keep track of the current InventoryItem
    InventoryItem* inventoryItemPtr = nullptr;
    // Don't do anything if we're dealing with an empty list
    if (getHead() != nullptr) {
        // Initialize inventoryItemPtr to head
        inventoryItemPtr = getHead();
        while (inventoryItemPtr != nullptr && inventoryItemPtr->getValue() != val) {
            // Set the prev pointer to the current pointer
            // Set the current pointer to the next one
            inventoryItemPtr = inventoryItemPtr->getNext();
        }
    }

    return inventoryItemPtr;
}

/****************************************************
** Description: Returns the first item in the list.
****************************************************/

InventoryItem *Inventory::getHead() {
    return head;
}

/****************************************************
** Description: Returns the last item in the list.
****************************************************/

InventoryItem *Inventory::getTail() {
    return tail;
}

/****************************************************
** Description: Private function to set the first
** item in the list. Takes a pointer to the new
** head.
****************************************************/

void Inventory::setHead(InventoryItem *n) {
    if (n != nullptr) {
        // Set next of the new head to the old head if one exists
        n->setNext(head);
        // Set the new head's prev pointer to null in its new position
        n->setPrev(nullptr);
    }
    if (head != nullptr) {
        // Set prev pointer of head to the new InventoryItem (or nullptr)
        head->setPrev(n);
    }
    head = n;
}

/****************************************************
** Description: Private function to set the last
** item in the list. Takes a pointer to the new
** tail.
****************************************************/

void Inventory::setTail(InventoryItem *n) {
    if (n != nullptr) {
        // Set the prev pointer to point to the old tail if one exists
        n->setPrev(tail);
        // Set the new tail's next pointer to null in its new position
        n->setNext(nullptr);
    }
    if (tail != nullptr) {
        // Set the next pointer of the old tail to the new tail
        tail->setNext(n);
    }
    tail = n;
}

/****************************************************
** Description: Adds a new InventoryItem to the tail
** of the list.
****************************************************/

void Inventory::addToTail(string val, int frequency) {
    // This constructor instantiates with next and prev set to nullptr
    InventoryItem* n = new InventoryItem(val, frequency);
    // Set the tail to the new InventoryItem
    setTail(n);
    // Set the head if none exists
    if (getHead() == nullptr) {
        setHead(n);
    }
}
