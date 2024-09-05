# baekjoon 1564
import sys
input = sys.stdin.readline

N = int(input())
result = 1

for i in range(2, N+1):
    result *= i
    while True:
        if str(result)[-1] == '0':
            result //= 10
        else:
            break
    result %= 10000000000000000

print(str(result)[-5::])
