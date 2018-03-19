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
    asking_for_reg_or_external = true;
}

user_interface::~user_interface() {
    delete original_array;
}

void user_interface::introduction() {
    std::regex digit_check("^[0-9]+");
    do {
        std::cout << "Welcome user. How many numbers are we sorting?\n>> ";
        std::getline(std::cin, requested_numbers);
        if(std::regex_match(requested_numbers, digit_check)) {
            if(requested_numbers[0] == '0') {
                std::cout << "Invalid input\n\n";
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
                std::cout << "Sorting..." << std::endl << std::endl;
                //original->returnarray(original_array, array_size);
                switch(sort_choice) {
                    case 1: {
                        auto *bubble = new sorting_methods(array_size);
                        bubble->bubblesort(original_array, array_size);
                        if(array_size <= 1000) {
                            bubble->writetofile(bubble->new_array, array_size, 1);
                            std::cout << "Done. Results are logged in cmake-build-debug folder." << std::endl;
                        }
                        else
                            bubble->tracktime();
                        delete bubble;
                        break;
                    } case 2: {
                        auto *selection = new sorting_methods(array_size);
                        selection->selectionsort(original_array, array_size);
                        if(array_size <= 1000) {
                            selection->writetofile(selection->new_array, array_size, 2);
                            std::cout << "Done. Results are logged in cmake-build-debug folder." << std::endl;
                        }
                        else
                            selection->tracktime();
                        delete selection;
                        break;
                    } case 3: {
                        auto *insertion = new sorting_methods(array_size);
                        insertion->insertionsort(original_array, array_size);
                        if(array_size <= 1000) {
                            insertion->writetofile(insertion->new_array, array_size, 3);
                            std::cout << "Done. Results are logged in cmake-build-debug folder." << std::endl;
                        }
                        else
                            insertion->tracktime();
                        delete insertion;
                        break;
                    } case 4: {
                        auto *shell = new sorting_methods(array_size);
                        shell->shellsort(original_array, array_size);
                        if(array_size <= 1000) {
                            shell->writetofile(shell->new_array, array_size, 4);
                            std::cout << "Done. Results are logged in cmake-build-debug folder." << std::endl;
                        }
                        else
                            shell->tracktime();
                        delete shell;
                        break;
                    } case 5: {
                        auto *merge = new sorting_methods(array_size);
                        merge->startmergesort(original_array, array_size);
                        if(array_size <= 1000) {
                            merge->writetofile(merge->new_array, array_size, 5);
                            std::cout << "Done. Results are logged in cmake-build-debug folder." << std::endl;
                        }
                        else
                            merge->tracktime();
                        delete merge;
                        break;
                    } case 6: {
                        auto *quick = new sorting_methods(array_size);
                        quick->startpartition(original_array, array_size);
                        if(array_size <= 1000) {
                            quick->writetofile(quick->new_array, array_size, 6);
                            std::cout << "Done. Results are logged in cmake-build-debug folder." << std::endl;
                        }
                        else
                            quick->tracktime();
                        delete quick;
                        break;
                    }
                    default:
                        break;
                }
                //original->returnarray(original_array, array_size);
                delete original;
                break;
            }
        } else {
            std::cout << "Invalid input\n\n";
            continue;
        }
    } while(asking_for_array_size);
}
