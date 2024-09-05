# baekjoon 1697
import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())
arr = [0] * 100001

q = deque()
q.append((N))

while q:

    x = q.popleft()

    if x == K:
        print(arr[x])
        sys.exit()
    for i in (x-1, x+1, 2 * x):
        if 0 <= i < 100001 and not arr[i]:
            arr[i] = arr[x] + 1
            q.append(i)