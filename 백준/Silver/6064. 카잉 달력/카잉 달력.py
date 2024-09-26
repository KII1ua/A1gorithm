# baekjoon 6064
import sys
# from collections import deque
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

def calculator(m, n, x, y):
    k = x
    while k <= m * n:
        if (k - x) % m == 0 and (k - y) % n == 0:
            return k
        k += m
    return -1

T = int(input())

for _ in range(T):
    m, n, x, y = map(int, input().split())
    print(calculator(m, n, x, y))