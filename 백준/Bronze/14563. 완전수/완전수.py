#baekjoon 14563
import sys
input = sys.stdin.readline

T = int(input())
arr = list(map(int, input().split()))

for i in arr:
    tmp = []
    for j in range(1, i):
        if i % j == 0:
            tmp.append(j)
    if sum(tmp) > i:
        print("Abundant")
    elif sum(tmp) < i:
        print("Deficient")
    elif sum(tmp) == i:
        print("Perfect")
