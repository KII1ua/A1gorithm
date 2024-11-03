# baekjoon 2446
import sys
input = sys.stdin.readline

N = int(input())
tmp = N-1
num = 0
num1 = 1

for i in range(N-1):
    for j in range(tmp):
        print(' ', end = '')
    
    tmp -= 1
    
    num += 1
    result = 2 * num - 1
    for k in range(result):
        print('*', end = '')
    print()

print('*' * (2*N-1))

for i in range(N-1, 0, -1):
    for j in range(num1):
        print(' ', end = '')

    num1 += 1
    
    for k in range(2 * i - 1):
        print("*", end = '')
    print()