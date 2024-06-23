# baekjoon 10773
import sys
input = sys.stdin.readline

K = int(input())
result = []

for i in range(K):
    i = int(input().rstrip())

    if i == 0:
        result.pop()
        continue

    result.append(i)

print(sum(result))