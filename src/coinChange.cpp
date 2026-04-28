#include <iostream>
#include <vector>

using namespace std;

// 状态定义: dp[i]：凑出总金额 i，所需要的最少硬币数量
// 状态转移方程: 如果 coin <= i dp[i]=min(dp[i], dp[i−coin]+1);
// 初始状态: dp[0] = 0;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (auto cs : coins)
            {
                if (cs <= i)
                {
                    dp[i] = min(dp[i], dp[i - cs] + 1);
                }
            }
        }
        if(dp[amount] > amount){
            return -1;
        }
        return dp[amount];
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int res = s.coinChange(coins, amount);
    cout << res;

    return 0;
}