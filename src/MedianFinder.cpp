#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 大顶堆（left）：存前半部分数据，最大值在堆顶（所有数都 ≤ 中位数）
// 小顶堆（right）：存后半部分数据，最小值在堆顶（所有数都 ≥ 中位数）

class MedianFinder
{
public:
    priority_queue<int> left;                             // 大顶堆，存前半部分
    priority_queue<int, vector<int>, greater<int>> right; // 小顶堆，存后半部分

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (left.empty() || num <= left.top())
        {
            left.push(num);
        }
        else
        {
            right.push(num);
        }
        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        if (right.size() > left.size())
        {
            left.push(right.top());
            right.pop();
        }
        if (!left.empty() && !right.empty() && left.top() > right.top())
        {
            int l = left.top();
            left.pop();
            int r = right.top();
            right.pop();
            left.push(r);
            right.push(l);
        }
    }

    double findMedian()
    {
        if (left.size() > right.size())
        {
            return left.top();
        }
        else
        {
            return (left.top() + right.top()) / 2.0;
        }
    }
};

int main()
{
    MedianFinder mf;

    // 测试用例 1
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl;

    mf.addNum(3);
    cout << mf.findMedian() << endl;

    mf.addNum(4);
    cout << mf.findMedian() << endl;

    return 0;
}