# baekjoon 2579
import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    a, b = map(int, input().split())
    if a % 10 == 0:
        print(10)

    if a % 10 == 1:
        print(1)
    elif a % 10 == 2:
        result = b % 4
        tmp = [2, 4, 8, 6]
        print(tmp[result-1])
    elif a % 10 == 3:
        result = b % 4
        tmp = [3, 9, 7, 1]
        print(tmp[result-1])
    elif a % 10 == 4:
        result = b % 2
        tmp = [4, 6]
        print(tmp[result-1])
    elif a % 10 == 5:
        print(5)
    elif a % 10 == 6:
        print(6)
    elif a % 10 == 7:
        result = b % 4
        tmp = [7, 9, 3, 1]
        print(tmp[result-1])
    elif a % 10 == 8:
        result = b % 4
        tmp = [8, 4, 2, 6]
        print(tmp[result-1])
    elif a % 10 == 9:
        result = b % 2
        tmp = [9, 1]
        print(tmp[result-1])
