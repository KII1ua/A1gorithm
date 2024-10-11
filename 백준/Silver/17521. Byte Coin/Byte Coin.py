# baekjoon 11047
import sys
input = sys.stdin.readline

N, W = map(int, input().split())
arr = [int(input()) for _ in range(N)]
coin = 0
money = 0

for i in range(N-1):
    if arr[i] < arr[i+1]:
        coin += W // arr[i]      # 코인 사기
        W = W - (coin * arr[i])

        W = W + (coin * arr[i+1])
        coin = 0

print(W)