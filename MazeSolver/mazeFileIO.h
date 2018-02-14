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
    void makeMaze(std::string maze);
    void drawMaze(std::string** maze);
    void solveMaze(std::string** maze);
    void writeMaze(std::string mazeName);
    std::string **returnedMaze;
    std::string mazeName;
private:
    int numberOfLines;
    long widthOfMaze;
    std::string lineToRead;
    std::string fileName;
    bool solved;
    int mazeRow;
    int mazeColumn;
};


#endif //MAZESOLVER_MAZEFILEIO_H
