# baekjoon 9465
import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    arr = [list(map(int, input().split())) for a in range(2)]
    
    dp = [[0] * N for b in range(2)]

    dp[0][0] = arr[0][0]
    dp[1][0] = arr[1][0]

    if N == 1:
        print(max(dp[0][0], dp[1][0]))
        continue
    
    dp[0][1] = arr[1][0] + arr[0][1]
    dp[1][1] = arr[0][0] + arr[1][1]

    if N == 2:
        print(max(dp[0][1], dp[1][1]))
        continue
    
    for i in range(2, N):
        dp[0][i] = max(dp[1][i - 2], dp[1][i-1]) + arr[0][i]
        dp[1][i] = max(dp[0][i - 2], dp[0][i-1]) + arr[1][i]
    
    print(max(dp[0][-1], dp[1][-1]))