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
    // 思路：两个指针从两个头开始走，各自走完自己的去走别人的，当同时到达某一点时就是答案
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p = headA, q = headB;
        while (pq != q)
        {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }   
};