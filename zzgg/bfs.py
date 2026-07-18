#!/bin/python
# -*- coding: utf8 -*-
import sys
import os
import re
from collections import deque

#请完成下面这个函数，实现题目要求的功能
#当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
#******************************开始写代码******************************


def  shortestDistance(grid):
    n = len(grid)
    m = len(grid[0])
    dq = deque()
    dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
    dist = [[-1] * m for _ in range(n)] # 该格子到所有楼房的最短路之和
    buildings = [[0] * m for _ in range(n)] # 该格子能通向的楼房数
    total = 0
    for i in range(n):
        for j in range(m):
            # 针对每个楼房，对grid做多源最短路
            if grid[i][j] == 1:
                visited = [[False] * m for _ in range(n)]
                dq.append((i, j, 0))
                visited[i][j] = True
                total += 1 # 顺便统计全局楼房总数
                while dq:
                    cur = dq.popleft()
                    x, y = cur[0], cur[1]
                    cur_dist = cur[2]
                    for dir in range(4):
                        nx = x + dx[dir]
                        ny = y + dy[dir]
                        if nx >= 0 and nx < n and ny >= 0 and ny < m and not visited[nx][ny]:
                            if grid[nx][ny] != 2 and grid[nx][ny] != 1:
                                visited[nx][ny] = True
                                if dist[nx][ny] == -1:
                                    dist[nx][ny] = cur_dist + 1
                                else:
                                    dist[nx][ny] += cur_dist + 1
                                buildings[nx][ny] += 1
                                dq.append((nx, ny, cur_dist + 1))
    
    shortest = float('inf')
    for i in range(n):
        for j in range(m):
            if  dist[i][j] != -1 and dist[i][j] < shortest and buildings[i][j] == total:
                shortest = dist[i][j]
    return -1 if shortest == float('inf') else shortest
        

#******************************结束写代码******************************


_grid_rows = 0
_grid_cols = 0
_grid_rows = int(input())
_grid_cols = int(input())

_grid = []
for _grid_i in range(_grid_rows):
    _grid_temp = map(int,re.split(r'\s+', input().strip()))
    _grid.append(list(_grid_temp))

  
res = shortestDistance(_grid)

print(str(res) + "\n")