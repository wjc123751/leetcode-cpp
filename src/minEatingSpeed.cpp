#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 二分查找判定，核心是「找满足条件的最小 k」

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int pmax = -1;
        for(int p : piles){
            pmax = max(pmax, p);
        }
        int right = pmax;
        while(left < right){
            int mid = left + (right - left) / 2;
            int time = 0;
            for(int p : piles){
                time += (p + mid - 1) / mid;
            }
            if(time > h){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};

int main()
{
    Solution s;
    vector<int> piles = {30,11,23,4,20};
    int h = 6;
    int res = s.minEatingSpeed(piles, h);
    cout << res;

    return 0;
}
