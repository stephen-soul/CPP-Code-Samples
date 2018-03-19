//
// Created by Stephen Fetinko
//

#include "user_interface.h"

user_interface::user_interface() {
    requested_numbers = "";
    requested_sort = "";
    array_size = 0;
    sort_choice = 0;
    asking_for_array_size = true;
    asking_for_sort_type = true;
}

user_interface::~user_interface() {
    delete original_array;
}

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
                do {
                    std::regex digit_check_two("^[1-6]");
                    std::cout << "\nWhich type of sort would you like?\n"
                            "(1) Bubble\n(2) Selection\n(3) Insertion\n(4) Shell\n"
                            "(5) Merge\n(6) Quick\n>> ";
                    std::getline(std::cin, requested_sort);
                    if(std::regex_match(requested_sort, digit_check_two)) {
                        sort_choice = std::stoi(requested_sort);
                        break;
                    } else {
                        std::cout << "Please enter a choice listed." << std::endl;
                        continue;
                    }
                } while(asking_for_sort_type);
                auto *original = new sorting_methods();
                std::cout << "Original" << std::endl;
                original->returnarray(original_array, array_size);
                switch(sort_choice) {
                    case 1: {
                        auto *bubble = new sorting_methods(array_size);
                        std::cout << "\nBubble sort" << std::endl;
                        bubble->bubblesort(original_array, array_size);
                        bubble->returnarray(bubble->new_array, array_size);
                        bubble->writetofile(bubble->new_array, array_size, 1);
                        delete bubble;
                        break;
                    } case 2: {
                        auto *selection = new sorting_methods(array_size);
                        std::cout << "\nSelection sort" << std::endl;
                        selection->selectionsort(original_array, array_size);
                        selection->returnarray(selection->new_array, array_size);
                        selection->writetofile(selection->new_array, array_size, 2);
                        delete selection;
                        break;
                    } case 3: {
                        auto *insertion = new sorting_methods(array_size);
                        std::cout << "\nInsertion method" << std::endl;
                        insertion->insertionsort(original_array, array_size);
                        insertion->returnarray(insertion->new_array, array_size);
                        delete insertion;
                        break;
                    } case 4: {
                        auto *shell = new sorting_methods(array_size);
                        std::cout << "\nShell sort" << std::endl;
                        shell->shellsort(original_array, array_size);
                        shell->returnarray(shell->new_array, array_size);
                        delete shell;
                        break;
                    } case 5: {
                        auto *merge = new sorting_methods(array_size);
                        std::cout << "\nMerge sort" << std::endl;
                        merge->startmergesort(original_array, array_size);
                        merge->returnarray(merge->new_array, array_size);
                        delete merge;
                        break;
                    } case 6: {
                        auto *quick = new sorting_methods(array_size);
                        std::cout << "\nQuick sort" << std::endl;
                        quick->startpartition(original_array, array_size);
                        quick->returnarray(quick->new_array, array_size);
                        delete quick;
                        break;
                    }
                    default:
                        break;
                }
                std::cout << "\nAnd the original again" << std::endl;
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
