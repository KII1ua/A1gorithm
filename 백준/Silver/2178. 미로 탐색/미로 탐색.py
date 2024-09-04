#baekjoon 2178
import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().rstrip())) for _ in range(N)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
q = deque()

q.append((0, 0))

while q:
    x, y = q.popleft()

    for k in range(4):
        nx = dx[k] + x
        ny = dy[k] + y

        if nx >= N or ny >= M or nx < 0 or ny < 0 or graph[nx][ny] == 0:
            continue
        if graph[nx][ny] == 1:
            q.append((nx, ny))
            graph[nx][ny] = graph[x][y] + 1

print(graph[N-1][M-1])