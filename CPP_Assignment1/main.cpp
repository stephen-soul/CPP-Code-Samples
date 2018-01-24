/**
 * MAIN FILE TO THE LINE EDITOR. MAIN WILL TAKE IN A FILE NAME ALONG WITH A NEW FILE NAME AND TRY TO EDIT THE FILE
 * ARGC AND ARGV ARE THE COMMAND LINE ARGUMENTS
 * @param argc - Parameter Count
 * @param argv - Parameter Values
 * @return
 */
#include "Interface.h"
#include "LinkedList.h"

int main(int argc, char *argv[]) {
    // Variables
    bool running = true;
    // Make an object for the interface
    Interface anInterface;
    // Make an object for the unix extras (clear screen, pause, colours, etc.)
    UnixExtras extras;
    // Make an object for the linked list
    LinkedList linkedList;
    // Check the arguments. If there are not 3 (the file name, the text file to open and the new file name) then close.
    if(argc != 3) {
        std::cout << "When opening the line editor, you must include a file to open and a new file name. Please try again.";
        extras.pause();
        return 1;
    } else {
        // We assume that argument 1 is the file to open, so make it a string
        std::string newFile = argv[1];
        // Try to open it. If you can, great. If you can't, return and exit.
        if(linkedList.readFileIntoLinkedList(newFile)) {

        } else {
            std::cout << "That file could not be found. Please try again later.";
            extras.pause();
            return 2;
        }
    }
    return 0;
}