# baekjoon 11047
import sys
input = sys.stdin.readline

N, K = map(int, input().split())
coin = [int(input()) for x in range(N)]
cnt = 0

coin.sort(reverse=True)


while K>0:
    for i in coin:
        if K // i > 0:
            cnt += K // i 
            K = K % i

print(cnt)