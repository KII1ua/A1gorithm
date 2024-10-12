#baekjoon 2636
import sys
from collections import deque
input = sys.stdin.readline

def bfs():
    q = deque()
    visited = [[False] * M for _ in range(N)]
    cheeze = deque()
    q.append([0, 0])
    tmp = 0
    visited[0][0] = True

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<= nx < N and 0<= ny < M and not visited[nx][ny]:
                if graph[nx][ny] == 0:
                    q.append([nx, ny])
                    visited[nx][ny] = True
                elif graph[nx][ny] == 1:
                    cheeze.append([nx, ny])
                    visited[nx][ny] = True
    for a, b in cheeze:
        graph[a][b] = 0
        tmp += 1
    return tmp

N, M = map(int, input().split())
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
graph = []
cheeze_cnt = 0
time = 0

for _ in range(N):
    a = list(map(int, input().split()))
    graph.append(a)
    cheeze_cnt += a.count(1)

while True:
    cnt = bfs()
    cheeze_cnt -= cnt

    if cheeze_cnt == 0:
        print(time+1)
        print(cnt)
        break

    time += 1