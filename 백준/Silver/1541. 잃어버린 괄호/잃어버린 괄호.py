# baekjoon 1541
import sys
input = sys.stdin.readline

N = input().rstrip().split('-')
result = []

for i in N:
    num = 0
    tmp = i.split('+')
    for j in tmp:
        num += int(j)
    result.append(num)

first = result[0]
for _ in range(1, len(result)):
    first -= result[_]

print(first)