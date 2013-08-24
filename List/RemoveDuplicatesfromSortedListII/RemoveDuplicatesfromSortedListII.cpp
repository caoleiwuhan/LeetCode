//============================================================================
// Remove Duplicates from Sorted List II
// Given a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list.
//
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.
//============================================================================

#include <iostream>
using namespace std;

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = NULL, *newNode = NULL;
        ListNode* curNode = head;
        while (curNode != NULL) {
            bool found = true;
            ListNode* nextNode;
            while (curNode->next != NULL && curNode->val == curNode->next->val) {
                nextNode = curNode->next;
                delete curNode;
                curNode = nextNode;
                found = false;
            }
            if (found) {
                if (newHead == NULL) {
                    newHead = curNode;
                    newNode = curNode;
                }
                else {
                    newNode->next = curNode;
                    newNode = newNode->next;
                }
                curNode = curNode->next;
            }
            else {
                nextNode = curNode->next;
                delete curNode;
                curNode = nextNode;
            }
        }
        if (newNode) newNode->next = NULL;
        return newHead;
    }
};

int main() {
    return 0;
}
