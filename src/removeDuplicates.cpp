#include <iostream>
#include <vector>
#include <set>
using namespace std;

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int> unique_nums(nums.begin(), nums.end());
//         vector<int> temp(unique_nums.begin(), unique_nums.end());
//         nums = temp;
//         return unique_nums.size();
//     }
// };

// 快慢指针
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = 0;
        int h = 1;
        while (h < nums.size())
        {
            if (nums[h] == nums[l])
            {
                h++;
            }
            else
            {
                l++;
                nums[l] = nums[h];
                h++;
            }
        }
        vector<int> r(nums.begin(), nums.begin() + l + 1);
        r.swap(nums);
        return l + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 2};
    int res = sol.removeDuplicates(nums);
    cout << res << endl;
    for (int x : nums)
        cout << x << " ";
    return 0;
}