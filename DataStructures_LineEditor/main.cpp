/*
 * DATA STRUCTURES LINE EDITOR // STEPHEN FETINKO 2018
 */

#include "Editor.h"
#include <algorithm>
#include <regex>

// Make a variable for user input
std::string userInput;
std::string newLine;
std::string selectedInput;

// Set the main function to take in arguments
int main(int argc, char *argv[]) {
    // If we make it here, make the file name argument 1 and new file argument 2
    std::string fileName = argv[1];
    std::string newFile = argv[2];
    // Make a bool for the editor running
    bool running = true;
    // Make a note of the line number
    int currentLineNumber = 1;
    // If there are not 3 arguments, then tell the user and close. Else, proceed
    if (argc != 3) {
        std::cout << "The program must be the program name followed by the file name and new file name.\n"
                "e.g.\"PROGRAM NAME\" \"FILE TO EDIT\" \"NEW FILE\". Please try again" << std::endl;
        system("pause");
    } else {
        // While the editor is running, do this
        while (running) {
            // Make regex for digits
            std::regex digitCheck("[0-9]+");
            // Make the screen appealing
            std::cout << "\n\t    CPP LINE EDITOR\n----------------------------------------\n\n";
            // Now make an editor object and pass the file name
            Editor editor;
            editor.readFromFile(fileName);
            std::cout << "Please type a command (or help for help)\n\nCurrent line number: " << currentLineNumber << "\n" << ">> ";
            // Get user input and then stringstream it to parse it properly, make the first word lowercase and then dump it into a string array
            getline(std::cin, userInput);
            // Int for the while loop below
            int i = 0;
            std::string userChoice[3];
            std::stringstream splitInput(userInput);
            std::transform(userChoice[0].begin(), userChoice[0].end(), userChoice[0].begin(), ::tolower);
            while (splitInput.good() && i < 3) {
                splitInput >> userChoice[i];
                ++i;
            }
            if (userChoice[0] == "help") {
                // If the user types help, go to help
                system("cls");
                editor.displayHelpScreen();
                std::cout << std::endl << std::endl;
                system("pause");
                system("cls");
                continue;
            } else if (userChoice[0] == "i") {
                // If the user types i, check the second value.
                if (userChoice[1] == "0") {
                    std::cout << "Please enter a number greater than 0\n\n";
                    system("pause");
                    system("cls");
                } else if (std::regex_match(userChoice[1], digitCheck)) {
                    // If the second digit matches 1-9 do this
                    system("cls");
                    std::cout << "Please enter the new line for line " << userChoice[1] << "\n\n>> ";
                    getline(std::cin, newLine);
                    // Turn the user input into an int and pass it
                    selectedInput = userChoice[1];
                    int lineToInsertInto = std::stoi(selectedInput);
                    editor.insertIntoBuffer(lineToInsertInto, newLine);
                    system("pause");
                    system("cls");
                } else if (userChoice[1].empty()) {
                    // If there is no second digit do this

                } else {
                    // Else do this
                    std::cout << "\n\nPlease enter a proper command. Thank you0\n\n.";
                    system("pause");
                    system("cls");
                    continue;
                }

            } else if (userChoice[0] == "i") {

            } else if (userChoice[0] == "i") {

            } else if (userChoice[0] == "i") {

            } else if (userChoice[0] == "i") {

            } else if (userChoice[0] == "i") {

            } else if (userChoice[0] == "v") {
                // If the user types quit, then quit
                system("cls");
                std::cout << "Here are the lines in the buffer\n\n";
                editor.displayLinesWithLineNumber();
                std::cout << "\n";
                system("pause");
                system("cls");
            } else if (userChoice[0] == "q") {
                // If the user types quit, then quit
                std::cout << "Have a lovely day.";
                running = false;
            } else {
                // Else, re-ask for input
                std::cout << "Please enter proper input";
                std::cout << std::endl << std::endl;
                system("pause");
                system("cls");
                continue;
            }
        }
    }
    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}// End of main