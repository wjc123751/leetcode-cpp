#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 核心原理：每个柱子上方能接的雨水量 = 左右两侧最高柱子的较小值 - 当前柱子高度

// 暴力解法 O (n²) 超时
// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int res = 0;    // 必须初始化为0
//         for (int i = 1; i < height.size() - 1; ++i)
//         {
//             int lefth = *max_element(height.begin(), height.begin() + i);
//             int righth = *max_element(height.begin() + i + 1, height.end());
//             int minh = min(lefth, righth);
//             int rainh = minh - height[i];
//             if (rainh > 0)
//             {
//                 res += rainh;
//             }
//         }
//         return res;
//     }
// };

// 双指针 O(n)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;
        int lefthmax = 0;
        int righthmax = 0;
        while (left < right)
        {
            lefthmax = max(lefthmax, height[left]);
            righthmax = max(righthmax, height[right]);

            if (lefthmax < righthmax)
            {
                res += lefthmax - height[left];
                left++;
            }
            else
            {
                res += righthmax - height[right];
                right--;
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = s.trap(height);
    cout << res;

    return 0;
}