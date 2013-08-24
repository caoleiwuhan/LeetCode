//============================================================================
// Convert Sorted List to Binary Search Tree
//
// Given a singly linked list where elements are sorted in ascending order,
// convert it to a height balanced BST.
//
//============================================================================

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* node = head;
        int len = 1;
        while (NULL != (node = node->next)) len++;
        return sortedListToBSTHelper(head, 0, len - 1);
    }

    // in-order build tree, takes O(n) time
    TreeNode* sortedListToBSTHelper(ListNode*& head, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* leftTree = sortedListToBSTHelper(head, start, mid - 1);
        TreeNode* root = new TreeNode(head->val);
        root->left = leftTree;
        head = head->next;
        root->right = sortedListToBSTHelper(head, mid + 1, end);
        return root;
    };
};

int main() {
    return 0;
}
