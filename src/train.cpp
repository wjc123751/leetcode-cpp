#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <unordered_map>

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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                cur->next = new ListNode(list1->val);
                list1 = list1->next;
                cur = cur->next;
            }
            else{
                cur->next = new ListNode(list2->val);
                list2 = list2->next;
                cur = cur->next;
            }
        }
        while(list1 != nullptr){
            cur->next = new ListNode(list1->val);
            list1 = list1->next;
            cur = cur->next;
        }
        while(list2 != nullptr){
            cur->next = new ListNode(list2->val);
            list2 = list2->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    s.mergeTwoLists(list1, list2);

    return 0;
}