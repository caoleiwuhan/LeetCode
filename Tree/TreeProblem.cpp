#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _key) : key(_key), left(NULL), right(NULL) {}
};

/*
    1��������ʾ
    2����list
    3���Ƿ���parentָ��
    4��bool
*/
// ��һ��ǰ�᣺p��qһ����root��
TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (root == p || root == q)
        return root;
    TreeNode *pLeft = LCA(root->left, p, q);
    TreeNode *pRight = LCA(root->right, p, q);
    if (pLeft && pRight)
        return root;
    return pLeft ? pLeft : pRight;
}

// ���ش˽ڵ����һ���ڵ㣬���ΪNULL������NULL
TreeNode *prevNode(TreeNode *root, TreeNode *p)
{
    return NULL;
}
// ���ش˽ڵ����һ���ڵ�
TreeNode *nextNode(TreeNode *root, TreeNode *p)
{
    return NULL;
}


// ����һ����x��һ���������������2���ڵ㣬ʹ�����Ϊx�������ڴ��ڲ�ѯ
void findTwoNodeSumX(TreeNode *root, int sum, TreeNode * &p1, TreeNode * &p2)
{
    TreeNode *left = root;
    while (prevNode(root, left) != NULL)
    {
        left = prevNode(root, left);
    }
    TreeNode *right = root;
    while (nextNode(root, right) != NULL)
    {
        right = nextNode(root, right);
    }
    while (left->key < right->key)
    {
        int num = left->key + right->key;
        if (num == sum)
        {
            p1 = left;
            p2 = right;
        }
        else if (num > sum)
        {
            right = prevNode(root, right);
        }
        else
        {
            left = nextNode(root, left);
        }
    }
}
// ��BST������ӽ�num�Ľڵ㣬ǰ�����
TreeNode *closestNode(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;
    TreeNode *ans = root;
    int num1 = abs(root->key - val);
    if (val < root->key)
    {
        TreeNode *pLeft = closestNode(root->left, val);
        if (pLeft && abs(pLeft->key - val) < num1)
        {
            ans = pLeft;
            num1 = abs(pLeft->key - val);
        }
    }
    else
    {
        TreeNode *pRight = closestNode(root->right, val);
        if (pRight && abs(pRight->key - val) < num1)
        {
            ans = pRight;
            num1 = abs(pRight->key - val);
        }
    }
    return ans;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
