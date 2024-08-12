# baekjoon 1183
import sys
input = sys.stdin.readline

N = input().rstrip()

tmp = N[::-1]

if N == tmp:
    print(1)
else:
    print(0)