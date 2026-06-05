class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def max_sum(root: TreeNode):
    res = float('-inf')
    
    def dfs(node: TreeNode):
        nonlocal res
        if node == None:
            return 0
        
        left = dfs(node.left)
        right = dfs(node.right)
        res = max(res, left + right + node.val)
        return max(left, right, 0) + node.val
    
    dfs(root)
    return res