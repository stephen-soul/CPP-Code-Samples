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
    bool changeEditingSpotState();
    bool changeEditingNameState();
    bool changeEditingNumberState();
    // Functions to check the state
    bool isMainMenuActive();
    bool isProgramRunning();
    bool isNameActive();
    bool isNumberActive();
    bool isDeleteNumberActive();
    bool isEditingSpotActive();
    bool isEditingNameActive();
    bool isEditingNumberActive();
private:
    // Bools
    bool programRunning;
    bool mainMenuActive;
    bool askingForName;
    bool askingForNumber;
    bool askingForDeleteNumber;
    bool askingForEditedSpot;
    bool askingForEditedName;
    bool askingForEditedNumber;
};