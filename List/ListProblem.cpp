#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

struct ListNode
{
    int key;
    ListNode *next;
    ListNode(int _key) : key(_key) {}
};

struct ComplexNode
{
    int key;
    ComplexNode *next;
    ComplexNode *sibling;
    ComplexNode(int _key) : key(_key), next(NULL), sibling(NULL) {}
    ComplexNode(int _key, ComplexNode *_next, ComplexNode *_sibling) : key(_key),
                                                next(_next), sibling(_sibling) {}
};

bool hasLoop(ListNode *head);

ListNode *firstListNode(ListNode *head);

ListNode *findMiddleNode(ListNode *head);

ListNode *randomNListNode(ListNode *head);

// find the start of a loop list
ListNode *firstListNode(ListNode *head)
{
    ListNode *pSlow = head;
    ListNode *pFast = head;
    if (!pSlow)
        return false;
    while (pFast && pFast->next)
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pSlow == pFast)
        {
            break;
        }
    }

    if (pFast != NULL && pFast->next != NULL)
    {
        pSlow = head;
        while (pSlow != pFast)
        {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pFast;
    }
    return NULL;
}

// find middle node
ListNode *findMiddleNode(ListNode *head)
{
    ListNode *pSlow = head;
    ListNode *pFast = head;
    while (pFast && pFast->next && pFast->next->next)
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
    }
    return pSlow;
}

// �ж�һ�������Ƿ��л�
bool hasLoop(ListNode *head)
{
    ListNode *pSlow = head;
    if (!pSlow)
        return false;
    ListNode *pFast = pSlow;
    while (pFast && pFast->next)
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pSlow == pFast)
        {
            return true;
        }
    }
    return false;
}

// �����������ListNode�з���N���ڵ�
ListNode *randomNListNode(ListNode *head, int N)
{
    ListNode dummy(0);
    ListNode *pCur = &dummy;
    int tot = 0;
    int count = 0;
    while (head)
    {
        ++tot;
        if (count < N)
        {
            pCur->next = new ListNode(head->key);
            pCur = pCur->next;
        }
        else
        {
            int num = rand() % tot;
            if (num <= N)
            {
                ListNode *pDel = &dummy;
                // ��dummy���滻����num��
                for (int i = 0; i < num; ++i)
                {
                    pDel = pDel->next;
                }
                pDel->key = head->key;
            }
        }
        head = head->next;
    }
    return dummy.next;
}

// ��������ĸ���
ComplexNode *copyComplexNode(ComplexNode *head)
{
    static map<ComplexNode *, ComplexNode *> nodeMap;
    if (!head)
        return NULL;
    ComplexNode *n = NULL;
    if (nodeMap.find(head) == nodeMap.end())
    {
        n = new ComplexNode(head->key);
        nodeMap[head] = n;
        n->next = copyComplexNode(head->next);
        n->sibling = copyComplexNode(head->sibling);
    }
    else
    {
        n = nodeMap[head];
    }
    return n;
}

// �ݹ鷽ʽ���и�������ĸ���
ComplexNode *clone(ComplexNode *head)
{
    // ��Ӧ�Ŀ�¡�ڵ��Ƿ����
    static map<ComplexNode *, ComplexNode *> nodeMap;
    if (head == NULL)
        return NULL;
    ComplexNode *n = NULL;
    if (nodeMap.find(head) == nodeMap.end())
    {
        n = new ComplexNode(head->key);
        nodeMap[head] = n;
        n->next = clone(head->next);
        n->sibling = clone(head->sibling);
    }
    else
    {
        n = nodeMap[head];
    }
    return n;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
