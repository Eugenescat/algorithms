class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        cells = deque()
        safeness = [[-1] * n for _ in range(n)] # 多源最短路，记录每个cell的safeness factor
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    safeness[i][j] = 0
                    cells.append((i, j))

        while cells:
            cell = cells.popleft()
            x = cell[0]
            y = cell[1]
            for dx, dy in directions:
                nx = x + dx
                ny = y + dy
                if nx >= 0 and nx < n and ny >= 0 and ny < n:
                    if safeness[nx][ny] == -1:
                        safeness[nx][ny] = safeness[x][y] + 1
                        cells.append((nx, ny))
        
        best = [[-1] * n for _ in range(n)] # 记录从[0,0]到达每个cell的路径的最大safeness factor
        best[0][0] = safeness[0][0]
        hp = []
        heapq.heappush(hp, (best[0][0], 0, 0)) # (safeness, x, y)
        while hp:
            cur = heapq.heappop(hp) # 取出so far路径上factor最大的节点
            factor, x, y = - cur[0], cur[1], cur[2]
            for dx, dy in directions:
                nx = x + dx
                ny = y + dy
                if nx >= 0 and nx < n and ny >= 0 and ny < n:
                    new_factor = min(best[x][y], safeness[nx][ny])
                    if best[nx][ny] == -1 or new_factor > best[nx][ny]:
                        best[nx][ny] = new_factor
                        heapq.heappush(hp, (- new_factor, nx, ny))
            
        return best[n - 1][n - 1]


                
        