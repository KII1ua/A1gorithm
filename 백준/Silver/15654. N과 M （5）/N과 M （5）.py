# baekjoon 15654
import sys
from itertools import permutations
input = sys.stdin.readline

N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

per = list(permutations(arr, M))

for i in per:
    print(*i)
