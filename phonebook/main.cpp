#include "userInterface.h"
#include "logic.h"

int main() {
    interface menu;
    while(menu.program_running) {
        menu.main_menu();
    }
    return 0;
}