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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *h = head;
        int nsize = 0;
        while (h)
        {
            nsize++;
            h = h->next;
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        cur->next = head;
        for (int i = 0; i < (nsize - n); ++i)
        {
            cur = cur->next;
        }

        ListNode* toDelete = cur->next;
        cur->next = toDelete->next;
        delete toDelete;

        return dummy->next;
    }
};

void printList(ListNode *list)
{
    ListNode *p = list;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    int n = 2;
    ListNode *removed = s.removeNthFromEnd(head, n);

    printList(removed);

    return 0;
}
