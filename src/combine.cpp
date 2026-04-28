#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(int n, int k, int startIdx)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for (int i = startIdx; i <= n; ++i)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        res.clear();
        path.clear();
        backtracking(n, k, 1);

        return res;
    }
};

int main()
{
    vector<vector<int>> res;
    Solution s;
    int n = 4;
    int k = 2;
    res = s.combine(n, k);
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