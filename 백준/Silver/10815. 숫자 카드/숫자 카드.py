#baekjoon 10815
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
M = int(input())
tmp = list(map(int, input().split()))
dict = {}

for i in range(N):
    if arr[i] not in dict:
        dict[arr[i]] = 1
    else:
        continue

for j in range(M):
    if tmp[j] not in dict:
        print(0, end = ' ')
    else:
        print(1, end = ' ')