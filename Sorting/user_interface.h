//
// Created by Stephen
//

#ifndef SORTING_INTERFACE_H
#define SORTING_INTERFACE_H
#include <iostream>
#include <string>

class user_interface {
 public:
  user_interface();
  ~user_interface();
  void Introduction();
 private:
  std::string requested_numbers;
  int array_size;

};


#endif //SORTING_INTERFACE_H
