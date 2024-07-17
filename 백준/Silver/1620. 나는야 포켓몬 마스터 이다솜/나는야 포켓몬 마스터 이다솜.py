# baekjoon 1620
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

poketmon = {}
solve = {}

for i in range(N):
    a = input().rstrip()
    poketmon[a] = int(i) + 1
    poketmon[i+1] = a

for j in range(M):
    a = input().rstrip()
    if a.isdigit():
        print(poketmon[int(a)])
    else:
        print(poketmon[a])