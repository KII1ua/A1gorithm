# baekjoon 7576
import sys
from collections import deque
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

M, N, H = map(int, input().split())
graph = [[list(map(int, input().split())) for _ in range(N)] for h in range(H)]
dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, 0, 0, -1, 1]
dz = [0, 0, -1, 1, 0, 0]
res = 0

q = deque()

def bfs():
    global res

    while q:
        x, y, z = q.popleft()
        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]

            if 0 <= nz < H and 0 <= nx < N and 0 <= ny < M and graph[nz][nx][ny] == 0:
                q.append([nx, ny, nz])
                graph[nz][nx][ny] = graph[z][x][y] + 1

for k in range(H):
    for i in range(N):
        for j in range(M):
            if graph[k][i][j] == 1:
                q.append([i, j, k])     # 높이, 행, 열

bfs()

for k in range(H):
    for i in range(N):
        for j in range(M):
            if graph[k][i][j] == 0:
                print(-1)
                sys.exit()
            if graph[k][i][j] > res:
                res = graph[k][i][j]

print(res - 1)