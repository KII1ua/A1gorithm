# baekjoon 11659
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
N_list = list(map(int, input().split()))
sum = [0]
tmp = 0

for i in N_list:
    tmp = tmp + i
    sum.append(tmp)

for i in range(M):
    a, b = map(int, input().split())
    print(sum[b] - sum[a - 1])