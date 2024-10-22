/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        
        auto s = head, f = head;
        while (f)
        {
            s = s->next, f = f->next;
            if (!f) return NULL;
            f = f->next;

            if (s == f)
            {
                auto ptr = head;
                while (ptr != s) ptr = ptr->next, s = s->next;
                return ptr;
            }
        }
        return NULL;
    }
};