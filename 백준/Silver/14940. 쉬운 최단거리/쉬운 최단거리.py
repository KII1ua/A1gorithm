#baekjoon 14940
import sys  
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

q = deque()

for i in range(N):
    for j in range(M):
        if graph[i][j] == 2:
            q.append((i, j))
            graph[i][j] = 0
            visited[i][j] = True

while q:
    x, y = q.popleft()

    for i in range(4):      # 아래, 위, 왼, 오
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < N and 0 <= ny < M and graph[nx][ny] == 1 and not visited[nx][ny]:
            q.append((nx, ny))
            visited[nx][ny] = True
            graph[nx][ny] = graph[x][y] + 1

for i in range(N):
    for j in range(M):
        if graph[i][j] == 1 and not visited[i][j]:
            print(-1, end= ' ')
        else:
            print(graph[i][j], end = ' ')
    print()