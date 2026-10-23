
# Escape to the Safe Haven

'''def can_move_safely(position, grid):
    n, m = len(grid), len(grid[0])
    visited = set()
    # visited = [False] * 
    
    dx, dy = [1, 0, -1, 0], [0, -1, 0, 1]
    def dfs(row, col):
        visited.add((row, col))
        if row == n-1 and col == m-1:
            return True
        
        # up, left, right, down
        res = False
        for d in range(4):
            nr, nc = row + dx[d], col + dy[d]
            if (nr, nc) not in visited:
                if nr >= 0 and nr < n and nc >= 0 and nc < m:
                    if grid[nr][nc] == 1:
                        if dfs(nr, nc):
                            res = True
        
        return res
    
    return dfs(position[0], position[1])

grid = [
    [1, 0, 1, 1, 0], # Row 0
    [1, 1, 1, 1, 0], # Row 1
    [0, 0, 1, 1, 0], # Row 2
    [1, 0, 1, 1, 1]  # Row 3
]

position_1 = (0, 0)
position_2 = (0, 4)
position_3 = (3, 0)

print(can_move_safely(position_1, grid))
print(can_move_safely(position_2, grid))
print(can_move_safely(position_3, grid))'''

'''
# List All Escape Routes

def list_all_escape_routes(grid):
    n, m = len(grid), len(grid[0])
    visited = set()
    
    dx, dy = [1, 0, -1, 0], [0, -1, 0, 1]
    def dfs(row, col):
        visited.add((row, col))
        
        # up, left, right, down
        for d in range(4):
            nr, nc = row + dx[d], col + dy[d]
            if (nr, nc) not in visited:
                if nr >= 0 and nr < n and nc >= 0 and nc < m:
                    if grid[nr][nc] == 1:
                        dfs(nr, nc)
    dfs(n-1, m-1)
    return sorted(list(visited))

grid = [
    [1, 0, 1, 0, 1], # Row 0
    [1, 1, 1, 1, 0], # Row 1
    [0, 0, 1, 0, 0], # Row 2
    [1, 0, 1, 1, 1]  # Row 3
]

print(list_all_escape_routes(grid))'''


# Zombie Spread

from collections import deque

def time_to_infect(grid):
    # bfs
    n, m = len(grid), len(grid[0])
    total = 0
    visited = set()
    q = deque()
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1:
                total += 1
            if grid[i][j] == 2:
                q.append((i, j))
                visited.add((i, j)) # 保持一致性：每次append时update visited
    
    dx, dy = [1, 0, -1, 0], [0, -1, 0, 1]
    time = 0
    while q:
        time += 1
        cnt = len(q)
        while cnt:
            cnt -= 1
            cur = q.popleft()
            row, col = cur[0], cur[1]
            # visited.add((row, col)) # 不建议留到这里才update visited
#            print(row, col)
            
            for d in range(4):
                nr, nc = row + dx[d], col + dy[d]
                if (nr, nc) not in visited:
                    if nr >= 0 and nr < n and nc >= 0 and nc < m:
                        if grid[nr][nc] == 1:
                            total -= 1
                            q.append((nr, nc)) # newly infected in this round
                            visited.add((nr, nc)) # 注意在这里update visited更合适，因为range(4)loop中可能重复访问同一个格子
    
#    print(total)
#    print(visited)
    return -1 if total > 0 else time - 1 # last layer is redundant
        

grid_1 = [
        [2,1,1],
        [1,1,0],
        [0,1,1]]

grid_2 = [
        [2,1,1],
        [0,1,1],
        [1,0,1]]

grid_3 = [[0,2]]

print(time_to_infect(grid_1))
print(time_to_infect(grid_2))
print(time_to_infect(grid_3))