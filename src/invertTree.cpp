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

// 翻转二叉树 = 对树里的「每一个节点」，交换它的左孩子 和 右孩子，整棵树变成左右镜像。

class Solution
{
public:
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root == nullptr){
    //         return root;
    //     }

    //     swap(root->left, root->right);
    //     invertTree(root->left);
    //     invertTree(root->right);

    //     return root;
    // }

    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return root;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();

            swap(cur->left, cur->right);
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }
        return root;
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        dfslev(root, 0, res);
        return res;
    }

private:
    void dfslev(TreeNode *root, int level, vector<vector<int>> &res)
    {
        if (root == nullptr)
        {
            return;
        }

        if (level == res.size())
        {
            res.push_back(vector<int>());
        }

        res[level].push_back(root->val);
        dfslev(root->left, level + 1, res);
        dfslev(root->right, level + 1, res);
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    TreeNode *invroot = s.invertTree(root);

    vector<vector<int>> res = s.levelOrder(invroot);

    for (int i = 0; i < res.size(); ++i)
    {
        for (int r : res[i])
        {
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}