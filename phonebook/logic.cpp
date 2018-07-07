/*Stephen Fetinko 2018*/
#include "logic.h"

// Initialize the constructor as default
logic::logic() = default;

// When the program ends, clear the vectors.
logic::~logic() {
    if(names.size() > 0)
        names.clear();
    if(phoneNumbers.size() > 0)
        phoneNumbers.clear();
}

// Add to the registry. Will add to the end.
void logic::addEntry(std::string name, std::string number) {
    names.push_back(name);
    phoneNumbers.push_back(number);
}

// Remove an entry from the registry. Will take a number and subtract 1 to match the position in the vector.
bool logic::removeEntry(int number) {
    int numberToDelete = number - 1;
    names.erase(names.begin() + numberToDelete);
    phoneNumbers.erase(phoneNumbers.begin() + numberToDelete);
}

// Edit an entry. Will take a nuber and subtract 1 to match the position in the vector.
void logic::editEntry(int numberToEdit, std::string name, std::string number) {
    int editingSpot = numberToEdit - 1;
    names.at(editingSpot) = name;
    phoneNumbers.at(editingSpot) = number;
}