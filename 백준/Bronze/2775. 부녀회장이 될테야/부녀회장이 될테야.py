# baekjoon 1639
import sys
input = sys.stdin.readline

N = int(input())

for _ in range(N):
    floor = int(input())
    hosu = int(input())
    dp = [[0] * (hosu + 1) for m in range(floor + 1)]

    for a in range(1, hosu + 1):
        dp[0][a] = a
    
    for b in range(1, floor + 1):
        dp[b][1] = 1

    for i in range(1, floor + 1):
        for j in range(2, hosu + 1):
            dp[i][j] = dp[i][j-1] + dp[i-1][j]
    
    print(dp[floor][hosu])
