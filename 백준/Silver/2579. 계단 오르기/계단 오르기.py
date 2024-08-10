#baekjoon 2579
import sys
input = sys.stdin.readline

N = int(input())
dp = [0] * (N + 1)
stair = [0] * (N + 1)

for i in range(1, N+1):
    a = int(input())
    stair[i] = a

if N == 1:
    print(stair[1])
    exit()

if N == 2:
    print(sum(stair[:3]))
    exit()

dp[1] = stair[1]
dp[2] = stair[1] + stair[2]

for i in range(3, N+1):
    dp[i] = max(dp[i-3] + stair[i] + stair[i-1], dp[i-2] + stair[i])

print(dp[N])