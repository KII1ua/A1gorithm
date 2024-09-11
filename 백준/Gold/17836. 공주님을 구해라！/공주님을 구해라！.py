# baekjoon 17836
import sys
from collections import deque
input = sys.stdin.readline

N, M, T = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y, z):      # 검을 먼저 찾고 공주를 찾는 경우
    visited = [[False] * (M) for _ in range(N)]
    global T
    q = deque()
    q.append((x, y, z))

    while q:
        x, y, z = q.popleft()

        if graph[x][y] == 2:    # N-1, M-1 공주 위치
            return z + (N + M - x - y - 2)

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny] and graph[nx][ny] != 1:
                q.append((nx, ny, z+1))
                visited[nx][ny] = True
    return T + 1

def prince(x, y, z):     # 바로 공주를 찾는 경우
    visited = [[False] * M for _ in range(N)]
    q = deque()
    global T
    q.append((x, y, z))
    visited[x][y] = True

    while q:
        x, y, z = q.popleft()

        if x == N-1 and y == M-1:
            return z

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny] and graph[nx][ny] != 1:
                q.append((nx, ny, z+1))
                visited[nx][ny] = True
    return T + 1

sword = bfs(0, 0, 0)
firstprince = prince(0, 0, 0)

min_ = min(sword, firstprince)

if min_ <= T:
    print(min_)
else:
    print("Fail")


# 1. 검을 먼저 찾고 공주를 찾는경우
# 2. 바로 공주를 찾는 경우