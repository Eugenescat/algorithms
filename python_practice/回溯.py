n = 4
k = 2
# 从 [1, 2, 3, 4] 中选 2 个
# 返回：[[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]

n = 3
k = 1
# 返回：[[1], [2], [3]]

# 假设你有一个 Agent 系统，需要从 n 个候选工具中选择 k 个工具组合使用。给定 n 和 k，返回所有可能的组合（不考虑顺序）。

def combination(n, k):

    res = []
    path = list()

    def dfs(idx: int, path: list[int]):
        if len(path) == k:
            res.append(path[:])
            return
        elif n - idx < k - len(path):
            return
        
        else:
            path.append(idx)
            dfs(idx + 1, path)
            path.pop()
            dfs(idx + 1, path)
    
    dfs(1, path)
    return res
    
    