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
        cout << "The inventory is empty." << endl;
    }
    while (n != nullptr) {
        // Print the value
        printItem(n);
        // Move on to the next
        n = n->getNext();
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

bool Inventory::registerItem(string item) {
    bool registerResult = false;
    // Check to see if the item exists first
    InventoryItem* i = findItemByValue(item);
    if (i == nullptr) {
        // The item doesn't exist in the inventory
        addToTail(item);
        registerResult = true;
    }
    // Return the result of the operation
    return registerResult;
}

/****************************************************
** Description: Finds an item in the list. Returns
** the item if it exists, returns nullptr otherwise.
****************************************************/

InventoryItem* Inventory::findItemByValue(std::string val) {
    // Keep track of the current InventoryItem and the prev InventoryItem
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
** Description: Private function to delete a single
** item from the list. Takes a pointer to the item
** to delete. Does NOT reset head and tail. Returns
** false for an empty list
****************************************************/

bool Inventory::deleteItemByValue(string val) {
    // Variable for result
    bool deleteResult = false;
    // Keep track of the current InventoryItem and the prev InventoryItem
    InventoryItem* InventoryItemPtr = nullptr;
    InventoryItem* prevInventoryItemPtr = nullptr;
    // Don't do anything if we're dealing with an empty list
    if (getHead() != nullptr) {
        // Initialize InventoryItemPtr to head
        InventoryItemPtr = getHead();
        while (InventoryItemPtr != nullptr && InventoryItemPtr->getValue() != val) {
            // Set the prev pointer to the current pointer
            prevInventoryItemPtr = InventoryItemPtr;
            // Set the current pointer to the next one
            InventoryItemPtr = InventoryItemPtr->getNext();
        }
        // See if there's a matching InventoryItem to delete
        if (InventoryItemPtr != nullptr) {
            // Set the prev pointer of the next item in the list to the one before the item to be deleted
            InventoryItem* newNext = nullptr;
            newNext = InventoryItemPtr->getNext();
            if (newNext != nullptr) {
                newNext->setPrev(prevInventoryItemPtr);
            }
            // Set the next pointer of the previous item in the list to the one after the item to be deleted
            if (prevInventoryItemPtr != nullptr) {
                prevInventoryItemPtr->setNext(InventoryItemPtr->getNext());
            }
            // Delete the item
            delete InventoryItemPtr;
            // Set the result to true
            deleteResult = true;
        }
    }

    return deleteResult;
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
** Description: Adds a new InventoryItem to the head
** of the list.
****************************************************/

void Inventory::addToHead(string val) {
    // This constructor instantiates with next and prev set to nullptr
    InventoryItem* n = new InventoryItem(val);
    // Set the head
    setHead(n);
    // Set the tail if none exists
    if (getTail() == nullptr) {
        setTail(n);
    }
}

/****************************************************
** Description: Adds a new InventoryItem to the tail
** of the list.
****************************************************/

void Inventory::addToTail(string val) {
    // This constructor instantiates with next and prev set to nullptr
    InventoryItem* n = new InventoryItem(val);
    // Set the tail to the new InventoryItem
    setTail(n);
    // Set the head if none exists
    if (getHead() == nullptr) {
        setHead(n);
    }
}
