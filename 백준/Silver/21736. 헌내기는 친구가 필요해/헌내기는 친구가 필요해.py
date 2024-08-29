# baekjoon 21736
import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(input().rstrip()) for _ in range(N)]
q = deque()
cnt = 0
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(N):
    for j in range(M):
        if graph[i][j] == 'I':
            q.append((i, j))
            graph[i][j] = 'X'

while q:
    x, y = q.popleft()      # 현재 좌표

    for _ in range(4):      # 상 하 좌 우 탐색
        nx = x + dx[_]
        ny = y + dy[_]

        if nx >= N or ny >= M or nx < 0 or ny < 0:      # 갈 수 있는 좌표인지 확인
            continue
        if graph[nx][ny] == 'X':
            continue
        if graph[nx][ny] == 'P':
            q.append((nx, ny))
            graph[nx][ny] = 'X'
            cnt += 1
            continue
        q.append((nx, ny))
        graph[nx][ny] = 'X'     # 방문 표시
    
if cnt:
    print(cnt)
else:
    print('TT')