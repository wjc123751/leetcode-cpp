#include <iostream>
#include <vector>

using namespace std;

// 环形拆成两个线性普通打家劫舍问题：
// 情况 1：不偷最后一间，只在 [0, n-2] 区间求最大金额
// 情况 2：不偷第一间，只在 [1, n-1] 区间求最大金额

// 状态定义 dp[i] = 前 i 间房子，能偷到的最大总金额
// 状态转移方程: dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
// 初始状态: dp[0] = num[0]; dp[1] = max(nums[0], num[1]);

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        int case1 = robLine(nums1);
        int case2 = robLine(nums2);
        int res = max(case1, case2);
        return res;
    }

    int robLine(vector<int> &nums)
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
        for (int i = 2; i < n; ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};

int main()
{
    vector<int> nums = {2,2,3};
    Solution s;
    int res = s.rob(nums);
    cout << res;

    return 0;
}