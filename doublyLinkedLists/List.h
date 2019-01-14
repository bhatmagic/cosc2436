/* ************************************************************************
Name: David Boyd
Assignment: 03, Doubly Linked List
Purpose: List header file
Notes: none.
Completed: 2018.10.27
************************************************************************ */
#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {

public:

    Node *headptr;
    Node *tailptr;

    // Note: single argument constructors must be marked
    // explicit to avoid unintentional implicit conversions
    explicit List(int);

    bool addNode(Node *, Node *);
    bool deleteHeadNode(Node *);
    bool deleteNode(Node *, int);
    bool deleteMiddleNode(Node *);
    bool deleteTailNode(Node *);
    void printList(Node *);

};

#endif /* LIST_H */