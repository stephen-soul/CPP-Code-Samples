/*Stephen Fetinko 2018*/
#pragma once

class state {
public:
    // Constructor && Destructor
    state();
    ~state();
    // Functions to change the bools
    bool change_main_menu_state();
    bool change_program_running_state();
    bool change_name_state();
    bool change_number_state();
    // Functions to check the state
    bool is_main_menu_active();
    bool is_program_running();
    bool is_name_active();
    bool is_number_active();
private:
    // Bools
    bool program_running;
    bool main_menu_active;
    bool asking_for_name;
    bool asking_for_number;
};