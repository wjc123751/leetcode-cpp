#include <iostream>
using namespace std;

typedef int ElemType;

struct DListNode
{
    ElemType data;
    DListNode *prev;
    DListNode *next;
    DListNode() : data(0), prev(nullptr), next(nullptr) {}
    DListNode(ElemType x) : data(x), prev(nullptr), next(nullptr) {}
};

bool InsertList(DListNode *&head, int i, ElemType e)
{
    if (i < 1)
        return false;

    DListNode *newNode = new DListNode(e);

    // 插入到第1个位置
    if (i == 1)
    {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
        return true;
    }

    DListNode *cur = head;

    for (int j = 1; j < i - 1; j++)
    {
        if (!cur)
            return false;
        cur = cur->next;
    }

    if (!cur)
        return false;

    newNode->next = cur->next;
    newNode->prev = cur;

    if (cur->next)
        cur->next->prev = newNode;

    cur->next = newNode;

    return true;
}

bool DeleteList(DListNode *&head, int i, ElemType &e)
{
    if (i < 1 || !head)
        return false;

    DListNode *cur = head;

    if (i == 1)
    {
        e = cur->data;
        head = cur->next;

        if (head)
            head->prev = nullptr;

        delete cur;
        return true;
    }

    for (int j = 1; j < i; j++)
    {
        if (!cur)
            return false;
        cur = cur->next;
    }

    if (!cur)
        return false;

    e = cur->data;

    if (cur->prev)
        cur->prev->next = cur->next;

    if (cur->next)
        cur->next->prev = cur->prev;

    delete cur;

    return true;
}

bool GetElem(DListNode *head, int i, ElemType &e)
{
    if (i < 1)
        return false;

    DListNode *p = head;

    for (int j = 1; j < i; j++)
    {
        if (!p)
            return false;
        p = p->next;
    }

    if (!p)
        return false;

    e = p->data;
    return true;
}

DListNode *LocateElem(DListNode *head, ElemType e)
{
    DListNode *p = head;

    while (p && p->data != e)
    {
        p = p->next;
    }

    return p;
}

void DestroyList(DListNode *&head)
{
    DListNode *cur = head;

    while (cur)
    {
        DListNode *tmp = cur;
        cur = cur->next;
        delete tmp;
    }

    head = nullptr; // 防止野指针
}

void PrintList(DListNode *head)
{
    DListNode *p = head;

    cout << "链表：";
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void PrintReverse(DListNode *head)
{
    if (!head)
        return;

    DListNode *p = head;

    while (p->next)
    {
        p = p->next;
    }

    cout << "反向链表：";

    while (p)
    {
        cout << p->data << " ";
        p = p->prev;
    }

    cout << endl;
}

int main()
{
    DListNode *head = nullptr;

    cout << "=== 插入测试 ===" << endl;

    InsertList(head, 1, 10); // 10
    InsertList(head, 2, 20); // 10 20
    InsertList(head, 3, 30); // 10 20 30
    InsertList(head, 2, 15); // 10 15 20 30

    PrintList(head);
    PrintReverse(head);

    cout << "\n=== 按位查找 ===" << endl;
    ElemType val;
    if (GetElem(head, 3, val))
        cout << "第3个元素: " << val << endl;

    cout << "\n=== 按值查找 ===" << endl;
    DListNode *p = LocateElem(head, 20);
    if (p)
        cout << "找到值20节点: " << p->data << endl;

    cout << "\n=== 删除测试 ===" << endl;

    ElemType del;

    DeleteList(head, 1, del);
    cout << "删除第1个元素: " << del << endl;
    PrintList(head);

    DeleteList(head, 2, del);
    cout << "删除第2个元素: " << del << endl;
    PrintList(head);

    cout << "\n=== 最终状态 ===" << endl;
    PrintList(head);
    PrintReverse(head);

    cout << "\n=== 销毁链表 ===" << endl;

    DestroyList(head);

    if (!head)
    {
        cout << "销毁完成, head已置空" << endl;
    }

    cout << "销毁完成" << endl;

    return 0;
}
