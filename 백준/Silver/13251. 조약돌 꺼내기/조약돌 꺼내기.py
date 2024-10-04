#baekjoon 13251
import sys  
from collections import deque
import math
input = sys.stdin.readline

# def comb(a, k):
#     up = 1
#     down = 1
#     for i in range(a, a-k, -1):
#         up *= i
#     for j in range(k, 1, -1):
#         down *= j
    # return up / down

M = int(input())
arr = list(map(int, input().split()))
K = int(input())

if len(arr) == 1 or K == 1:
    print(1.0)
    sys.exit()

res = 0
tmp = 0

for i in arr:
    res += math.comb(i, K)

tmp = math.comb(sum(arr), K)

print(res / tmp)