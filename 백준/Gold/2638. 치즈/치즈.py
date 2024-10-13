#baekjoon 2636
import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
time = 0

def bfs():
    q = deque()
    q.append([0, 0])

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if visited[nx][ny] == 0 and graph[nx][ny] == 0:
                q.append([nx, ny])
                visited[nx][ny] = 1
            elif graph[nx][ny] == 1:
                visited[nx][ny] += 1



while True:
    tmp = False
    visited = [[0] * M for _ in range(N)]

    bfs()

    for i in range(N):
        for j in range(M):
            if visited[i][j] >= 2:
                graph[i][j] = 0
                tmp = True

    if tmp == False:
        print(time)
        sys.exit()
    time += 1