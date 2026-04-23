#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> schar;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                schar.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (!schar.empty())
                {
                    if (schar.top() == '(')
                    {
                        schar.pop();
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ']')
            {
                if (!schar.empty())
                {
                    if (schar.top() == '[')
                    {
                        schar.pop();
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == '}')
            {
                if (!schar.empty())
                {
                    if (schar.top() == '{')
                    {
                        schar.pop();
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (schar.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;
    string str = "()";
    bool res = s.isValid(str);
    cout << res;

    return 0;
}