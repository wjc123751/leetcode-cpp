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

// 为什么必须用 后序遍历？ 因为要先知道 左、右子树 能贡献多少，才能计算 当前节点 的值
// 实时更新遍历过程中遇到的最大路径和 maxsum

class Solution
{
public:
    vector<int> res;

    int maxPathSum(TreeNode *root)
    {
        int maxsum = INT_MIN;
        dfs(root, maxsum);
        return maxsum;
    }

    int dfs(TreeNode* root, int& maxsum){
        if(root == nullptr){
            return 0;
        }
        int maxleft = max(dfs(root->left, maxsum), 0);
        int maxright = max(dfs(root->right, maxsum), 0);
        int cursum = maxleft + maxright + root->val;
        maxsum = max(maxsum, cursum);
        // return 的这个值 = 当前节点能向上提供的最大单边路径和
        return root->val + max(maxleft, maxright);
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    int res = s.maxPathSum(root);
    cout << res;

    return 0;
}