/*Stephen Fetinko 2018*/
#include "programState.h"

state::state() {
    programRunning = true;
    mainMenuActive = true;
    askingForName = true;
    askingForNumber = false;
    askingForEditedSpot = true;
    askingForEditedName = false;
    askingForEditedNumber = false;
}

state::~state() = default;

/*
    All of the below functions exist to manipulate the state of the program through bools
*/

bool state::changeMainMenuState() {
    if(mainMenuActive)
        mainMenuActive = false;
    else
        mainMenuActive = true;
}

bool state::changeProgramRunningState() {
    if(programRunning)
        programRunning = false;
    else
        programRunning = true;
}

bool state::changeNameState() {
    if(askingForName)
        askingForName = false;
    else
        askingForName = true;
}

bool state::changeNumberState() {
    if(askingForNumber)
        askingForNumber = false;
    else
        askingForNumber = true;
}

bool state::changeDeleteNumberState() {
    if(askingForDeleteNumber)
        askingForDeleteNumber = false;
    else
        askingForDeleteNumber = true;
}

bool state::changeEditingSpotState() {
    if(askingForEditedSpot)
        askingForEditedSpot = false;
    else
        askingForEditedSpot = true;
}

bool state::changeEditingNameState() {
    if(askingForEditedName)
        askingForEditedName = false;
    else    
        askingForEditedName = true;
}

bool state::changeEditingNumberState() {
    if(askingForEditedNumber)
        askingForEditedNumber = false;
    else
        askingForEditedNumber = true;
}


bool state::isMainMenuActive() {
    return mainMenuActive;
}

bool state::isProgramRunning() {
    return programRunning;
}

bool state::isNameActive() {
    return askingForName;
}

bool state::isNumberActive() {
    return askingForNumber;
}

bool state::isDeleteNumberActive() {
    return askingForDeleteNumber;
}

bool state::isEditingSpotActive() {
    return askingForEditedSpot;
}

bool state::isEditingNameActive() {
    return askingForEditedName;
}

bool state::isEditingNumberActive() {
    return askingForEditedNumber;
}