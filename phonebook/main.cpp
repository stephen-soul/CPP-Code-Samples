#include "userInterface.h"

int main() {
    interface menu;
    while(menu.program_running) {
        menu.main_menu();
    }
    return 0;
}