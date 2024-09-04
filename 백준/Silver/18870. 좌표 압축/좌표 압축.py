#baekjoon 18870
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
dict = {}
idx = 0

tmp = sorted(arr)

for i in range(len(tmp)):
    if tmp[i] not in dict:
        dict[tmp[i]] = idx
        idx += 1
    else:
        pass

for j in arr:
    print(dict[j], end = " ")