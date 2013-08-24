//============================================================================
// Binary Tree Inorder Traversal
// Given a binary tree, return the inorder traversal of its nodes' values.
//
// For example:
// Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
// return [1,3,2].
//
// Note: Recursive solution is trivial, could you do it iteratively?
//
// Reference:
// http://www.leetcode.com/2010/04/binary-search-tree-in-order-traversal.html
//
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root) {
        //return inorderTraversal1(root);
        return inorderTraversal2(root);
    }

    vector<int> inorderTraversal1(TreeNode* node) {
        vector<int> result;
        inorderTraversalHelper1(node, result);
        return result;
    }

    void inorderTraversalHelper1(TreeNode* node, vector<int> &result) {
        if (node == NULL) return;
        inorderTraversalHelper1(node->left, result);
        result.push_back(node->val);
        inorderTraversalHelper1(node->right, result);
    }

    vector<int> inorderTraversal2(TreeNode *node) {
        vector<int> result;
        if (node == NULL) return result;
        stack<TreeNode*> stk;
        TreeNode* curr = node;
        while (!stk.empty() || curr != NULL) {
            if (curr != NULL) {
                stk.push(curr);
                curr = curr->left;
            }
            else {
                curr = stk.top();
                stk.pop();
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
