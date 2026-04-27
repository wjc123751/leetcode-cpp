#include <iostream>
#include <vector>

using namespace std;

// 状态定义: dp[i] = 前 i 间房子，能偷到的最大总金额
// 状态转移方程: dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
// 初始状态: dp[0] = num[0]; dp[1] = max(nums[0], num[1]);

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> dp(n + 1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; ++i){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    Solution s;
    int res = s.rob(nums);
    cout << res;

    return 0;
}