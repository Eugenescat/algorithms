import ast
import sys

from collections import deque
def count_routines(n):
    # Write your code here
    # step : 1, spin: 2
    # spin, step, spin
    # bfs
    queue = deque() # (beats used, IS_SPIN)
    queue.append((1, False))
    queue.append((2, True))
    
    cnt = 0
    while queue:
        cur = queue.popleft()
        beats_used = cur[0]
        is_spin = cur[1]
        if beats_used == n:
            cnt += 1
            continue
        if is_spin == True or beats_used == n - 1:
            queue.append((beats_used + 1, False)) # step
        else:
            queue.append((beats_used + 1, False)) # step
            queue.append((beats_used + 2, True)) # spin
    
    return cnt