# baekjoon 11723
import sys
input = sys.stdin.readline

M = int(input())
S = []

for i in range(M):
    a = input().rstrip().split()

    if a[0] == 'add' and a[1] not in S:
        S.append(a[1])
    elif a[0] == 'remove' and a[1] in S:
        S.remove(a[1])
    elif a[0] == 'check':
        if a[1] in S:
            print("1")
        else:
            print("0")
    elif a[0] == 'toggle':
        if a[1] in S:
            S.remove(a[1])
        else:
            S.append(a[1])
    elif a[0] == 'all':
        S = [str(x) for x in range(1, 21)]
    elif a[0] == 'empty':
        S = []