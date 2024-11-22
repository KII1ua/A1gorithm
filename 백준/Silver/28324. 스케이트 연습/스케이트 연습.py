#baekjoon 28324
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

lst = arr[::-1]
tmp = 0
result = 0

for i in lst:
    if tmp < i:
        tmp += 1
        result += tmp
    else:
        tmp = i
        result += tmp

print(result)