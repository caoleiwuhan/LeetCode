//============================================================================
// Convert Sorted Array to Binary Search Tree
//
// Given an array where elements are sorted in ascending order, convert it to
// a height balanced BST.
//
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST1(num);    
    }
    
    TreeNode *sortedArrayToBST1(vector<int> &num) {
        return sortedArrayToBSTHelper1(num, 0, num.size() - 1);
    }

    // pre-order construct tree, takes O(n) time
    TreeNode* sortedArrayToBSTHelper1(vector<int> &num, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(num[mid]);
        node->left = sortedArrayToBSTHelper1(num, start, mid - 1);
        node->right = sortedArrayToBSTHelper1(num, mid + 1, end);
        return node;
    }

    TreeNode* sortedArrayToBST2(const int array[], int size) {
        if (NULL == array or size <= 0) return NULL;
        int idx = 0;
        return sortedArrayToBSTHelper2(array, 0, size - 1, idx);
    }

    TreeNode* sortedArrayToBSTHelper2(const int array[], int start, int end, int& idx) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* tmpNode = sortedArrayToBSTHelper2(array, start, mid - 1, idx);
        TreeNode* node = new TreeNode(array[idx++]);
        node->left = tmpNode;
        node->right = sortedArrayToBSTHelper2(array, mid + 1, end, idx);
        return node;
    }
};

int main() {
    return 0;
}
