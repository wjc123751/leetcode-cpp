#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// 为什么遍历 2*n 次？
// 环形需要：每个元素不仅看自己右边，还要绕到数组开头再找一圈更大值
// 为什么栈存下标，不存数值？
// 解决数组重复元素的问题，精准定位结果位置

// class Solution
// {
// public:
//     vector<int> nextGreaterElements(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> res(n, -1);
//         stack<int> st;

//         // 逻辑遍历2倍数组，模拟环形
//         for (int i = 0; i < 2 * n; ++i)
//         {
//             int idx = i % n;
//             // 当前元素 > 栈顶下标元素，找到栈顶的下一个更大值
//             while (!st.empty() && nums[idx] > nums[st.top()])
//             {
//                 res[st.top()] = nums[idx];
//                 st.pop();
//             }
//             // 只在前n个下标入栈，避免重复处理
//             if (i < n)
//             {
//                 st.push(idx);
//             }
//         }

//         return res;
//     }
// };

// 暴力解
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1);  // 保持-1
        stack<int> st;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int idx = (i + j) % n; // 你原来的环形下标
                
                // 判断 nums[idx] > nums[i]（当前i的下一个更大）
                if (nums[idx] > nums[i])
                {
                    res[i] = nums[idx];
                    break; // 找到就退出j循环
                }
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1};
    Solution s;
    vector<int> res = s.nextGreaterElements(nums);
    for (auto &r : res)
    {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
