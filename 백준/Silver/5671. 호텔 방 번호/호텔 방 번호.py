# baekjoon 4659
import sys
from collections import deque
input = sys.stdin.readline

try:
    while True:
        N, M = map(int, input().split())
        count = 0       # 중복되는 숫자

        for i in range(N, M+1):
            dict = {}
            visited = False
            a = list(str(i))
            for j in a:
                if j not in dict:
                    dict[j] = 1
                else:
                    visited = True
                    break
            if visited == False:
                count += 1
        print(count)
except:
    pass