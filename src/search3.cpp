#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// class Solution
// {
// public:
//     bool search(vector<int> &nums, int target)
//     {
//         sort(nums.begin(), nums.end());
//         int left = 0;
//         int right = nums.size() - 1;
//         while (left <= right)
//         {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] == target)
//             {
//                 return true;
//             }
//             else if (nums[mid] < target)
//             {
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid - 1;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // ========= 第一步：用 set 去重 =========
        set<int> s(nums.begin(), nums.end());
        vector<int> newNums(s.begin(), s.end()); // 转成无重复数组

        // ========= 第二步：标准二分 =========
        int left = 0;
        int right = newNums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (newNums[mid] == target) return true;

            // 左半段有序
            if (newNums[left] <= newNums[mid]) {
                if (target >= newNums[left] && target < newNums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            // 右半段有序
            else {
                if (target > newNums[mid] && target <= newNums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    int res = s.search(nums, target);
    cout << res;

    return 0;
}