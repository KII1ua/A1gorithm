# baekjoon 31797
import sys
input = sys.stdin.readline

N, M = map(int, input().split())    # 층수, 참가자 수
apart = [0] * 10001     # 두손의 최대 높이 10000

for i in range(1, M+1):
    a, b = list(map(int, input().split()))
    apart[a] = i
    apart[b] = i

# 최대 높이가 참가자 인원수보다 작거나 크거나 같을 경우
N = N % (2 * M)     
if N == 0:
    N = 2 * M

floor = 1
for i in range(1, 10001):
    if apart[i] != 0:
        if floor == N:
            print(apart[i])
            break
        else:
            floor += 1