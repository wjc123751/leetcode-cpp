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

// 递归
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         dfs(root, 0, res); // 从第0层开始
//         return res;
//     }

//     void dfs(TreeNode* root, int level, vector<vector<int>>& res){
//         if(root == nullptr){
//             return;
//         }
//         if(level == res.size()){
//             res.push_back(vector<int>());
//         }
//         res[level].push_back(root->val);

//         dfs(root->left, level + 1, res);
//         dfs(root->right, level + 1, res);
//     }
// };

// 队列
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> r;
            // 层序遍历必须先锁死当前层大小
            int size = q.size();
            for(int i = 0; i < size; ++i){
                TreeNode* cur = q.front();
                q.pop();
                r.push_back(cur->val);

                // 左右孩子入队
                if(cur->left != nullptr){
                    q.push(cur->left);
                }
                if(cur->right != nullptr){
                    q.push(cur->right);
                }
            }
            res.push_back(r);
        }

        return res;
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

    vector<vector<int>> res = s.levelOrder(root);
    for (int i = 0; i < res.size(); ++i)
    {
        for (auto r : res[i])
        {
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}