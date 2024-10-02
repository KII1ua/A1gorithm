# baekjoon 7576
import sys
from collections import deque
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

M, N = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
q = deque()
visited = False
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
res = 0

def bfs():
    global res

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < M and graph[nx][ny] == 0:
                q.append([nx, ny])
                graph[nx][ny] = graph[x][y] + 1
                res = graph[x][y]

for i in range(N):
    for j in range(M):
        if graph[i][j] == 1:
            q.append([i, j])
        
bfs()
for i in range(N):
    for j in range(M):
        if graph[i][j] == 0:
            print(-1)
            sys.exit()

print(res)