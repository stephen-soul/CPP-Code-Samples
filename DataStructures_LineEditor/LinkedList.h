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
    void deleteValue(std::string value);
    void deleteNode(int nodenum);
    void insertAfterValue(std::string value, std::string num);
    void insertBeforeNode(int nodenum, std::string num);
    void display();
    void displayWithoutLineNumber();
    void addToPosition(int position, std::string value);
    void insertAtStart(std::string value);
    // Variables
    int lineNumber;
private:
    // Make object for node
    Node *head, *tail;
};
