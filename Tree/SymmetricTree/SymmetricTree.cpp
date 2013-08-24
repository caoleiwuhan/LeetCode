//============================================================================
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric
// around its center).
//
// For example, this binary tree is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.
//
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
    bool isSymmetric(TreeNode *root) {
        return isSymmetric1(root);
    }

    bool isSymmetric1(TreeNode *root) {
        if (root == NULL) return true;
        return isSymmetricHelper1(root->left, root->right);
    }

    bool isSymmetricHelper1(TreeNode *a, TreeNode *b) {
        if (a == NULL || b == NULL) return (a == b);
        return (a->val == b->val)
            && isSymmetricHelper1(a->left, b->right)
            && isSymmetricHelper1(a->right, b->left);
    }
};

int main() {
    return 0;
}
