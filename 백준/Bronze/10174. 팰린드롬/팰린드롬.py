#baekjoon 17352
import sys

N = int(input())
arr = []

for i in range(N):
    a = input()
    tmp = a.lower()
    result = tmp[::-1]

    if tmp == result:
        print("Yes")
    else:
        print("No")