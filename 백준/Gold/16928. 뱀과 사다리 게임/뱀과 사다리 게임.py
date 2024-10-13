#baekjoon 16928
import sys
from collections import deque
input = sys.stdin.readline

ladder = {}
snake = {}
N, M = map(int, input().split())

for _ in range(N):
    a, b = map(int, input().split())
    ladder[a] = b
    
for _ in range(M):
    a, b = map(int, input().split())
    snake[a] = b

dx = [1, 2, 3, 4, 5, 6]
visited = [False] * 101
q = deque()
q.append([1, 0])

while True:
    x, z = q.popleft()

    if x in ladder.keys():
        x = ladder[x]
    elif x in snake.keys():
        x = snake[x]

    if x == 100:
        print(z)
        sys.exit()

    for i in range(6):
        nx = x + dx[i]

        if 1 <= nx <= 100 and not visited[nx]:
            q.append([nx, z+1])
            visited[nx] = True