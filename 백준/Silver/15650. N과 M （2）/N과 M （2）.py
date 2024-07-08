# baekjoon 11723
import sys
from itertools import combinations
input = sys.stdin.readline

N, M = map(int, input().split())
arr = [x for x in range(1, N+1)]
comb = list(combinations(arr, M))

for i in comb:
    print(" ".join(map(str, i)))