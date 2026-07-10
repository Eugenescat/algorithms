class Node:
	def __init__(self, value, next=None):
		self.value = value
		self.next = next

# For testing
def print_linked_list(head):
    current = head
    while current:
        print(current.value, end=" -> " if current.next else "")
        current = current.next
    print()

# two linkedlist, ath, bth
# head of merged list
# plan: 
# 1. iterate through list1, find the node at a-1
# 2. link list2's head with a-1
# 3. iterate through list2, find the tail; iterate through list1, find the node at b+1
# 4. link the list2's tail to list1 at b+1
# 5. return head of list1

# edge cases:
# list1 is none, return None
# list2 is none, just remove [a-b] and return list1
# if a == b, not edge case
# if a == 0, need dummy node
# if b > length of list1, consider this

# time complexity: O(n+m)
# space : O(1)

def merge_playlists(playlist1, playlist2, a, b):
    if playlist1 == None:
        return None
    
    dummy = Node(0)
    dummy.next = playlist1
    cur = playlist1
    
    # a = 2, b = 3
    # dummy, 0, [1], 2, 3, [4], 5, None
    #               0, 1, 2, 3
    for _ in range(a - 1):
        if cur == None:
            return playlist1
        cur = cur.next # 1
    
    temp = cur # 1
    
    # find b + 1 node at playlist1
    for _ in range(b - a + 2): # 4
        if cur == None:
            break
        cur = cur.next
        
    temp.next = playlist2 
    
    # find the tail of playlist2
    cur2 = playlist2
    while cur2.next: # 3
        cur2 = cur2.next
    # link tail of list2 , with b + 1 node at playlist1
    cur2.next = cur
    
    return dummy.next
    

playlist1 = Node(('Flea', 'St. Vincent'),
                Node(('Juice', 'Lizzo'), 
                    Node(('Tenderness', 'Jay Som'),
                        Node(('Ego Death', 'The Internet'),
                            Node(('Empty', 'Kevin Abstract'))))))

playlist2 = Node(('Dreams', 'Solange'), Node(('First', 'Gallant')))

print_linked_list(merge_playlists(playlist1, playlist2, 2, 6))
# print_linked_list(merge_playlists(playlist1, playlist2, 2, 3))