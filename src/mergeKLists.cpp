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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;

        while (true)
        {
            int min = 1e4;
            int idx = -1;
            for (int i = 0; i < lists.size(); ++i)
            {
                if (lists[i])
                {
                    if (lists[i]->val < min)
                    {
                        idx = i;
                        min = lists[i]->val;
                    }
                }
            }
            if (idx == -1)
            {
                break;
            }
            cur->next = lists[idx];
            cur = cur->next;
            lists[idx] = lists[idx]->next;
        }
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
    vector<ListNode *> lists;

    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);

    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    Solution s;
    ListNode *merged = s.mergeKLists(lists);
    printList(merged);

    return 0;
}