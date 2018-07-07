/*Stephen Fetinko 2018*/
#pragma once
#include <string>
#include <vector>
class logic {
public:
    // Constructor and destructor
    logic();
    ~logic();
    // Variables
    std::vector<std::string> names; // Regex to validate only letters
    std::vector<std::string> phoneNumbers; // Regex to validate the format 999-999-9999
    // Functions for adding, removing and editing
    void addEntry(std::string name, std::string number);
    bool removeEntry(int number);
    bool editEntry(int numberToEdit, std::string name, std::string number);
};