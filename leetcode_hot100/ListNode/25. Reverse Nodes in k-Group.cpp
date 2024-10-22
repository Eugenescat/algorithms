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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        for (auto p = dummy;;)
        {
            // 判断是否存在一组完整的k
            auto q = p;
            for (int i = 0; i < k && q; i++) q = q->next;
            if (!q) break;

            // 开始翻转
            auto a = p->next, b = a->next;
            for (int i = 0; i < k - 1; i++) // 需要翻转k-1次
            {               
                auto c = b->next;
                b->next = a;
                a = b, b = c;
            }
            auto d = p->next;
            p->next = a;
            d->next = b;

            p = d; // 这一组k的结尾，是下一组k的dummy node
        }
        return dummy->next;
    }
};