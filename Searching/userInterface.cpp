// C++ console application to compare sequential and binary searches | Stephen Fetinko 2018

#include <sstream>
#include "userInterface.h"
using namespace std;

// Constructor
userInterface::userInterface() {
    askingForSearchMethod = true;
    searchMethod = "";
    // Initialize the array and fill it with 1-1000
    for(int i = 1; i <= 1000; i++) {
        searchableArray[i] = i;
    }
    // Make a value for the array size which just gets the size of the array
    arraySize = sizeof(searchableArray) / sizeof(searchableArray[0]);
}

// Destructor
userInterface::~userInterface() {
    delete []searchableArray;
}

// Function to introduce the user to the program and see which sort they want
void userInterface::introduction() {
    do {
        cout << "Please select a search to run and time\n(1) Sequential search\n(2) "
                "Binary search\n(3) Both\n>> ";
        getline(cin, searchMethod);
        if (searchMethod == "1") {
            // Run the Sequential search
            runSequentialSearch();
            askingForSearchMethod = false;
        } else if (searchMethod == "2") {
            // Run the binary search
            runBinarySearch();
            askingForSearchMethod = false;
        } else if (searchMethod == "3") {
            // Run both
            runSequentialSearch();
            runBinarySearch();
            askingForSearchMethod = false;
        } else {
            // If 1, 2 or 3 wasn't entered, re-ask the user
            cout << "I'm sorry, I didn't catch that." << endl << endl;
        }
    } while (askingForSearchMethod);
}
// Function to run the sequential search in a for loop x amount of times
// (x is the number of elements in array)
void userInterface::runSequentialSearch() {
    auto sequential = new sequentialSearch();
    startTimer();
    for(int i = 1; i <= arraySize; i++) {
        if(!sequential->searchSequentially(searchableArray, i, arraySize)) {
            cout << "Number not found!" << endl;
            break;
        }
    }
    endTimer();
    cout << endl << "Sequential search: ";
    displayTotalTime();
    delete sequential;
}

// Function to run the binary search in a for loop x amount of times
// (x is the number of elements in array)
void userInterface::runBinarySearch() {
    auto binary = new binarySearch();
    startTimer();
    for(int i = 1; i <= arraySize; i++) {
        if(!binary->searchBinarily(searchableArray, 0, arraySize, i)) {
            cout << "Number not found!" << endl;
            break;
        }
    }
    endTimer();
    displayTotalTime();
    delete binary;
}

// Function to start a clock
void userInterface::startTimer() {
    start = clock();
}

// Function to stop the clock and get the time and make a string show the time it took
void userInterface::endTimer() {
    double timeTaken = (clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
    ostringstream convertTime;
    convertTime << timeTaken;
    totalEndTime = "Elapsed time: " + convertTime.str() + " ms";
}

// Function to output the time saved from the end timer
void userInterface::displayTotalTime() {
    cout << totalEndTime << endl << endl;
}