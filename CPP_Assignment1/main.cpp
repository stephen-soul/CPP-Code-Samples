/**
 * MAIN FILE TO THE LINE EDITOR. MAIN WILL TAKE IN A FILE NAME ALONG WITH A NEW FILE NAME AND TRY TO EDIT THE FILE
 * ARGC AND ARGV ARE THE COMMAND LINE ARGUMENTS
 * @param argc
 * @param argv
 * @return
 */
#include "Interface.h"

void pause();

void pause() {
    std::cout<<"\n\nPress ENTER to exit";
    std::cin.ignore(std::cin.rdbuf()->in_avail()+1);
}

int main(int argc, char *argv[]) {
    // Make an object for the interface
    Interface anInterface;
    // Check the arguments. If there are not 3 (the file name, the text file to open and the new file name) then close.
    if(argc != 3) {
        std::cout << "There are not enough arguments. Please try again.";
        pause();
        return(0);
    } else {
        // We assume that argument 1 is the file to open
        std::string newFile = argv[1];
        anInterface.openFile(newFile);
    }
    return 0;
}