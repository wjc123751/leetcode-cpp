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

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // 空树没有任何路径，永远返回 false
        if (root == nullptr)
        {
            return false;
        }

        queue<pair<TreeNode *, int>> q;
        q.push({root, root->val});

        while (!q.empty())
        {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            TreeNode *cur = p.first;
            // pair 里已经存了当前路径的和，你根本不需要额外 sum
            int sum = p.second;
            if (cur->left == nullptr && cur->right == nullptr)
            {
                if (sum == targetSum)
                {
                    return true;
                }
            }
            if (cur->left)
            {
                q.push({cur->left, sum + cur->left->val});
            }
            if (cur->right)
            {
                q.push({cur->right, sum + cur->right->val});
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    cout << s.hasPathSum(root, targetSum);

    return 0;
}