/*Stephen Fetinko 2018*/
#pragma once

class state {
public:
    // Constructor && Destructor
    state();
    ~state();
    // Functions to change the bools
    bool changeMainMenuState();
    bool changeProgramRunningState();
    bool changeNameState();
    bool changeNumberState();
    bool changeDeleteNumberState();
    // Functions to check the state
    bool isMainMenuActive();
    bool isProgramRunning();
    bool isNameActive();
    bool isNumberActive();
    bool isDeleteNumberActive();
private:
    // Bools
    bool programRunning;
    bool mainMenuActive;
    bool askingForName;
    bool askingForNumber;
    bool askingForDeleteNumber;
};