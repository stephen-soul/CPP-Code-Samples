/*
 * DATA STRUCTURES LINE EDITOR // STEPHEN FETINKO 2018
 */

#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList() {
}

/*
 *	DESTRUCTOR
 */

LinkedList::~LinkedList() {
    Node *node = first;

    while (node != nullptr) {
        Node *temp = node;

        node = node->next;

        delete temp;
    }
}

/*
 *	ADD TO THE LIST
 */

void LinkedList::add(std::string num) {
    Node *node = new Node();
    node->data = num;

    if (first == NULL) {
        first = node;
    } else {
        Node *currNode = first;
        Node *prevNode = NULL;

        while (currNode != NULL) {
            prevNode = currNode;
            currNode = currNode->next;
        }

        if (prevNode != NULL) {
            prevNode->next = node;
        }
    }
}

/*
 *	DELETE A VALUE
 */

void LinkedList::deleteValue(std::string value) {
    Node *node = first;
    Node *prev = nullptr;

    while (node != nullptr) {
        if (node->data == value) {
            break;
        }

        prev = node;
        node = node->next;
    }

    if (node != nullptr) {
        if (node == first) {
            first = node->next;
        } else {
            prev->next = node->next;
        }

        delete node;
    }
}

/*
 *	DELETE A NODE
 */

void LinkedList::deleteNode(int nodenum) {
    int index = -1;

    Node *node = first;
    Node *prev = nullptr;

    while (node != nullptr) {
        index++;

        if (index == nodenum) {
            break;
        }

        prev = node;
        node = node->next;
    }

    if (index >= 0) {
        if (node == first) {
            first = node->next;
        } else {
            prev->next = node->next;
        }

        delete node;
    }
}

/*
 *	INSERT AFTER CURRENT VALUE
 */

void LinkedList::insertAfterValue(std::string value, std::string num) {
    Node *node = new Node();
    node->data = num;

    // search for node to insert after
    Node *prev = first;

    while (prev != nullptr) {
        if (prev->data == value) {
            break;
        }

        prev = prev->next;
    }

    // insert node into list
    if (first == nullptr) {
        first = node;
    } else {
        if (prev != nullptr) {
            node->next = prev->next;
            prev->next = node;
        } else {
            // could not find the node to insert after
            // so defaulting to Add function
            add(num);
        }
    }
}

/*
 *	INSERT BEFORE CURRENT NODE
 */

void LinkedList::insertBeforeNode(int nodenum, std::string num) {
    int index = -1;
    Node *newnode = new Node();
    newnode->data = num;
    Node *node = first;
    Node *prev = first;

    while (node != nullptr) {
        index++;

        if (index == nodenum) {
            break;
        }

        prev = node;
        node = node->next;
    }

    // insert node into list
    if (first == nullptr) {
        first = newnode;
    } else {
        if (node != nullptr) {
            prev->next = newnode;
            newnode->next = node;
        } else {
            // could not find the node to insert after
            // so defaulting to Add function
            add(num);
        }
    }
}

/*
 *	DISPLAY LINES WITH LINE NUMBER
 */

void LinkedList::displayWithLineNumber() {
    // Get the node, put it at the beginning, while node != nullptr show the data
    int lineNumber = 1;
    Node *node = new Node;
    node = first;
    while (node != nullptr) {
        std::cout << lineNumber << ". " << node->data << std::endl;
        node = node->next;
        lineNumber++;
    }
}

/*
 *	DISPLAY LINES WITHOUT LINE NUMBER
 */

void LinkedList::displayWithoutLineNumber() {
    Node *node = new Node;
    node = first;
    while (node != nullptr) {
        std::cout << node->data << std::endl;
        node = node->next;
    }
}

void LinkedList::addToPosition(int position, std::string value) {
    // Add to a specific position
    Node *previous = new Node;
    Node *current = new Node;
    Node *temporary = new Node;
    current = first;
    for (int i = 1; i < position; i++) {
        previous = current;
        current = current->next;
    }
    temporary->data = value;
    previous->next = temporary;
    temporary->next = current;
}
