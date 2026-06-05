import sys

def solution(s):
    n = len(s)
    s = list(s)

    def mirror(c):
        return chr(ord('a') + ord('z') - ord(c))
    
    i = 0
    while i < n and mirror(s[i]) >= s[i]:
        i += 1
    
    if i == n:
        return "".join(s)
    
    while i < n and mirror(s[i]) < s[i]:
        s[i] = mirror(s[i])
        i += 1
    
    return "".join(s)


input = sys.stdin.readline
N = int(input().strip())
for _ in range(N):
    s = input().strip()
    print(solution(s))