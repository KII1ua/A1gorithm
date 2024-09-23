#baekjoon 11286
import sys
import heapq
input = sys.stdin.readline

N = int(input())
hq = []

for _ in range(N):
    a = int(input())
    if a != 0:
        heapq.heappush(hq, (abs(a), a))
    else:
        if len(hq) != 0:
            print(heapq.heappop(hq)[1])
        else:
            print(0)