from collections import defaultdict, deque

n = 4
dependencies = [[1, 0], [2, 0], [3, 1], [3, 2]]
# 任务 1必须在任务0之前完成

adj_list = [[] for _ in range(n)]
pre_num = [0] * n
for a, b in dependencies:
    adj_list[a].append(b) # a是哪些节点的前置节点
    pre_num[b] += 1 # b一共有多少个前置节点
    
q = deque()

for k in range(n):
    if pre_num[k] == 0:
        q.append(k)

processed = 0
while q:
    cur = q.popleft()
    processed += 1
    for node in adj_list[cur]: # 遍历所有cur是哪些节点的前置节点
        pre_num[node] -= 1
        if pre_num[node] == 0:
            q.append(node)

print(processed == n)
