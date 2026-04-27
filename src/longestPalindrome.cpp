#include <iostream>
#include <vector>

using namespace std;

// 状态定义: bool dp[i][j]：表示 字符串 s 的下标 i 到下标 j 的子串，是否为回文
// 状态转移方程: dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]
// 初始状态: 子串长度为 1（i == j）：单个字符，一定是回文 dp[i][i] = true
//           子串长度为 2（j = i+1）：只要两个字符相等，就是回文 dp[i][j] = (s[i] == s[j])

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if(n <= 1){
            return s;
        }
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i){
            dp[i][i] = true;
        }
        int maxLen = 1;
        int start = 0;
        for(int i = 0; i < n-1; ++i){
            int j = i + 1;
            if(s[i] == s[j]){
                dp[i][j] = true;
                maxLen = 2;
                start = i;
            }
        }
        for(int len = 3; len <= n; ++len){
            for(int i = 0; i <= n-len; ++i){
                // i是起点，j是终点
                int j = i + len - 1;
                if(s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    if(len > maxLen){
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main()
{
    Solution s;
    string str = "babad";
    string res = s.longestPalindrome(str);
    cout << res;

    return 0;
}