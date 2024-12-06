# baekjoon 1744
import sys
input = sys.stdin.readline

N = int(input())
plus = []
minus = []
result = 0

for i in range(N):
    a = int(input())
    if a > 1:
        plus.append(a)
    elif a <= 0:
        minus.append(a)
    else:
        result += a

plus.sort(reverse=True)
minus.sort()

for i in range(0, len(plus), 2):
    if i+1 >= len(plus):
        result += plus[i]
    else:
        result += (plus[i] * plus[i+1])


for j in range(0, len(minus), 2):
    if j+1 >= len(minus):
        result += minus[j]
    else:
        result += (minus[j] * minus[j+1])

print(result)