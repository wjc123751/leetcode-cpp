#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int> &nums, int startIdx)
    {
        res.push_back(path);
        for (int i = startIdx; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;
    }
};

int main()
{
    vector<vector<int>> res;
    Solution s;
    vector<int> nums = {1, 2, 2};
    res = s.subsets(nums);
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