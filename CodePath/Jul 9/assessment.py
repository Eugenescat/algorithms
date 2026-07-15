# 头插法
def reverse_between(head, left, right):
    # Write your code here
    dummy = ListNode(0)
    dummy.next = head
    prev, cur = dummy, dummy
    
    for i in range(left):
        prev = cur
        cur = cur.next
    
    # front insertion
    for i in range(right - left):
        target = cur.next
        cur.next = target.next
        target.next = prev.next
        prev.next = target

    return dummy.next