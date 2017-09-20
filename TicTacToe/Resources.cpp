//
// Created by Stephen on 9/19/2017.
//

#include <iomanip>
#include "Resources.h"

Resources::Resources()
{
    for(int row = 0; row < 3; row++)
        for(int col = 0; col < 3; col++)
            board[row][col] = '1' + row + col;
}

void Resources::printBoard()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
            std::cout << std::setw(3) << board[row][col] << " ";
        std::cout << std::endl << std::endl;
    }
}