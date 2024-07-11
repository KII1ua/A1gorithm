# baekjoon 16493
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

dp = [[0] * (N + 1) for _ in range(M + 1)]
library = [[0, 0]]

for _ in range(M):
  a, b = map(int, input().split())
  library.append([a,b])

library = sorted(library)

for i in range(1, M+1):
  for j in range(1, N+1):
    day, page = library[i][0], library[i][1]
    if j < day:
      dp[i][j] = dp[i-1][j]
    else:
      dp[i][j] = max(dp[i-1][j], dp[i-1][j-day] + page)

print(dp[M][N])