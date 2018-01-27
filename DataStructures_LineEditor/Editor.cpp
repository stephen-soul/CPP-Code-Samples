/*
 * DATA STRUCTURES LINE EDITOR // STEPHEN FETINKO 2018
 */

#include "Editor.h"

Editor::Editor() {
    running = true;
    currentLineNumber = 1;
}

Editor::~Editor() {

}

bool Editor::readFromFile(std::string fileName) {
    // Use an ifstream to try to open a file
    file.open(fileName);
    if (file.fail()) {
        std::cout << "Could not open file. Please try again later or try a different file.";
        return false;
    } else {
        while (getline(file, line)) {
            linkedList.add(line);
        }
        file.close();
    }
    return true;
}

void Editor::displayHelpScreen() {
    std::cout << "\nHere are a list of known commands."
            "\nTo start, You may type I followed by a number to insert on that line number."
            "\nIf I is not followed by a number you will insert on the previous line."
            "\nYou may type D to delete the current line."
            "\nAlternately D may be followed by a specific line number,"
            "\nOr D can be followed by a range of numbers. i.e 3-5 deleting"
            "\nLine 3 through 5. V may display entire sets of lines in the buffer."
            "\nG goes to the beginning of the buffer, or you may choose one."
            "\nL lists the lines of the buffer using the same numbering system as the delete."
            "\nS substitutes a new line entered by the user for the current line in the buffer or"
            "\na specified line number. You will be prompted for a new line."
            "\nE specifies exiting and saving.";
}

void Editor::displayLinesWithLineNumber() {
    if(linkedList.getSizeOfList() > 0) {
        std::cout << "Here are the lines in the buffer\n\n";
        linkedList.display();
    } else {
        std::cout << "There are no more lines in the buffer!\n\n";
    }
}

void Editor::insertIntoBuffer(int i, std::string newValue) {
    if(i == 1) {
        linkedList.insertAtStart(newValue);
    } else {
        if(i > linkedList.getSizeOfList()) {
            // If i is greater than the size of the list add it to the end
            linkedList.insertAtEnd(newValue);
        } else {
            linkedList.addToPosition(i, newValue);
        }
    }
}

