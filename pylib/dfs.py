from collections import deque

n = 10
g = [[] for _ in range(n)]
seen = [False] * n

# stackでDFS
# pypyはstackでないと厳しい
deq = deque()
deq.append(0)
while deq:
    v = deq.pop()
    seen[v] = True
    for nv in g[v]:
        if seen[nv]:
            continue
        deq.append(nv)

# 再帰でDFS
def dfs(v):
    seen[v] = True
    for nv in g[v]:
        if seen[nv]:
            continue
        dfs(nv)
dfs(0)
