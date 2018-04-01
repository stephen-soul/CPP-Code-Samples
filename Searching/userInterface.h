// C++ console application to compare sequential and binary searches | Stephen Fetinko 2018

#ifndef SEARCHING_USERINTERFACE_H
#define SEARCHING_USERINTERFACE_H

#include <ctime>
#include "sequentialSearch.h"
#include "binarySearch.h"

class userInterface {
public:
    userInterface();
    ~userInterface();
    void introduction();
    void runSequentialSearch();
    void runBinarySearch();
    int searchableArray[1000];
    int arraySize;
private:
    bool askingForSearchMethod;
    std::string searchMethod;
    void startTimer();
    void endTimer();
    void displayTotalTime();
    std::clock_t start;
    std::string totalEndTime;
};


#endif //SEARCHING_USERINTERFACE_H
