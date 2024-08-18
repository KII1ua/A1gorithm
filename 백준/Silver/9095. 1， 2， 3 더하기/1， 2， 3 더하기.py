# baekjoon 9095
import sys
from itertools import product
input = sys.stdin.readline

T = int(input())
arr = [1, 2, 3]

for _ in range(T):
    a = int(input())
    cnt = 0
    for i in range(1, a+1):
        result = list(product(arr, repeat = i))
        for j in result:
            if sum(j) == a:
                cnt += 1
    print(cnt)