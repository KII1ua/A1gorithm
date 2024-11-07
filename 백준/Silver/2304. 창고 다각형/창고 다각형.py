# baekjoon 2304
import sys
input = sys.stdin.readline
from collections import deque
# sys.setrecursionlimit(10**6)

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
result = 0

arr.sort(key = lambda x : x[0])

idx = 0

for i in range(N):
    if arr[i][1] > result:
        idx = i
        result = arr[i][1]

height = arr[0][1]

for i in range(idx):
    if arr[i+1][1] > height:
        result += height * (arr[i+1][0] - arr[i][0])
        height = arr[i+1][1]
    else:
        result += (arr[i+1][0] - arr[i][0]) * height

height = arr[-1][1]

for i in range(N-1, idx, -1):
    if arr[i-1][1] < height:
        result += height * (arr[i][0] - arr[i-1][0])
    else:
        result += height * (arr[i][0] - arr[i-1][0])
        height = arr[i-1][1]

print(result)