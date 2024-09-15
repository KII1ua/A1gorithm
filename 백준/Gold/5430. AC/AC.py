#baekjoon 5430
import sys
from collections import deque
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    visited = False
    p = input().rstrip()
    n = int(input())
    arr = input().rstrip()
    q = deque(arr[1:-1].split(","))
    if n == 0:
        q = deque()
    cnt = 0
    for i in range(len(p)):
        if p[i] == 'R':
            cnt += 1
        elif p[i] == 'D':
            if len(q) == 0:
                print("error")
                visited = True
                break
            else:
                if cnt % 2 == 0:
                    q.popleft()
                else:
                    q.pop()
    if visited == True:
        continue
    else:
        if cnt % 2 == 0:
            print('[' + ",".join(q) + ']')
        else:
            q.reverse()
            print('[' + ",".join(q) + ']')