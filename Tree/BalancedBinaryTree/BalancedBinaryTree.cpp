//============================================================================
// Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.
//
// An example of a height-balanced tree. A height-balanced tree is a tree
// whose subtrees differ in height by no more than one and the subtrees are
// height-balanced, too.
//============================================================================

#include <iostream>
#include <cmath>
#include <climits>
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
    bool isBalanced(TreeNode *root) {
        return isBalanced1(root);
    }

    bool isBalanced1(TreeNode *root) {
        return isBalancedHelper1(root);
    }

    bool isBalancedHelper1(TreeNode* node) {
        if (node == NULL) return true;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (abs(leftHeight - rightHeight) > 1) return false;
        return isBalancedHelper1(node->left) && isBalancedHelper1(node->right);
    }

    int height(TreeNode *node) {
        if (node == NULL) return 0;
        return (1 + max(height(node->left), height(node->right)));
    }

    bool isBalanced2(TreeNode *root) {
        int height;
        return isBalancedHelper2(root, height);
    }

    bool isBalancedHelper2(TreeNode *node, int &height) {
        if (node == NULL) {
            height = 0;
            return true;
        }
        int leftHeight, rightHeight;
        bool leftBalanced = isBalancedHelper2(node->left, leftHeight);
        bool rightBalanced = isBalancedHelper2(node->right, rightHeight);
        height = 1+max(leftHeight, rightHeight);
        return (leftBalanced && rightBalanced && abs(leftHeight-rightHeight) <= 1);
    }
};

int main() {
    return 0;
}
