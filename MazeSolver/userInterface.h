/*
 * MAZE SOLVER - STEPHEN FETINKO 2018
 */

#ifndef MAZESOLVER_INTERFACE_H
#define MAZESOLVER_INTERFACE_H
#include <iostream>
#include <string>
#include <regex>
#include "mazeFileIO.h"

class interface {
public:
    // Constructor and Destructor
    interface();
    ~interface();
    // Functions
    void introduction();
    void programRun();
    // Variables
    std::string choice;
    int selectedMaze;
    bool askingForMaze;
    bool running;
};


#endif //MAZESOLVER_INTERFACE_H
