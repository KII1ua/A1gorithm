# baekjoon 10026
import sys
from collections import deque
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

N = int(input())
graph = [list(input().rstrip()) for _ in range(N)]
visited = [[False] * N for _ in range(N)]
cnt = 0
res = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(a, b, color):
    q = deque()
    q.append([a, b])
    visited[a][b] = True

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < N and graph[nx][ny] == color and not visited[nx][ny]:
                q.append([nx, ny])
                visited[nx][ny] = True

def bfs1(a, b, color):
    q = deque()
    q.append([a, b])
    visited[a][b] = True

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny] and graph[nx][ny] == color:
                q.append([nx, ny])
                visited[nx][ny] = True

for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            bfs(i, j, graph[i][j])
            cnt += 1

print(cnt, end = ' ')

visited = [[False] * N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if graph[i][j] == 'G':
            graph[i][j] = 'R'

for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            bfs1(i, j, graph[i][j])
            res += 1

print(res, end = ' ')