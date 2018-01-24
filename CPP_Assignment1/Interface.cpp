/**
 * INTERFACE CLASS
 */

#include "Interface.h"

/**
 * This is a constructor. It is probably not needed
 */
Interface::Interface() {

}

/**
 * This handles opening a file. The filename param is for the file name that's entered as an command line argument
 * @param fileName
 */
bool Interface::openFile(std::string fileName) {
    std::cout << "Opened a file";
}
