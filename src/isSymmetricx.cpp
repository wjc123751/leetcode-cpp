#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 轴对称 = 树的左子树 和 右子树 互为镜像镜像的规则：
// 根节点值相等
// 左子树的左孩子 = 右子树的右孩子
// 左子树的右孩子 = 右子树的左孩子

class Solution
{
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return isMirror(root->left, root->right);
    }

    // bool isSymmetric(TreeNode *root)
    // {
    //     if (root == nullptr)
    //     {
    //         return true;
    //     }
    //     queue<TreeNode *> q;
    //     q.push(root->left);
    //     q.push(root->right);
    //     while (!q.empty())
    //     {
    //         TreeNode *n1 = q.front();
    //         q.pop();
    //         TreeNode *n2 = q.front();
    //         q.pop();
    //         if (n1 == nullptr && n2 == nullptr)
    //         {
    //             continue;
    //         }
    //         if (n1 == nullptr || n2 == nullptr)
    //         {
    //             return false;
    //         }
    //         if (n1->val != n2->val)
    //         {
    //             return false;
    //         }
    //         q.push(n1->left);
    //         q.push(n2->right);

    //         q.push(n1->right);
    //         q.push(n2->left);
    //     }
    //     return true;
    // }

private:
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        if (left == nullptr || right == nullptr)
        {
            return false;
        }
        if (left->val != right->val)
        {
            return false;
        }
        bool lMirror = isMirror(left->left, right->right);
        bool rMirror = isMirror(left->right, right->left);
        return lMirror && rMirror;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << s.isSymmetric(root);

    return 0;
}