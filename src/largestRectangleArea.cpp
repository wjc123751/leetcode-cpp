#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 每个柱子宽度为 1，以某根柱子的高度为矩形高，向左右扩展，找到左右第一个比它矮的柱子，
// 中间的宽度 × 当前高度，就是这个柱子能围成的最大矩形面积，最终取全局最大值。

// O(n²)
// class Solution
// {
// public:
//     int largestRectangleArea(vector<int> &heights)
//     {
//         int maxarea = 0;
//         int n = heights.size();

//         for (int i = 0; i < n; ++i)
//         {
//             int left = -1;
//             for (int j = i - 1; j >= 0; --j)
//             {
//                 if (heights[j] < heights[i])
//                 {
//                     left = j;
//                     break;
//                 }
//             }

//             int right = n;  // 默认是 n，不是 -1
//             for (int j = i + 1; j < n; ++j)
//             {
//                 if (heights[j] < heights[i])
//                 {
//                     right = j;
//                     break;
//                 }
//             }

//             int width = right - left - 1;
//             int area = heights[i] * width;

//             if (area > maxarea)
//                 maxarea = area;
//         }
//         return maxarea;
//     }
// };

// O (n) 单调栈
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxarea = 0;
        stack<int> st;        // 栈里存下标，保持高度单调递增
        heights.push_back(0); // 末尾加0，强迫栈里所有剩下的元素全部弹出来计算面积

        for (int i = 0; i < heights.size(); ++i)
        {
            // 遇到更小的高度，弹出栈顶计算面积
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                // 弹出的这个柱子：要计算以它为高的矩形
                int h = heights[st.top()];
                st.pop();

                // 左边第一个比它小的：新的栈顶！
                // 右边第一个比它小的：当前 i！
                int w;
                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1; // 宽度 = 右 - 左 - 1

                maxarea = max(maxarea, h * w);
            }
            st.push(i);
        }

        return maxarea;
    }
};

int main()
{
    Solution s;
    vector<int> height = {2, 1, 5, 6, 2, 3};
    int res = s.largestRectangleArea(height);
    cout << res;

    return 0;
}