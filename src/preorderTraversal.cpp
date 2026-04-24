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

// class Solution
// {
// public:
//     vector<int> res;

//     vector<int> preorderTraversal(TreeNode *root)
//     {
//         dfs(root);
//         return res;
//     }

//     void dfs(TreeNode *node){
//         if(node == nullptr){
//             return;
//         }
//         res.push_back(node->val);
//         dfs(node->left);
//         dfs(node->right);
//     }
// };

// 迭代 + 栈
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty())
        {
            while (cur != nullptr)
            {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
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

    vector<int> res = s.preorderTraversal(root);
    for (auto r : res)
    {
        cout << r << " ";
    }

    return 0;
}
