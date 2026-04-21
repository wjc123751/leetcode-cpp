#include <iostream>
#include <vector>
#include <set>
using namespace std;

// class Solution
// {
// public:
//     int removeElement(vector<int> &nums, int val)
//     {
//         for(auto it = nums.begin(); it != nums.end();)
//         {
//             if (*it == val)
//                 it = nums.erase(it);
//             else
//                 ++it;
//         }
//         return nums.size();
//     }
// };

// class Solution
// {
// public:
//     int removeElement(vector<int> &nums, int val)
//     {
//         vector<int> res;
//         for(auto& n: nums){
//             if(n != val){
//                 res.push_back(n);
//             }
//         }
//         nums = res;
//         return nums.size();
//     }
// };

// 快慢指针
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int res = 0;
        int l = 0;
        int h = 0;
        while (h < nums.size())
        {
            if (nums[h] == val)
            {
                h++;
            }
            else
            {
                nums[l] = nums[h];
                l++;
                h++;
            }
        }
        vector<int> r(nums.begin(), nums.begin() + l);
        r.swap(nums);
        return l;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int res = sol.removeElement(nums, val);
    cout << res << endl;
    for (int x : nums)
        cout << x << " ";
    return 0;
}
