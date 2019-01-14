/* ************************************************************************
Name: David Boyd
Assignment: 05, Binary Search Tree
Purpose: Functions source file - definitions
Notes: none.
Date: 2018.11.23
      2018.11.26
      2018.12.20
Completed: 2018.11.27
************************************************************************ */
#include "functions.h"

//========================
//=== Assign Random ID ===
//========================
/*
 * Purpose  : Assigns a random integer to node's Id.
 * Called by: main.cpp.
 * Calls    : BST::add.
 * Returns  : none.
 * Notes    : none.
 */
void assignRandomId(BST *root, int n) {

    // One time seed for random
    srand(static_cast<unsigned int>(time(nullptr)));

    // Loop through number of needed nodes.
    for (int i = 0; i < n; ++i) {
        // Create random id for node.
        int id = rand() % MAX_RAND + MIN_RAND;
        std::string data = "\"This is Node " + std::to_string(id) + "'s data\"";
        // Add node to tree.
        if (!root->add(id, data)) {std::cout<<"\nAttempted placement of duplicate node.  \nNode count -1.\n";}
    }
}

//=============================
//=== Check Class Accessors ===
//=============================
/*
 * Purpose  : Calls the tree's accessor methods.
 * Called by: main.cpp.
 * Calls    : BST::isEmpty, getHeight, getNumberOfNodes.
 * Returns  : none.
 * Notes    : none.
 */
void checkClassAccessors(BST* root) {

    std::cout << "\n------------------------------";
    std::cout << "\nTesting BST's Accessor Methods";
    std::cout << "\n------------------------------";
    std::cout << "\nisEmpty?:" << SPACE << (root->isEmpty() ? "Yes" : "No");
    std::cout << "\ngetHeight():" << SPACE << root->getHeight();
    std::cout << "\ngetNumberOfNodes():" << SPACE << root->getNumberOfNodes() << std::endl;
}

//=======================
//=== Check Container ===
//=======================
/*
 * Purpose  : Checks if tree holds a node based off its id.
 * Called by: main.cpp.
 * Calls    : BST::inOrderTraverse.
 * Returns  : none.
 * Notes    : none.
 */
void checkContainer(BST* root) {

    int id;
    int nTests;

    std::cout << "\n\n----------------";
    std::cout << "\nTest BST's Nodes";
    std::cout << "\n----------------";
    std::cout << "\nInput the number of containment tests you want to perform:" << SPACE;
    std::cin >> nTests;
    for (int i = 0; i < nTests; i++) {
        std::cout << "\nEnter id or '0' to cancel:" << SPACE;
        std::cin >> id;

        if (id != 0) {
            std::cout << "\nThis tree contains" << SPACE << id << ":" << SPACE
                      << (root->contains(id) ? "Yes\n" : "No\n");
            root->inOrderTraverse();
        } else break;
    }
}

//======================
//=== Check Deletion ===
//======================
/*
 * Purpose  : Calls for the deletion of a node based of its id.
 * Called by: main.cpp.
 * Calls    : BST::remove, inOrderTraversal.
 * Returns  : none.
 * Notes    : none.
 */
void checkDeletion(BST* root) {

    int id;
    int nTests;

    std::cout << "\n-------------------";
    std::cout << "\nTest BST's Deletion";
    std::cout << "\n-------------------";
    std::cout << "\nInput the number of deletion tests you want to perform:" << SPACE;
    std::cin >> nTests;
    for (int i = 0; i < nTests; i++) {
        std::cout << "\nEnter id to remove TreeNode or '0' to cancel:" << SPACE;
        std::cin >> id;

        if (id != 0) {
            std::cout<< (root->remove(id) ? "\nNode Deleted\n" : "\nNode not found\n");
            std::cout<<std::endl;
            root->inOrderTraverse();

        } else break;
    }
}

//==================
//=== Delete BST ===
//==================
/*
 * Purpose  : Deletes BST.
 * Called by: main.cpp.
 * Calls    : BST::clear.
 * Returns  : none.
 * Notes    : none.
 */
void deleteBST(BST* root) {

    std::cout<<"\n\n=============================================================";
    std::cout<<"\n\n                     Deleting BST...";
    std::cout<<"\n\n=============================================================";
    root->clear();
}

//=================
//=== Print All ===
//=================
/*
 * Purpose  : Displays tree via inorder, preorder, and postorder.
 * Called by: main.cpp.
 * Calls    : BST::inOrderTraverse, preOrderTraverse, postOrderTraverse.
 * Returns  : none.
 * Notes    : none.
 */
void printAll(BST* root) {

    std::cout << "\n---------------------------";
    std::cout << "\nTesting BST's Print Methods";
    std::cout << "\n---------------------------";
    std::cout << "\nIn   Order Traversal:" << SPACE;
    root->inOrderTraverse();
    std::cout << "\nPre  Order Traversal:" << SPACE;
    root->preOrderTraverse();
    std::cout << "\nPost Order Traversal:" << SPACE;
    root->postOrderTraverse();
}

//==============
//=== Verify ===
//==============
/*
 * Purpose  : Checks for terminal argument count and bounds.
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

    // argc and argv checking
    if (count != 2) {
        std::cout << wrong << std::endl;
        return false;
    }

    int num = std::atoi(value[1]);

    if ((num > MAX_BOUND) || (num < MIN_BOUND)) {
        std::cout << num << SPACE << bound << std::endl;
        return false;
    }
    else
        return true;
}