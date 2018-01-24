/*
 * DATA STRUCTURES LINE EDITOR // STEPHEN FETINKO 2018
 */

#include "Editor.h"

Editor::Editor() {
}

Editor::~Editor() {
}

void Editor::readFromFile(std::string fileName) {
    // Use an ifstream to try to open a file
    file.open(fileName);
    if (file.fail()) {
        std::cout << "Could not open file. Please try again later." << std::endl << std::endl;
    } else {
        while (getline(file, line)) {
            linkedList.add(line);
        }
        file.close();
    }
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
    linkedList.displayWithLineNumber();
}

void Editor::insertIntoBuffer(int i, std::string value) {
    linkedList.addToPosition(i, value);
}
