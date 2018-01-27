/*
 * DATA STRUCTURES LINE EDITOR // STEPHEN FETINKO 2018
 */

#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList() {
    // Construct the head and the tail from node to null to avoid garbage
    head = nullptr;
    tail = nullptr;
}

/*
 *	DESTRUCTOR
 */

LinkedList::~LinkedList() {
    Node *node = head;
    if(node == nullptr) {

    } else {
        while (node != nullptr) {
            Node *temp = node;

            node = node->next;

            delete temp;
        }
    }
}

/*
 *	ADD TO THE LIST
 */

void LinkedList::add(std::string num) {
    Node *node = new Node;
    node->data = num;
    node->next = nullptr;

    if(head == nullptr) {
        head = node;
        tail = node;
        node = nullptr;
    } else {
        tail->next = node;
        tail = node;
    }
}

/*
 *	DELETE A THE FIRST VALUE
 */

void LinkedList::deleteFirst()
{
    auto *node = new Node;
    node = head;
    head = head->next;
    delete node;
}

/*
 *	DISPLAY LINES WITH LINE NUMBER
 */

void LinkedList::display() {
    // Get the node, put it at the beginning, while node != nullptr show the data
    Node *node;
    showLine = 1;
    node = head;
    while (node != nullptr) {
        std::cout << showLine << ". " << node->data << std::endl;
        node = node->next;
        showLine++;
    }
}

void LinkedList::addToPosition(int position, std::string value) {
    // Add to a specific position
    Node *previous = new Node;
    Node *current = new Node;
    Node *temporary = new Node;
    current = head;
    if(position == 1) {
        temporary->data = value;
        previous->next = temporary;
        current = current->next;
        temporary->next = current;
    }
    for (int i = 1; i < position; i++) {
        previous = current;
        current = current->next;
    }
    temporary->data = value;
    previous->next = temporary;
    temporary->next = current;
}

/*
 * ENTER AT THE BEGINNING OF THE NODE
 */

void LinkedList::insertAtStart(std::string value)  {
    auto *node=new Node;
    node->data=value;
    node->next=head;
    head=node;
}

/*
 * HANDLE DELETION AT A SPECIFIC POSITION
 */

void LinkedList::deleteAtPosition(int positionOne, int positionTwo) {
    auto *firstNode = new Node;
    auto *secondNode = new Node;
    firstNode = head;
    secondNode = head;
    if(positionTwo == 0) {
        // If only one number was entered then delete only that one
        for (int i = 1; i < positionOne; i++) {
            secondNode = firstNode;
            firstNode = firstNode->next;
        }
        secondNode->next = firstNode->next;
    } else {
        // Else if more than one number was entered, delete in the range
        for(int x = 1; x < positionOne; x++) {
            firstNode = firstNode->next;
        }
        for(int o = 1; o < positionTwo; o++) {
            secondNode = secondNode->next;
        }
        for(int z = positionOne; z <= positionTwo; z++) {
            firstNode->next = secondNode->next;
        }
    }
}

/*
 * DISPLAY THE SPECIFIC LINE(S) ENTERED
 */

void LinkedList::displaySpecificLines(int lineToShow1, int lineToShow2) {
    // Show just the line(s) entered
    auto *currentNode = new Node;
    //auto *secondaryNode = new Node;
    currentNode = head;
    //secondaryNode = head;
    specificLine1 = lineToShow1;
    specificLine2 = lineToShow2;
    if(lineToShow2 == 0) {
        for(int i = 1; i < lineToShow1; i++) {
            currentNode = currentNode->next;
        }
        std::cout << specificLine1 << ". " << currentNode->data;
    } else {
        for(int i = 1; i < specificLine1; i++) {
            currentNode = currentNode->next;
        }
        for(int i = specificLine1; i <= specificLine2; i++) {
            std::cout << specificLine1 << ". " << currentNode->data << std::endl;
            currentNode = currentNode->next;
            specificLine1++;
        }
    }
}

/*
 * GET THE SIZE OF THE LIST TO AVOID SEGMENTATION FAULTS
 */

int LinkedList::getSizeOfList() {
    auto *node = new Node;
    node = head;
    howManyLines = 1;
    if(node != nullptr) {
        while (node != nullptr) {
            node = node->next;
            howManyLines++;
        }
    } else {
        howManyLines = 0;
    }
    return howManyLines;
}

/*
 * INSERT AT THE END OF THE LIST
 */

void LinkedList::insertAtEnd(std::string value) {
    auto *node = new Node;
    node->data = value;
    node->next = nullptr;
    if(head == nullptr) {
        head = node;
        tail = node;
        node = nullptr;
    } else {
        tail->next = node;
        tail = node;
    }
}

/*
 * DELETE THE LAST ENTRY
 */

void LinkedList::deleteLast() {
    auto *currentNode = new Node;
    auto *previousNode = new Node;
    currentNode = head;
    while(currentNode->next != nullptr) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    tail = previousNode;
    previousNode->next = nullptr;
    delete currentNode;
}

/*
 * THIS IS PURELY FOR SAVING THE CONTENTS TO THE FILE
 */

std::string LinkedList::returnLinesForSaving(int numOfLine) {
    auto *node = new Node;
    node = head;
    for(int i = 1; i < numOfLine; i++) {
        node = node->next;
    }
    std::string lineInformation = node->data;
    return lineInformation;
}