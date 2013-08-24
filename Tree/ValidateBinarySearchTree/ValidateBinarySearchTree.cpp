//============================================================================
// Validate Binary Search Tree
// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than the
// node's key. The right subtree of a node contains only nodes with keys
// greater than the node's key. Both the left and right subtrees must also be
// binary search trees.
//============================================================================

#include <iostream>
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
    bool isValidBST(TreeNode *root) {
        //        return isValidBST1(root);
        //        return isValidBST2(root);
        return isValidBST3(root);
    }

    // pre-order walk with looking up min and max
    // takes O(n*log(n)) time
    bool isValidBST1(TreeNode* node) {
        if (node == NULL) return true;
        if (maxVal(node->left) < node->val && node->val < minVal(node->right)) {
            return isValidBST1(node->left) && isValidBST1(node->right);
        }
        return false;
    }

    int minVal(TreeNode* node) {
        if (node == NULL) return INT_MAX;
        while (node->left != NULL) node = node->left;
        return node->val;
    }

    int maxVal(TreeNode* node) {
        if (node == NULL) return INT_MIN;
        while (node->right != NULL) node = node->right;
        return node->val;
    }

    // pre-order walk with updating min and max
    // takes O(n) time
    bool isValidBST2(TreeNode* node) {
        return isValidBSTHelper2(node, INT_MIN, INT_MAX);
    }

    bool isValidBSTHelper2(TreeNode* node, int min, int max) {
        if (node == NULL) return true;
        if (min  < node->val && node->val < max) {
            return isValidBSTHelper2(node->left, min, node->val)
                    && isValidBSTHelper2(node->right, node->val, max);
        }
        return false;
    }

    // in-order walk and check if it is no-decreasing
    // takes O(n) time
    bool isValidBST3(TreeNode* node) {
        int prev = INT_MIN;
        return isValidBSTHelper3(node, prev);
    }

    bool isValidBSTHelper3(TreeNode* node, int &prev) {
        if (node == NULL) return true;
        if (isValidBSTHelper3(node->left, prev)) {
            if (prev < node->val) {
                prev = node->val;
                return isValidBSTHelper3(node->right, prev);
            }
            return false;
        }
        return false;
    }
};

int main() {
    return 0;
}
