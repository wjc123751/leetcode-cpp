#include <iostream>
#include <vector>

using namespace std;

// https://pythontutor.com/visualize.html#mode=display

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // left = 1 or right = 1
        ListNode dummy(0);
        dummy.next = head;

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
        while(cnt--){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        preLeft->next = prev;

        return dummy.next;
    }
};

void printLint(ListNode *head)
{
    ListNode *p = head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    int left = 2;
    int right = 4;
    ListNode *newhead = s.reverseBetween(head, left, right);
    printLint(newhead);

    return 0;
}
