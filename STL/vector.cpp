#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class MyVector
{
private:
    T* _start;         // 起始指针
    T* _finish;        // 有效元素末尾
    T* _end_storage;   // 内存容量末尾

public:
    // 构造
    MyVector()
        : _start(nullptr), _finish(nullptr), _end_storage(nullptr)
    {}

    // 析构
    ~MyVector()
    {
        delete[] _start;
        _start = _finish = _end_storage = nullptr;
    }

    // 获取元素个数
    int size() const
    {
        return _finish - _start;
    }

    // 获取容量
    int capacity() const
    {
        return _end_storage - _start;
    }

    // 尾插元素
    void push_back(const T& val)
    {
        // 容量已满，触发扩容
        if (size() == capacity())
        {
            int newCap = capacity() == 0 ? 1 : capacity() * 2;
            expand(newCap);
        }
        *_finish = val;
        _finish++;
    }

    // 扩容函数
    void expand(int newCap)
    {
        T* newSpace = new T[newCap];
        int oldSize = size();
        // 拷贝旧数据
        for (int i = 0; i < oldSize; ++i)
        {
            newSpace[i] = _start[i];
        }
        // 释放旧空间
        delete[] _start;
        // 更新三个指针
        _start = newSpace;
        _finish = _start + oldSize;
        _end_storage = _start + newCap;
    }

    // 尾删
    void pop_back()
    {
        assert(size() > 0);
        _finish--;
    }

    // 下标访问
    T& operator[](int idx)
    {
        assert(idx >= 0 && idx < size());
        return _start[idx];
    }
};

// 测试
int main()
{
    MyVector<int> vec;
    for (int i = 1; i <= 5; ++i)
    {
        vec.push_back(i);
        cout << "大小：" << vec.size() << " 容量：" << vec.capacity() << endl;
    }

    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    return 0;
}