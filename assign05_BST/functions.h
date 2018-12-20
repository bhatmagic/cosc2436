/* ************************************************************************
Name: David Boyd
Assignment: 05, Binary Search Tree
Purpose: Functions header file
Notes: none.
Date: 2018.11.23
      2018.11.26
      2018.12.20
Completed: 2018.11.27
************************************************************************ */
#include "main.h"
#include "BST.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void assignRandomId(BST *root, int n);
void checkClassAccessors(BST*);
void checkContainer(BST*);
void checkDeletion(BST*);
void deleteBST(BST*);
void printAll(BST*);
bool verify(int, char**);

#endif //FUNCTIONS_H
