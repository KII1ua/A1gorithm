# baekjoon 19941
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = list(map(int, input().split()))
count = 0

for i in range(N):
    tmp = 0 
    for j in range(i, N):
        tmp += arr[j]
        if tmp == M:
            count += 1
            break

print(count)