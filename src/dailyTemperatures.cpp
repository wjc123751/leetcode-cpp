#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 超时
// class Solution
// {
// public:
//     vector<int> dailyTemperatures(vector<int> &temperatures)
//     {
//         vector<int> res;
//         int left = 0;
//         int right = left + 1;
//         while (left < temperatures.size())
//         {
//             while (right < temperatures.size())
//             {
//                 if (temperatures[right] > temperatures[left])
//                 {
//                     res.push_back(right - left);
//                     break;
//                 }
//                 right++;
//             }
//             if (right == temperatures.size())
//             {
//                 res.push_back(0);
//             }

//             left++;
//             right = left + 1;
//         }
//         return res;
//     }
// };

// 单调栈
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size());
        stack<int> st;
        for(int i = 0; i < temperatures.size(); ++i){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }

        return res;
    }
};

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res;

    Solution s;
    res = s.dailyTemperatures(temperatures);
    for (auto &r : res)
    {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
