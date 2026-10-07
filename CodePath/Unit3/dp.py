import ast
import sys

from collections import deque
def count_routines(n):
    dp = [0, 0] * (n + 1)
    dp[0] = [1, 1] # step, spin
    dp[1] = [1, 0]
    for i in range(2, n + 1):
        dp[i] = [dp[i - 1][0] + dp[i - 1][1], dp[i - 2][0]]
    return dp[n][0] + dp[n][1]


print(count_routines(4)) # 1, 1, 1, 1; 1, 2, 1; 1,1,2; ; 2, 1,1 => 4