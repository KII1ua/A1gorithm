# baekjoon 1926
import sys
from collections import deque
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
arr = [0]
cnt = 0

def bfs(a, b):
    q = deque()
    q.append([a, b])
    graph[a][b] = 0
    tmp = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<= nx < N and 0 <= ny < M and graph[nx][ny] == 1:
                graph[nx][ny] = 0
                q.append([nx, ny])
                tmp += 1
    
    arr.append(tmp)


for i in range(N):
    for j in range(M):
        if graph[i][j] == 1:
            bfs(i,j)
            cnt += 1

print(cnt)
print(max(arr))