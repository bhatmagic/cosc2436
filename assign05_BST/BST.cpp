/* ************************************************************************
Name: David Boyd
Assignment: 05, Binary Search Tree
Purpose: BST source file - definitions
Notes: None.
Date: 2018.11.23
      2018.11.26
      2018.12.20
Completed: 2018.11.27
************************************************************************ */
#include "BST.h"

//==================
//=== _Get Count ===
//==================
/*
 * Purpose  : Gets the number of nodes in tree.
 * Called by: BST::getNumberOfNodes
 * Calls    : none.
 * Returns  : int.
 * Notes    : none.
 */
int BST::_getCount() const {

    return num_nodes;
}

//======================
//=== _Get Root Data ===
//======================
/*
 * Purpose  : Gets the root node.
 * Called by: BST::add, clear, remove,
 *          :      getEntry, getHead, getHeight
 *          :      inOrderTraverse, isEmpty, postOrderTraverse,
 *          :      preOrderTraverse, ~BST.
 * Calls    : none.
 * Returns  : TreeNode*.
 * Notes    : none.
 */
TreeNode* BST::_getRootData() const {

    return _root;
}

//=====================
//=== _Find Minimum ===
//=====================
/*
 * Purpose  : Finds the minimum ID node.
 * Called by: BST::_makeDeletion
 * Calls    : none.
 * Returns  : TreeNode*.
 * Notes    : Returns min node by traversing from root
 *          : to furthest left leaf node.
 */
