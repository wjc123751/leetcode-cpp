#include <iostream>
using namespace std;

// shared_ptr 底层是引用计数实现：
// 内部维护一个原始指针和一个共享的引用计数
// 拷贝时计数 + 1，析构时计数 - 1
// 当计数变为 0，才真正释放对象内存
// 线程安全指计数安全（原子操作），对象访问不安全（指向的实际数据读写线程不安全）

// 手写 简易 shared_ptr
template <typename T>
class MySharedPtr {
private:
    T* _ptr;           // 真实指针
    int* _refCount;    // 引用计数（必须是指针！所有对象共用）

public:
    // 1. 构造函数
    MySharedPtr(T* ptr = nullptr) : _ptr(ptr) {
        if (_ptr) {
            _refCount = new int(1); // 创建计数，初始=1
        } else {
            _refCount = new int(0);
        }
    }

    // 2. 拷贝构造（核心！）
    MySharedPtr(const MySharedPtr& other) {
        _ptr = other._ptr;
        _refCount = other._refCount; // 共用计数器
        (*_refCount)++;              // 计数+1
    }

    // 3. 赋值重载
    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this == &other) return *this;

        // 先释放当前对象
        (*_refCount)--;
        if (*_refCount == 0) {
            delete _ptr;
            delete _refCount;
        }

        // 共享新对象
        _ptr = other._ptr;
        _refCount = other._refCount;
        (*_refCount)++;
        return *this;
    }

    // 4. 析构函数（计数-1，=0才释放）
    ~MySharedPtr() {
        (*_refCount)--;
        if (*_refCount == 0) {
            delete _ptr;
            delete _refCount;
            cout << "内存已释放\n";
        }
    }

    // 指针用法(* ->运算符重载)
    T& operator*() { return *_ptr; }
    T* operator->() { return _ptr; }

    // 获取引用计数
    int use_count() { return *_refCount; }
};

// 测试
int main() {
    MySharedPtr<int> p1(new int(10));
    cout << p1.use_count() << endl; // 1

    MySharedPtr<int> p2 = p1;
    cout << p1.use_count() << endl; // 2

    MySharedPtr<int> p3(p1);
    cout << p1.use_count() << endl; // 3

    return 0; // 最后计数变0，自动释放
}