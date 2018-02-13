//
// Created by stephen on 12/02/18.
//

#ifndef MAZESOLVER_STACKNODE_H
#define MAZESOLVER_STACKNODE_H


class stackNode {
public:
    // Constructor
    stackNode();
    stackNode( int data, stackNode* next );
    // Virtual destructor
    virtual ~stackNode();
    // Function
    int getData();
    void setData( int data );

    stackNode* getNext();
    void setNext( stackNode *next );
private:
    // Variables
    int _data;
    stackNode *_next;
};


#endif //MAZESOLVER_STACKNODE_H
