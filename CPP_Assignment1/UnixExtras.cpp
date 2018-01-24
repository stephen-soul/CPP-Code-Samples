/**
 * THIS IS THE CLASS THAT HANDLES THE CODE FOR THE UNIX EXTRAS
 */

#include "UnixExtras.h"

/**
 * This is the pause function. It will act as a system("pause") for *nix
 */
void UnixExtras::pause() {
    std::cout<<"\n\nPress ENTER to exit";
    std::cin.ignore(std::cin.rdbuf()->in_avail()+1);
}

/**
 * This is a clear screen function. It will output the ANSI escape code for clear screen
 */
void UnixExtras::clearScreen() {
    std::cout << "\033[2J";
}

