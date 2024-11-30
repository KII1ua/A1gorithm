# baekjoon 16953
import sys
from collections import deque
input = sys.stdin.readline

A, B = map(int, input().split())

q = deque()
q.append([A, 1])

while q:

    x, z = q.popleft()

    if x == B:
        print(z)
        sys.exit()

    for nx in (2 * x, str(x) + "1"):
        nx = int(nx)

        if 0 <= nx <= B:
            q.append([nx, z+1])

print(-1)