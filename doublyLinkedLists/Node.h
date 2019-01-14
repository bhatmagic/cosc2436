/* ************************************************************************
Name: David Boyd
Assignment: 03, Doubly Linked List
Purpose: Node header file
Notes: none.
Completed: 2018.10.27
************************************************************************ */
#ifndef ASSIGN03_LINKEDLISTS_NODE_H
#define ASSIGN03_LINKEDLISTS_NODE_H

class Node {

private:

    int _id;         // value
    Node *_forward;  // _forward pointer
    Node *_backward; // _backward pointer

public:

    static int count;   // running count of Nodes

    explicit Node(int);

    int getCount();
    int getId();
    Node *getForward();
    Node *getBackward();

    void setCount(int);
    void setId(int);
    void setForward(Node *);
    void setBackward(Node *);

};

#endif //ASSIGN03_LINKEDLISTS_NODE_H