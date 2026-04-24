#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// class Solution
// {
// public:
//     int longestConsecutive(vector<int> &nums)
//     {
//         if(nums.empty()){
//             return 0;
//         }

//         int curLen = 1;
//         int maxLen = 1;
//         sort(nums.begin(), nums.end());
//         for(int i = 1; i < nums.size(); ++i){
//             if(nums[i] == nums[i-1]){
//                 continue;
//             }
//             if(nums[i] - nums[i-1] == 1){
//                 curLen++;
//                 maxLen = max(maxLen, curLen);
//             }
//             else{
//                 curLen = 1;
//             }
//         }
//         return maxLen;
//     }
// };

// 哈希集合
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int maxLen = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        for (int s : set)
        {
            if(!set.count(s - 1)){
                int cur = s;
                int curLen = 1;
                while(set.count(cur + 1)){
                    cur++;
                    curLen++;
                }
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int res = s.longestConsecutive(nums);
    cout << res;

    return 0;
}
