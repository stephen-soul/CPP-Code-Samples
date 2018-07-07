/*Stephen Fetinko 2018*/
#pragma once
#include "logic.h"
#include "programState.h"
#include <iostream>
#include <regex>
class interface {
public:
    // Constructor && Destructor
    interface();
    ~interface();
    // Functions for the interface
    void runInterface();
    void mainMenu();
    void displayRegistry();
    void askForEntryToAdd();
    void askForEntryToDelete();
    void askForEntryToEdit();
    // Variables for input
    std::string menuChoice;
    int menuChoiceConverted;
    // Make an object for the logic
    logic phonebookLogic;
    // Make an object for the state
    state programState;
private:
    std::string nameToAdd;
    std::string numberToAdd;
    std::string numberToDelete;
};