//
// Created by stephen on 12/02/18.
//

#ifndef MAZESOLVER_STACK_H
#define MAZESOLVER_STACK_H
#include "stackNode.h"

enum errorCodes { success, underflow, overflow };

class stack {
public:
    // Constructor and Destructor
    stack();
    virtual ~stack();

    // Functions
    errorCodes Push( int num );
    int Peek();
    errorCodes Pop();
private:
    stackNode *_top;
};


#endif //MAZESOLVER_STACK_H
