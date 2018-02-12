/*
 * MAZE SOLVER - STEPHEN FETINKO 2018
 */

#ifndef MAZESOLVER_MAZEFILEIO_H
#define MAZESOLVER_MAZEFILEIO_H

#include "userInterface.h"
#include <fstream>

class mazeFileIO {
public:
    // Constructor & Destructor
    mazeFileIO();
    ~mazeFileIO();
    // Functions
    void selectMaze(int i);
    void drawMaze(std::string maze);
    std::string **returnedMaze;
    std::string mazeName;
private:
    int numberOfLines;
    long widthOfMaze;
    std::string lineToRead;
};


#endif //MAZESOLVER_MAZEFILEIO_H
