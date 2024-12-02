# baekjoon 2448
import sys
input = sys.stdin.readline

A, B, C = map(int, input().split())
result = 1

while B:
    if B % 2 == 1:  # 지수가 홀수일 경우 지수에서 1을 빼고 반으로 나누어 곱하고 밑을 한번더 곱함
        result *= A

    A *= A % C
    B //= 2

print(result % C)