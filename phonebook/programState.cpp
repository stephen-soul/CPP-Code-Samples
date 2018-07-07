/*Stephen Fetinko 2018*/
#include "programState.h"

state::state() {
    programRunning = true;
    mainMenuActive = true;
    askingForName = true;
    askingForNumber = false;
}

state::~state() = default;

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