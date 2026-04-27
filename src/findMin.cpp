#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 原本是升序，从中间旋转了一次，只有一个下降点

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
            {
                // 最小值在右半区
                left = mid + 1;
            }
            else
            {
                // 最小值在左半区，保留mid
                right = mid;
            }
        }
        return nums[left];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 4, 5, 1, 2};
    int res = s.findMin(nums);
    cout << res;

    return 0;
}
