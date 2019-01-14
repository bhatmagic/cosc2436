/* ************************************************************************
Name: David Boyd
Assignment: 03, Doubly Linked List
Purpose: Functions source file - definitions
Notes: none.
Completed: 2018.10.27
************************************************************************ */
#include "Functions.h"

//==============
//=== Verify ===
//==============
/*
 * Purpose  : Checks main's parameters.
 * Called by: main.cpp.
 * Calls    : none.
 * Returns  : bool.
 * Notes    : none.
 */
bool verify(int count, char** value){

    std::string wrong = "Argument needs to equal 2\n"
                        "Gratefully exiting...";

    std::string bound = "is not within bounds\n"
                        "Gradually exiting...";

    // Check for 2 arguments
    if (count != 2) {
        std::cout << wrong << std::endl;
        return false;
    }

    // Check bounds of argument
    int num = std::atoi(value[1]);
    if ((num > MAX_BOUND) || (num < MIN_BOUND)) {
        std::cout << num << SPACE << bound << std::endl;
        return false;
    }

    else {
        return true;
    }
}