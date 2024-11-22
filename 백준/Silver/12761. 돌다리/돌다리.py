#baekjoon 12761
import sys
from collections import deque
input = sys.stdin.readline

A, B, N, M = map(int, input().split())
dx = [-1, 1, -A, A, -B, B, A, B]
visited = [0] * 100001

q = deque()
q.append([N,0])

while q:
    x, z = q.popleft()

    if x == M:
        print(z)
        sys.exit()

    for i in range(8):
        if i <= 5:
            nx = x + dx[i]
        else:
            nx = x * dx[i]
        
        if 0 <= nx <= 100000 and not visited[nx]:
            q.append([nx, z+1])
            visited[nx] = 1