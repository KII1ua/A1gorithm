# baekjoon 2588
import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
tmp = 2

for i in range(1, N):
    for j in range(i):
        print("*", end = '')
    
    for k in range((2 * N) - (2 * i)):
        print(" ", end = '')
    
    for j in range(i):
        print("*", end = '')
    print()
print("*" * N * 2) 

for i in range(N-1, 0, -1):
    for j in range(i):
        print("*", end = '')
    
    for k in range(tmp):
        print(" ", end = '')
    
    for j in range(i):
        print("*", end = '')
    print()
    tmp += 2