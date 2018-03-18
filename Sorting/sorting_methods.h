//
// Created by stephen on 16/03/18.
//

#ifndef SORTING_SORTING_METHODS_H
#define SORTING_SORTING_METHODS_H
#include <iostream>
#include <string>

class sorting_methods {
 public:
  sorting_methods();
  sorting_methods(int arraysize);
  sorting_methods(const sorting_methods &curr);
  ~sorting_methods();
  void returnarray(int *array, int array_size);
  void makearray(int arraysize);
  void bubblesort(int *array, int size);
  void selectionsort(int *passed_array);
  void insertionsort(int *passed_array);
  void shellsort(int *passed_array);
  void mergesort(int *passed_array);
  void quicksort(int *passed_array);
  int *new_array;
  int *sorted_array;
  int random_number;
  int array_size;
  bool ordered;
};


#endif //SORTING_SORTING_METHODS_H
