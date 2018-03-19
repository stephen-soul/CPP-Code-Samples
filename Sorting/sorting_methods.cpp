//
// Created by stephen on 16/03/18.
//
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

void sorting_methods::selectionsort(int *array, int size) {
    for(int i = 0; i < size; i++) {
        this->new_array[i] = array[i];
    }
    int inner, outer, min;
    for (outer = 0; outer < size - 1; outer++) {
        min = outer;
        for (inner = outer + 1; inner < size; inner++) {
            if (new_array[inner] < new_array[min]) {
                min = inner;
            }
        }
        int temp = new_array[outer];
        new_array[outer] = new_array[min];
        new_array[min] = temp;
    }
}

void sorting_methods::insertionsort(int *array, int size) {
    for(int i = 0; i < size; i++) {
        this->new_array[i] = array[i];
    }
    int i, j, temp;
    for (i = 1; i < size; i++) {
        j = i;
        while (j > 0 && new_array[j-1] > new_array[j]) {
            temp = new_array[j];
            new_array[j] = new_array[j-1];
            new_array[j-1] = temp;
            j--;
        }
    }
}

void sorting_methods::shellsort(int *array, int size) {
    for(int i = 0; i < size; i++) {
        this->new_array[i] = array[i];
    }
    int i, j, increment;
    for (increment = size/2; increment > 0; increment /= 2) {
        for (i = increment; i < size; i++) {
            int temp = new_array[i];
            for (j = i; j >= increment; j -= increment) {
                if (temp < new_array[j-increment]) {
                    new_array[j] = new_array [j-increment];
                } else {
                    break;
                }
            }
            new_array[j] = temp;
        }
    }
}

void sorting_methods::startmergesort(int *array, int size) {
    for(int i = 0; i < size; i++) {
        this->new_array[i] = array[i];
    }
    mergesort(new_array, 0, size-1);
}

void sorting_methods::mergesort(int *array, int left, int right) {
    if (left < right) {
        int middle = left+(right-left)/2;
        mergesort(array, left, middle);
        mergesort(array, middle+1, right);
        merge(array, left, middle, right);
    }
}

void sorting_methods::merge(int *array, int left, int middle, int right) {
    int x, y, z;
    int firsthalf = middle - left + 1;
    int secondhalf = right - middle;
    // Make a temp array
    int Left[firsthalf], Right[secondhalf];

    for (x = 0; x < firsthalf; x++) {
        Left[x] = array[left + x];
    }
    for(y = 0; y < secondhalf; y++) {
        Right[y] = array[middle + 1 + y];
    }
    x = 0;
    y = 0;
    z = left;
    while(x < firsthalf && y < secondhalf) {
        if(Left[x] <= Right[y]) {
            array[z] = Left[x];
            x++;
        } else {
            array[z] = Right[y];
            y++;
        }
        z++;
    }
    while (x < firsthalf) {
        array[z] = Left[x];
        x++;
        z++;
    }
    while (y < secondhalf) {
        array[z] = Right[y];
        y++;
        z++;
    }
}

void sorting_methods::swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sorting_methods::startpartition(int *array, int size) {
    for(int i = 0; i < size; i++) {
        this->new_array[i] = array[i];
    }
    quicksort(new_array, 0, size-1);
}

int sorting_methods::partitionforquicksort(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int x = low; x <= high-1; x++) {
        if(array[x] <= pivot) {
            i++;
            swap(&array[i], &array[x]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void sorting_methods::quicksort(int *array, int low, int high) {
    if (low < high) {
        // Pi is partition index
        int pi = partitionforquicksort(array, low, high);
        // Separetely sort elements before and after
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
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