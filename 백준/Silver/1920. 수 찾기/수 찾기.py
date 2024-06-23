# baekjoon 1920
import sys
input = sys.stdin.readline

N = int(input().rstrip())
N_arr = list(map(int, input().split()))

M = int(input().rstrip())
M_arr = list(map(int, input().split()))

result = {} 

for i in N_arr:
    if i in result:
        result[i] += 1
    else:
        result[i] = 1

for i in M_arr:
    if i in result:
        print('1')
    else:
        print('0')
