#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (map.count(complement)) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 4};
    int target = 9;
    auto res = sol.twoSum(nums, target);
    for (int x : res)
        cout << x << " ";
    return 0;
}