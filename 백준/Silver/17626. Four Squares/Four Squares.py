import sys
input = sys.stdin.readline

N = int(input())
dp = [0, 1]

for i in range(2, N + 1):
    j = 1
    min_ = 5
    while j * j <= i:
        min_ = min(min_, dp[i - j * j])
        j += 1
    dp.append(min_ + 1)

print(dp[N])