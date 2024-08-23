#baekjoon 20155
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
conv = list(map(int, input().split()))
dict = {}

for i in conv:
    if i not in dict:
        dict[i] = 1
    else:
        dict[i] += 1

print(max(dict.values()))