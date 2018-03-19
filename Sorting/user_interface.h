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
  void externalmergesort();
  int *original_array;
  int *array_to_sort;
  int random_number;
 private:
  std::string requested_numbers;
  std::string reg_or_external;
  int array_size;
  int sort_choice;
  bool run_external_merge;
  bool asking_for_reg_or_external;
  bool asking_for_array_size;
  bool asking_for_sort_type;
  bool log_time;
  std::string requested_sort;
};


#endif //SORTING_INTERFACE_H
