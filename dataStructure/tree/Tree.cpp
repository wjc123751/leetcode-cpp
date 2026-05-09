#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef int ElemType;

vector<ElemType> tree;

struct TreeNode
{
    ElemType data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(ElemType x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(ElemType x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void InitTree(TreeNode *root)
{
    root = nullptr;
}

bool TreeEmpty(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 从前序与中序遍历序列构造二叉树
TreeNode *PreInBuildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.empty() || inorder.empty())
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[0]);
    auto it = find(inorder.begin(), inorder.end(), preorder[0]);
    int rootIndex = it - inorder.begin();
    vector<int> preLeft(preorder.begin() + 1, preorder.begin() + 1 + rootIndex);
    vector<int> preRight(preorder.begin() + 1 + rootIndex, preorder.end());
    vector<int> inLeft(inorder.begin(), it);
    vector<int> inRight(it + 1, inorder.end());
    root->left = PreInBuildTree(preLeft, inLeft);
    root->right = PreInBuildTree(preRight, inRight);
    return root;
}

// 从中序与后序遍历序列构造二叉树
TreeNode *PreInBuildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.empty() || postorder.empty())
    {
        return nullptr;
    }
    int rootData = postorder.back();
    TreeNode *root = new TreeNode(rootData);
    auto it = find(inorder.begin(), inorder.end(), rootData);
    int rootIndex = it - inorder.begin();
    vector<int> postLeft(postorder.begin(), postorder.begin() + rootIndex);
    vector<int> postRight(postorder.begin() + rootIndex, postorder.end() - 1);
    vector<int> inLeft(inorder.begin(), it);
    vector<int> inRight(it + 1, inorder.end());
    root->left = PreInBuildTree(inLeft, postLeft);
    root->right = PreInBuildTree(inRight, postRight);
    return root;
}

// dfs
void PreOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    tree.push_back(root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    InOrder(root->left);
    tree.push_back(root->data);
    InOrder(root->right);
}

void PostOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    tree.push_back(root->data);
}

void LevelOrder(TreeNode *root, int level, vector<vector<ElemType>> &res)
{
    if (root == nullptr)
    {
        return;
    }
    if (level == res.size())
    {
        res.push_back(vector<int>());
    }
    res[level].push_back(root->data);
    LevelOrder(root->left, level + 1, res);
    LevelOrder(root->right, level + 1, res);
}

/*
DFS(节点u){
    访问节点u
    标记已访问
    for(u 的每一个邻接节点 v){
        if(v 未被访问){
            DFS(v)
        }
    }
}
*/

void PreOrderStack(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<TreeNode *> st;
    TreeNode *cur = root;
    while (cur != nullptr || !st.empty())
    {
        while (cur != nullptr)
        {
            tree.push_back(cur->data);
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        cur = cur->right;
    }
}

// 必须左子树全部遍历完，才能访问根
void InOrderStack(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<TreeNode *> st;
    TreeNode *cur = root;
    while (cur != nullptr && !st.empty())
    {
        while (cur != nullptr)
        {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        tree.push_back(cur->data);
        cur = cur->right;
    }
}

void PostOrderStack(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<TreeNode *> st;
    TreeNode *cur = root;
    TreeNode *pre = nullptr;
    while (cur != nullptr || !st.empty())
    {
        while (cur != nullptr)
        {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        if (cur->right == nullptr || cur->right == pre)
        {
            tree.push_back(cur->data);
            st.pop();
            pre = cur;
            cur = nullptr;
        }
        else
        {
            cur = cur->right;
        }
    }
}

/*
栈stack
起点入栈
标记起点已访问
while(栈非空){
    u = 栈弹出
    访问u
    for( u 的每一个邻接节点 v 逆序){
        if(v 未访问){
            标记已访问
            v 入栈
        }
    }
}
*/

// bfs 二叉树是无环的连通图，不会重复访问同一个节点
void LevelOrderQueue(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();
        tree.push_back(cur->data);
        if (cur->left != nullptr)
        {
            q.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            q.push(cur->right);
        }
    }
}

/*
队列queue
起点入队
标记起点已访问
while(队列非空){
    u = 队头出队
    访问u
    for(u 的每一个邻接节点 v){
        if(v 未被访问){
            标记已访问
            v入队
        }
    }
}
*/

int CountNode(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = CountNode(root->left);
    int right = CountNode(root->right);
    return left + right + 1;
}

int TreeMaxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftDep = TreeMaxDepth(root->left);
    int rightDep = TreeMaxDepth(root->right);
    if (leftDep > rightDep)
    {
        return leftDep + 1;
    }
    else
    {
        return rightDep + 1;
    }
}

int TreeMinDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    else if (root->left == nullptr)
    {
        return TreeMinDepth(root->right) + 1;
    }
    else if (root->right == nullptr)
    {
        return TreeMinDepth(root->left) + 1;
    }
    else
    {
        return min(TreeMinDepth(root->left), TreeMinDepth(root->right)) + 1;
    }
}

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return root;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    return isMirror(root->left, root->right);
}

