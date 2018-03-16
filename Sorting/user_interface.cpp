//
// Created by Stephen
//

#include "user_interface.h"

user_interface::user_interface() {
    user_choice = "";
}

user_interface::~user_interface()=default;

void user_interface::Introduction() {
    std::cout << "Welcome user. How many numbers are we sorting?\n>> ";

}
