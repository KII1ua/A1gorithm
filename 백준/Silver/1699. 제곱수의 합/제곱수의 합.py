# baekjoon 1699
import sys
input = sys.stdin.readline

N = int(input())
dp = [0, 1]

for i in range(2, N + 1):
    j = 1
    mini = 4
    while j * j <= i:
        mini = min(mini, dp[i - j * j])
        j += 1
    dp.append(mini + 1)

print(dp[N])