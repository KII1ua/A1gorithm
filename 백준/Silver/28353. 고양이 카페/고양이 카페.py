#baekjoon 28353
import sys
input = sys.stdin.readline

N, K = map(int, input().split())
arr = list(map(int, input().split()))
start, end = 0, N-1
cnt = 0

arr.sort()

while start < end:
    if arr[start] + arr[end] <= K:
        start += 1
        end -= 1
        cnt += 1
    else:
        end -= 1

print(cnt)