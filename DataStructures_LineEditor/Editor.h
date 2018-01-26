/*
 * DATA STRUCTURES LINE EDITOR // STEPHEN FETINKO 2018
 */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>
#include "LinkedList.h"
#include "UnixExtras.h"

class Editor {
public:
    // Linked List object
    LinkedList linkedList;
    // Constructor & Destructor
    Editor();
    ~Editor();
    // Functions
    bool readFromFile(std::string fileName);
    void displayHelpScreen();
    void displayLinesWithLineNumber();
    void insertIntoBuffer(int i, std::string value);
    void askUserForInput(std::string newFile);
    void deletion(int firstLineToDelete, int secondLineToDelete);
    void showLine(int lineToShow1, int lineToShow2);
    void quitAndSave(std::string newFile);
    void callSubstitution(int lineToSubstitute, std::string valueToSubstitute);
    // Variables
    std::ifstream file;
    std::string line;
    std::string userInput;
    std::string newLine;
    std::string selectedFirstInput;
    std::string selectedSecondInput;
    // Make a bool for the editor running
    bool running = true;
    // Make a variable for the line number
    int currentLineNumber;
};
