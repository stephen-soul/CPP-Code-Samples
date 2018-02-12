/*
 * MAZE SOLVER - STEPHEN FETINKO 2018
 */

#include "userInterface.h"

using std::cout;

interface::interface() {
    choice = "";
    selectedMaze = 0;
    askingForMaze = true;
    running = true;
}

interface::~interface() {
    choice = "";
    selectedMaze = 0;
}

// Welcome the user to the program and get the maze they want
void interface::introduction() {
    // Object for mazeFileIO class
    mazeFileIO *maze = new mazeFileIO;
    // Regex for the choice validation
    std::regex digitCheck("^[1-5]");
    // Do while asking for input for user validation
    do {
        cout << "Welcome to the maze solver. Please select "
                "an option below (1-5)\n"
                "(1) Maze 1\n(2) Maze 2\n(3) Maze 3\n(4) Maze 4\n(5) Exit\n"
                ">> ";
        getline(std::cin, choice);
        // If the input is 1-5
        if(std::regex_match(choice, digitCheck)) {
            // If the number is 5, close the program
            if(choice == "5") {
                cout << "Thank you. Good bye." << std::endl;
                askingForMaze = false;
            } else {
                // Else pass the 1-4 value to the maze selector class
                cout << "Proper input. Thank you. Have a maze." << std::endl;
                selectedMaze = stoi(choice);
                maze->selectMaze(selectedMaze);
                askingForMaze = false;
            }
        } else {
            // Else if the input is NOT 1-5, inform them and ask again
            cout << "Please ensure you enter a number 1 - 4" << std::endl << std::endl;
            continue;
        }
    } while(askingForMaze);
}

void interface::programRun() {
    do {
        introduction();
        if(choice == "5")
            running = false;
    } while(running);
}