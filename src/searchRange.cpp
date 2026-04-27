#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = findLeft(nums, target);
        int right = findRight(nums, target);
        if (left == nums.size() || nums[left] != target)
        {
            return {-1, -1};
        }
        return {left, right};
    }

    int findLeft(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] >= target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }

    int findRight(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0};
    int target = 0;
    vector<int> res = s.searchRange(nums, target);
    for (int r : res)
    {
        cout << r << " ";
    }

    return 0;
}