void Editor::askUserForInput(std::string newFile) {
    while (running) {
        // Make regex for digits
        std::regex digitCheck("^[1-9][0-9]*");
        // Check the size of the list
        if(linkedList.getSizeOfList() > 0) {
            // Make the screen appealing
            std::cout << "\n----------------------------------------\n\t    "
                    "CPP LINE EDITOR\n----------------------------------------\n\n";
            // Now make an editor object and pass the file name
            std::cout << "Please type a command (or help for help)\n\nCurrent line number: " << currentLineNumber << "\n"
                      << ">> ";
        } else {
            // Make the screen appealing
            std::cout << "\n----------------------------------------\n\t    "
                    "CPP LINE EDITOR\n----------------------------------------\n\n";
            // Now make an editor object and pass the file name
            std::cout << "Please type a command (or help for help)\n\nCurrent line number: NOTHING. EMPTY BUFFER WARNING." << "\n"
                      << ">> ";
        }
        // Get user input and then stringstream it to parse it properly, make the head word lowercase and then dump it into a string array
        getline(std::cin, userInput);
        // Int for the while loop below
        int i = 0;
        // Make an array for user input (only keeping track of 3 arguments [command, arg1, arg2])
        std::string userChoice[3];
        // Make a string stream for the input
        std::stringstream splitInput(userInput);
        // Transform the argument into lowercase
        std::transform(userChoice[0].begin(), userChoice[0].end(), userChoice[0].begin(), ::tolower);
        // Loop the string stream into the array
        while (splitInput.good() && i < 3) {
            splitInput >> userChoice[i];
            ++i;
        }
        // ------------------------------------------------------------------------------------------------------------
        if (userChoice[0] == "help") {
            // If the user types help, go to help
            displayHelpScreen();
            std::cout << std::endl << std::endl << "Press enter";
            continue;
            // --------------------------------------------------------------------------------------------------------
        } else if (userChoice[0] == "i") {
            // If the user types i, check the second value.
            if (std::regex_match(userChoice[1], digitCheck)) {
                // If the second digit matches 1-9 do this
                int selectedLineNumber = std::stoi(userChoice[1]);
                if(selectedLineNumber <= linkedList.getSizeOfList()) {
                    // If the number of lines is less than the number of lines available, do what they asked
                    std::cout << "Please enter the new line for line " << userChoice[1] << "\n\n>> ";
                    getline(std::cin, newLine);
                    // Pass the value to the buffer and add it
                    insertIntoBuffer(selectedLineNumber, newLine);
                } else {
                    // Else, If the user entered a number greater than the size of the list, tell them
                    std::cout << "That line number exceeds the number of lines available\n\n";
                    continue;
                }
            } else if (userChoice[1].empty()) {
                // If there is no second digit do this
                std::cout << "Please enter a new line for line " << currentLineNumber << "\n\n>> ";
                getline(std::cin, newLine);
                // Pass the current line and the content into the new line
                insertIntoBuffer(currentLineNumber, newLine);
            } else {
                // Else do this
                std::cout << "\n\nPlease enter a proper command. Thank you\n\n.";
                continue;
            }
            // --------------------------------------------------------------------------------------------------------
        } else if (userChoice[0] == "g") {
            if(std::regex_match(userChoice[1], digitCheck)) {
                // If the selected input as long as it matches a digit check and set it to the current line number
                selectedFirstInput = userChoice[1];
                int newCurrentLine = std::stoi(selectedFirstInput);
                if(newCurrentLine <= linkedList.getSizeOfList()) {
                    currentLineNumber = newCurrentLine;
                } else {
                    std::cout << "The number you have entered is more than the number of lines.\n\n";
                    continue;
                }
                continue;
            } else if (!userChoice[2].empty()) {
                // Else if the user types more than the one extra argument, say there's too many
                std::cout << "Too many arguments. Please try again\n\n";
                continue;
            } else if (userChoice[1].empty()){
                // Else get the selected input as long as it matches a digit check and set it to the current line number
                currentLineNumber = 1;
                continue;
            } else {
                // Else the user enters G followed by nothing else, go to line 1
                std::cout << "What you entered does not match what we can do. Please refer to the help screen"
                        " if you're confused.\n\n";
                continue;
            }
            // --------------------------------------------------------------------------------------------------------
        } else if (userChoice[0] == "d") {
            if(userChoice[1].empty()) {
                // If the user enters d and nothing else delete the current line
                deletion(currentLineNumber, 0);
                currentLineNumber--;
            } else if (std::regex_match(userChoice[1], digitCheck) && userChoice[2].empty()) {
                // If the user enters d and a only one number, check that number and then delete it
                selectedFirstInput = userChoice[1];
                int newCurrentLine = std::stoi(selectedFirstInput);
                deletion(newCurrentLine, 0);
                currentLineNumber = newCurrentLine-1;
            } else if (std::regex_match(userChoice[1], digitCheck) && std::regex_match(userChoice[2], digitCheck)) {
                // If the user enters d and 2 numbers, check them and then delete the range
                selectedFirstInput = userChoice[1];
                selectedSecondInput = userChoice[2];
                int convertedFirstInput = std::stoi(selectedFirstInput);
                int convertedSecondInput = std::stoi(selectedSecondInput);
                // If the first number is greater than the second number inform the user of the issue
                if(convertedFirstInput > convertedSecondInput) {
                    std::cout << "Unfortunately this text editor only shows a range with a lower number first.\n"
                            "(e.g. d 3 4 to delete 3-4 will work. d 4 3 to delete 4-3 will not work.\n\n";
                    continue;
                } else {
                    // Else run the delete in the range of number 1 to number 2
                    deletion(convertedFirstInput, convertedSecondInput);
                    if(currentLineNumber > linkedList.getSizeOfList()) {
                        currentLineNumber = convertedFirstInput;
                    }
                }
            } else {
                // If the user enters anything else, notify them that the input is weird and to retry
                std::cout << "The input does not match the requirements. Please check help and try again.\n\n";
                continue;
            }
            // --------------------------------------------------------------------------------------------------------
        } else if (userChoice[0] == "l") {
            if(userChoice[1].empty()) {
                // If the user enters L with nothing else display current line
                showLine(currentLineNumber, 0);
            } else if (std::regex_match(userChoice[1], digitCheck) && userChoice[2].empty()) {
                // Else if the user enters L with one number show the one line
                int newCurrentLine = std::stoi(userChoice[1]);
                showLine(newCurrentLine, 0);
            } else if (std::regex_match(userChoice[1], digitCheck) && std::regex_match(userChoice[2], digitCheck)) {
                // Else if the user enters L and 2 numbers, check them and show numbers in range
                int newFirstLine = std::stoi(userChoice[1]);
                int newSecondLine = std::stoi(userChoice[2]);
                if(newFirstLine > newSecondLine) {
                    std::cout << "Unfortunately this editor only shows ranges with a lower number first.\n"
                            "e.g. l 1 3 to show lines 1-3 will work. l 3 1 to show lines 3-1 will not work.\n\n";
                    continue;
                } else {
                    showLine(newFirstLine, newSecondLine);
                }
            }
            // --------------------------------------------------------------------------------------------------------
        } else if (userChoice[0] == "e") {
            // If the user hits e it means save & quit, so do just that
            quitAndSave(newFile);
            running = false;
            // --------------------------------------------------------------------------------------------------------
        } else if (userChoice[0] == "s") {
            // If the user hits s it means they want to substitute.
            if (userChoice[1].empty()) {
                // If the user hit S without anything else then they want to substitute the current line
                std::cout << "Please enter the substitution for line " << currentLineNumber << "\n\n>> ";
                getline(std::cin, newLine);
                callSubstitution(currentLineNumber, newLine);
            } else if (std::regex_match(userChoice[1], digitCheck) && userChoice[2].empty()) {
                int newLineNumber = std::stoi(userChoice[1]);
                if(newLineNumber < linkedList.getSizeOfList()) {
                    // If the user enters S and a number substitute that number, but check that number
                    std::cout << "Please enter the substitution for line " << currentLineNumber << "\n\n>> ";
                    getline(std::cin, newLine);
                    callSubstitution(newLineNumber, newLine);
                } else {
                    std::cout << "You cannot substitute a line that does not exist. Please check things over"
                            "and try again.\n\n";
                }
            } else {
                // If the user enters anything else, tell them it wont work and re-ask for input
                std::cout << "Unfortunately that input cannot be parsed. Please look it over and try again.\n\n";
                continue;
            }
            // --------------------------------------------------------------------------------------------------------
        } else if (userChoice[0] == "v") {
            // If the user types V show them the lines in the buffer
            displayLinesWithLineNumber();
            continue;
            // --------------------------------------------------------------------------------------------------------
        } else if (userChoice[0] == "q") {
            // If the user types quit, then quit
            std::cout << "\nQuitting without saving. Have a lovely day.\n\n";
            running = false;
            // --------------------------------------------------------------------------------------------------------
        } else {
            // Else, re-ask for input
            std::cout << "Please enter proper input";
            std::cout << std::endl << std::endl;
            continue;
            // --------------------------------------------------------------------------------------------------------
        }
    }
}

