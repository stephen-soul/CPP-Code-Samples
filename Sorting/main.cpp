//
// Created by Stephen Fetinko
//

#include "user_interface.h"

int main() {
    user_interface user;
    bool choosing_mode = true;
    std::string user_choice;
    std::regex choice_validation("^[1-2]");
    do {
        std::cout << "Welcome to the sorter. Would you like to...\n"
                "(1) Run the original sorter, choosing your own sorting method\n"
                "(2) Run the external merge sort on a text file\n>> ";
        std::getline(std::cin, user_choice);
        if(std::regex_match(user_choice, choice_validation)) {
            if(user_choice == "1") {
                user.introduction();
                choosing_mode = false;
            } else {
                user.externalmergesort();
                choosing_mode = false;
            }
        } else
            continue;
    } while (choosing_mode);
    return 0;
}