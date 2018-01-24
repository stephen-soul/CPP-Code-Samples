/*
 * DATA STRUCTURES LINE EDITOR // STEPHEN FETINKO 2018
 */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedList.h"

class Editor {
public:
    // Linked List object
    LinkedList linkedList;
    // Constructor & Destructor
    Editor();
    ~Editor();
    // Functions
    void readFromFile(std::string fileName);
    void displayHelpScreen();
    void displayLinesWithLineNumber();
    void insertIntoBuffer(int i, std::string value);
    // Variables
    std::ifstream file;
    std::string line;
};
