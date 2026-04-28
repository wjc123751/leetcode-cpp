#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
private:
    set<vector<int>> res;
    vector<int> path;
    vector<bool> used;

    void backtracking(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            res.insert(path);
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
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        res.clear();
        path.clear();
        used.assign(nums.size(), false);
        backtracking(nums);
        vector<vector<int>> ret(res.begin(), res.end());
        return ret;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res;
    vector<int> nums = {1, 1, 2};
    res = s.permuteUnique(nums);
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
