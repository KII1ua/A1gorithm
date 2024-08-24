# baekjoon 10989번
import sys
input = sys.stdin.readline

n = int(input())
num = [0] * 10001

for i in range(n):
    x = int(input())
    num[x] += 1

for i in range(1, 10001):
    for c in range(0, num[i]):
        print(i)