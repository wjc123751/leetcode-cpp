#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> vs;
        string tmp;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ' '){
                tmp += s[i];
            }
            else{
                if(tmp.empty()){
                    continue;
                }
                else{
                    vs.push_back(tmp);
                    tmp = "";
                }
            }
        }
        if(!tmp.empty()){
            vs.push_back(tmp);
        }
        string res;
        for(int i = vs.size() - 1; i >= 0; --i){
            res += vs[i];
            if(i > 0){
                res += ' ';
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str = "  hello world  ";
    s.reverseWords(str);

    return 0;
}