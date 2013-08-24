//============================================================================
// Swap Nodes in Pairs
// Given a linked list, swap every two adjacent nodes and return its head.
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Your algorithm should use only constant space. You may not modify the
// values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        return swapPairs1(head);
    }

    ListNode *swapPairs1(ListNode *head) {
       swapPairsHelper(head);
       return head;
    }
    
    void swapPairsHelper(ListNode*& curNode) {
        if(curNode == NULL or curNode->next == NULL) return;
        ListNode* nextNode = curNode->next;
        ListNode* nextNext = nextNode->next;
        swapPairsHelper(nextNext);
        nextNode->next = curNode;
        curNode->next = nextNext;
        curNode = nextNode;
    }

    ListNode *swapPairs2(ListNode *head) {
        ListNode *preNode = NULL;
        ListNode *curNode = head;
        while (curNode != NULL) {
            ListNode *nextNode = curNode->next;
            if (nextNode == NULL) return head;
            if (preNode == NULL) head = nextNode;
            else preNode->next = nextNode;
            curNode->next = nextNode->next;
            nextNode->next = curNode;
            preNode = curNode;
            curNode = curNode->next;
        }
        return head;
    }
};
int main() {
    return 0;
}
