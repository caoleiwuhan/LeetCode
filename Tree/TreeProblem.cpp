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
    1：如下所示
    2：用list
    3：是否有parent指针
    4：bool
*/
// 有一个前提：p、q一定在root中
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

// 返回此节点的上一个节点，如果为NULL，返回NULL
TreeNode *prevNode(TreeNode *root, TreeNode *p)
{
    return NULL;
}
// 返回此节点的下一个节点
TreeNode *nextNode(TreeNode *root, TreeNode *p)
{
    return NULL;
}


// 给定一个数x和一个二叉查找树，找2个节点，使得其和为x：类似于窗口查询
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
// 在BST中找最接近num的节点，前序遍历
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
