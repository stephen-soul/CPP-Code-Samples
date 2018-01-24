/*
 * DATA STRUCTURES LINE EDITOR // STEPHEN FETINKO 2018
 */

#pragma once
#include "Node.h"
#include <string>

class LinkedList {
public:
    // Make object for node
    Node *first, *last;
    // Constructor and virtual destructor
    LinkedList();
    virtual ~LinkedList();
    // Functions
    void add(std::string num);
    void deleteValue(std::string value);
    void deleteNode(int nodenum);
    void insertAfterValue(std::string value, std::string num);
    void insertBeforeNode(int nodenum, std::string num);
    void displayWithLineNumber();
    void displayWithoutLineNumber();
    void addToPosition(int position, std::string value);
    // Variables

private:

};
