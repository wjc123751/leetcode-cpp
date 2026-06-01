#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNthValue(int M, int N) {
        int max_num = INT_MIN;
        int min_num = INT_MAX;
        vector<int> nums;
        for(int i = 1; i <= M; ++i){
            nums.push_back(i);
            max_num = max(max_num, i);
            min_num = min(min_num, i);
        }
        if(N <= M){
            return nums[N-1];
        }
        bool is_same = false;
        for(int i = M+1; i <= N; ++i){
            int num = 0;
            if(!is_same){
                num = max_num - min_num;
            }
            else{
                num = max_num + min_num;
            }
            if(is_same == false && find(nums.begin(), nums.end(),num) != nums.end()){
                is_same = true;
            }
            nums.push_back(num);
            if(nums.size() > M){
                nums.erase(nums.begin());
                max_num = INT_MIN;
                min_num = INT_MAX;
            }
            for(int num : nums){
                max_num = max(max_num, num);
                min_num = min(min_num, num);
            }
        }
        return nums.back();
    }
};

int main(){
    Solution s;
    int M;
    int N;
    cin >> M >> N;
    cout << s.getNthValue(M, N);
    return 0;
}

