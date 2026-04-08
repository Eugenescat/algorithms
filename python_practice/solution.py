# 多叉树 n个节点 n-1条边 寻找1节点最远的距离
# n = 4     
# 1-2
# 2-3,4

import deque from collections

Class Node(self, value, size):
    self.val = value
    self.children = Node[size]

def bfs(self, root: Node):
    
    q = deque()
    
    level = 0
    q.append(root)
    
    while len(q):
        s = len(q)
        # 把当前层的所有节点加入队列
        while (s):
            cur = q.pop()
            for i in range(len(cur.children)):
                q.append(cur.children[i])
            s -= 1
        # 进入下一层
        level += 1
    
    return level
        
        
            