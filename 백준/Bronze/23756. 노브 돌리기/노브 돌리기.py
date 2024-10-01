# baekjoon 23756
import sys
from collections import deque
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

N = int(input())
A0 = int(input())
arr = []
min_ = 0

for _ in range(N):
    a = int(input())
    arr.append(a)

for i in range(N):
    min_ += min(abs(arr[i] - A0), A0 + 360 - arr[i], 360 - A0 + arr[i])
    A0 = arr[i]

print(min_)