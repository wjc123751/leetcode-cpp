#include <iostream>
#include <vector>
#include <algorithm>  // 排序必须加这个头文件
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> merged(nums1.begin(), nums1.begin() + m);
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        sort(merged.begin(), merged.end());
        nums1 = merged;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    sol.merge(nums1, m, nums2, n);
    for (int x : nums1)
        cout << x << " ";
    return 0;
}