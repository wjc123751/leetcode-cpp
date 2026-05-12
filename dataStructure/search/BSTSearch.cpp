// 查找时间复杂度:最好O(logn) 最坏O(n)
// 二叉排序树性质：左子树值 < 根 < 右子树值
// 中序遍历一定是递增有序序列
// 插入只能插在叶子节点
#include <iostream>
#include <vector>
using namespace std;
struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode() : data(0), left(nullptr), right(nullptr) {}
    BSTNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool BSTInsert(BSTNode *&root, int val)
{
    if (root == nullptr)
    {
        root = new BSTNode(val);
        return true;
    }
    if (val == root->data)
    {
        return false;
    }
    else if (val < root->data)
    {
        return BSTInsert(root->left, val);
    }
    else
    {
        return BSTInsert(root->right, val);
    }
}

void InOrder(BSTNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

BSTNode *BSTSearch(BSTNode *root, int target)
{
    if (root == nullptr || root->data == target)
    {
        return root;
    }
    if (target < root->data)
    {
        return BSTSearch(root->left, target);
    }
    else
    {
        return BSTSearch(root->right, target);
    }
}

// 删除节点三大规则
// 1. 叶子节点直接删
// 2. 只有左子树或右子树，子树顶替当前节点
// 3. 左右子树都有，找中序前驱(左子树最右)顶替，再删前驱
void BSTDelete(BSTNode *&root, int target)
{
    if (root == nullptr)
    {
        return;
    }
    if (target < root->data)
    {
        BSTDelete(root->left, target);
    }
    else if (target > root->data)
    {
        BSTDelete(root->right, target);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            BSTNode *p = root;
            root = root->right;
            delete p;
        }
        else if (root->right == nullptr)
        {
            BSTNode *p = root;
            root = root->left;
            delete p;
        }
        else
        {
            BSTNode *pre = root->left;
            while (pre->right)
            {
                pre = pre->right;
            }
            root->data = pre->data;
            BSTDelete(root->left, pre->data);
        }
    }
}

int main()
{
    BSTNode *root = nullptr;
    vector<int> arr = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < arr.size(); ++i)
    {
        BSTInsert(root, arr[i]);
    }

    InOrder(root);
    cout << endl;

    int x = 40;
    if (BSTSearch(root, x))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    BSTDelete(root, 40);
    InOrder(root);
    cout << endl;

    return 0;
}