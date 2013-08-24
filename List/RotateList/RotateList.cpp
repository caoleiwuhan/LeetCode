//============================================================================
// Rotate List
// Given a list, rotate the list to the right by k places, where k is
// non-negative.
//
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.
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

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *node = head;
        int n = 0;
        while (node != NULL) node = node->next, n++;
        k = k % n;
        if (k == 0) return head;
        ListNode *fast = head;
        int i = 0;
        while (fast != NULL && i < k) fast = fast->next, i++;
        ListNode *slow = head;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};

int main() {
    return 0;
}
