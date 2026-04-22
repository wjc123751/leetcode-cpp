#include <iostream>
#include <vector>

using namespace std;

// https://pythontutor.com/visualize.html#mode=display

// 有环：快慢指针一定会在环内相遇

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

// Floyd 快慢指针法
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
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
    bool res = s.hasCycle(head);
    cout << res;

    return 0;
}
