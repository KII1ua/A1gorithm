#baekjoon 1010
import sys
input = sys.stdin.readline

T = int(input())

def comb(a, b):
    up = 1
    down = 1
    for i in range(a, 0, -1):
        down *= i
    for j in range(b, b-a, -1):
        up *= j
    return up // down

for i in range(T):
    a, b = list(map(int, input().split()))
    print(comb(a, b))