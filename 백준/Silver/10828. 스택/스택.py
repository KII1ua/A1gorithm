# baekjoon 10845
import sys
input = sys.stdin.readline

N = int(input())
lst = []

for _ in range(N):
    command = list(input().split())
    if command[0] == 'push':
        lst.append(command[1])
    elif command[0] == 'top':
        if len(lst) == 0: print(-1)
        else: print(lst[-1])
    elif command[0] == 'size':
        print(len(lst))
    elif command[0] == 'empty':
        if len(lst) == 0: print(1)
        else: print(0)
    elif command[0] == 'pop':
        if len(lst) == 0: print(-1)
        else: print(lst.pop())