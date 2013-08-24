//============================================================================
// Merge two sorted linked lists and return it as a new list. The new list
// should be made by splicing together the nodes of the first two lists.
//============================================================================

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, *node = NULL;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                if (head == NULL) {
                    head = l1;
                    node = head;
                }
                else {
                    node->next = l1;
                    node = node->next;
                }
                l1 = l1->next;
            }
            else {
                if (head == NULL) {
                    head = l2;
                    node = head;
                }
                else {
                    node->next = l2;
                    node = node->next;
                }
                l2 = l2->next;
            }
        }
        if (l1 == NULL) {
            if (head == NULL) head = l2;
            else node->next = l2;
        }
        else if (l2 == NULL) {
            if (head == NULL) head = l1;
            else node->next = l1;
        }
        return head;
    }
};

int main() {
    return 0;
}
