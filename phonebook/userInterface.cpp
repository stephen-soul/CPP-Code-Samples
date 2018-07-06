#include "userInterface.h"
#include <iostream>

using std::cout;
using std::endl;

interface::interface() {
    // Constructor initializes variables
    main_menu_input = false;
    menu_choice = "";
    menu_choice_converted = 0;
    program_running = true;
}

interface::~interface() = default;

void interface::main_menu() {
    // Make a regex statement to specifically get number input from the user
    std::regex digit_check("^[1-5]");
    do {
        cout << "Welcome to the phonebook ver. 1.0" << endl;
        cout << "(1) View registry" << endl;
        cout << "(2) Add entry" << endl;
        cout << "(3) Edit entry" << endl;
        cout << "(4) Delete entry" << endl;
        cout << "(5) Exit" << endl;
        cout << ">> ";
        getline(std::cin, menu_choice);
        if(std::regex_match(menu_choice, digit_check)) {
            menu_choice_converted = std::stoi(menu_choice);
            switch(menu_choice_converted) {
                case 1:
                    cout << endl << "View registry" << endl;
                    phonebookLogic.add_entry();
                    break;
                case 2:
                    cout << endl << "Add entry" << endl;
                    break;
                case 3:
                    cout << endl << "Edit entry" << endl;
                    break;
                case 4:
                    cout << endl << "Delete entry" << endl;
                    break;
                case 5:
                    program_running = false;
                    return;
                    break;
                default:
                    break;
            }
        } else
            cout << "\nInvalid response. Please try again.\n" << endl;
    } while (!main_menu_input);
}