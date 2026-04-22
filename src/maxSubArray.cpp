#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// O(n³)
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         int max = -1e4;
//         for(int i = 0; i < nums.size(); ++i){
//             vector<int> sub;
//             for(int j = i; j < nums.size(); ++j){
//                 sub.push_back(nums[j]);
//                 int sum = accumulate(sub.begin(), sub.end(), 0);
//                 if(sum > max){
//                     max = sum;
//                 }
//             }
//         }
//         return max;
//     }
// };

// O(n²)
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         int max = -1e4;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             int sum = 0;
//             for (int j = i; j < nums.size(); ++j)
//             {
//                 sum += nums[j];
//                 if (sum > max)
//                 {
//                     max = sum;
//                 }
//             }
//         }
//         return max;
//     }
// };

// Kadane 算法 O(n)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int cur = nums[0];
        int maxsub = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            cur = max(nums[i], cur + nums[i]);
            maxsub = max(maxsub, cur);
        }
        return maxsub;
    }
};

int main()
{

    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = s.maxSubArray(nums);
    cout << res;

    return 0;
}
