#include <iostream>
#include <vector>

using namespace std;

// 桶排序思想
// 答案一定在 [1, n+1] 之间，其中 n 是数组长度

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 0};
    int res = s.firstMissingPositive(nums);
    cout << res;

    return 0;
}