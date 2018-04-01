// C++ console application to compare sequential and binary searches | Stephen Fetinko 2018

#include "sequentialSearch.h"
using namespace std;

sequentialSearch::sequentialSearch()=default;

sequentialSearch::~sequentialSearch()=default;

// Function to sequentially search for a number that's passed into it in the array
bool sequentialSearch::searchSequentially(int (&myArray)[1000], int numberToSearch, int arraySize) {
    for (int i = 1; i <= arraySize; i++) {
        if (myArray[i] == numberToSearch)
            return true;
        if(i == 1000 && myArray[i] != numberToSearch)
            return false;
    }
//    while(index < 1000 && (numberToSearch != myArray[index])) {
//        if(myArray[index] != numberToSearch)
//            index++;
//    }
//    index = 0;
}