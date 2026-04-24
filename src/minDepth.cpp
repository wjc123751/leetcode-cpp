#include <iostream>
#include <vector>

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
    int minDepth(TreeNode *root)
    {
        return dfs(root);
    }
    
    int dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        // 只有一边有子树、一边为空时，不能选空的那一边（空深度是 0）
        // 情况1：左空，只看右子树
        if (left == 0)
            return right + 1;
        // 情况2：右空，只看左子树
        if (right == 0)
            return left + 1;
        // 情况3：左右都有，取最小
        return min(left, right) + 1;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int res = s.minDepth(root);
    cout << res;

    return 0;
}
