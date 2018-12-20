/* ************************************************************************
Name: David Boyd
Assignment: 05, Binary Search Tree
Purpose: Main Program
Notes: None.
Date: 2018.11.23
      2018.11.26
      2018.12.20
Completed: 2018.11.27
************************************************************************ */
#include "main.h"
#include "functions.h"
#include "BST.h"

int main(int argc, char **argv) {

    // validate main arguments
    if (!verify(argc, argv)){
        return 0;
    }

    // create BST
    BST* root = new BST;
    assignRandomId(root, std::atoi(argv[1]));

    // check BST
    checkClassAccessors(root);
    printAll(root);
    checkContainer(root);

    // deleteNode
    checkDeletion(root);
    checkClassAccessors(root);
    printAll(root);

    // delete BST
    deleteBST(root);

    // check BST
    checkClassAccessors(root);
    checkContainer(root);

    std::cout<<std::endl;

    return 0;
}