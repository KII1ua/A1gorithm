#baekjoon 14732
import sys
import collections
input = sys.stdin.readline

N = int(input())
graph = [[0] * 500 for _ in range(501)]
result = 0

for _ in range(N):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(x1, x2):
        for j in range(y1, y2):
            graph[i][j] = 1

for i in range(500):
    result += graph[i].count(1)

print(result)