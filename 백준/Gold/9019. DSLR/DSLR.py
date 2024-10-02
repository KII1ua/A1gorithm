# baekjoon 9019
import sys
from collections import deque
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

T = int(input())

for _ in range(T):
    A, B = map(int, input().split())
    visited = [False] * 10001

    q = deque()
    q.append([A, ''])
    visited[A] = True

    while q:
        tmp, cmd = q.popleft()

        if tmp == B:
            print(cmd)
            break
        
        D = tmp * 2 % 10000
        if not visited[D]:
            visited[D] = True
            q.append([D, cmd + 'D'])
        
        S = (tmp - 1) % 10000
        if not visited[S]:
            visited[S] = True
            q.append([S, cmd + 'S'])

        L = tmp // 1000 + (tmp % 1000) * 10
        if not visited[L]:
            visited[L] = True
            q.append([L, cmd + 'L'])
        
        R = tmp // 10 + (tmp % 10) * 1000
        if not visited[R]:
            visited[R] = True
            q.append([R, cmd + 'R'])