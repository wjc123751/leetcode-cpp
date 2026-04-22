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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 双指针
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA != pB)
        {
            if (pA == nullptr)
                pA = headB;
            else
                pA = pA->next;

            if (pB == nullptr)
                pB = headA;
            else
                pB = pB->next;
        }
        return pA;
    }
};

int main()
{

    ListNode *head8 = new ListNode(8);
    ListNode *head4 = new ListNode(4);
    ListNode *head5 = new ListNode(5);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = head8;
    headA->next->next->next = head4;
    headA->next->next->next->next = head5;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = head8;
    headB->next->next->next->next = head4;
    headB->next->next->next->next->next = head5;

    Solution s;
    ListNode *insec = s.getIntersectionNode(headA, headB);
    cout << insec->val;

    return 0;
}
