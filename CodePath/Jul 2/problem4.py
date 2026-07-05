class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def has_cycle(head):
    
    dummy = Node(0)
    dummy.next = head
    slow = dummy
    fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            return True
    
    return False

# input: head of linkedin list
# output: true or false

peach = Node("Peach", Node("Luigi", Node("Mario", Node("Toad"))))

# Toad.next = Luigi
peach.next.next.next = peach.next

print(has_cycle(peach))