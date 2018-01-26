/*
 * DATA STRUCTURES LINE EDITOR // STEPHEN FETINKO 2018
 */

// Include the editor
#include "Editor.h"

// Set the main function to take in arguments
int main(int argc, char *argv[]) {
    // If there are not 3 arguments, then tell the user and close. Else, proceed
    if (argc != 3) {
        std::cout << "The program must be the program name followed by the file name and new file name.\n"
                "e.g.\"PROGRAM NAME\" \"FILE TO EDIT\" \"NEW FILE\". Please try again" << std::endl;
    } else {
        // Make an object the editor
        Editor editor;
        // If we make it here, make the file name argument 1 and new file argument 2
        std::string fileName = argv[1];
        std::string newFile = argv[2];
        // Try to open the file. If it fails, return 0
        if(!editor.readFromFile(fileName))
            return 0;
        // Then ask the user for input and start that loop
        editor.askUserForInput();
    }
    return 0;
}// End of main