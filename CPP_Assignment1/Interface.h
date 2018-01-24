/**
 * INTERFACE HEADER
 */

#ifndef CPP_ASSIGNMENT1_INTERFACE_H
#define CPP_ASSIGNMENT1_INTERFACE_H
#include "UnixExtras.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ostream>
#include <fstream>

class Interface {
public:
    // Constructor
    Interface();

    // Functions
    bool openFile(std::string fileName);
private:

};


#endif //CPP_ASSIGNMENT1_INTERFACE_H