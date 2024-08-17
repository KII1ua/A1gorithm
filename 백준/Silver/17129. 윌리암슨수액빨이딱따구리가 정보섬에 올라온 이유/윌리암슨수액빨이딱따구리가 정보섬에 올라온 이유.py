# baekjoon 17129
import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())        # 행, 열
graph = [list(map(int, list(input().rstrip()))) for _ in range(N)]

q = deque()

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

for i in range(N):  
    for j in range(M):  
        if graph[i][j] == 2:
            q.append((i, j, 0))
            graph[i][j] = 1     # 방문표시

while q:
    x, y, z = q.popleft()
    for a in range(4):
        nx = x + dx[a]
        ny = y + dy[a]
        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            continue
        if graph[nx][ny] == 1:
            continue
        if graph[nx][ny] in [3, 4, 5]:
            print("TAK")
            print(z + 1)
            sys.exit()
        q.append((nx, ny, z + 1))
        graph[nx][ny] = 1

print("NIE")