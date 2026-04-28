#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;

    void backtracking(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i] == true)
            {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums);
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        res.clear();
        path.clear();
        used.assign(nums.size(), false);
        backtracking(nums);
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res;
    vector<int> nums = {1, 2, 3};
    res = s.permute(nums);
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