void Editor::deletion(int firstLineToDelete, int secondLineToDelete) {
    // If the first number is less than the size of the list
    if(firstLineToDelete < linkedList.getSizeOfList() && secondLineToDelete < linkedList.getSizeOfList()) {
        if (firstLineToDelete == 1 && secondLineToDelete == 0) {
            // If first number is 1 and second number is 0 delete the head
            std::cout << "\nDeleting line " << firstLineToDelete << std::endl;
            linkedList.deleteFirst();
        } else if (firstLineToDelete == linkedList.getSizeOfList() && secondLineToDelete == 0) {
            // Else if the first line is the size of the list and the second number is 0 delete the tail
            std::cout << "\nDeleting line " << firstLineToDelete << std::endl;
            linkedList.deleteLast();
        } else {
            if(firstLineToDelete > 0 && secondLineToDelete == 0) {
                // If the first number is greater than 0 and there's no second number
                linkedList.deleteAtPosition(firstLineToDelete, 0);
            } else if (firstLineToDelete == 1 && secondLineToDelete == linkedList.getSizeOfList()-1) {
                std::cout << "\nBlowing up every line\n";
                // Else If the first number is 1 and the second number is max, delete all lines
                for(int i = 1; i <= secondLineToDelete; i++) {
                    linkedList.deleteFirst();
                }
            } else {
                if(firstLineToDelete == 1) {
                    // Else if the first line is 1 delete first up to the second number entered
                    for (int i = firstLineToDelete; i <= secondLineToDelete; i++) {
                        linkedList.deleteFirst();
                    }
                } else {
                    // Else make a for loop to delete a range
                    std::cout << "Deleting lines " << firstLineToDelete << "-" << secondLineToDelete << std::endl;
                    for (int i = firstLineToDelete; i <= secondLineToDelete; i++) {
                        linkedList.deleteAtPosition(firstLineToDelete, 0);
                    }
                }
            }
        }
    } else if (linkedList.getSizeOfList() == 0) {
        // If there's nothing left in the list warn the user that there is no more lines available
        std::cout << "The line(s) to delete exceed the number of lines available. Please look over your source.\n\n";
    } else {
        // Lastly if I've missed any other condition, warn the user that there are no more lines available
        std::cout << "The line(s) to delete exceed the number of lines available. Please look over your source.\n\n";
    }
}

void Editor::showLine(int lineToShow1, int lineToShow2) {
    // If the user views a line that's within range do this
    if (lineToShow1 < linkedList.getSizeOfList() && lineToShow2 < linkedList.getSizeOfList()) {
        if (lineToShow2 == 0) {
            linkedList.displaySpecificLines(lineToShow1, 0);
        } else {
            linkedList.displaySpecificLines(lineToShow1, lineToShow2);
        }
    } else {
        // Else inform the user that they are out of range
        std::cout
                << "The line(s) to show exceed the number of lines available. Please look over your source and try again.\n\n";
    }
}

void Editor::quitAndSave(std::string fileName) {
    // Open up an ofstream to make the new file
    std::ofstream newFile(fileName);
    if(newFile.is_open()) {
        // If file is open, make a for loop the size of the list - 1 and dump the contents into the text file
        for(int i = 1; i <= linkedList.getSizeOfList()-1; i++) {
            newFile << linkedList.returnLinesForSaving(i) << "\n";
        }
    } else {
        // If it somehow fails (maybe read/write access issues) tell the user
        std::cout << "Unable to open file\n\n";
    }
    newFile.close();
}

void Editor::callSubstitution(int lineToSubstitute, std::string valueToSubstitute) {
    // If the line to subtitute is in range, do it
    deletion(lineToSubstitute, 0);
    insertIntoBuffer(lineToSubstitute, valueToSubstitute);
}