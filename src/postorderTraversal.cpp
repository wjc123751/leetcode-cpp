#include <iostream>
#include <vector>
#include <stack>

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

// class Solution {
// public:
//     vector<int> res;
//     vector<int> postorderTraversal(TreeNode* root) {
//         dfs(root);
//         return res;
//     }
//     void dfs(TreeNode* node){
//         if(node == nullptr){
//             return;
//         }
//         dfs(node->left);
//         dfs(node->right);
//         res.push_back(node->val);
//     }
// };

// 栈 + 迭代
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = nullptr; // 只加这一行

        while (cur != nullptr || !st.empty())
        {
            while (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top(); // 不弹出！只查看

            // 只加这个判断：右子树为空 或 已经访问过
            if (cur->right == nullptr || cur->right == pre)
            {
                res.push_back(cur->val); // 访问根
                st.pop();                // 弹出
                pre = cur;               // 标记已访问
                cur = nullptr;           // 下次不进左循环
            }
            else
            {
                cur = cur->right; // 先遍历右子树
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = s.postorderTraversal(root);
    for (auto r : res)
    {
        cout << r << " ";
    }

    return 0;
}