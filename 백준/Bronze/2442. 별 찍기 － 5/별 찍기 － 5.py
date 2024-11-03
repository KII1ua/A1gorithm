# baekjoon 2446
import sys
input = sys.stdin.readline

N = int(input())
tmp = 0
result = 0

for i in range(N, 0, -1):
    for j in range(i-1, 0, -1):
        print(' ', end = '')

    tmp += 1
    result = 2 * tmp - 1

    for k in range(result):
        print('*', end = '')
    print()