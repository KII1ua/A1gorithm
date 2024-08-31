# baekjoon 2553
import sys
input = sys.stdin.readline

N = int(input())
result = 1

for i in range(1, N + 1):
    result *= i

result = str(result)
for j in result[::-1]:
    if j != '0':
        print(int(j))
        break