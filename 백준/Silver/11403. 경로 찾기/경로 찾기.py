# baekjoon 11403
import sys
# from collections import deque
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

INF = 999999
N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]

for i in range(N):
    for j in range(N):
        if graph[i][j] == 0:
            graph[i][j] = INF

for k in range(N):
    for i in range(N):
        for j in range(N):
            if graph[i][k] + graph[k][j] > 999:
                continue
            else:
                graph[i][j] = 1

for i in range(N):
    for j in range(N):
        if graph[i][j] == INF:
            print(0, end = ' ')
        else:
            print(graph[i][j], end = ' ')
    print()