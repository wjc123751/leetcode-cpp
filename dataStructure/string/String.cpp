#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ===================== 1. 字符串基本操作 =====================
void stringBasicOperation()
{
    string s1 = "hello";
    string s2("world");

    string s = s1 + " " + s2;

    // 截取子串 substr(起始位置, 长度)
    string sub = s.substr(1, 3);
    cout << "substr(1,3): " << sub << endl;

    // 查找字符
    size_t pos = s.find('w'); // 用 size_t 类型
    if (pos == string::npos)
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << "找到了，位置是：" << pos << endl;
    }
}

// ===================== 2. 暴力匹配算法 =====================
int violentMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();

    for (int i = 0; i <= n - m; ++i)
    {
        int j = 0;
        while (j < m && s[i + j] == p[j])
        {
            j++;
        }
        if (j == m)
            return i;
    }
    return -1;
}

// ===================== 3. KMP 算法 =====================

// 求next数组 后缀匹配前缀
vector<int> getNext(string p){
    int m = p.size();
    vector<int> next(m, 0);
    int j = 0;
    for(int i = 1; i < m; ++i){
        while(j > 0 && p[i] != p[j]){
            j = next[j - 1];
        }
        if(p[i] == p[j]){
            j++;
        }
        next[i] = j;
    }
    return next;
}

// 求nextval数组
vector<int> getNext(string p, vector<int> next){
    int m = p.size();
    vector<int> nextval(m, 0);
    int j = 0;
    for(int i = 1; i < m; ++i){
        // 如果当前字符 == next 指向的字符
        if(p[i] = p[next[i]]){
            nextval[i] = nextval[next[i]];
        }
        else{
            nextval[i] = next[i];
        }
    }
    return nextval;
}

// KMP算法 主串匹配子串
// i 指向主串最后一个匹配成功的位置
// j 指向当前已匹配成功的字符个数
int kmpSearch(string s, string p, vector<int> next){
    int n = s.size();
    int m = p.size();
    int j = 0;
    for(int i = 1; i < n; ++i){
        while(j > 0 && s[i] != p[j]){
            j = next[j - 1];
        }
        if(s[i] == p[j]){
            j++;
        }
        if(j == m){
            return i - m + 1;
        }
    }
    return -1;
}

// KMP算法 主串匹配子串
// i 指向主串最后一个匹配成功的位置
// j 指向当前已匹配成功的字符个数
int kmpSearchVal(string s, string p, vector<int> nextval){
    int n = s.size();
    int m = p.size();
    int j = 0;
    for(int i = 1; i < n; ++i){
        while(j > 0 && s[i] != p[j]){
            j = nextval[j - 1];
        }
        if(s[i] == p[j]){
            j++;
        }
        if(j == m){
            return i - m + 1;
        }
    }
    return -1;
}

// ===================== 主函数 =====================
int main()
{
    // 1. 字符串基本操作
    stringBasicOperation();

    // 2. 测试字符串匹配
    string s = "abcabcabcd";
    string p = "cd";

    // 暴力法
    int pos1 = violentMatch(s, p);
    cout << "暴力匹配结果: " << pos1 << endl;

    // KMP
    vector<int> next = getNext(p);
    int pos2 = kmpSearch(s, p, next);
    cout << "KMP 匹配结果: " << pos2 << endl;

    return 0;
}