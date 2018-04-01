// C++ console application to compare sequential and binary searches | Stephen Fetinko 2018

#ifndef SEARCHING_SEQUENTIALSEARCH_H
#define SEARCHING_SEQUENTIALSEARCH_H
#include <iostream>
#include <string>

class sequentialSearch {
public:
    sequentialSearch();
    ~sequentialSearch();
    bool searchSequentially(int (&myArray)[1000], int numberToSearch, int arraySize);
    int index;
private:
};


#endif //SEARCHING_SEQUENTIALSEARCH_H