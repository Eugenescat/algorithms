def  isPalindrome(head):
    slow, fast = head, head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    # first half并没有截断，还是往后连着的
    prev = None
    cur = slow
    while cur:
        temp = cur.next
        cur.next = prev
        prev = cur
        cur = temp
    
    second = prev
    first = head
    # 因为second half只有一半长度 所以second half会先到None
    while second:
        if first.val != second.val:
            return False
        first = first.next
        second = second.next
    
    return True