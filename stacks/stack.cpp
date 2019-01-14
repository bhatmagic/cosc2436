/* ************************************************************************
Name: David Boyd
Assignment: 04, Stacks
Purpose: Stack object definition
Notes: None.
Completed: 2018.10.04
************************************************************************ */
#include "stack.h"

//=======================
//=== Constructor() =====
//=======================
Stack::Stack() {
    _arr = new DATA*[CAPACITY];
    _size = CAPACITY;
    _count = 0;
    _ids = 1;
    assert (_arr != nullptr);  // Check whether storage allocation was successful
                               // If OS is unable to allocate the num of bytes
                               // requested, it sets the pointer to 0.
}                              // Likely upon allocations >= 5 MB declarations of memory
//=======================
//=== Destructor() ======
//=======================
Stack::~Stack() {
    delete _arr;
}

//=============
//=== Clear ===
//=============
/* Purpose: Clears the stack without deleting it*/
void Stack::clear() {
    while (_count > 0) {
        pop();
        _count--;
    }
}

//=======================
//=== bool is_empty() ===
//=======================
bool Stack::is_empty() const {
    return (_count == 0);
}

//=======================
//=== bool is_full() ====
//=======================
/* Purpose: Return if stack is at capacity */
bool Stack::is_full() const {
    return (_count == _size);
}

//============
//=== Peak ===
//============
/* Purpose: Returns the last element on stack */
DATA* Stack::peak() const {
    if (_count > 0) {
        return _arr[_count - 1];
    } else{
        return nullptr;
    }
}

//===========
//=== Pop ===
//===========
DATA* Stack::pop() {

    if (_count > 0) {
        _count--;
        return _arr[_count];
    } else {
        return nullptr;
    }
}

//============
//=== Push ===
//============
void Stack::push(DATA* d) {
    if (_count < _size) {
        d->id_ = _ids;
        _arr[_count] = d;
        _count++;
        _ids++;
    }
}