#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

// 前序遍历（根→左→右）：数组第一个元素，永远是当前树 / 子树的根节点
// 中序遍历（左→根→右）：根节点的左边，全是左子树；根节点的右边，全是右子树
// 前序定根，中序分左右，递归分治，左右分别再造。

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if(preorder.empty() || inorder.empty()){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int rootIndex = it - inorder.begin();
        
        vector<int> preLeft(preorder.begin() + 1, preorder.begin() + 1 + rootIndex);
        vector<int> preRight(preorder.begin() + 1 + rootIndex, preorder.end());

        vector<int> inLeft(inorder.begin(), it);
        vector<int> inRight(it + 1, inorder.end());

        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);

        return root;
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> r;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();
                r.push_back(cur->val);
                if (cur->left != nullptr)
                {
                    q.push(cur->left);
                }
                if (cur->right != nullptr)
                {
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

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = s.buildTree(preorder, inorder);

    vector<vector<int>> res = s.levelOrder(root);

    for(int i = 0; i < res.size(); ++i){
        for(auto r : res[i]){
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}
