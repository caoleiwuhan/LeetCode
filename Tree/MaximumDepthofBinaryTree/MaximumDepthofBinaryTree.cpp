//============================================================================
// Maximum Depth of Binary Tree
// Given a binary tree, find its maximum depth.
//
// The maximum depth is the number of nodes along the longest path from the
// root node down to the farthest leaf node.
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
    int maxDepth(TreeNode *root) {
//        return maxDepth1(root);
        return maxDepth2(root);
    }

    int maxDepth1(TreeNode *root) {
        int maxDepth = 0;
        maxDepthHelper(root, 0, maxDepth);
        return maxDepth;
    }

    void maxDepthHelper(TreeNode *node, int curDepth, int &maxDepth) {
        if (node == NULL) return;
        curDepth++;
        if (node->left == NULL && node->right == NULL) {
            if (curDepth > maxDepth) maxDepth = curDepth;
        }
        maxDepthHelper(node->left, curDepth, maxDepth);
        maxDepthHelper(node->right, curDepth, maxDepth);
    }

    int maxDepth2(TreeNode *root) {
        return maxDepthHelper2(root);
    }

    int maxDepthHelper2(TreeNode *node) {
        if (node == NULL) return 0;
        return 1+max(maxDepthHelper2(node->left), maxDepthHelper2(node->right));
    }
};

int main() {
    return 0;
}
