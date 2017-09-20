//
// Created by Stephen on 9/19/2017.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H
#include <iostream>
#include <string>

class Resources {
public:
    //CONSTRUCTOR
    Resources();

    void printBoard();

private:
    //MAKE A 3X3 2D ARRAY
    char board[3][3];
};


#endif //TICTACTOE_BOARD_H
