#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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

// 每个柱子宽度为 1，以某根柱子的高度为矩形高，向左右扩展，找到左右第一个比它矮的柱子，
// 中间的宽度 × 当前高度，就是这个柱子能围成的最大矩形面积，最终取全局最大值。

// O (n) 单调栈
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxarea = 0;
        stack<int> st;
        heights.push_back(0);       // 2, 4 这种情况
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int idxh = st.top();
                st.pop();
                int l;
                if (st.empty())
                {
                    l = -1;
                }
                else
                {
                    l = st.top();
                }
                int area = heights[idxh] * (i - l - 1);
                maxarea = max(area, maxarea);
            }
            st.push(i);
        }

        return maxarea;
    }
};

int main()
{
    Solution s;
    vector<int> height = {2, 4};
    int res = s.largestRectangleArea(height);
    cout << res;

    return 0;
}