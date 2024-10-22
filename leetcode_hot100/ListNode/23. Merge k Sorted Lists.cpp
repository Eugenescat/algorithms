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

    // 为了制造一个小根堆，我们需要重载比较函数（注意是operator()，跟为了sort而写的operator<不一样）
    // 默认的priority_queue是大根堆，重载成小根堆需要加上greater比较器，所以这里是a->val ">" b->val
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 按照每个链表的头节点排序 小根堆
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        auto dummy = new ListNode(-1), tail = dummy;
        // 把每条链表加入堆
        for (auto l : lists) if (l) heap.push(l);

        while(heap.size())
        {   
            // 每次拿出头节点最小的一根链表
            auto t = heap.top();
            heap.pop();
            tail = tail->next = t;

            if (t->next) heap.push(t->next); // 如果这根链表后续还有节点，就放回堆中
        }

        return dummy->next;
    }
};