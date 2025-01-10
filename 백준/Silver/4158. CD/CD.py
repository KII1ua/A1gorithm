# baekjoon 20006
import sys
input = sys.stdin.readline

while(True):
    N, M = map(int, input().split())

    if(N == 0 and M == 0):
        break
    cnt = 0
    dict = {}

    for _ in range(N + M):
        a = int(input())
        if a not in dict:
            dict[a] = 1
        else:
            dict[a] += 1
    
    for i, j in dict.items():
        if(j >= 2):
            cnt += 1
    
    print(cnt)