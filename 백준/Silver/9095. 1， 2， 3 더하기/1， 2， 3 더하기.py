# baekjoon 9095
import sys
input = sys.stdin.readline

dp = [0] * 12
T = int(input())

dp[1] = 1
dp[2] = 2
dp[3] = 4

for i in range(4, 11):
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

for _ in range(T):
    a = int(input())
    print(dp[a])