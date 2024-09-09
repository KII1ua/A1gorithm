# baekjoon 26265
import sys
input = sys.stdin.readline

N = int(input())
lst = [tuple(input().rstrip().split()) for _ in range(N)]

lst.sort(key= lambda x : x[1], reverse=True)
lst.sort(key= lambda x : x[0])

for i in lst:
    x, y = i
    print("{} {}".format(x, y))