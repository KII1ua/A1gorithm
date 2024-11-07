# baekjoon 2304
import sys
input = sys.stdin.readline
from collections import deque
# sys.setrecursionlimit(10**6)

H, W = map(int, input().split())
arr = list(map(int, input().split()))
graph = [[0] * W for _ in range(H)]
count = 0

for i in range(W):
    for j in range(H-arr[i], H):
        graph[j][i] = 1

for i in range(H-1 , -1, -1):
    for j in range(W):
        tmp = 0
        visited = False
        if graph[i][j] == 1:
            for k in range(j+1, W):
                if graph[i][k] == 0:
                    tmp += 1
                else:
                    visited = True
                    break
            if visited == True:
                count += tmp

print(count)