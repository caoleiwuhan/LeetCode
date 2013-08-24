//============================================================================
// Path Sum II
// Given a binary tree and a sum, find all root-to-leaf paths where each
// path's sum equals the given sum.
//
// For example:
// Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
// return
// [
//   [5,4,11,2],
//   [5,8,4,5]
// ]
//============================================================================

#include <iostream>
#include <vector>
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int> > res;
        pathSumHelper(root, sum, path, res);
        return res;
    }

    void pathSumHelper(TreeNode* node, int sum, vector<int> path, vector<vector<int> > &res) {
        if (node == NULL) return;
        sum -= node->val;
        path.push_back(node->val);
        if (sum == 0 && NULL == node->left && NULL == node->right) {
            res.push_back(path);
            return;
        }
        pathSumHelper(node->left, sum, path, res);
        pathSumHelper(node->right, sum, path, res);
    }
};

int main() {
    return 0;
}
