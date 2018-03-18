//
// Created by stephen on 16/03/18.
//

#include "sorting_methods.h"

sorting_methods::sorting_methods() {
    ordered = false;
}

sorting_methods::~sorting_methods()=default;

void sorting_methods::makearray(int array_size) {
    srand((unsigned int) time(nullptr));
    new_array = new int[array_size];
    for(int i = 0; i < array_size; i++) {
        random_number = (rand() % 32767) + 1;
        new_array[i] = random_number;
    }
    //returnarray(original_array, array_size);
}

void sorting_methods::bubblesort(int *array, int size) {
    for(int i = 0; i < size; i++) {
        this->new_array[i] = array[i];
    }
    int inner, outer;
    for (outer = size - 1; outer > 0; outer--) {
        for (inner = 0; inner < outer; inner++) {
            if (new_array[inner] > new_array[inner + 1]) {
                int temp = new_array[inner];
                new_array[inner] = new_array[inner + 1];
                new_array[inner + 1] = temp;
            }
        }
    }
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
    this->new_array = new int[array_size];
}

sorting_methods::sorting_methods(int arraysize) {
    this->array_size = arraysize;
    this->new_array = new int[array_size];
    //this->original_array = array;
}
