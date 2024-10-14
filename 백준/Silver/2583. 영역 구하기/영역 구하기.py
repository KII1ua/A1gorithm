# baekjoon 2468
import sys
from collections import deque
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

M, N, K = map(int, input().split())
graph = [[0] * (N) for _ in range(M)]
visited = [[False] * N for _ in range(M)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
arr = []
cnt = 0

def bfs(i, j):
    q = deque()
    q.append([i, j])
    visited[i][j] = True
    res = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < M and 0 <= ny < N and not visited[nx][ny] and graph[nx][ny] == 0:
                q.append([nx, ny])
                visited[nx][ny] = True
                res += 1

    arr.append(res)

for i in range(K):
    x, y, nx, ny = map(int, input().split())
    for i in range(y, ny):
        for j in range(x, nx):
            graph[i][j] += 1

for i in range(M):
    for j in range(N):
        if graph[i][j] == 0 and not visited[i][j]:
            bfs(i, j)
            cnt += 1

arr.sort()
print(cnt)
print(*arr)