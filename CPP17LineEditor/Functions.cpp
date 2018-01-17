//
// Created by stephen on 10/01/18.
//

#include "Functions.h"

void Functions::helpScreen() {
    std::cout << "\nHere are a list of known commands."
            "\nTo start, type 'edit' <input file> <output file>"
            "\nYou will start on line 1 with a prompt. You may"
            "\nType I followed by a number to insert on that line number."
            "\nIf I is not followed by a number you will insert on the previous line."
            "\nYou may type D to delete the current line."
            "\nAlternately D may be followed by a specific line number,"
            "\nOr D can be followed by a range of numbers. i.e 3-5 deleting"
            "\nLine 3 through 5. V may display entire sets of lines in the buffer."
            "\nG goes to the beginning of the buffer, or you may choose one."
            "\nL lists the lines of the buffer using the same numbering system as the delete."
            "\nS substitutes a new line entered by the user for the current line in the buffer or"
            "\na specified line number. You will be prompted for a new line."
            "\nE specifies exiting and saving."
            "\nType 'Q' to quit" << "\n\nPRESS ENTER TO CONTINUE";
}