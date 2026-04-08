"""
LRU Cache 实现
核心思路：dict + 双向链表，get/put 均 O(1)
"""
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None
    
class LRUCache:
    def __init__(self, capacity: int):
        self.map = dict() # 保存所有已经存在的值
        self.head = Node(None, None)
        self.tail = Node(None, None)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.capacity = capacity
    
    def _remove(self, node: Node):
        node.prev.next = node.next
        node.next.prev = node.prev
    
    def _add_to_head(self, node: Node):
        temp = self.head.next
        self.head.next = node
        node.prev = self.head
        
        temp.prev = node
        node.next = temp
    
    def get(self, key):
        if key not in self.map:
            return None
        node = self.map[key]
        self._remove(node)
        self._add_to_head(node)
        return node.value
        
    def put(self, key, val):
        if key in self.map:
            self.map[key].value = val
            self._remove(self.map[key])
            self._add_to_head(self.map[key])
        else:
            node = Node(key, val)
            self.map[key] = node
            self._add_to_head(node)
            if len(self.map) > self.capacity:
                self._remove(self.tail.prev)
                self.map.pop(key)
            
            
    
        
        