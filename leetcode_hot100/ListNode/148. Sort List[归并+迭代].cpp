public:
    // 归并+迭代
    ListNode* sortList(ListNode* head) {
        // 计算链表长度
        int n = 0;
        for (auto p = head; p; p = p->next) n ++;

        auto dummy = new ListNode(-1);  // 创建一个虚拟头节点，方便处理边界情况
        dummy->next = head;  // 将虚拟头节点指向原链表的头节点

        // 外层循环，i表示每次合并的子链表长度，每次翻倍
        for (int i = 1; i < n; i *= 2) {
            auto cur = dummy;  // cur用于跟踪当前正在处理的链表的最后一个节点
            
            // 内层循环，j表示每次处理的起始位置，每次处理两个长度为i的子链表
            for (int j = 1; j + i <= n; j += i * 2) {
                auto p = cur->next, q = p;
                for (int k = 0; k < i; k ++ ) q = q->next;  // 让q指针指向第二个子链表的起始位置
                
                int x = 0, y = 0;  // x和y分别记录当前已经从两个子链表中取出的节点数，用于判断是否已经取够i个节点

                // 合并两个已排序的子链表，直到其中一个链表为空或取够i个节点
                while (x < i && y < i && p && q) {
                    if (p->val <= q->val) {
                        cur = cur->next = p;
                        p = p->next;
                        x++;
                    } else {
                        cur = cur->next = q;
                        q = q->next;
                        y++;
                    }
                }

                // 如果第一个子链表还有剩余节点，继续添加到合并后的链表中
                while (x < i && p) {
                    cur = cur->next = p;
                    p = p->next;
                    x++;
                }

                // 如果第二个子链表还有剩余节点，继续添加到合并后的链表中
                while (y < i && q) {
                    cur = cur->next = q;
                    q = q->next;
                    y++;
                }

                // 将当前已合并的链表的末尾正确地连接到后面的部分
                cur->next = q;
            }
        }
        
        return dummy->next;  // 返回重新排序后的链表的头节点
    }
