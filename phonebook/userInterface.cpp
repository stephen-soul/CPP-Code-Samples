/*Stephen Fetinko 2018*/
#include "userInterface.h"

using std::cout;
using std::endl;

interface::interface() {
    // Constructor initializes variables
    menuChoice = "";
    menuChoiceConverted = 0;
    numberToAdd = "";
    numberToDelete = "";
}

interface::~interface() = default;

// Function to act as the portal from main. Loops the main menu as long as the program is running
void interface::runInterface() {
    while(programState.isProgramRunning()) {
        mainMenu();
    }
}

// Function for the main menu interface allowing the user to select where they want to go
void interface::mainMenu() {
    // Make a regex statement to specifically get number input from the user
    std::regex digitCheck("^[1-5]");
    do {
        cout << "Welcome to the phonebook ver. 1.0" << endl;
        cout << "(1) View registry" << endl;
        cout << "(2) Add entry" << endl;
        cout << "(3) Edit entry" << endl;
        cout << "(4) Delete entry" << endl;
        cout << "(5) Exit" << endl;
        cout << ">> ";
        getline(std::cin, menuChoice);
        if(std::regex_match(menuChoice, digitCheck)) {
            menuChoiceConverted = std::stoi(menuChoice);
            switch(menuChoiceConverted) {
                case 1:
                    cout << endl << "-------------" << endl << "View registry" << endl << "-------------" << endl << endl;
                    displayRegistry();
                    break;
                case 2:
                    cout << endl << "Add entry" << endl;
                    askForEntryToAdd();
                    break;
                case 3:
                    cout << endl << "Edit entry" << endl;
                    askForEntryToEdit();
                    break;
                case 4:
                    cout << endl << "Delete entry" << endl;
                    askForEntryToDelete();
                    break;
                case 5:
                    programState.changeProgramRunningState();
                    programState.changeMainMenuState();
                    return;
                    break;
                default:
                    break;
            }
        } else
            cout << "\nInvalid response. Please try again.\n" << endl;
    } while (programState.isMainMenuActive());
}

// Function to display the registry and inform when it's at the end
void interface::displayRegistry() {
    if (phonebookLogic.names.size() > 0) {
        for (int i = 0; i < phonebookLogic.phoneNumbers.size(); i++)
        {
            std::cout << "(" << i + 1 << ") " << phonebookLogic.names.at(i) << " :: " << phonebookLogic.phoneNumbers.at(i) << std::endl
                      << std::endl;
        }
        std::cout << "----------------------------------------" << std::endl
                  << "End of current registry. Back to main..." << std::endl
                  << "----------------------------------------" << std::endl
                  << std::endl;
    }
    else {
        std::cout << "Empty!" << std::endl
                  << std::endl;
        std::cout << "--------------------------------" << std::endl
                  << "No entries are currently listed!" << std::endl
                  << "--------------------------------" << std::endl
                  << std::endl;
    }
}

// Function to ask for a name, validate it, then a number, validate it and then get the logic to add it to the list
void interface::askForEntryToAdd() {
    // Make some validating regex for the name and phone number
    std::regex nameMatch("^[A-Za-z]*+\\s?[A-Za-z]*"); // Match the name as only any number of letters A-Z or a-z first name only or first and last name
    std::regex numberMatch("[[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4}"); // Match the phone number to something like 999-999-9999
    do {
        std::cout << std::endl << "Please enter the name you wish to add." << std::endl;
        std::cout << ">> ";
        getline(std::cin, nameToAdd);
        if(std::regex_match(nameToAdd, nameMatch)) {
            programState.changeNameState();
            programState.changeNumberState();
        } else
            std::cout << "The name doesn't match a proper name!" << std::endl;
    } while (programState.isNameActive());
    do {
        std::cout << std::endl << "Please enter the number associated to add to the registry." << std::endl;
        std::cout << ">> ";
        getline(std::cin, numberToAdd);
        if(std::regex_match(numberToAdd, numberMatch)) {
            phonebookLogic.addEntry(nameToAdd, numberToAdd);
            std::cout << "The entry was successfully added!" << std::endl << std::endl;
            programState.changeNumberState();
            programState.changeNameState();
        } else
            std::cout << "The number doesn't match the format (ex. 999-123-4567)";
    } while (programState.isNumberActive());
}

// Ask the user for a number to delete. If the number exists, then delete it and inform the user. Else, inform of any issues.
void interface::askForEntryToDelete() {
    std::regex entryToDelete("^[0-9]+"); // Only take something that's a number. Then check if it exists.
    do {
        std::cout << std::endl << "Please enter the number you wish to delete (located beside the name)" << std::endl;
        std::cout << ">> ";
        getline(std::cin, numberToDelete);
        int numberToDeleteConverted = std::stoi(numberToDelete);
        if(std::regex_match(numberToDelete, entryToDelete) && phonebookLogic.removeEntry(numberToDeleteConverted))
            std::cout << "The selected entry has been deleted." << std::endl << std::endl;
        else
            std::cout << "That number doesn't exist in our records. Please try another." << std::endl << std::endl;
    } while (programState.isDeleteNumberActive());
}

// Function for editing. Acts similar to the adding, but with an additional spot entry like what was used in the delete process
void interface::askForEntryToEdit() {
    // Make some validating regex for the spot, name and phone number
    std::regex spotMatch("^[0-9]*");                                        // Match 0-9 for input to ensure they try to match a number listed
    std::regex nameMatch("^[A-Za-z]*+\\s?[A-Za-z]*");                       // Match the name as only any number of letters A-Z or a-z first name only or first and last name
    std::regex numberMatch("[[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4}"); // Match the phone number to something like 999-999-9999
    do {
        std::cout << std::endl
                  << "Please enter the number you wish to edit (located beside the name)" << std::endl
                  << ">> ";
        getline(std::cin, numberToEdit);
        if (std::regex_match(numberToEdit, spotMatch) && std::stoi(numberToEdit) <= phonebookLogic.names.size()) {
            convertedEditNumber = std::stoi(numberToEdit);
            programState.changeEditingSpotState();
            programState.changeEditingNameState();
        } else
            std::cout << "The number doesn't exist on the board!";
    } while (programState.isEditingSpotActive());
    do
    {
        std::cout << std::endl
                  << "Please enter the new name for this entry" << std::endl;
        std::cout << ">> ";
        getline(std::cin, editedName);
        if (std::regex_match(editedName, nameMatch))
        {
            programState.changeEditingNameState();
            programState.changeEditingNumberState();
        }
        else
            std::cout << "The name doesn't match a proper name!" << std::endl;
    } while (programState.isEditingNameActive());
    do
    {
        std::cout << std::endl
                  << "Please enter the new phone number for this entry." << std::endl;
        std::cout << ">> ";
        getline(std::cin, editedNumber);
        if (std::regex_match(editedNumber, numberMatch))
        {
            phonebookLogic.editEntry(convertedEditNumber, editedName, editedNumber);
            std::cout << "The entry was successfully edited!" << std::endl
                      << std::endl;
            programState.changeEditingNumberState();
            programState.changeEditingSpotState();
        }
        else
            std::cout << "The number doesn't match the format (ex. 999-123-4567)";
    } while (programState.isEditingNumberActive());
}