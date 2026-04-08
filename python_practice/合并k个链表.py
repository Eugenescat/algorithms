
import heapq

class Node:
    def __init__(self, val):
        self.val = val
        self.next: Node | None = None
    def __lt__(self, other):
        return self.val < other.val

def solution(input: list[Node]) -> Node:
    heap = list()
    for node in input:
        if (node):
            heapq.heappush(heap, node)
    
    head = Node(0)
    cur = head
    while heap:
        n = heapq.heappop(heap)
        cur.next = n
        cur = cur.next
        if (n.next):
            heapq.heappush(heap, n.next)
    
    return head.next
    
    