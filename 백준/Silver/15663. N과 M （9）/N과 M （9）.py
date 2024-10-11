# baekjoon 15663
import sys
from itertools import permutations
input = sys.stdin.readline

N, M = map(int, input().split())
arr = list(map(int, input().split()))

per = sorted(set(list(permutations(arr, M))))

for i in per:
    print(*i)