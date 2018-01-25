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
        std::cout << "Could not open file. Please try again later.";
        unixExtras.pause();
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
    linkedList.display();
}

void Editor::insertIntoBuffer(int i, std::string newValue) {
    if(i == 1) {
        linkedList.insertAtStart(newValue);
    } else {
        linkedList.addToPosition(i, newValue);
    }
}

void Editor::askUserForInput(std::string fileName, std::string newFile) {
    while (running) {
        // Make regex for digits
        std::regex digitCheck("^[1-9][0-9]*");
        // Make the screen appealing
        std::cout << "\n----------------------------------------\n\t    "
                "CPP LINE EDITOR\n----------------------------------------\n\n";
        // Now make an editor object and pass the file name
        std::cout << "Please type a command (or help for help)\n\nCurrent line number: " << currentLineNumber << "\n"
                  << ">> ";
        // Get user input and then stringstream it to parse it properly, make the head word lowercase and then dump it into a string array
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
            displayHelpScreen();
            std::cout << std::endl << std::endl << "Press enter";
            continue;
        } else if (userChoice[0] == "i") {
            // If the user types i, check the second value.
            if (std::regex_match(userChoice[1], digitCheck)) {
                // If the second digit matches 1-9 do this
                std::cout << "Please enter the new line for line " << userChoice[1] << "\n\n>> ";
                getline(std::cin, newLine);
                // Turn the user input into an int and pass it
                selectedInput = userChoice[1];
                int lineToInsertInto = std::stoi(selectedInput);
                insertIntoBuffer(lineToInsertInto, newLine);
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

        } else if (userChoice[0] == "g") {
            if(std::regex_match(userChoice[1], digitCheck)) {
                // If the selected input as long as it matches a digit check and set it to the current line number
                selectedInput = userChoice[1];
                int newCurrentLine = std::stoi(selectedInput);
                currentLineNumber = newCurrentLine;
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
        } else if (userChoice[0] == "i") {

        } else if (userChoice[0] == "i") {

        } else if (userChoice[0] == "i") {

        } else if (userChoice[0] == "i") {

        } else if (userChoice[0] == "v") {
            // If the user types quit, then quit
            std::cout << "Here are the lines in the buffer\n\n";
            displayLinesWithLineNumber();
            continue;
        } else if (userChoice[0] == "q") {
            // If the user types quit, then quit
            std::cout << "Have a lovely day.";
            running = false;
        } else {
            // Else, re-ask for input
            std::cout << "Please enter proper input";
            std::cout << std::endl << std::endl;
            continue;
        }
    }
}

void Editor::insertAtBeginning(int i, std::string value) {
    linkedList.insertBeforeNode(i-1, value);
}
