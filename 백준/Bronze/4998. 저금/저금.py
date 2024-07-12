# baekjoon 11047
import sys
import math
input = sys.stdin.readline

try:
    while True:
        N, B, M = map(float, input().split())
        count = 0
        saving = N
        interest = 0        # 이자

        while M > saving:
            interest = saving * (B * 0.01)
            saving += interest
            count += 1

        print(count)
except:
    pass