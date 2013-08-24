//============================================================================
//  Given a binary tree containing digits from 0-9 only, each root-to-leaf 
//  path could represent a number.
//
//  An example is the root-to-leaf path 1->2->3 which represents the number 
//  123.
//
//  Find the total sum of all root-to-leaf numbers.
//
//  For example,
//
//  /*    1     */
//  /*   / \    */
//  /*  2   3   */
//  The root-to-leaf path 1->2 represents the number 12.
//  The root-to-leaf path 1->3 represents the number 13.
//
//  return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode *root)
    {
        if (root == NULL) return 0;
        int sum = 0, res = 0;
        sumNumbersHelper(root, sum, res);
        return res;
    }

    void sumNumbersHelper(TreeNode *node, int sum, int & res)
    {
        sum += node->val;
        if (node->left == NULL && node->right == NULL)
        {
            res += sum;
            return;
        }
        sum *= 10;
        if (node->left) sumNumbersHelper(node->left, sum, res);
        if (node->right) sumNumbersHelper(node->right, sum, res);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    cout << sol.sumNumbers(root) << endl;
    return 0;
}
