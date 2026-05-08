#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int maxr = 0;
        for(int h : houses){
            maxr = max(maxr, h);
        }
        for(int h : heaters){
            maxr = max(maxr, h);
        }
        // int r;
        for(int r = 0; r <= maxr; ++r){
            bool allCovered = true;
            for(int house : houses){
                bool covered = false;
                for(int heater : heaters){
                    int left = max(heater - r, 1);
                    int right = heater + r;
                    if(house >= left && house <= right){
                        covered = true;
                        break;
                    }
                }
                if(!covered){
                    allCovered = false;
                    break;
                }
            }
            if(allCovered){
                return r;
            }
        }
        return maxr;
    }
};

int main()
{
    Solution s;
    vector<int> houses = {1};
    vector<int> heaters = {1,2,3,4};
    int r = s.findRadius(houses, heaters);

    return 0;
}