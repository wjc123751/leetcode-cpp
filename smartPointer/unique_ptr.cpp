#include <iostream>
using namespace std;

// 成员只有一个原始指针，无引用计数，比shared_ptr轻量
// delete 拷贝构造 & 赋值，从语法层面杜绝共享
// 靠移动语义转移资源所有权，原智能指针置空
// 析构直接delete指向内存，出作用域自动释放
// 常用接口底层逻辑
// get()：直接返回内部裸指针
// release()：交出指针地址，自身置空，不释放内存
// reset()：先删旧资源，再指向新地址

template<typename T>
class MyUniquePtr
{
private:
    T* _ptr;  // 仅存原始裸指针，无计数器

public:
    // 普通构造
    explicit MyUniquePtr(T* p = nullptr) : _ptr(p) {}

    // 析构：自动释放内存
    ~MyUniquePtr()
    {
        delete _ptr;
        _ptr = nullptr;
    }

    // ========== 禁止拷贝 ==========
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    // ========== 允许移动 ==========
    // 移动构造
    MyUniquePtr(MyUniquePtr&& other) noexcept
    {
        // 抢走对方指针
        _ptr = other._ptr;
        // 原指针置空，放弃所有权
        other._ptr = nullptr;
    }

    // 移动赋值
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept
    {
        if(this != &other)
        {
            // 先释放自己原有资源
            delete _ptr;
            // 接管新资源
            _ptr = other._ptr;
            other._ptr = nullptr;
        }
        return *this;
    }

    // 指针重载
    T& operator*() const { return *_ptr; }
    T* operator->() const { return _ptr; }

    // 获取裸指针
    T* get() const { return _ptr; }
    // 释放管理权，不析构
    T* release()
    {
        T* temp = _ptr;
        _ptr = nullptr;
        return temp;
    }
    // 重置指向
    void reset(T* p = nullptr)
    {
        delete _ptr;
        _ptr = p;
    }
};

// 测试
int main()
{
    MyUniquePtr<int> p1(new int(666));
    cout << *p1 << endl;

    // MyUniquePtr<int> p2 = p1;  // 报错，拷贝被删除

    MyUniquePtr<int> p2 = move(p1); // 移动构造
    cout << *p2 << endl;

    return 0;
}