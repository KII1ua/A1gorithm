# baekjoon 18126
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

N = int(input())
graph = [[] * (N + 1) for _ in range(N + 1)]
visited = [False] * (N + 1)
ans = 0

for i in range(N-1):
    a, b, c = list(map(int, input().split()))
    graph[a].append((b, c))
    graph[b].append((a, c))

def dfs(i, res):
    global ans
    ans = max(ans, res)
    visited[i] = True
    for a, b in graph[i]:
        if not visited[a]:
            dfs(a, res + b)

dfs(1,0)
print(ans)