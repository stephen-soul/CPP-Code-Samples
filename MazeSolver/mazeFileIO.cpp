/*
 * MAZE SOLVER - STEPHEN FETINKO 2018
 */

#include "mazeFileIO.h"
#include "stack.h"

// Constructor
mazeFileIO::mazeFileIO() {
    mazeName = "";
    numberOfLines = 0;
    lineToRead = "";
    widthOfMaze = 0;
    solved = false;
    mazeRow = 0;
    mazeColumn = 0;
    fileName = "";
}

// Destructor
mazeFileIO::~mazeFileIO() {
    delete returnedMaze;
};

// Opens the file based on the selected number
void mazeFileIO::selectMaze(int i) {
    fileName = "";
    switch(i) {
        case 1:
            fileName = "maze";
            makeMaze(fileName+".txt");
            break;
        case 2:
            fileName = "maze2";
            makeMaze(fileName+".txt");
            break;
        case 3:
            fileName = "maze3";
            makeMaze(fileName+".txt");
            break;
        case 4:
            fileName = "maze4";
            makeMaze(fileName+".txt");
            break;
        case 5:
            fileName = "mazex";
            makeMaze(fileName+".txt");
            break;
        default:
            break;
    }
}

// Draw maze - append to array
void mazeFileIO::makeMaze(std::string maze) {
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
            }
        }
        std::cout << "The maze is " << widthOfMaze << " wide and " << numberOfLines << " lines tall." << std::endl;
        mazeToOpen.close();
        // Solve maze
        solveMaze(returnedMaze);
    }
}

void mazeFileIO::drawMaze(std::string **maze) {
    // The maze is kind of backwards. [1][0] will fill in the first spot
    for(int x = 0; x < numberOfLines; x++) {
        for(unsigned o = 0; o < widthOfMaze; o++) {
            if(maze[x][o] == "Z")
                std::cout << " ";
            else
                std::cout << maze[x][o];
        }
        std::cout << std::endl;
    }
}

void mazeFileIO::solveMaze(std::string **maze) {
    auto *stackRow = new stack();
    auto *stackColumn = new stack();
    // Initialize values
    mazeRow = 1;
    mazeColumn = 0;
    stackRow->Push(mazeRow);
    stackColumn->Push(mazeColumn);
    maze[mazeRow][mazeColumn] = "X";
    do {
        if(mazeRow == numberOfLines-2 && mazeColumn == widthOfMaze-2) {
            // Maze solved check
            solved = true;
        }
        if(maze[mazeRow][mazeColumn+1] == " ") {
           // If right is available do this
           mazeColumn+=1;
           maze[mazeRow][mazeColumn] = "X";
           stackColumn->Push(mazeColumn);
           stackRow->Push(mazeRow);
           continue;
        } else if(maze[mazeRow+1][mazeColumn] == " ") {
           // Else if down is available do this
           mazeRow+=1;
           maze[mazeRow][mazeColumn] = "X";
           stackColumn->Push(mazeColumn);
           stackRow->Push(mazeRow);
           continue;
        } if(maze[mazeRow][mazeColumn-1] == " ") {
           // Else if left is available do this
           mazeColumn-=1;
           maze[mazeRow][mazeColumn] = "X";
           stackColumn->Push(mazeColumn);
           stackRow->Push(mazeRow);
           continue;
        } else if(maze[mazeRow-1][mazeColumn] == " ") {
           // Else if up is available do this
           mazeRow-=1;
           maze[mazeRow][mazeColumn] = "X";
           stackColumn->Push(mazeColumn);
           stackRow->Push(mazeRow);
           continue;
        }
        if(maze[mazeRow][mazeColumn] != " ") {
            mazeRow = stackRow->Peek();
            mazeColumn = stackColumn->Peek();
            stackColumn->Pop();
            stackRow->Pop();
            maze[mazeRow][mazeColumn] = "Z";
        }
    } while(!solved);
    drawMaze(maze);
    writeMaze(fileName);
}

void mazeFileIO::writeMaze(std::string mazeName) {
    // Open up an ofstream to make the new file
    std::ofstream newFile(mazeName + "solved.txt");
    if(newFile.is_open()) {
        for(int x = 0; x < numberOfLines; x++) {
            for(unsigned o = 0; o < widthOfMaze; o++) {
                if(returnedMaze[x][o] == "Z")
                    newFile << " ";
                else
                    newFile << returnedMaze[x][o];
            }
            newFile << "\n";
        }
    } else {
        // If it somehow fails (maybe read/write access issues) tell the user
        std::cout << "Unable to open file\n\n";
    }
    newFile.close();
}


