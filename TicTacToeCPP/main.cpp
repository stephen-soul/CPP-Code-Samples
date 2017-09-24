#include "Resources.h"
Resources resources = Resources();
int main() {
    //MAKE A STRING FOR THE USER INPUT FOR DIFFICULTY
    std::string selectDifficulty;
    //OUTPUT A MESSAGE TO INTRODUCE THE PLAYER TO THE CONSOLE GAME
    std::cout << "\t\t\tWelcome to C++ Tic Tac Toe!" << std::endl;
    std::cout << "Would you like to play (1) EASY mode or (2) HARD mode?" << std::endl;
    //THIS IS A FOR(;;) LOOP WHICH FUNCTIONALLY WORKS LIKE A "WHILE(TRUE)"
    for(;;) {
        //ASK FOR USER INPUT
        std::cout << "> ";
        //GET THE LINE
        getline(std::cin, selectDifficulty);
        //IF THEY ENTER 1 OR 2, BREAK
        if (selectDifficulty == "1" || selectDifficulty == "2")
            break;
            //ELSE SAY IT'S INVALID AND GO BACK TO THE TOP
        else
            std::cout << "Invalid.\n";
    }
    //END OF FOR LOOP. HERE'S WHERE YOU DO SOMETHING BASED ON USER INPUT
    //IF THEY WANT EASY MODE
    if(selectDifficulty == "1")
    {
        std::cout << "You chose EASY mode.\n\n";
        for(;;) {
            resources.playerTurn();
            resources.checkWin();
            if (resources.playerWin)
            {
                std::cout << "Good job, player!\n...Though it is easy mode...";
                break;
            }
            if(resources.tieGame)
            {
                std::cout << "It's a tie game!";
                break;
            }
            resources.easyCPU();
            resources.checkWin();
            if(resources.cpuWin)
            {
                std::cout << "Good job, CPU!";
                break;
            }
            if(resources.tieGame)
            {
                //CHECK ME OUT I'M A COMMENT
                std::cout << "It's a tie game!";
                break;
            }
        }
    }//END OF DIFFICULTY ONE
    //IF THEY WANT DIFFICULT MODE
    if(selectDifficulty == "2")
    {
        resources.playerTurn();
    }
    std::cout << "\n\nThank you for playing.";
    //INT MAIN IS AN INT. RETURN SOMETHING. 0 IS DEFAULT.
    return 0;
}