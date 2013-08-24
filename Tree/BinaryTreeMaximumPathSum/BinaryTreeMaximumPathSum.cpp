//============================================================================
// Binary Tree Maximum Path Sum
// Given a binary tree, find the maximum path sum.
//
// The path may start and end at any node in the tree.
//
// For example:
// Given the below binary tree,
//
//  "     1     "
//  "    / \    "
//  "   2   3   " 
//  
//  Return 6.
//
//============================================================================

#include <iostream>

using namespace std;

/**
 * Definition for binary tree
 */ 
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    int maxPathSum(TreeNode *root) 
    {
        if (root == NULL) return 0;
        int maxSoFar = root->val;
        maxPathSumHelper(root, maxSoFar);
        return maxSoFar;
    }

    int maxPathSumHelper(TreeNode *node, int &maxSoFar)
    {
        if (node == NULL) return 0;
        int leftMax = maxPathSumHelper(node->left, maxSoFar);
        int rightMax = maxPathSumHelper(node->right, maxSoFar);
        int maxPath = node->val;
        if (leftMax > 0)  maxPath += leftMax;
        if (rightMax > 0) maxPath += rightMax;
        if (maxPath > maxSoFar) maxSoFar = maxPath; 
        int res = node->val;
        return max(res, res+max(leftMax, rightMax));
    }
};

int main()
{
    return 0;
}
