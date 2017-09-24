//
// Created by Stephen on 2017-09-20.
//

#ifndef TICTACTOE_RESOURCES_H
#define TICTACTOE_RESOURCES_H
#include <iostream>
#include <string>
#include <iomanip>
#include <random>

class Resources {
public:
    //MAKE YOUR CONSTRUCTOR
    Resources();
    //CHARS TO DETERMINE PLAYER AND CPU
    char playerSymbol;
    char cpuSymbol;
    //VOID FUNCTIONS
    void playerTurn();
    void easyCPU();
    void difficultCPU();
    void checkWin();
    void drawBoard();
    int makeRandomNumber();
    //STRING
    std::string playerMove;
    //BOOLS
    bool playerWin;
    bool cpuWin;
    bool tieGame;
    //INTEGERS
    int easyCpuRandomNumber;
private:
    //MAKE THE GAME BOARD
    char board[3][3];
};


#endif //TICTACTOE_RESOURCES_H
