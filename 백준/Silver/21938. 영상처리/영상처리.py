import sys
input = sys.stdin.readline
from math import ceil
sys.setrecursionlimit(500000)

N, M = map(int, input().rstrip().split())
graph = []
count = 0  
for _ in range(N):
    line = list(map(int, input().rstrip().split()))
    row = []
    for i in range(M):
        k = line[3*i] + line[3*i+1] + line[3*i+2]
        row.append(k/3)
    graph.append(row)
T = int(input())

for row in range(N):
    for col in range(M):
        if graph[row][col] >= T:
            graph[row][col] = 1
        else:
            graph[row][col] = 0

def dfs(row, col):
    if 0 <= row < N and 0 <= col < M and graph[row][col] == 1:
        graph[row][col] = 0
        dfs(row+1, col)
        dfs(row-1, col)
        dfs(row, col+1)
        dfs(row, col-1)
        return 1

for row in range(N):
    for col in range(M):
        if bool(graph[row][col]):
            count += dfs(row, col)

print(count)