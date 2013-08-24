//============================================================================
// Flatten Binary Tree to Linked List
// Given a binary tree, flatten it to a linked list in-place.
//
// For example,
// Given
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
// The flattened tree should look like:
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6
// Hints:
// If you notice carefully in the flattened tree, each node's right child
// points to the next node of a pre-order traversal.
//============================================================================

#include <iostream>
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
    void flatten(TreeNode *root) {
        return flatten1(root);
        //        return flatten2(root);
    }

    void flatten1(TreeNode *root) {
        TreeNode* res = NULL;
        flattenHelper1(root, res);
        root = res;
    }

    void flattenHelper1(TreeNode *node, TreeNode *&res) {
        if (node == NULL) return;
        TreeNode* leftSub = node->left;
        node->left = NULL;
        TreeNode* rightSub = node->right;
        node->right = NULL;
        if (res == NULL) res = node;
        else res->right = node, res = res->right;
        flattenHelper1(leftSub, res);
        flattenHelper1(rightSub, res);
    }

    void flatten2(TreeNode *root) {
        if (root == NULL) return;
        TreeNode *res = NULL;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* top = stk.top();
            stk.pop();
            if (top->right) stk.push(top->right), top->right = NULL;
            if (top->left) stk.push(top->left), top->left = NULL;
            if (res == NULL) res = top;
            else res->right = top, res = res->right;
        }
        root = res;
    }
};

int main() {
    return 0;
}
