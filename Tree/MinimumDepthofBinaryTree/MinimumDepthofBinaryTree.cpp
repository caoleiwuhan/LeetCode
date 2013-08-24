//============================================================================
// Minimum Depth of Binary Tree
//
// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the
// root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        return minDepth1(root);
    }

    int minDepth1(TreeNode *root) {
        int minDepth = INT_MAX;
        minDepthHelper(root, 0, minDepth);
        return minDepth;
    }

    void minDepthHelper(TreeNode *node, int curDepth, int &minDepth) {
        if (node == NULL) return;
        curDepth++;
        if (node->left == NULL && node->right == NULL) {
            if (curDepth > minDepth) minDepth = curDepth;
        }
        minDepthHelper(node->left, curDepth, minDepth);
        minDepthHelper(node->right, curDepth, minDepth);
    }
};

int main() {
    return 0;
}
