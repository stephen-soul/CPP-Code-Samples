/*Stephen Fetinko 2018*/
#include "userInterface.h"
#include "logic.h"

// We always want main to be as lean as possible. Make an object for the interface, run it, and end afterwards
int main() {
    interface menu;
    menu.runInterface();
    return 0;
}