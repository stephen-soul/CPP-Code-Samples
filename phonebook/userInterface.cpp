/*Stephen Fetinko 2018*/
#include "userInterface.h"

using std::cout;
using std::endl;

interface::interface() {
    // Constructor initializes variables
    menu_choice = "";
    menu_choice_converted = 0;
}

interface::~interface() = default;

void interface::run_interface() {
    while(program_state.is_program_running()) {
        main_menu();
    }
}

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
                    cout << endl << "-------------" << endl << "View registry" << endl << "-------------" << endl << endl;
                    phonebookLogic.view_registry();
                    break;
                case 2:
                    cout << endl << "Add entry" << endl;
                    ask_for_entry_to_add();
                    break;
                case 3:
                    cout << endl << "Edit entry" << endl;
                    break;
                case 4:
                    cout << endl << "Delete entry" << endl;
                    break;
                case 5:
                    program_state.change_program_running_state();
                    program_state.change_main_menu_state();
                    return;
                    break;
                default:
                    break;
            }
        } else
            cout << "\nInvalid response. Please try again.\n" << endl;
    } while (program_state.is_main_menu_active());
}

void interface::ask_for_entry_to_add() {
    // Make some validating regex for the name and phone number
    std::regex name_match("^[A-Za-z]*+\\s?[A-Za-z]*"); // Match the name as only any number of letters A-Z or a-z first name only or first and last name
    do {
        std::cout << std::endl << "Please enter the name you wish to add." << std::endl;
        std::cout << ">> ";
        getline(std::cin, name_to_add);
        if(std::regex_match(name_to_add, name_match)) {
            std::cout << "Good!";
        } else {
            std::cout << "The name doesn't match a proper name!" << std::endl;
        }
    } while (program_state.is_name_active());
}

void interface::ask_for_entry_to_delete() {

}

void interface::ask_for_entry_to_edit() {

}