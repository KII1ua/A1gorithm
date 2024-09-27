# baekjoon 15652
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = []

def bt(start):
    if len(arr) == M:
        print(' '.join(map(str, arr)))
        return
    
    for i in range(start, N+1):
        arr.append(i)
        bt(i)
        arr.pop()

bt(1)