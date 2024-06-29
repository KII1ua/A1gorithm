#baekjoon 26169
import sys
import math
input = sys.stdin.readline

N = int(input())
size = list(map(int, input().split()))
T, P = map(int, input().split())

order = 0

for i in size:
    if i == 0:
        continue
    elif T >= i:
        order += 1
    else:
        order += math.ceil(i/T)

print(order)
print(N // P, N % P)