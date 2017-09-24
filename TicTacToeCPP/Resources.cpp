//
// Created by Stephen on 2017-09-20.
//

//INCLUDE THE HEADER FILES FOR THE RESOURCES
#include "Resources.h"

//INITIALIZER
Resources::Resources()
{
    //INITIALIZE THE VARIABLES
    this->playerSymbol = 'X';
    this->cpuSymbol = 'O';
    this->playerMove = "";
    this->playerWin = false;
    this->cpuWin = false;
    this->tieGame = false;
    this->easyCpuRandomNumber = 0;
    //INITIALIZE THE BOARD. IN THIS FOR LOOP WE ADD CHARS AND INTS TO FILL A CHAR ARRAY
    for (int i = 0; i < 9; i++) {
        board[i / 3][i % 3] = '1' + i;
    }
}
//DRAW BOARD
void Resources::drawBoard()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
            std::cout << std::setw(5) << board[row][col] << " ";
        std::cout << std::endl << std::endl;
    }
}
//PLAYER TURN
void Resources::playerTurn()
{
    drawBoard();
    for(;;)
    {
        std::cout << "Which space would you\nlike to mark? (1-9)" << std::endl;
        std::cout << "> ";
        std::getline(std::cin, playerMove);
        if(playerMove == "1")
        {
            if(board[0][0] != playerSymbol && board[0][0] != cpuSymbol) {
                board[0][0] = playerSymbol;
                break;
            }
            else
            {
                std::cout << "Please enter a space not already filled.\n\n";
                continue;
            }
        }//END OF IF PLAYER SELECTS 1
        if(playerMove == "2")
        {
            if(board[0][1] != playerSymbol && board[0][1] != cpuSymbol) {
                board[0][1] = playerSymbol;
                break;
            }
            else
            {
                std::cout << "Please enter a space not already filled.\n\n";
                continue;
            }
        }//END OF IF PLAYER SELECTS 2
        if(playerMove == "3")
        {
            if(board[0][2] != playerSymbol && board[0][2] != cpuSymbol) {
                board[0][2] = playerSymbol;
                break;
            }
            else
            {
                std::cout << "Please enter a space not already filled.\n\n";
                continue;
            }
        }//END OF IF PLAYER SELECTS 3
        if(playerMove == "4")
        {
            if(board[1][0] != playerSymbol && board[1][0] != cpuSymbol) {
                board[1][0] = playerSymbol;
                break;
            }
            else
            {
                std::cout << "Please enter a space not already filled.\n\n";
                continue;
            }
        }//END OF IF PLAYER SELECTS 4
        if(playerMove == "5")
        {
            if(board[1][1] != playerSymbol && board[1][1] != cpuSymbol) {
                board[1][1] = playerSymbol;
                break;
            }
            else
            {
                std::cout << "Please enter a space not already filled.\n\n";
                continue;
            }
        }//END OF IF PLAYER SELECTS 5
        if(playerMove == "6")
        {
            if(board[1][2] != playerSymbol && board[1][2] != cpuSymbol) {
                board[1][2] = playerSymbol;
                break;
            }
            else
            {
                std::cout << "Please enter a space not already filled.\n\n";
                continue;
            }
        }//END OF IF PLAYER SELECTS 6
        if(playerMove == "7")
        {
            if(board[2][0] != playerSymbol && board[2][0] != cpuSymbol) {
                board[2][0] = playerSymbol;
                break;
            }
            else
            {
                std::cout << "Please enter a space not already filled.\n\n";
                continue;
            }
        }//END OF IF PLAYER SELECTS 7
        if(playerMove == "8")
        {
            if(board[2][1] != playerSymbol && board[2][1] != cpuSymbol) {
                board[2][1] = playerSymbol;
                break;
            }
            else
            {
                std::cout << "Please enter a space not already filled.\n\n";
                continue;
            }
        }//END OF IF PLAYER SELECTS 8
        if(playerMove == "9")
        {
            if(board[2][2] != playerSymbol && board[2][2] != cpuSymbol) {
                board[2][2] = playerSymbol;
                break;
            }
            else
            {
                std::cout << "Please enter a space not already filled.\n\n";
                continue;
            }
        }//END OF IF PLAYER SELECTS 9
        else
        {
            std::cout << "Please enter a number on the board.\n\n";
            continue;
        }
    }//END OF FOR(;;)
}
//MAKE EASY CPU RANDOM NUMBER
int Resources::makeRandomNumber()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 9);
    return dis(rd);
}
//CPU TURN (EASY)
void Resources::easyCPU()
{
    for(;;) {
        if (makeRandomNumber() == 1) {
            if (board[0][0] != playerSymbol && board[0][0] != cpuSymbol) {
                board[0][0] = cpuSymbol;
                break;
            } else
                continue;
        }
        if (makeRandomNumber() == 2) {
            if (board[0][1] != playerSymbol && board[0][1] != cpuSymbol) {
                board[0][1] = cpuSymbol;
                break;
            } else
                continue;
        }
        if (makeRandomNumber() == 3) {
            if (board[0][2] != playerSymbol && board[0][2] != cpuSymbol) {
                board[0][2] = cpuSymbol;
                break;
            } else
                continue;
        }
        if (makeRandomNumber() == 4) {
            if (board[1][0] != playerSymbol && board[1][0] != cpuSymbol) {
                board[1][0] = cpuSymbol;
                break;
            } else
                continue;
        }
        if (makeRandomNumber() == 5) {
            if (board[1][1] != playerSymbol && board[1][1] != cpuSymbol) {
                board[1][1] = cpuSymbol;
                break;
            } else
                continue;
        }
        if (makeRandomNumber() == 6) {
            if (board[1][2] != playerSymbol && board[1][2] != cpuSymbol) {
                board[1][2] = cpuSymbol;
                break;
            } else
                continue;
        }
        if (makeRandomNumber() == 7) {
            if (board[2][0] != playerSymbol && board[2][0] != cpuSymbol) {
                board[2][0] = cpuSymbol;
                break;
            } else
                continue;
        }
        if (makeRandomNumber() == 8) {
            if (board[2][1] != playerSymbol && board[2][1] != cpuSymbol) {
                board[2][1] = cpuSymbol;
                break;
            } else
                continue;
        }
        if (makeRandomNumber() == 9) {
            if (board[2][2] != playerSymbol && board[2][2] != cpuSymbol) {
                board[2][2] = cpuSymbol;
                break;
            } else
                continue;
        }
    }
}
//CPU TURN (DIFFICULT)
void Resources::difficultCPU()
{

}
//CHECK FOR A WIN
void Resources::checkWin()
{
    //IF THE TOP ROW IS FILLED WITH PLAYER SYMBOLS, RETURN THAT THE PLAYER WON
    if(board[0][0] == playerSymbol && board[0][1] == playerSymbol && board[0][2] == playerSymbol)
    {
        drawBoard();
        playerWin = true;
    }
    //IF THE TOP ROW IS FILLED WITH CPU SYMBOLS, RETURN THAT THE CPU WON
    if(board[0][0] == cpuSymbol && board[0][1] == cpuSymbol && board[0][2] == cpuSymbol)
    {
        drawBoard();
        cpuWin = true;
    }
    //IF THE MIDDLE ROW IS FILLED WITH PLAYER SYMBOLS, RETURN THAT THE PLAYER WON
    if(board[1][0] == playerSymbol && board[1][1] == playerSymbol && board[1][2] == playerSymbol)
    {
        drawBoard();
        playerWin = true;
    }
    //IF THE MIDDLE ROW IS FILLED WITH CPU SYMBOLS, RETURN THAT THE CPU WON
    if(board[1][0] == cpuSymbol && board[1][1] == cpuSymbol && board[1][2] == cpuSymbol)
    {
        drawBoard();
        cpuWin = true;
    }
    //IF THE BOTTOM ROW IS FILLED WITH PLAYER SYMBOLS, RETURN THAT THE PLAYER WON
    if(board[2][0] == playerSymbol && board[2][1] == playerSymbol && board[2][2] == playerSymbol)
    {
        drawBoard();
        playerWin = true;
    }
    //IF THE BOTTOM ROW IS FILLED WITH CPU SYMBOLS, RETURN THAT THE CPU WON
    if(board[2][0] == cpuSymbol && board[2][1] == cpuSymbol && board[2][2] == cpuSymbol)
    {
        drawBoard();
        cpuWin = true;
    }
    //IF THE TOP LEFT, MIDDLE LEFT AND BOTTOM LEFT ARE FILLED WITH PLAYER, RETURN WIN
    if(board[0][0] == playerSymbol && board[1][0] == playerSymbol && board[2][0] == playerSymbol)
    {
        drawBoard();
        playerWin = true;
    }
    //IF THE TOP LEFT, MIDDLE LEFT AND BOTTOM LEFT ARE FILLED WITH CPU, RETURN WIN
    if(board[0][0] == cpuSymbol && board[1][0] == cpuSymbol && board[2][0] == cpuSymbol)
    {
        drawBoard();
        cpuWin = true;
    }
    //IF THE TOP MIDDLE, MIDDLE MIDDLE, RIGHT MIDDLE ARE FILLED WITH PLAYER, RETURN WIN
    if(board[0][1] == playerSymbol && board[1][1] == playerSymbol && board[2][1] == playerSymbol)
    {
        drawBoard();
        playerWin = true;
    }
    //IF THE TOP MIDDLE, MIDDLE MIDDLE, RIGHT MIDDLE ARE FILLED WITH CPU, RETURN WIN
    if(board[0][1] == cpuSymbol && board[1][1] == cpuSymbol && board[2][1] == cpuSymbol)
    {
        drawBoard();
        cpuWin = true;
    }
    //IF THE TOP RIGHT, MIDDLE RIGHT AND RIGHT RIGHT ARE FILLED WITH PLAYER RETURN WIN
    if(board[0][2] == playerSymbol && board[1][2] == playerSymbol && board[2][2] == playerSymbol)
    {
        drawBoard();
        playerWin = true;
    }
    //IF THE TOP RIGHT, MIDDLE RIGHT AND RIGHT RIGHT ARE FILLED WITH CPU RETURN WIN
    if(board[0][1] == cpuSymbol && board[1][1] == cpuSymbol && board[2][1] == cpuSymbol)
    {
        drawBoard();
        cpuWin = true;
    }
    //IF THE TOP LEFT, MIDDLE, AND BOTTOM RIGHT ARE FILLED WITH PLAYER SYMBOLS, RETURN WIN
    if(board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
    {
        drawBoard();
        playerWin = true;
    }
    //IF THE TOP LEFT, MIDDLE, AND BOTTOM RIGHT ARE FILLED WITH CPU SYMBOLS, RETURN WIN
    if(board[0][0] == cpuSymbol && board[1][1] == cpuSymbol && board[2][2] == cpuSymbol)
    {
        drawBoard();
        cpuWin = true;
    }
    //IF THE TOP RIGHT, MIDDLE AND BOTTOM LEFT ARE FILLED WITH PLAYER SYMBOLS, RETURN WIN
    if(board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
    {
        drawBoard();
        playerWin = true;
    }
    //IF THE TOP RIGHT, MIDDLE AND BOTTOM LEFT ARE FILLED WITH CPU SYMBOLS, RETURN WIN
    if(board[0][2] == cpuSymbol && board[1][1] == cpuSymbol && board[2][0] == cpuSymbol)
    {
        drawBoard();
        cpuWin = true;
    }
    //CHECK FOR A TIE
    if(board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3'
            && board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6'
            && board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
    {
        if(! playerWin)
        {
            drawBoard();
            tieGame = true;
        } else
            tieGame = true;
    }
}