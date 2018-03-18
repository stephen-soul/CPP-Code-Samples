//
// Created by Stephen Fetinko
//

#ifndef SORTING_INTERFACE_H
#define SORTING_INTERFACE_H
#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include "sorting_methods.h"

class user_interface {
 public:
  user_interface();
  ~user_interface();
  void introduction();
  int *original_array;
  int *array_to_sort;
  int random_number;
 private:
  std::string requested_numbers;
  int array_size;
  bool asking_for_array_size;
};


#endif //SORTING_INTERFACE_H
