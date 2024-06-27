# baekjoon 15649
import sys
from collections import deque
input = sys.stdin.readline

N, M, V = list(map(int, input().split()))
graph = [[] * (N + 1) for _ in range(N+1)]
visited = [False] * (N + 1)
visited1 = visited.copy()

for _ in range(M):
    a, b = list(map(int, input().split()))
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()
    
def dfs(graph, v, visited):
    visited[v] = True
    print(v, end = ' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph, start, visited1):
    queue = deque([start])
    visited1[start] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited1[i]:
                queue.append(i)
                visited1[i] = True


dfs(graph, V, visited)
print()
bfs(graph, V, visited1)