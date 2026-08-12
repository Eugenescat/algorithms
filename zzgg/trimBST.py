def  trimBST(root, L, R):
    
    def findFirstGood(node):
        if not node:
            return None
        if node.val < L:
            return findFirstGood(node.right)
        elif node.val > R:
            return findFirstGood(node.left)
        else:
            return node
    
    root = findFirstGood(root)
    if not root:
        return None
    
    def helper(node):
        if not node:
            return
        
        left = node.left
        if left:
            if left.val < L:
                node.left = findFirstGood(left.right)
            elif left.val > R:
                node.left = findFirstGood(left.left)
            helper(node.left)
        
        right = node.right
        if right:
            if right.val < L:
                node.right = findFirstGood(right.right)
            elif right.val > R:
                node.right = findFirstGood(right.left)
            helper(node.right)
    
    helper(root)
    return root