bool isMirror(TreeNode *left, TreeNode *right)
{
    if (left == nullptr && right == nullptr)
    {
        return true;
    }
    else if (left == nullptr || right == nullptr)
    {
        return false;
    }
    if (left->data != right->data)
    {
        return false;
    }
    bool lMirror = isMirror(left->left, right->right);
    bool rMirror = isMirror(left->right, right->left);
    return lMirror && rMirror;
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
    {
        return false;
    }
    queue<pair<TreeNode *, int>> q;
    q.push({root, root->data});
    while (!q.empty())
    {
        pair<TreeNode *, int> p = q.front();
        q.pop();
        TreeNode *cur = p.first;
        int sum = p.second;
        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (sum == targetSum)
            {
                return true;
            }
        }
        if (cur->left == nullptr)
        {
            q.push({cur->right, sum + cur->right->data});
        }
        if (cur->right == nullptr)
        {
            q.push({cur->left, sum + cur->left->data});
        }
    }
    return false;
}

// 二叉树的右视图
vector<int> rightSideView(TreeNode* root){
    vector<int> res;
    if(root == nullptr){
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; ++i){
            TreeNode* cur = q.front();
            q.pop();
            if(i == size - 1){
                res.push_back(cur->data);
            }
            if(cur->left != nullptr){
                q.push(cur->left);
            }
            if(cur->right != nullptr){
                q.push(cur->right);
            }
        }
    }
    return res;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (root == p)
    {
        return p;
    }
    else if (root == q)
    {
        return q;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    TreeNode *res;
    if (left != nullptr && right != nullptr)
    {
        res = root;
    }
    else if (left != nullptr)
    {
        res = left;
    }
    else if (right != nullptr)
    {
        res = right;
    }
    return res;
}

TreeNode *FindNode(TreeNode *root, int x)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == x)
    {
        return root;
    }
    TreeNode *p = FindNode(root->left, x);
    if (p != nullptr)
    {
        return p;
    }
    TreeNode *q = FindNode(root->right, x);
    if (q != nullptr)
    {
        return q;
    }
    return nullptr;
}

void DestroyTree(TreeNode *&root)
{
    if (root == nullptr)
    {
        return;
    }
    DestroyTree(root->left);
    DestroyTree(root->right);
    delete root;
    root = nullptr;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    tree.clear();
    PreOrder(root);
    for (auto t : tree)
    {
        cout << t << " ";
    }
    cout << endl;

    tree.clear();
    InOrder(root);
    for (auto t : tree)
    {
        cout << t << " ";
    }
    cout << endl;

    tree.clear();
    PostOrder(root);
    for (auto t : tree)
    {
        cout << t << " ";
    }
    cout << endl;

    tree.clear();
    LevelOrderQueue(root);
    for (auto t : tree)
    {
        cout << t << " ";
    }
    cout << endl;

    cout << CountNode(root) << endl;

    cout << TreeMaxDepth(root) << endl;

    TreeNode *p = FindNode(root, 2);
    if (p)
    {
        cout << p->data << endl;
    }

    DestroyTree(root);

    cout << TreeEmpty(root) << endl;

    return 0;
}