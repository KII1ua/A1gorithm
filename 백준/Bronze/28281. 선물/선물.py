#baekjoon 27496
import sys
input = sys.stdin.readline

N, X = map(int, input().split())
arr = list(map(int, input().split()))
result = (arr[0] * X) + (arr[1] * X)

for i in range(1, N-1):
    tmp = (arr[i] * X) + (arr[i+1] * X)
    if result > tmp:
        result = tmp

print(result)