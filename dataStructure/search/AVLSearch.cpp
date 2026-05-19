// 查找时间复杂度：最好 O(logn)  最坏 O(logn)  稳定平衡
// AVL 树性质：任意节点的左右子树高度差（平衡因子）绝对值 ≤ 1
// 二叉排序树性质：左子树值 < 根节点值 < 右子树值
// 中序遍历结果一定是递增有序序列
// 插入后可能破坏平衡，通过旋转自动恢复平衡
#include <iostream>
#include <algorithm>
using namespace std;

// 标准AVL树节点结构体
struct AVLNode
{
    int data;
    int height;
    AVLNode *left;
    AVLNode *right;
    AVLNode() : data(0), height(1), left(nullptr), right(nullptr) {}
    AVLNode(int x) : data(x), height(1), left(nullptr), right(nullptr) {}
};

// 获取高度
int getHeight(AVLNode* root)
{
    return root ? root->height : 0;
}

// 更新高度
void updateHeight(AVLNode* root)
{
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

// 获取平衡因子
int getBalance(AVLNode* root)
{
    return root ? getHeight(root->left) - getHeight(root->right) : 0;
}

// 右旋
AVLNode* rightRotate(AVLNode* y)
{
    AVLNode* x = y->left;
    AVLNode* t3 = x->right;
    x->right = y;
    y->left = t3;
    updateHeight(y);
    updateHeight(x);
    return x;
}

// 左旋
AVLNode* leftRotate(AVLNode* x)
{
    AVLNode* y = x->right;
    AVLNode* t2 = y->left;
    y->left = x;
    x->right = t2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// AVL插入
AVLNode* avlInsert(AVLNode* root, int val)
{
    if (!root) return new AVLNode(val);
    if (val < root->data)
        root->left = avlInsert(root->left, val);
    else if (val > root->data)
        root->right = avlInsert(root->right, val);
    else
        return root;

    updateHeight(root);
    int bal = getBalance(root);

    // LL
    if (bal > 1 && val < root->left->data)
        return rightRotate(root);
    // RR
    if (bal < -1 && val > root->right->data)
        return leftRotate(root);
    // LR
    if (bal > 1 && val > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL
    if (bal < -1 && val < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// 【核心查找函数】参数严格：AVLNode* root
bool avlSearch(AVLNode* root, int target)
{
    if (root == nullptr)
        return false;
    if (root->data == target)
        return true;
    if (target < root->data)
        return avlSearch(root->left, target);
    else
        return avlSearch(root->right, target);
}

// 中序遍历
void inOrder(AVLNode* root)
{
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    AVLNode* root = nullptr;
    int arr[] = {20,10,30,5,15,25,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        root = avlInsert(root,arr[i]);

    cout << "中序遍历：";
    inOrder(root);
    cout << endl;

    int key = 15;
    if(avlSearch(root,key))
        cout << key << " 查找成功\n";
    else
        cout << key << " 查找失败\n";

    return 0;
}