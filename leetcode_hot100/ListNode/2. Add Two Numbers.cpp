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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1), cur = dummy;
        auto a = l1, b = l2;
        int t = 0; // 表示进位
        while (a || b || t)
        {
            if (a) t += a->val, a = a->next;
            if (b) t += b->val, b = b->next;
            cur = cur->next = new ListNode(t % 10);
            t /= 10;
        }
        return dummy->next;
    }
};