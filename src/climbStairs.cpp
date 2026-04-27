#include <iostream>
#include <vector>

using namespace std;

// 状态定义:dp[i] 表示爬到第 i 阶的不同方法数量
// 状态转移方程: dp[i] = dp[i-1] + dp[i-2]
// 初始状态: dp[1] = 1; dp[2] = 2;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    int n = 2;
    int res = s.climbStairs(n);
    cout << res;

    return 0;
}