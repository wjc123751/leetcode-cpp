#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 标准语法格式：
// [捕获列表](参数列表) mutable -> 返回值类型 {函数体}

// 自定义结构体
struct Student {
    string name;
    int score;
};

int main() {
    vector<Student> stus = {{"Tom", 80}, {"Jerry", 95}, {"Alice", 88}};

    // 按分数 升序排序（严格标准格式）
    sort(stus.begin(), stus.end(), 
    []           // 捕获列表
    (const Student& s1, const Student& s2)  // 参数列表
    mutable      // mutable (这里不需要,保留格式)
    -> bool      // 返回值类型（sort 必须返回 bool）
    {            // 函数体
        return s1.score < s2.score;
    });

    // 输出
    for(auto& s : stus) {
        cout << s.name << " " << s.score << endl;
    }
    return 0;
}