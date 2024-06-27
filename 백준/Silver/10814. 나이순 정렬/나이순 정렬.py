#baekjoon 10814
import sys
input = sys.stdin.readline

N = int(input())
result = []

for _ in range(N):
    a, b = list(input().rstrip().split())
    result.append([int(a), b])

sorted_lst = sorted(result, key=lambda x : x[0])

for i, j in sorted_lst:
    print(i, j)