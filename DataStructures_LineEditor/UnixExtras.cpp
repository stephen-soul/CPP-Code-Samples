/**
 * THIS IS THE CLASS THAT HANDLES THE CODE FOR THE UNIX EXTRAS
 */

#include "UnixExtras.h"

/**
 * This is the pause function. It will act as a system("pause") for *nix
 */
void UnixExtras::pause() {
    // Simulate a pause screen and wait for user input to close it
    std::cout<<"\n\nPress ENTER to continue";
    std::cin.ignore(std::cin.rdbuf()->in_avail()+1);
}

/**
 * This is a clear screen function. It will output the ANSI escape code for clear screen
 */
void UnixExtras::clearScreen() {
    // Do a clear screen in ascii
    std::cout << "\033[2J";
}