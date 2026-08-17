import sys
import os
import re

def  graphColoring(graph, m):
    n = len(graph)
    colored = [-1] * n
    
    def is_valid(v, color):
        for neibor in range(len(graph[v])):
            if not graph[v][neibor]:
                continue # not connected
            if colored[neibor] != -1:
                if colored[neibor] != color:
                    continue # colored but no conflict
                if colored[neibor] == color:
                    return False # v cannot be colored to this
        return True
        
    def dfs(v):
        if v == n:
            return True
        for color in range(m):
            if is_valid(v, color):
                colored[v] = color
                if dfs(v + 1):
                    return True
                colored[v] = -1
        return False
    
    return dfs(0)
                    