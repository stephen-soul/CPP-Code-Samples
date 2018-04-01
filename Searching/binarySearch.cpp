//
// Created by stephen on 01/04/18.
//

#include "binarySearch.h"

binarySearch::binarySearch()=default;

binarySearch::~binarySearch()=default;

bool binarySearch::searchBinarily(int (&myArray)[1000], int startPoint, int arraySize, int numberToSearch) {
    do {
        // Make a midPoint which is the size of the array - start point(0) / 2
        int midPoint = startPoint + (arraySize - startPoint)/2;
        // If the number we're looking for is in the middle, return true
        if(myArray[midPoint] == numberToSearch)
            return true;
        // If the number to find is greater, ignore the left half
        if(myArray[midPoint] < numberToSearch)
            startPoint = midPoint + 1;
        // If the number to find is smaller, ignore the right half
        if(myArray[midPoint] > numberToSearch)
            arraySize = midPoint - 1;
    } while (startPoint <= arraySize);
    // If the number was not found. Return false
    return false;
}