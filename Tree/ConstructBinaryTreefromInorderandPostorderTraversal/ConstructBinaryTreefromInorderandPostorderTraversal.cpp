//============================================================================
// Construct Binary Tree from Inorder and Postorder Traversal
// Given inorder and postorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeHelper(inorder.begin(), postorder.begin(), inorder.size());
    }

    TreeNode *buildTreeHelper(vector<int>::iterator inorder, vector<int>::iterator postorder, size_t n) {
        if (n == 0) return NULL;
        vector<int>::iterator it = find(inorder, inorder + n, *(postorder+n-1));
        int idx = it - inorder;
        TreeNode* root = new TreeNode(*it);
        root->left = buildTreeHelper(inorder, postorder, idx);
        root->right = buildTreeHelper(inorder+idx+1, postorder+idx, n-idx-1);
        return root;
    }
};

int main() {
    return 0;
}
