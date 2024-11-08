#baekjoon 27496
import sys
input = sys.stdin.readline

N, L = map(int, input().split())
arr = list(map(int, input().split()))
result = 0
cnt = 0
visited = False

for i in range(N):
    result += arr[i]

    if i >= L:
        result -= arr[i-L]

    if 129 <= result <= 138:
        cnt += 1

print(cnt)