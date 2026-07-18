from collections import deque

# dfs做法: O(2n)
def isCousins(root, x, y):
    if not root:
        return False
    
    # dfs记录每个节点的parent node和depth
    def dfs(node, parent, depth, target):
        if node == None:
            return None
        if node.val == target:
            return (depth, parent)
        return dfs(node.left, node, depth + 1, target) or dfs(node.right, node, depth + 1, target)
    
    x_info = dfs(root, None, 0, x)
    y_info = dfs(root, None, 0, y)
    return x_info[0] == y_info[0] and x_info[1] != y_info[1]

# bfs做法：O(n)
def isCousins(root, x, y):
    if not root:
        return False
    
    x_depth, x_parent = None, None
    y_depth, y_parent = None, None
    
    queue = deque()
    queue.append((root, None, 0))
    while queue:
        node, parent, depth = queue.popleft()
        if node.val == x:
            x_depth = depth
            x_parent = parent
        elif node.val == y:
            y_depth = depth
            y_parent = parent
        
        if x_depth is not None and y_depth is not None:
            break
        
        if node.left: queue.append((node.left, node, depth + 1))
        if node.right: queue.append((node.right, node, depth + 1))
    
    return x_depth == y_depth and x_parent != y_parent