#pragma once
#include <string>
#include <regex>
class logic {
public:
    // Constructor and destructor
    logic();
    ~logic();
    // Variables
    
    // Functions for viewing, adding, removing and editing
    void view_registry();
    void add_entry();
    void remove_entry();
    void edit_entry();
};