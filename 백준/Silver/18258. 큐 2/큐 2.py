# baekjoon 18258번
import sys
from collections import deque
input = sys.stdin.readline

queue = deque()
N = int(input())

for _ in range(N):
    _ = list(input().rstrip().split())
    if _[0] == 'push':
        queue.append(int(_[1]))
    elif _[0] == 'front':
        if len(queue) == 0:
            print(-1)
        else: print(queue[0])
    elif _[0] == 'back':
        if len(queue) == 0:
            print(-1)
        else: print(queue[-1])
    elif _[0] == 'size':
        print(len(queue))
    elif _[0] == 'empty':
        if len(queue) == 0:
            print(1)
        else: print(0)
    elif _[0] == 'pop':
        if len(queue) == 0:
            print(-1)
        else: print(queue.popleft())