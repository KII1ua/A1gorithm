#baekjoon 28446
import sys
input = sys.stdin.readline

M = int(input())
dict = {}

for i in range(M):
    x = list(input().rstrip().split())
    if x[0] == '1':
        if int(x[2]) not in dict:
            dict[int(x[2])] = [x[1]]
        else:
            dict[int(x[2])] += x[1]
    else:
        x[1] = int(x[1])
        for i in dict[x[1]]:
            print(int(i))