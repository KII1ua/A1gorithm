#baekjoon 2239
import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
arr = list(input().rstrip())

if arr[-1] in ['r', 's', 'e', 'f', 'a', 'q', 't', 'd', 'w', 'c', 'z', 'x', 'v', 'g']:
    print(1)
else:
    print(0)