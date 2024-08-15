# baekjoon 2312
import sys
input = sys.stdin.readline

N = int(input())

for _ in range(N):
    a = int(input())
    dict = {}
    for i in range(2, a+1):
        while a > 1:
            if a % i == 0:
                if i not in dict:
                    dict[i] = 1
                else:
                    dict[i] += 1
                a /= i
            else:
                break
    for j in dict:
        print("{} {}".format(j, dict[j]))