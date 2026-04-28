#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int curSum, int startIdx)
    {
        if(curSum > target){
            return;
        }
        else if(curSum == target){
            res.push_back(path);
            return;
        }
        for(int i = startIdx; i < candidates.size(); ++i){
            path.push_back(candidates[i]);
            curSum += candidates[i];
            backtracking(candidates, target, curSum, i);
            curSum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        res.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    res = s.combinationSum(candidates, target);
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
