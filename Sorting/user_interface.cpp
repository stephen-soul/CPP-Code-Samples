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
                srand((unsigned int) time(nullptr));
                original_array = new int[array_size];
                for(int i = 0; i < array_size; i++) {
                    random_number = (rand() % 32767) + 1;
                    original_array[i] = random_number;
                }
                auto *original = new sorting_methods();
                std::cout << "Original" << std::endl;
                original->returnarray(original_array, array_size);
                auto *bubble = new sorting_methods(array_size);
                std::cout << "\nBubble" << std::endl;
                bubble->bubblesort(original_array, array_size);
                bubble->returnarray(bubble->new_array, array_size);
                std::cout << "\nBack to original" << std::endl;
                delete bubble;
                original->returnarray(original_array, array_size);
                delete original;
                break;
            }
        } else {
            std::cout << "Bad\n\n";
            continue;
        }
    } while(asking_for_array_size);
}
