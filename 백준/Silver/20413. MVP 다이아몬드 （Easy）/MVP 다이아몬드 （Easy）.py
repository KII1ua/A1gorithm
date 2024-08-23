#baekjoon 20413
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
t_ = ['B', 'S', 'G', 'P', 'D']
standard = {}
tier = list(input().rstrip())
dp = [0] * N

for i in range(len(t_) + 1):
    if t_[i] == 'D':
        standard[t_[i]] = arr[i-1]
        break
    standard[t_[i]] = arr[i] - 1

for i in range(len(tier)):
    if i == 0:
        dp[i] = standard[tier[i]]
        continue
    if tier[i] == 'D':
        dp[i] = standard['D']
        continue
    dp[i] = standard[tier[i]] - dp[i-1]

print(sum(dp))