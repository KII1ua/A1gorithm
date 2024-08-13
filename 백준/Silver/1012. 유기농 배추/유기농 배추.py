# baekjoon 1072
import sys
from collections import deque
input = sys.stdin.readline


def bfs(a, b):
    q = deque()
    q.append((a, b))
    graph[a][b] = 0         # 방문처리 0으로 만듬

    while q:
        x, y = q.popleft()

        for _ in range(4):
            nx = x + dx[_]          
            ny = y + dy[_]

            if nx < 0 or ny < 0 or nx >= M or ny >= N:
                continue
            if graph[nx][ny] == 1:
                q.append((nx, ny))
                graph[nx][ny] = 0

T = int(input())

dx = [-1, 1, 0 , 0]
dy = [0, 0, -1, 1]

for _ in range(T):
    M, N, K = map(int, input().split())     # 세로, 가로, 배추개수
    graph = [[0] * N for _ in range(M)]
    total = 0

    for a in range(K):
        x, y = map(int ,input().split())    # 세로, 가로
        graph[x][y] = 1

    for i in range(M):
        for j in range(N):
            if graph[i][j] == 1:
                bfs(i, j)
                total += 1
    
    print(total)