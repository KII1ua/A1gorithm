#baekjoon 27446
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
paper = list(map(int, input().split()))
l_page = []
ink = 0
tmp = 0

for i in range(1, N + 1):
    if i not in paper:
        l_page.append(i)

for i in l_page:
    if tmp:
        ink += min(7, (i - tmp) * 2)
    else:
        ink += 7
    tmp = i

print(ink)