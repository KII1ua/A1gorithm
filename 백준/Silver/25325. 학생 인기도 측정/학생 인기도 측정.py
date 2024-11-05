# baekjoon 5585
import sys
input = sys.stdin.readline

N = int(input())
arr = list(input().rstrip().split())
dict = {}

for j in arr:
    dict[j] = 0

for _ in range(N):
    a = input().rstrip().split()
    for i in a:
        if i not in dict:
            dict[i] = 1
        else:
            dict[i] += 1

d = sorted(dict.items(), key = lambda x : x[1], reverse=True)

for a, b in d:
    print(a, b)