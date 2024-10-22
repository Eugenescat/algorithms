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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto dummy = new ListNode(-1), tail = dummy;
        auto a = list1;
        auto b = list2;
        while (a && b)
        {
            if (a->val < b->val)
            {
                tail->next = a; 
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        if (a) tail->next = a;
        if (b) tail->next = b;
        return dummy->next;
    }
};