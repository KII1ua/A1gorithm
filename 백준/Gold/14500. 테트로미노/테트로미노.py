# baekjoon 14500
import sys
input = sys.stdin.readline
from collections import deque
# sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
result = 0
count = 0

def dfs(x, y, tmp, cnt):        # 값, 개수
    global result
    if cnt == 4:
        result = max(result, tmp)
        return
    
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0<= nx < N and 0<= ny < M and not visited[nx][ny]:
            visited[nx][ny] = True
            dfs(nx, ny, tmp + graph[nx][ny], cnt + 1)
            visited[nx][ny] = False

def square(x, y):
    global result
    arr = []

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0<= nx < N and 0<= ny < M:
            arr.append(graph[nx][ny])
    
    if len(arr) == 4:
        arr.sort(reverse=True)
        arr.pop()
        result = max(result, sum(arr) + graph[x][y])
    elif len(arr) == 3:
        result = max(result,  sum(arr) + graph[x][y])
    return


for i in range(N):
    for j in range(M):
        visited[i][j] = True
        dfs(i, j, graph[i][j], 1)
        square(i, j)
        visited[i][j] = False

print(result)