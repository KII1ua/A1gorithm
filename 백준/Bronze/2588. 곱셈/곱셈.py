# baekjoon 2588
import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
M = int(input())

print(N * (M % 10))
print(N * (M % 100 // 10))
print(N * (M % 1000 // 100))
print(N * M)