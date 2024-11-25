#baekjoon 12851
import sys
from itertools import combinations_with_replacement
input = sys.stdin.readline

arr = set()

N, M = map(int, input().split())
arr = list(set(map(int, input().split())))

arr.sort()

comb = list(combinations_with_replacement(arr, M))

for i in comb:
    print(*i)