/*Stephen Fetinko 2018*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
class logic {
public:
    // Constructor and destructor
    logic();
    ~logic();
    // Variables
    std::vector<std::string> names; // Regex to validate only letters
    std::vector<std::string> phone_numbers; // Regex to validate the format 999-999-9999
    std::string name_to_add;
    std::string number_to_add;
    // Functions for viewing, adding, removing and editing
    void view_registry();
    void add_entry(std::string name, std::string number);
    void remove_entry();
    void edit_entry();
};