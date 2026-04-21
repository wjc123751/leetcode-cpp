#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 三重循环 O(n³)
// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         set<vector<int>> result;
//         for(int i = 0; i < nums.size(); ++i)
//         {
//             for(int j = i + 1; j < nums.size(); ++j)
//             {
//                 for(int k = j + 1; k < nums.size(); ++k)
//                 {
//                     if(nums[i] + nums[j] + nums[k] == 0)
//                     {
//                         result.insert({nums[i], nums[j], nums[k]});
//                     }
//                 }
//             }
//         }
//         return vector<vector<int>>(result.begin(), result.end());
//     }
// };

// 双指针 O(n²)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        for(int i = 0; i < nums.size() - 2; ++i){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    result.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        vector<vector<int>> res(result.begin(), result.end());
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto res = sol.threeSum(nums);
    for (const auto &triplet : res)
    {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}