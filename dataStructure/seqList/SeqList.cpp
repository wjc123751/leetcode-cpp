#include <iostream>
using namespace std;

typedef int ElemType;

// 顺序表结构体
struct SeqList
{
    ElemType *data;
    int length;   // 当前元素个数
    int capacity; // 总容量
};

// 1. 初始化顺序表
void InitList(SeqList *L, int initCap = 10)
{
    L->data = new ElemType[initCap];
    L->length = 0;
    L->capacity = initCap;
}

// 2. 扩容
void Expand(SeqList *L)
{
    int newCap = L->capacity * 2;
    ElemType *newData = new ElemType[newCap];

    // 拷贝旧元素
    for (int i = 0; i < L->length; ++i)
    {
        newData[i] = L->data[i];
    }

    delete[] L->data;
    L->data = newData;
    L->capacity = newCap;
}

// 3. 在位序i插入元素e（位序从1开始）
bool ListInsert(SeqList *L, int i, ElemType e)
{
    // 位置合法校验
    if (i < 1 || i > L->length + 1)
    {
        cout << "插入位置不合法" << endl;
        return false;
    }

    // 容量不足则扩容
    if (L->length >= L->capacity)
    {
        Expand(L);
    }

    // 元素后移
    for (int j = L->length; j >= i; --j)
    {
        L->data[j] = L->data[j - 1];
    }

    L->data[i - 1] = e;
    L->length++;
    return true;
}

// 4. 删除第i个元素，用e带回删除值
bool ListDelete(SeqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
    {
        cout << "删除位置不合法" << endl;
        return false;
    }

    *e = L->data[i - 1];

    // 元素前移覆盖
    for (int j = i; j < L->length; ++j)
    {
        L->data[j - 1] = L->data[j];
    }

    L->length--;
    return true;
}

// 5. 按值查找，返回位序(1开始)，找不到返回0
int LocateElem(SeqList *L, ElemType e)
{
    for (int i = 0; i < L->length; ++i)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

// 6. 按位查找，用e带回元素值
bool GetElem(SeqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
    {
        cout << "位序不合法" << endl;
        return false;
    }
    *e = L->data[i - 1];
    return true;
}

// 7. 打印顺序表
void PrintList(SeqList *L)
{
    cout << "顺序表元素：";
    for (int i = 0; i < L->length; ++i)
    {
        cout << L->data[i] << " ";
    }
    cout << endl;
}

// 8. 销毁顺序表
void DestroyList(SeqList *L)
{
    delete[] L->data;
    L->data = nullptr;
    L->length = 0;
    L->capacity = 0;
}

int main()
{
    SeqList *L = new SeqList();
    InitList(L, 4);

    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    ListInsert(L, 2, 15);

    PrintList(L);

    ElemType val;
    ListDelete(L, 2, &val);
    cout << "被删除元素：" << val << endl;

    PrintList(L);

    cout << "元素30所在位序: " << LocateElem(L, 30) << endl;

    GetElem(L, 2, &val);
    cout << "第2个元素: " << val << endl;

    DestroyList(L);
    return 0;
}