//
// Created by stephen on 16/03/18.
//

#ifndef SORTING_SORTING_METHODS_H
#define SORTING_SORTING_METHODS_H
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <ctime>
#include <sstream>


class sorting_methods {
 public:
  sorting_methods();
  sorting_methods(int arraysize);
  sorting_methods(const sorting_methods &curr);
  ~sorting_methods();
  void returnarray(int *array, int array_size);
  void makearray(int arraysize);
  void bubblesort(int *array, int size);
  void selectionsort(int *array, int size);
  void insertionsort(int *array, int size);
  void shellsort(int *array, int size);
  void startmergesort(int *array, int size);
  void mergesort(int *array, int left, int right);
  void merge(int *array, int left, int middle, int right);
  void swap(int *a, int *b);
  void startpartition(int *array, int size);
  int partitionforquicksort(int *array, int low, int high);
  void quicksort(int *array, int low, int high);
  void writetofile(int *array, int size, int sorttype);
  void startclock();
  void endclock();
  void tracktime();
  int *new_array;
  int *sorted_array;
  int random_number;
  int array_size;
  std::string end_time;
  bool ordered;
  std::clock_t start;
};


#endif //SORTING_SORTING_METHODS_H
