# baekjoon 1213
import sys
input = sys.stdin.readline

T = int(input())
dp = [0] * 101

for _ in range(1, 4):
    dp[_] = 1

for a in range(4, 6):
    dp[a] = 2

for i in range(T):
    a = int(input())    
    for j in range(6, a+1):
        dp[j] = dp[j-1] + dp[j-5]
    print(dp[a])