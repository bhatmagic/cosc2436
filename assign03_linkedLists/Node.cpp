/* ************************************************************************
Name: David Boyd
Assignment: 03, Doubly Linked List
Purpose: Node definitions
Notes: none.
Completed: 2018.10.27
************************************************************************ */
#include "Node.h"

//===================
//=== Constructor ===
//===================
/*
 * Purpose  : Assigns default values to Node
 * Called by: List
 * Calls    : setId, setForward, setBackward.
 * Returns  : none.
 * Notes    : none.
 */
Node::Node(int randomInt){
    setId(randomInt);
    setForward(nullptr);
    setBackward(nullptr);
}

//===============
//=== Methods ===
//===============
/*
 * Purpose: Getters and Setters
 */
Node* Node::getBackward()       { return _backward;}
int   Node::getCount()          { return count;   }
Node* Node::getForward()        { return _forward; }
int   Node::getId()             { return _id;      }

void  Node::setBackward(Node* b){ _backward = b;   }
void  Node::setCount(int cnt)   { count=cnt;      }
void  Node::setForward(Node* f) { _forward = f;    }
void  Node::setId(int randomInt){ _id = randomInt; }