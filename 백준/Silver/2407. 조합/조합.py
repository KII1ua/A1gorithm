#baekjoon 2407
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
up = 1
down = 1

for i in range(N, N-M, -1):
    up *= i

for j in range(M, 0, -1):
    down *= j

print(int(up // down))