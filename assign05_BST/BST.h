/* ************************************************************************
Name: David Boyd
Assignment: 05, Binary Search Tree
Purpose: BST Header File
Notes: None.
Date: 2018.11.23
      2018.11.26
      2018.12.20
Completed: 2018.11.27
************************************************************************ */
#include "main.h"
//#include <functional>   // used for template comparisons

#ifndef ROOT_H
#define ROOT_H

//========================
//=== Template Compare ===
//========================
/*
 * Purpose  : Finds and compares the lesser of two values.
 * Called by: BST::_insert, _makeDeletion, _search.
 * Calls    : none.
 * Returns  : bool.
 * Notes    : Return true if first argument is lesser than second argument.
 */
// The less class returns the result of the < operator on its two operands
template <typename A, typename B, typename U = std::less<>>
bool cmp(A a, B b, U u = U()) { return u(a, b);}

//=======================
//=== Struct TreeNode ===
//=======================
/*  Purpose  : User defined dataType node. */
struct TreeNode {

    int id;
    std::string data;
    TreeNode *left;
    TreeNode *right;
    // TreeNode constructor
    TreeNode( int key, std::string words,
              TreeNode *lchild = nullptr, TreeNode *rchild = nullptr)
            : id(key), data(std::move(words)), left(lchild), right(rchild) {}
}; // end struct

//=================
//=== Class BST ===
//=================
/*  Purpose  : Creates a binary search tree. */
class BST {

private:

    TreeNode* _root;
    int num_nodes;

    // Accessors
    int       _getCount() const;
    TreeNode* _getRootData() const;

    TreeNode* _findMin(TreeNode *) const;
    int       _maxDepth(TreeNode*) const;
    TreeNode* _search(TreeNode *, int) const;

    void _inOrder(TreeNode*) const;
    void _postOrder(TreeNode*) const;
    void _preOrder(TreeNode*) const;

    // Mutators
    void      _setRootData(TreeNode *root);

    TreeNode* _destroyAllNodes(TreeNode *root);
    TreeNode* _insert(TreeNode *, int, std::string);
    TreeNode* _makeDeletion(TreeNode *, int);

public:

    BST();
    ~BST()                           { _destroyAllNodes(_getRootData());   };

    // Accessors
    TreeNode* getEntry(int id) const { return _search(_getRootData(), id); };
    TreeNode* getHead()        const { return _getRootData();              };
    int getHeight()            const { return _maxDepth(_getRootData());   };
    int getNumberOfNodes()     const { return _getCount();                 };

    bool contains(int id)      const { return getEntry(id);                };
    bool isEmpty()             const { return !_getRootData();             };

    void inOrderTraverse()     const { _inOrder  (_getRootData());         };
    void preOrderTraverse()    const { _preOrder (_getRootData());         };
    void postOrderTraverse()   const { _postOrder(_getRootData());         };

    // Mutators
    bool add(int, std::string);
    bool clear();
    bool remove(int);
};
#endif //BST_H