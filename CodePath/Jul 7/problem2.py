class Node:
    def __init__(self, value, next=None):
        self.val = value
        self.next = next

def cycle_length(protein):
    slow = protein
    fast = protein
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            meet = slow
            break
        
    res = []
    res.append(meet.val)
    cur = meet.next
    while cur != meet:
        res.append(cur.val)
        cur = cur.next
    
    return res
    
protein_head = Node('Ala', Node('Gly', Node('Leu', Node('Val'))))
protein_head.next.next.next.next = protein_head.next 

print(cycle_length(protein_head))