//
// Created by stephen on 12/02/18.
//

#include "stack.h"

stack::stack() : _top(nullptr) {

}

stack::~stack() {
    while(_top != nullptr) {
        Pop();
    }
}

errorCodes stack::Push(int num) {
    _top = new stackNode(num, _top);
    return(success);
}

int stack::Peek() {
    return _top->getData();
}

errorCodes stack::Pop() {
    if (_top != nullptr) {

        stackNode* node = _top;
        _top = _top->getNext();
        delete node;
        return(success);
    }
    else {
        return(underflow);
    }
}

errorCodes stack::Check() {
    if (_top != nullptr) {
        return(success);
    }
    else {
        return(underflow);
    }
}