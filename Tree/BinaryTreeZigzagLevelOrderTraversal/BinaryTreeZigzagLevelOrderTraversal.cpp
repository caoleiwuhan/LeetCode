//============================================================================
// Binary Tree Zigzag Level Order Traversal
// Given a binary tree, return the zigzag level order traversal of its nodes'
// values. (ie, from left to right, then right to left for the next level and
// alternate between).
//
//For example:
// Given binary tree {3,9,20,#,#,15,7},
//    3
//   / \
//  9  20
//    /  \
//   15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        vector<int> row;
        stack<TreeNode*> currS, nextS;
        currS.push(root);
        bool leftToRight = true;
        while (!currS.empty()) {
            while (!currS.empty()) {
                TreeNode* front = currS.top();
                currS.pop();
                row.push_back(front->val);
                if (leftToRight) {
                    if (front->left) nextS.push(front->left);
                    if (front->right) nextS.push(front->right);
                }
                else {
                    if (front->right) nextS.push(front->right);
                    if (front->left) nextS.push(front->left);
                }
            }
            res.push_back(row);
            row.clear();
            swap(currS, nextS);
            leftToRight = !leftToRight;
        }
        return res;
    }
};

int main() {
    return 0;
}
