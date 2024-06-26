# baekjoon 2075
import sys
input = sys.stdin.readline
from heapq import heappush, heappop

N = int(input())
heap = []

for _ in range(N):
    numbers = map(int, input().split())
    for number in numbers:
        if len(heap) < N: # heap의 크기를 N개로 유지
            heappush(heap, number)
        else:
            if heap[0] < number:
                heappop(heap)
                heappush(heap, number)
print(heap[0])