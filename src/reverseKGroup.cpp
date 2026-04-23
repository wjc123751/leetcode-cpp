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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *h = head;
        int hsize = 0;
        while (h)
        {
            hsize++;
            h = h->next;
        }
        int hcnt = hsize / k;

        ListNode dummy(0);
        dummy.next = head;

        int left = 1;
        int right = k;

        while (hcnt--)
        {

            ListNode *preLeft = &dummy;
            for (int i = 1; i < left; ++i)
            {
                preLeft = preLeft->next;
            }

            ListNode *prev = &dummy;
            for (int i = 0; i <= right; ++i)
            {
                prev = prev->next;
            }
            ListNode *cur = preLeft->next;
            int cnt = right - left + 1;
            while (cnt--)
            {
                ListNode *next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            preLeft->next = prev;

            left += k;
            right += k;
        }

        return dummy.next;
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
    int k = 2;
    ListNode *reversed = s.reverseKGroup(head, k);

    printList(reversed);

    return 0;
}
