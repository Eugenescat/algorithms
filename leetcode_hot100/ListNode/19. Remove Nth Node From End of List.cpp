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
    // 只要头节点可能会变，就建一个虚拟头节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        int k = 0;
        for (auto p = head; p; p = p->next) k ++;

        auto p = dummy;
        for (int i = 0; i < k - n; i ++) p = p->next;
        p->next = p->next->next;

        return dummy->next;
    }
};