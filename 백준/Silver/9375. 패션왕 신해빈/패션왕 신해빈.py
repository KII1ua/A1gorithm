# baekjoon 1015
import sys
input = sys.stdin.readline

N = int(input())

for _ in range(N):
    clothes = {}
    a = int(input())
    for i in range(a):
        i, j = list(input().rstrip().split())
        if j in clothes:
            clothes[j].append(i)
        else:
            clothes[j] = [i]

    cnt = 1

    for x in clothes:
        cnt *= (len(clothes[x]) + 1)
    print(cnt-1)