TreeNode* BST::_findMin(TreeNode *root) const {

    TreeNode* temp = root;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

//==================
//=== _Max Depth ===
//==================
/*
 * Purpose  : Finds the maximum depth of tree.
 * Called by: BST::_maxDepth,
 *          :      getHeight.
 * Calls    : BST::_maxDepth.
 * Returns  : int.
 * Notes    : Total height of tree.
 */
int BST::_maxDepth(TreeNode* node) const {

    if (node == nullptr) {
        return 0;
    } else {

        int lDepth = _maxDepth(node->left);
        int rDepth = _maxDepth(node->right);

        return (lDepth > rDepth) ? (lDepth +1) : (rDepth +1);
    }
}

//===============
//=== _Search ===
//===============
/*
 * Purpose  : Searches the tree based off node's Id.
 * Called by: BST::_search,
 *          :      getEntry.
 * Calls    : BST::_search,
 *          : template::cmp.
 * Returns  : TreeNode*.
 * Notes    :
 */
TreeNode* BST::_search(TreeNode *root, int id) const {

    if (root == nullptr || root->id == id) {
        return root;
    }
    else if ( cmp(root->id, id) ) {
        return _search(root->right, id);
    } else {
        return _search(root->left, id);
    }
}

//=================
//=== _In Order ===
//=================
/*
 * Purpose  : Displays the BST via inorder traversal.
 * Called by: BST::_inOrder,
 *          :      inOrderTraverse.
 * Calls    : BST::_inOrder
 * Returns  : none.
 * Notes    : none.
 */
void BST::_inOrder(TreeNode *current) const {
    if (current) {
        _inOrder(current->left);
        std::cout<<current->id<<SPACE;
        _inOrder(current->right);
    }
}

//===================
//=== _Post Order ===
//===================
/*
 * Purpose  : Displays tree via postorder.
 * Called by: BST::_postOrder,
 *          :      postOrderTraverse.
 * Calls    : BST::_postOrder.
 * Returns  : none.
 * Notes    : Begins with the left-most node, ends with the root.
 *          : Explore all the leaves before any nodes;
 *          : you select post-order because you don't waste
 *          : any time inspecting roots in search for leaves.
 */
void BST::_postOrder(TreeNode *root) const {
    if (root) {
        _postOrder(root->left);
        _postOrder(root->right);
        std::cout<<root->id<<SPACE;
    }
}

//==================
//=== _Pre Order ===
//==================
/*
 * Purpose  : Displays tree via preorder.
 * Called by: BST::_preOrder,
 *          :      preOrderTraverse.
 * Calls    : BST::_preOrder.
 * Returns  : none.
 * Notes    : Begins at the root, ends at the right-most node.
 *          : Explore the roots before inspecting any leaves,
 *          : you pick pre-order because you will encounter
 *          : all the roots before all of the leaves.
 */
void BST::_preOrder(TreeNode *root) const {
    if (root) {
        std::cout<<root->id<<SPACE;
        _preOrder(root->left);
        _preOrder(root->right);
    }
}

//======================
//=== _Set Root Data ===
//======================
/*
 * Purpose  : Sets the public root node to object's private.
 * Called by: main.
 * Calls    : BST::add, constructor, clear.
 * Returns  : none.
 * Notes    : none.
 */
void BST::_setRootData(TreeNode *root) {
    _root = root;
}

//==========================
//=== _Destroy All Nodes ===
//==========================
/*
 * Purpose  : Deallocates all nodes in tree from memory.
 * Called by: BST::_destroyAllNodes,
 *          :      clear, ~BST().
 * Calls    : BST::_destroyAllNodes
 * Returns  : TreeNode*.
 * Notes    : Returns root* as NULL.
 */
TreeNode* BST::_destroyAllNodes(TreeNode *root) {
    if (root == nullptr) return root;

    // Delete both subtrees via post-order traversal
    _destroyAllNodes(root->left);
    _destroyAllNodes(root->right);

    // Delete the node at the root
    delete (root);

    root = nullptr;
    return root;
}

//===============
//=== _Insert ===
//===============
/*
 * Purpose  : Inserts TreeNode accordingly into BST.
 * Called by: BST::add.
 * Calls    : template::cmp.
 * Returns  : TreeNode*.
 * Notes    : Returns inserted node.
 *          : Inserts according to node's value left.
 */
TreeNode* BST :: _insert(TreeNode *root, int id, std::string data) {

    if (root == nullptr) { return new TreeNode(id, std::move(data)); }

    while (root) {
        if (cmp(id, root->id)) {
            if (root->left != nullptr) {root = root->left; }
            else {
                root->left = new TreeNode(id, std::move(data));
                break;
            }
        }
        else if (cmp(root->id, id)) {
            if (root->right != nullptr) {root = root->right; }
            else {
                root->right = new TreeNode(id, std::move(data));
                break;
            }
        }
        else { return nullptr; }
    }
    return root;
}

//======================
//=== _Make Deletion ===
//======================
/*
 * Purpose  : Deletes a node in tree based of its Id.
 * Called by: BST::_makeDeletion, remove.
 * Calls    : BST::_findMin,_makeDeletion
 * Returns  : TreeNode*.
 * Notes    : Rearranges BST in relation to its Id.
 */
TreeNode* BST::_makeDeletion(TreeNode *root, int id) {

    // If node doesn't exist
    if (root == nullptr) { return nullptr; }

    // Find node
    else if (cmp(id, root->id)) { root->left  = _makeDeletion(root->left,  id); }
    else if (cmp(root->id, id)) { root->right = _makeDeletion(root->right, id); }

    // Delete found node
    else {
        // Case 1: node has two-children
        if (root->left == nullptr
            && root->right == nullptr ) {
            delete root;
            root = nullptr;
        // Case 2a: node has one right child
        } else if (root->left == nullptr) {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        // Case 2b: node has one left child
        } else if (root->right == nullptr) {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        // Case 3: node has two-children
        } else {
            TreeNode *temp = _findMin(root->right);
            root->id = temp->id;
            root->right = _makeDeletion(root->right, temp->id);
        }
    }
    return root;
}

//===================
//=== Constructor ===
//===================
/*
 * Purpose  : Defaults root node to NULL and count to 0.
 * Called by: main.
 * Calls    : BST::_setRootData
 * Returns  : none.
 * Notes    : none.
 */
BST::BST(){
    _setRootData(nullptr);
    num_nodes = 0;
}

//===========
//=== Add ===
//===========
/*
 * Purpose  : Public method to add node into tree.
 * Called by: functions::assignRandomId.
 * Calls    : BST::_getRootData, _insert, _setRoodData.
 * Returns  : bool.
 * Notes    : none.
 */
bool BST::add(int id, std::string data) {

    // If tree is empty
    if (_getRootData() == nullptr){
        _setRootData(_insert(_getRootData(), id, data));
        ++num_nodes;
        return true;
    } else {
        TreeNode *temp = _insert(_getRootData(), id, data);
        if (!temp) { return false; }
        else {
            ++num_nodes;
            return true;
        }
    }
}

//=============
//=== Clear ===
//=============
/*
 * Purpose  : Public method to destroy all nodes in tree.
 * Called by: functions::deleteBST
 * Calls    : BST::_destroyAllNodes, _setRootData.
 * Returns  : bool.
 * Notes    : none.
 */
bool BST::clear() {
    if(!_destroyAllNodes(_getRootData())) {
        _setRootData(nullptr);
        num_nodes = 0;
        return true;
    } else { return false; }
}

//==============
//=== Remove ===
//==============
/*
 * Purpose  : Public method to delete a node from tree.
 * Called by: functions::checkDeletion.
 * Calls    : BST::_makeDeletion.
 * Returns  : bool.
 * Notes    : none.
 */
bool BST::remove(int id){
    if (contains(id)){
        _makeDeletion(_getRootData(), id);
        --num_nodes;
        return true;
    } else { return false; }
}