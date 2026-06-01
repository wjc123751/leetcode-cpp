#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

template<class Vec>
void func(Vec& v)
{
    // 嵌套依赖类型，只能用typename
    typename Vec::iterator it = v.begin();
}

int main()
{
    vector<int> arr;
    func(arr);
    return 0;
}