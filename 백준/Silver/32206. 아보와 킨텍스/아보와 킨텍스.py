#baekjoon 14940
import sys  
from collections import deque
input = sys.stdin.readline

N = int(input())
string = input().rstrip()
res = 0

for i in range(len(string)+1):
    res += 26

for j in range(len(string)):
    res -= 1

print(res)