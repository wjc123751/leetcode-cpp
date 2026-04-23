#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm> // 必须加！

using namespace std;

// class Solution
// {
// public:
//     vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
//     {
//         vector<int> res;
//         for (int i = 0; i < nums1.size(); ++i)
//         {
//             auto it = find(nums2.begin(), nums2.end(), nums1[i]);
//             int idx = it - nums2.begin();
//             while (idx + 1 < nums2.size())
//             {
//                 if (nums2[idx + 1] > nums1[i])
//                 {
//                     res.push_back(nums2[idx + 1]);
//                     break;
//                 }
//                 idx++;
//             }
//             if (idx + 1 == nums2.size())
//             {
//                 res.push_back(-1);
//             }
//         }
//         return res;
//     }
// };

// 单调栈
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        unordered_map<int, int> mp;
        stack<int> st;

        for(int i = 0; i < nums2.size(); ++i){
            while(!st.empty() && nums2[i] > nums2[st.top()]){
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            mp[nums2[st.top()]] = -1;
            st.pop();
        }

        for(int i = 0; i < nums1.size(); ++i){
            res.push_back(mp[nums1[i]]);
        }
        
        return res;
    }
};

int main()
{
    vector<int> nums1 = {3, 1, 5, 7, 9, 2, 6};
    vector<int> nums2 = {1, 2, 3, 5, 6, 7, 9, 11};
    Solution s;
    vector<int> res = s.nextGreaterElement(nums1, nums2);
    for (auto &r : res)
    {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
