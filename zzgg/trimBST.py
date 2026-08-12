def  trimBST(root, L, R):
    
    # 【一维搜索】找到并返回第一个合法节点
    def findFirstGood(node):
        if not node:
            return None
        if node.val < L:
            return findFirstGood(node.right)
        elif node.val > R:
            return findFirstGood(node.left)
        else:
            return node
    
    #  root = findFirstGood(root)
    if not root:
        return None
    
    # 【分支决策修剪】假设传进来的 node 已经合法，它的任务是：检查 node 的两个直接子节点是否合法，如果不合法就"嫁接"
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
    
    #【合二为一】最简洁的写法
    def trim(node):
        if not node:
            return None
        if node.val < L:
            return trim(node.right)
        if node.val > R:
            return trim(node.left)
        node.left = trim(node.left)
        node.right = trim(node.right)
        return node
    
    # helper(root)
    # return root
    return trim(root)