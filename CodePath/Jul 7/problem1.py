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

def edit_dna_sequence(dna_strand, m, n):
    dummy  = Node(0)
    dummy.next = dna_strand
    
    # dummy, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
    # m = 2, n = 3
    
    cur = dna_strand
    while cur:
        keep = m - 1
        while cur and keep:
            cur = cur.next
            keep -= 1
        
        if cur == None:
            return dummy.next
        
        prev = cur
        
        remove = n + 1
        while cur and remove:
            cur = cur.next
            remove -= 1
        
        if cur == None:
            prev.next = None
        else:
            prev.next = cur
    
    return dummy.next
    

dna_strand = Node(1, Node(2, Node(3, Node(4, Node(5, Node(6, Node(7, Node(8, Node(9, Node(10, Node(11, Node(12, Node(13)))))))))))))

print_linked_list(edit_dna_sequence(dna_strand, 2, 3))