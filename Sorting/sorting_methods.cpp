//
// Created by stephen on 16/03/18.
//

#include "sorting_methods.h"

sorting_methods::sorting_methods()=default;

sorting_methods::~sorting_methods() {
    delete original_array;
}

void sorting_methods::makearray(int array_size) {
    srand((unsigned int) time(nullptr));
    original_array = new int[array_size];
    for(int i = 0; i < array_size; i++) {
        random_number = (rand() % 32767) + 1;
        original_array[i] = random_number;
    }
    //returnarray(original_array, array_size);
}

void sorting_methods::bubblesort(int size) {
    for(int i = 0; i < size; i++) {
        original_array[i] = 0;
    }
    returnarray(original_array, size);
}

void sorting_methods::selectionsort(int *passed_array) {

}

void sorting_methods::insertionsort(int *passed_array) {

}

void sorting_methods::shellsort(int *passed_array) {

}

void sorting_methods::mergesort(int *passed_array) {

}

void sorting_methods::quicksort(int *passed_array) {

}

void sorting_methods::returnarray(int *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        std::cout << array[i] << " ";
    }
}

sorting_methods::sorting_methods(const sorting_methods &curr) {
    this->original_array = new int[array_size];
}

sorting_methods::sorting_methods(int arraysize) {
    arraysize = array_size;
}
