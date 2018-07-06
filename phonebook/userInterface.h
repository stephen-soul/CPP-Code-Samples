#pragma once
#include "logic.h"
class interface {
public:
    // Constructor && Destructor
    interface();
    ~interface();
    // Functions for the interface
    void main_menu();
    // Variables for input
    std::string menu_choice;
    int menu_choice_converted;
    // Variables to keep track of things.
    bool main_menu_input; // Main menu input flag (false for off true for on)
    bool program_running;
    // Make an object for the logic
    logic phonebookLogic;
};