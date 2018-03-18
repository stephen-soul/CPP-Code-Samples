//
// Created by Stephen Fetinko
//

#include "user_interface.h"

user_interface::user_interface() {
    requested_numbers = "";
    array_size = 0;
    asking_for_array_size = true;
}

user_interface::~user_interface()=default;

void user_interface::introduction() {
    std::regex digit_check("^[0-9]+");
    do {
        requested_numbers = "";
        std::cout << "Welcome user. How many numbers are we sorting?\n>> ";
        std::getline(std::cin, requested_numbers);
        if(std::regex_match(requested_numbers, digit_check)) {
            if(requested_numbers[0] == '0') {
                std::cout << "Bad\n\n";
                continue;
            } else {
                array_size = std::stoi(requested_numbers);
                auto *original = new sorting_methods();
                std::cout << "Original" << std::endl;
                original->makearray(array_size);
                for(int i = 0; i < array_size; i++) {
                    std::cout << original->original_array[i] << " ";
                }
                auto *bubble = new sorting_methods(*original);
                std::cout << "Bubble" << std::endl;
                bubble->bubblesort(array_size);
                std::cout << "Back to original" << std::endl;
                for(int i = 0; i < array_size; i++) {
                    std::cout << original->original_array[i] << " ";
                }
                delete original;
                break;
            }
        } else {
            std::cout << "Bad\n\n";
            continue;
        }
    } while(asking_for_array_size);
}
