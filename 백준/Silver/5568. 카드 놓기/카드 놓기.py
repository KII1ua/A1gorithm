# baekjoon 5568
import sys
from itertools import permutations
input = sys.stdin.readline

N = int(input())
K = int(input())
arr = [input().rstrip() for _ in range(N)]
result = set()

per = list(permutations(arr, K))

for i in per:
    tmp = "".join(i)
    result.add(tmp)

print(len(result))