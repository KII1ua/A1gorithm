#baekjoon 5525
import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
S = input().rstrip()

idx, result, cnt = 0, 0, 0      # 문자 위치, OI 횟수, 개수

while idx < (M - 1):
    if S[idx: idx+3] == 'IOI':
        idx += 2
        result += 1
        if result == N:
            result -= 1
            cnt += 1
    else:
        idx += 1
        result = 0

print(cnt)