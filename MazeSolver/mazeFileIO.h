/*
 * MAZE SOLVER - STEPHEN FETINKO 2018
 */

#ifndef MAZESOLVER_MAZEFILEIO_H
#define MAZESOLVER_MAZEFILEIO_H

#include "userInterface.h"

class mazeFileIO {
public:
    // Constructor & Destructor
    mazeFileIO();
    ~mazeFileIO();
    // Functions
    void openFile(int i);
private:
    // String for maze name
    std::string mazeName;
    // Int for switch case deciding which maze to open
    int selectedMaze;
    // Dynamic array
    std::string returnedMaze;
};


#endif //MAZESOLVER_MAZEFILEIO_H
