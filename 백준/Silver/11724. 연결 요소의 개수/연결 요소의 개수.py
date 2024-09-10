# baekjoon 11724
import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [False] * (N + 1)
result = 0

def bfs(start, graph, visited):
    q = deque()
    q.append(start)

    while q:
        x = q.popleft()

        for j in graph[x]:
            if not visited[j]:
                q.append(j)
                visited[j] = True

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, N+1):
    if not visited[i]:
        bfs(i, graph, visited)
        result += 1

print(result)