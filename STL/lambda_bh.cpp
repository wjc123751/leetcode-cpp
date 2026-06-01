// 1. 引入必要的标准库头文件
#include <iostream>
#include <vector>
#include <algorithm>

// 2. 声明std命名空间，简化标准库调用
using namespace std;

int main() {
    // 3. 所有变量定义、业务逻辑放入main函数内部
    int mid = 50;
    vector<int> score = {60, 30, 70, 20};
    
    // 捕获外部mid，大于50的元素排前面
    sort(score.begin(), score.end(), [mid](int a, int b) {
        return (a > mid) > (b > mid);
    });

    // 可选：打印排序结果验证
    for (int s : score) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}