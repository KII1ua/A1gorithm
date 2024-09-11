# baekjoon 24523
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

tmp = 0
for i in range(1, N):
    if arr[i] != arr[tmp]:
        for j in range(i-tmp):
            print(i+1, end = ' ')
        tmp = i

for j in range(N-tmp):
    print(-1, end = ' ')