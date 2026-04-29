#include <iostream>
using namespace std;

typedef int ElemType;

struct ListNode
{
    ElemType data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(ElemType x) : data(x), next(nullptr) {}
    ListNode(ElemType x, ListNode *next) : data(x), next(next) {}
};

// ================= 插入（第i个位置，i从1开始） =================
bool InsertList(ListNode *&head, int i, ElemType e)
{
    if (i < 1)
        return false;

    ListNode *newNode = new ListNode(e);

    if (i == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ListNode *cur = head;

        // 找第 i-1 个节点
        for (int j = 1; j < i - 1; ++j)
        {
            if (!cur)
                return false;
            cur = cur->next;
        }

        if (!cur)
            return false;

        newNode->next = cur->next;
        cur->next = newNode;
    }

    return true;
}

// ================= 删除（第i个位置） =================
bool DeleteList(ListNode *&head, int i, ElemType &e)
{
    if (i < 1 || !head)
        return false;

    if (i == 1)
    {
        ListNode *tmp = head;
        e = tmp->data;
        head = head->next;
        delete tmp;
    }
    else
    {
        ListNode *cur = head;

        // 找第 i-1 个节点
        for (int j = 1; j < i - 1; ++j)
        {
            if (!cur)
                return false;
            cur = cur->next;
        }

        if (!cur || !cur->next)
            return false;

        ListNode *tmp = cur->next;
        e = tmp->data;
        cur->next = tmp->next;
        delete tmp;
    }

    return true;
}

// ================= 按位查找 =================
bool GetElem(ListNode *head, int i, ElemType &e)
{
    if (i < 1)
        return false;

    ListNode *p = head;
    int j = 1;

    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    if (!p)
        return false;

    e = p->data;
    return true;
}

// ================= 按值查找 =================
ListNode *LocateElem(ListNode *head, ElemType e)
{
    ListNode *p = head;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// ================= 销毁 =================
void DestroyList(ListNode *&head)
{
    ListNode *cur = head;
    while (cur)
    {
        ListNode *tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head = nullptr; // 防止野指针
}

// ================= 打印 =================
void PrintList(ListNode *head)
{
    ListNode *cur = head;
    cout << "链表：";
    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// ================= 主函数 =================
int main()
{
    ListNode *head = nullptr;
    InsertList(head, 1, 20); // 插入到第1位

    InsertList(head, 1, 10); // 插入到第1位
    PrintList(head);

    InsertList(head, 3, 15); // 插入到第3位
    PrintList(head);

    int d;
    DeleteList(head, 2, d); // 删除第2个
    cout << "删除元素：" << d << endl;
    PrintList(head);

    int e;
    if (GetElem(head, 2, e))
    {
        cout << "第2个元素: " << e << endl;
    }

    DestroyList(head);

    return 0;
}