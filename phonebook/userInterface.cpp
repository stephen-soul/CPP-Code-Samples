#include "userInterface.h"
#include <iostream>

using std::cout;
using std::endl;

interface::interface() {
    // Constructor initializes variables
    main_menu_input = false;
    menu_choice = "";
}

interface::~interface() = default;

void interface::main_menu() {
    // Make a regex statement to specifically get number input from the user
    std::regex digit_check("^[1-3]");
    do {
        cout << "Welcome to the phonebook ver. 1.0" << endl;
        cout << "(1) View registry" << endl;
        cout << "(2) Edit entry" << endl;
        cout << "(3) Delete entry" << endl;
        cout << ">> ";
        getline(std::cin, menu_choice);
        if(std::regex_match(menu_choice, digit_check)) {

        } else
            clear_screen();
    } while (!main_menu_input);
}

void interface::clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}
