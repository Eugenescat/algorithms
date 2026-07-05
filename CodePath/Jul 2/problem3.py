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

def delete_dupes(head):
    if not head.next:
        return head
    
    dummy = Node(0)
    dummy.next = head
    
    cur = head
    prev = dummy
    
    # 1 2 3 3 4 5
    while cur.next:
        if cur.value == cur.next.value:
            while cur.value == cur.next.value:
                cur = cur.next
            prev.next = cur.next
            cur = cur.next
        else:
            prev = prev.next
            cur = cur.next
    
    return dummy.next

# linked list
# remove all the duplicated nodes
# previous node ~ cur node 
# if val1 == val2:
# end node of these duplicated nodes
# link prev node with 

head = Node(1, Node(2, Node(3, Node(3, Node(4, Node(5))))))

# Linked List: 1 -> 2 -> 3 -> 3 -> 4 -> 5
print_linked_list(delete_dupes(head))