#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n == 1){
            return true;
        }
        if(n < 0){
            n = -n;
        }
        vector<int> zhishu;
        for(int i = 2; i <= n; ++i){
            while(n % i == 0){
                zhishu.push_back(i);
                n /= i;
            }
        }
        for(int i = 0; i < zhishu.size(); ++i){
            if(zhishu[i] != 2 && zhishu[i] != 3 && zhishu[i] != 5){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    int num = -2147483648;
    bool res = s.isUgly(num);

    return 0;
}