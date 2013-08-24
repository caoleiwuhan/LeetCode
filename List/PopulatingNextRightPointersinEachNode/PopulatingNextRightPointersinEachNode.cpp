//============================================================================
// Populating Next Right Pointers in Each Node
// 
// Given a binary tree
//
// struct TreeLinkNode {
//     TreeLinkNode *left;
//     TreeLinkNode *right;
//     TreeLinkNode *next;
// }
//
// Populate each next pointer to point to its next right node. If there is no 
// next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
// Note:
//
// You may only use constant extra space.
// You may assume that it is a perfect binary tree (ie, all leaves are at the 
// same level, and every parent has two children).
// 
// For example, given the following perfect binary tree:
//  "     1     "
//  "    / \    "
//  "   2   3   "
//  "  / \ / \  "
//  " 4  5 6  7 "
// After calling your function, the tree should look like:
//  "      1 -> NULL      "
//  "     /  \            "
//  "    2 -> 3 -> NULL   "
//  "   / \  / \          "
//  "  4->5->6->7 -> NULL "
//============================================================================

#include <iostream>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode 
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution 
{
public:
    void connect(TreeLinkNode *root)
    {
        //connect1(root);
        connect2(root);
    }

    void connect1(TreeLinkNode *node)
    {
        if (node) node->next = NULL;
        connectHelper1(node);
    }

    // BFS
    void connectHelper1(TreeLinkNode* node) {
        if (!node || !(node->left) || !(node->right)) return;
        TreeLinkNode* curr = node;
        while (curr) {
            if (curr->left) curr->left->next = curr->right;
            if (curr->right) curr->right->next = (curr->next) ? curr->next->left : NULL;
            curr = curr->next;
        }   
        connectHelper1(node->left);
    }   

    void connect2(TreeLinkNode *node)
    {
        if (node) node->next = NULL;
        connectHelper2(node);
    }
    
    // DFS
    void connectHelper2(TreeLinkNode* node) {
        if (!node || !(node->left) || !(node->right)) return;
        node->left->next = node->right;
        node->right->next = (node->next) ? node->next->left: NULL;
        connectHelper2(node->left);
        connectHelper2(node->right);
    }
};

int main()
{
    return 0;    
}
