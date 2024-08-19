# baekjoon 17626
import sys
input = sys.stdin.readline

N = int(input())
dp = [0, 1]

for _ in range(2, N+1):
    i = 1
    mini = 4
    while i * i <= _:
        mini = min(mini, dp[_ - i * i])
        i += 1
    dp.append(mini + 1)

print(dp[N])