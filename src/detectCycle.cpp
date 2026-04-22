#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 把 slow 移回链表头 head
// fast 留在相遇点不动
// 之后两个指针每次都只走 1 步
// 两个指针再次相遇的节点，就是环的入口节点

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        bool hasCycle = false;
        ListNode *low = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            low = low->next;
            fast = fast->next->next;
            if (low == fast)
            {
                hasCycle = true;
                break;
            }
        }
        if (hasCycle == true)
        {
            low = head;
            while (low != fast)
            {
                low = low->next;
                fast = fast->next;
            }
            return fast;
        }
        else
        {
            return NULL;
        }
    }
};

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    Solution s;
    ListNode *res = s.detectCycle(head);
    cout << res->val;

    return 0;
}
