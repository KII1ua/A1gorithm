# baekjoon 1024
import sys
input = sys.stdin.readline

while True:
    try:
        dp = [0] * 251
        dp[0] = 1
        dp[1] = 1
        dp[2] = 3

        _ = int(input())

        for i in range(3, _+1):
            dp[i] = dp[i-1] + (dp[i-2] * 2)

        print(dp[_])
    except:
        break