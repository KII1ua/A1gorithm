# baekjoon 10872
import sys
input = sys.stdin.readline

N = int(input())
result = 1

if N == 0:
    print(1)
    sys.exit()

for i in range(N, 0, -1):
    result *= i

print(result)