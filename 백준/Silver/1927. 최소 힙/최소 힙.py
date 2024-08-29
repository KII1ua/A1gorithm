# baekjoon 1927
import sys
import heapq
input = sys.stdin.readline

hq = []

N = int(input())

for _ in range(N):
    a = int(input())
    if a == 0:
        if len(hq) == 0:
            print(0)
            continue
        else:
            print(heapq.heappop(hq))
            continue
    heapq.heappush(hq, a)