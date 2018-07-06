/*Stephen Fetinko 2018*/
#include "logic.h"

// Initialize the number and the name to add to empty strings
logic::logic() = default;

// When the program ends, clear the vectors.
logic::~logic() {
    if(names.size() > 0)
        names.clear();
    if(phone_numbers.size() > 0)
        phone_numbers.clear();
}

// View the registry. If there's nothing there, inform them. Else, print out the entries.
void logic::view_registry() {
    if(names.size() > 0) {
        for(int i = 0; i < phone_numbers.size(); i++) {
            std::cout << "(" << i+1 << ") " << names.at(i) << " - " << phone_numbers.at(i) << std::endl << std::endl;
            std::cout << "----------------------------------------" << std::endl
                      << "End of current registry. Back to main..." << std::endl
                      << "----------------------------------------" << std::endl
                      << std::endl;
        }
    } else {
        std::cout << "Empty!" << std::endl << std::endl;
        std::cout << "--------------------------------" << std::endl
                  << "No entries are currently listed!" << std::endl
                  << "--------------------------------" << std::endl
                  << std::endl;
    }
}

// Add to the registry. Will add to the end.
void logic::add_entry(std::string name, std::string number) {
    names.push_back(name);
    phone_numbers.push_back(number);
}

// Remove an entry from the registry. Will take a number and subtract 1 to match the position in the vector.
void logic::remove_entry() {

}

// Edit an entry. Will take a nuber and subtract 1 to match the position in the vector.
void logic::edit_entry() {

}