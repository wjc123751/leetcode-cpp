// 时间复杂度O(logn)
// 数组必须有序
#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    int target = 3;
    int pos = BinarySearch(a, target);

    return 0;
}