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
        delete maze;
    } while(askingForMaze);
}

// Handles the program running
void interface::programRun() {
    do {
        std::regex restartChoice("^[1-2]");
        bool askingForRestart = true;
        introduction();
        if(choice == "5") {
            cout << "Thank you. Good bye." << std::endl;
            running = false;
            break;
        }
        choice = "";
        while(askingForRestart) {
            cout << "\nWould you like to run through another maze?\n(1) Yes\n(2) No\n>> ";
            getline(std::cin, choice);
            if(std::regex_match(choice, restartChoice)) {
                int newChoice = stoi(choice);
                switch(newChoice) {
                    case 1:
                        askingForRestart = false;
                        break;
                    case 2:
                        cout << "\nThank you, have a good day." << std::endl;
                        running = false;
                        askingForRestart = false;
                        break;
                    default:
                        break;
                }
            } else {
                cout << "\nPlease enter a proper input\n";
            }
        }
    } while(running);
}