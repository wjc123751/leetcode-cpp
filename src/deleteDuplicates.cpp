#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // 处理空链表
        if (!head)
            return nullptr;

        // 虚拟头节点，处理头节点重复的情况
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy; // prev 指向当前不重复节点的前一个
        ListNode *cur = head;

        while (cur)
        {
            // 标记是否重复
            bool duplicate = false;
            // 找到所有和 cur 重复的节点
            while (cur->next && cur->val == cur->next->val)
            {
                duplicate = true;
                cur = cur->next;
            }

            if (duplicate)
            {
                // 删掉所有重复节点
                prev->next = cur->next;
            }
            else
            {
                // 不重复，prev 往后移
                prev = prev->next;
            }

            cur = cur->next;
        }

        return dummy->next;
    }

    void printList(ListNode *head)
    {
        ListNode *cur = head;
        while (cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    ListNode *res = s.deleteDuplicates(head);
    s.printList(res);

    return 0;
}
