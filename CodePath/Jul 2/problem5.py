
    
class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

# For testing
def print_linked_list(head):
    current = head
    while current:
        print(current.value, end=" -> " if current.next else "\n")
        current = current.next

def remove_nth_from_end(head, n):
    dummy = Node(0)
    dummy.next = head
    
    slow = dummy
    fast = dummy
    
    while n:
        n -= 1
        fast = fast.next
        
    while fast.next:
        slow = slow.next
        fast = fast.next
        
    slow.next = slow.next.next
    
    return dummy.next
    
# head of list, int n
# head of modified list

head1 = Node("apple", Node("cherry", Node("orange", Node("peach", Node("pear")))))
head2 = Node("Rainbow Trout", Node("Ray"))
head3 = Node("Rainbow Stag")


print_linked_list(remove_nth_from_end(head1, 2))
print_linked_list(remove_nth_from_end(head2, 1))
print_linked_list(remove_nth_from_end(head3, 1))