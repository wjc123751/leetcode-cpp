#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
private:
    set<vector<int>> res;
    vector<vector<int>> ret;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIdx)
    {
        res.insert(path);
        for (int i = startIdx; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        res.clear();
        path.clear();
        backtracking(nums, 0);
        ret.assign(res.begin(), res.end());
        return ret;
    }
};

int main()
{
    vector<vector<int>> res;
    Solution s;
    vector<int> nums = {4, 4, 4, 1, 4};
    res = s.subsetsWithDup(nums);
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
