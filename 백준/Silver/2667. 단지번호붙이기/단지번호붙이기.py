# baekjoon 2667
import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
graph = [list(map(int, input().rstrip())) for _ in range(N)]
lst = []
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

q = deque()

def bfs(a, b):
    q.append((a, b))
    graph[a][b] = 0
    global cnt
    cnt += 1

    while q:
        x, y = q.popleft()

        for _ in range(4):
            nx = x + dx[_]
            ny = y + dy[_]

            if 0 <= nx < N and 0 <= ny < N and graph[nx][ny] == 1:
                q.append((nx, ny))
                graph[nx][ny] = 0
                cnt += 1

for i in range(N):
    for j in range(N):
        if graph[i][j] == 1:
            cnt = 0
            bfs(i, j)
            lst.append(cnt)

lst.sort()
print(len(lst))
for i in lst:
    print(i)