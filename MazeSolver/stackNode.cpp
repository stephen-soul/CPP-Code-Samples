//
// Created by stephen on 12/02/18.
//

#include "stackNode.h"

stackNode::stackNode() : _data(0), _next(nullptr)  {

}

stackNode::stackNode( int data, stackNode* next ) : _data(data), _next(next) {

}

stackNode::~stackNode() {

}

// Getters and setters

int stackNode::getData()
{
    return _data;
}

void stackNode::setData( int data )
{
    _data = data;
}

stackNode* stackNode::getNext()
{
    return _next;
}

void stackNode::setNext( stackNode *next )
{
    _next = next;
}