//============================================================================
// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.
//============================================================================

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {};
};

struct greater_listnode {
    bool operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, greater_listnode > minHeap;
        for (vector<ListNode *>::iterator it = lists.begin(); it != lists.end(); it++) {
            if ((*it) != NULL) minHeap.push(*it);
        }
        if (minHeap.empty()) return NULL;
        ListNode *head = minHeap.top();
        minHeap.pop();
        ListNode *node = head;
        if (node->next != NULL) minHeap.push(node->next);
        while (!minHeap.empty()) {
            node->next = minHeap.top();
            minHeap.pop();
            node = node->next;
            if (node->next != NULL) minHeap.push(node->next);
        }
        return head;
    }
};

int main() {
    return 0;
}
