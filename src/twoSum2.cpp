#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &numbers, int target)
//     {
//         unordered_map<int, int> map;
//         for (int i = 0; i < numbers.size(); ++i)
//         {
//             int complement = target - numbers[i];
//             if (map.count(complement))
//             {
//                 return {map[complement] + 1, i + 1}; // 返回1-based索引
//             }
//             map[numbers[i]] = i;
//         }
//         return {};
//     }
// };

// 双指针
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> res;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                res.push_back(left + 1);
                res.push_back(right + 1);
                break;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    auto res = sol.twoSum(numbers, target);
    for (int x : res)
        cout << x << " ";
    return 0;
}
