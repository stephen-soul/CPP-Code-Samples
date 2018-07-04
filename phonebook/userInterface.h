#pragma once
#include <string>
#include <regex>
class interface {
public:
    // Constructor && Destructor
    interface();
    ~interface();
    // Functions for the interface
    void main_menu();
    void clear_screen();
    // Variables for input
    std::string menu_choice;
    // Variables to keep track of things.
    bool main_menu_input; // Main menu input flag (false for off true for on)
};