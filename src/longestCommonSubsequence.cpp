#include <iostream>
#include <vector>

using namespace std;

// 状态定义: dp[i][j] text1 的前 i 个字符、text2 的前 j 个字符，能构成的最长公共子序列的长度 i、j 从 1 开始计数
// 状态转移方程:
// if text1[i-1] == text2[j-1] dp[i][j]=dp[i−1][j−1]+1
// if text1[i-1] != text2[j-1] dp[i][j]=max(dp[i−1][j], dp[i][j−1]) 不能同时选这两个字符来加长公共子序列
// 初始状态:
// dp[0][j]=0(∀ j)
// dp[i][0]=0(∀ i)

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); ++i)
        {
            for (int j = 1; j <= text2.size(); ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

int main()
{
    string tx1 = "abcde";
    string tx2 = "ace";
    Solution s;
    int res = s.longestCommonSubsequence(tx1, tx2);
    cout << res;

    return 0;
}
