/*
 * DATA STRUCTURES LINE EDITOR // STEPHEN FETINKO 2018
 */

#pragma once
#include "Node.h"

class LinkedList {
public:
    // Constructor and virtual destructor
    LinkedList();
    virtual ~LinkedList();
    // Functions
    void add(std::string num);
    void deleteFirst();
    void deleteAtPosition(int position, int positionTwo);
    void deleteLast();
    void insertAtEnd(std::string value);
    void insertBeforeNode(int nodenum, std::string num);
    void display();
    void displaySpecificLines(int lineToShow, int lineToShow2);
    void addToPosition(int position, std::string value);
    void insertAtStart(std::string value);
    int getSizeOfList();
    // Variables for specific lines to display
    int specificLine1;
    int specificLine2;
    // Variable for display all lines
    int showLine;
    // Variable to count the lines
    int howManyLines;
private:
    // Make object for node
    Node *head, *tail;
};
