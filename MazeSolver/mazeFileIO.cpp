/*
 * MAZE SOLVER - STEPHEN FETINKO 2018
 */

#include "mazeFileIO.h"

// Constructor
mazeFileIO::mazeFileIO() {
    mazeName = "";
    numberOfLines = 0;
    lineToRead = "";
    widthOfMaze = 0;
}

// Destructor
mazeFileIO::~mazeFileIO() {
    delete returnedMaze;
};

// Opens the file based on the selected number
void mazeFileIO::selectMaze(int i) {
    switch(i) {
        case 1:
            drawMaze("maze.txt");
            break;
        case 2:
            drawMaze("maze2.txt");
            break;
        case 3:
            drawMaze("maze3.txt");
            break;
        case 4:
            drawMaze("maze4.txt");
            break;
        default:
            break;
    }
}

// Draw maze - append to array
void mazeFileIO::drawMaze(std::string maze) {
    std::ifstream mazeToOpen(maze);
    if(mazeToOpen.is_open()) {
        while(getline(mazeToOpen, lineToRead)) {
            widthOfMaze = lineToRead.length();
            ++numberOfLines;
        }
        mazeToOpen.clear();
        mazeToOpen.seekg(0, std::ios::beg);
        returnedMaze = new std::string*[numberOfLines];
        for( int x = 0; x < numberOfLines; ++x)
            returnedMaze[x] = new std::string[widthOfMaze];
        for(int x = 0; x < numberOfLines; x++) {
            getline(mazeToOpen, lineToRead);
            for(unsigned o = 0; o < widthOfMaze; o++) {
                returnedMaze[x][o] = lineToRead.at(o);
                std::cout << returnedMaze[x][o];
            }
            std::cout << std::endl;
        }
        std::cout << "The maze is " << widthOfMaze << " wide and " << numberOfLines << " lines tall." << std::endl;
        mazeToOpen.close();
    }
}
