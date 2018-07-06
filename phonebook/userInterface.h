/*Stephen Fetinko 2018*/
#pragma once
#include "logic.h"
#include "programState.h"
#include <regex>
class interface {
public:
    // Constructor && Destructor
    interface();
    ~interface();
    // Functions for the interface
    void run_interface();
    void main_menu();
    void ask_for_entry_to_add();
    void ask_for_entry_to_delete();
    void ask_for_entry_to_edit();
    // Variables for input
    std::string menu_choice;
    int menu_choice_converted;
    // Make an object for the logic
    logic phonebookLogic;
    // Make an object for the state
    state program_state;
private:
    std::string name_to_add;
    std::string number_to_add;
};