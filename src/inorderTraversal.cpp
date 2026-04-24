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

// 递归
// class Solution
// {
// public:
//     vector<int> res;
//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         dfs(root);
//         return res;
//     }

//     void dfs(TreeNode *node){
//         if(node == nullptr){
//             return;
//         }
//         dfs(node->left);
//         res.push_back(node->val);
//         dfs(node->right);
//     }
// };

// 迭代 + 栈
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur != nullptr || !st.empty()){
            while(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
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

    vector<int> res = s.inorderTraversal(root);
    for (auto r : res)
    {
        cout << r << " ";
    }

    return 0;
}
