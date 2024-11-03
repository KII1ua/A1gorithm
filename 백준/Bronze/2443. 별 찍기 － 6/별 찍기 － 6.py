# baekjoon 2446
import sys
input = sys.stdin.readline

N = int(input())
tmp = 0

for i in range(N, 0, -1):
    for k in range(tmp):
        print(' ', end = '')

    for j in range(2*i-1):
        print('*', end = '')
    print()

    tmp += 1