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

void interface::runInterface() {
    while(programState.isProgramRunning()) {
        mainMenu();
    }
}

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

void interface::displayRegistry() {
    if (phonebookLogic.names.size() > 0)
    {
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
    else
    {
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
            std::cout << "The number was successfully added!" << std::endl << std::endl;
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

void interface::askForEntryToEdit() {
    // Make some validating regex for the name and phone number
    std::regex nameMatch("^[A-Za-z]*+\\s?[A-Za-z]*");                       // Match the name as only any number of letters A-Z or a-z first name only or first and last name
    std::regex numberMatch("[[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4}"); // Match the phone number to something like 999-999-9999
    do
    {
        std::cout << std::endl
                  << "Please enter the name you wish to add." << std::endl;
        std::cout << ">> ";
        getline(std::cin, nameToAdd);
        if (std::regex_match(nameToAdd, nameMatch))
        {
            programState.changeNameState();
            programState.changeNumberState();
        }
        else
            std::cout << "The name doesn't match a proper name!" << std::endl;
    } while (programState.isNameActive());
    do
    {
        std::cout << std::endl
                  << "Please enter the number associated to add to the registry." << std::endl;
        std::cout << ">> ";
        getline(std::cin, numberToAdd);
        if (std::regex_match(numberToAdd, numberMatch))
        {
            phonebookLogic.addEntry(nameToAdd, numberToAdd);
            std::cout << "The number was successfully added!" << std::endl
                      << std::endl;
            programState.changeNumberState();
            programState.changeNameState();
        }
        else
            std::cout << "The number doesn't match the format (ex. 999-123-4567)";
    } while (programState.isNumberActive());
}