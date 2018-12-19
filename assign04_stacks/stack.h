/* ************************************************************************
Name: David Boyd
Assignment: 04, Stacks
Purpose: Stack header file.
Notes: None.
Completed: 2018.10.04
************************************************************************ */

#ifndef BLUEPRINT2_STACK_STACK_H
#define BLUEPRINT2_STACK_STACK_H

#include "main.h"

// Global variables
#define CAPACITY 6  // the maximum number of elements on the stack

struct DATA {

    int id_;
    std::string data_;
};

class Stack {

private:

    int _count;    // the number of elements on the stack
    int _ids;      // the identification of each stack
    int _size;     // the maximum number of elements on the stack
    DATA **_arr;   // the stack itself: a dynamic array of pointers to DATA

public:

    Stack();
    ~Stack();

    void clear();
    bool is_empty() const;
    bool is_full() const;
    DATA *peak() const;
    void push(DATA*);
    DATA *pop();
};
#endif //BLUEPRINT2_STACK_STACK_H