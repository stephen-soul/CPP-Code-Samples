/*Stephen Fetinko 2018*/
#include "programState.h"

state::state() {
    program_running = true;
    main_menu_active = true;
    asking_for_name = true;
    asking_for_number = true;
}

state::~state() = default;

bool state::change_main_menu_state() {
    if(main_menu_active)
        main_menu_active = false;
    else
        main_menu_active = true;
}

bool state::change_program_running_state() {
    if(program_running)
        program_running = false;
    else
        program_running = true;
}

bool state::change_name_state() {
    if(asking_for_name)
        asking_for_name = false;
    else
        asking_for_name = true;
}

bool state::change_number_state() {
    if(asking_for_number)
        asking_for_number = false;
    else
        asking_for_number = true;
}

bool state::is_main_menu_active() {
    return main_menu_active;
}

bool state::is_program_running() {
    return program_running;
}

bool state::is_name_active() {
    return asking_for_name;
}

bool state::is_number_active() {
    return asking_for_number;
}