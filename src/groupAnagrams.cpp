#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); ++i)
        {
            string val = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(val);
        }
        vector<vector<string>> res;
        for (auto &p : mp)
        {
            res.push_back(p.second);
        }
        return res;
    }
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res;
    Solution s;
    res = s.groupAnagrams(strs);
    for (int i = 0; i < res.size(); ++i)
    {
        for (auto &r : res[i])
        {
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}
