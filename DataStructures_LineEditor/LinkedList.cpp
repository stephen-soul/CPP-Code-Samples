/*
 * DATA STRUCTURES LINE EDITOR // STEPHEN FETINKO 2018
 */

#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList() {
    // Construct the head and the tail from node to null to avoid garbage
    head = nullptr;
    tail = nullptr;
}

/*
 *	DESTRUCTOR
 */

LinkedList::~LinkedList() {
    Node *node = head;
    if(node == nullptr) {

    } else {
        while (node != nullptr) {
            Node *temp = node;

            node = node->next;

            delete temp;
        }
    }
}

/*
 *	ADD TO THE LIST
 */

void LinkedList::add(std::string num) {
    Node *node = new Node;
    node->data = num;
    node->next = nullptr;

    if(head == nullptr) {
        head = node;
        tail = node;
        node = nullptr;
    } else {
        tail->next = node;
        tail = node;
    }
}

//void LinkedList::add(std::string num) {
//    Node *node = new Node();
//    node->data = num;
//
//    if (head == nullptr) {
//        head = node;
//    } else {
//        Node *currNode = head;
//        Node *prevNode = nullptr;
//
//        while (currNode != nullptr) {
//            prevNode = currNode;
//            currNode = currNode->next;
//        }
//
//        if (prevNode != nullptr) {
//            prevNode->next = node;
//        }
//    }
//}

/*
 *	DELETE A VALUE
 */

void LinkedList::deleteValue(std::string value) {
    Node *node = head;
    Node *prev = nullptr;

    while (node != nullptr) {
        if (node->data == value) {
            break;
        }

        prev = node;
        node = node->next;
    }

    if (node != nullptr) {
        if (node == head) {
            head = node->next;
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

    Node *node = head;
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
        if (node == head) {
            head = node->next;
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
    Node *prev = head;

    while (prev != nullptr) {
        if (prev->data == value) {
            break;
        }

        prev = prev->next;
    }

    // insert node into list
    if (head == nullptr) {
        head = node;
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
    Node *node = head;
    Node *prev = head;

    while (node != nullptr) {
        index++;

        if (index == nodenum) {
            break;
        }

        prev = node;
        node = node->next;
    }

    // insert node into list
    if (head == nullptr) {
        head = newnode;
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

void LinkedList::display() {
    // Get the node, put it at the beginning, while node != nullptr show the data
    Node *node;
    lineNumber = 1;
    node = head;
    while (node != nullptr) {
        std::cout << lineNumber << ". " << node->data << std::endl;
        node = node->next;
        lineNumber++;
    }
}

void LinkedList::addToPosition(int position, std::string value) {
    // Add to a specific position
    Node *previous = new Node;
    Node *current = new Node;
    Node *temporary = new Node;
    current = head;
    if(position == 1) {
        temporary->data = value;
        previous->next = temporary;
        current = current->next;
        temporary->next = current;
    }
    for (int i = 1; i < position; i++) {
        previous = current;
        current = current->next;
    }
    temporary->data = value;
    previous->next = temporary;
    temporary->next = current;
}

/*
 * ENTER AT THE BEGINNING OF THE NODE
 */

void LinkedList::insertAtStart(std::string value)  {
    auto *node=new Node;
    node->data=value;
    node->next=head;
    head=node;
}