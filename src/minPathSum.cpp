#include <iostream>
#include <vector>

using namespace std;

// 状态定义: dp[i][j] = 从初始坐标(0, 0)到坐标(i, j)的最小路径和
// 状态转移方程:
// dp[0][j] = dp[0][j-1] + grid[0][j];
// dp[i][0] = dp[i-1][0] + grid[i][0];
// dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
// 初始状态: dp[0][0] = grid[0][0];

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int res;

        vector<vector<int>> dp = grid;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = grid[0][0];
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        res = dp[grid.size() - 1][grid[0].size() - 1];

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    int res = s.minPathSum(grid);
    cout << res;

    return 0;
}
