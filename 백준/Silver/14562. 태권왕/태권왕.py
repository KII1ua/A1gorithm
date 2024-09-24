import sys
from collections import deque
input = sys.stdin.readline

def bfs(x, y):
    q = deque()

    q.append([x, y, 0])

    while q:
        x, y, cnt = q.popleft()

        if x == y:
            print(cnt)
            return True
        for i, j, k in ([x + 1, y, cnt], [2 * x, y + 3, cnt]):
            if i <= j:
                q.append([i, j, k+1])

        # if dx == dy:
        #     print(arr[dx])
        #     return True
        # for i, k in ([dx+1, dy], [2 * dx, dy + 3]):
        #     if i <= k and not arr[i]:
        #         arr[i] = arr[dx] + 1
        #         q.append([i, k])

C = int(input())

for _ in range(C):
    a, b = map(int, input().split())
    bfs(a, b)