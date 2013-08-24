//============================================================================
// Recover Binary Search Tree
// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//============================================================================

#include <iostream>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        recoverTreeHelper(root, prev, first, second);
        swap(first->val, second->val);
    }

    void recoverTreeHelper(TreeNode *curNode, TreeNode *&preNode, TreeNode *&first, TreeNode *&second) {
        if (curNode == NULL) return;
        recoverTreeHelper(curNode->left, preNode, first, second);
        if (preNode && preNode->val > curNode->val) {
            if (first == NULL) first = preNode;
            second = curNode;
        }
        preNode = curNode;
        recoverTreeHelper(curNode->right, preNode, first, second);
    }
};

int main() {
    return 0;
}
