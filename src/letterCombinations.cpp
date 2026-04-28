#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    vector<string> res;
    string path;
    unordered_map<char, string> phoneMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    
    void backtracking(string digits, int index){
        if(index == digits.size()){
            res.push_back(path);
            return;
        }
        for(auto p : phoneMap[digits[index]]){
            path.push_back(p);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        path.clear();
        backtracking(digits, 0);
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> res;
    string digits = "23";
    res = s.letterCombinations(digits);
    for (auto r : res)
    {
        cout << r << " ";
    }

    return 0;
}