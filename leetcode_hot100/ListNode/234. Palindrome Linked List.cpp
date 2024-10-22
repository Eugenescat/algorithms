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
    bool isPalindrome(ListNode* head) {
        // 计算节点数
        int n = 0;
        for (auto p = head; p; p = p->next) n++;
        if (n <= 1) return true;
        
        // 找到中间
        int half = n / 2;
        auto a = head;
        for (int i = 0; i < n - half; i ++) a = a->next; // 右半边头

        // 翻转后半段
        auto b = a->next;
        while(b)
        {
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }

        // 从两边向中间比较
        auto p = head, q = a;
        bool isPali = true;
        for (int i = 0; i < half; i++)
        {
            if (p->val != q->val){
                isPali = false;
                break;
            }
            p = p->next;
            q = q->next;
        }

        auto tail = a;
        b = a->next;
        // 将链表恢复原状
        for (int i = 0; i < half - 1; i++) // 这里是half-1，因为half-1个节点已经翻转了
        {
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }

        tail->next = nullptr;
        return isPali;
    }
};