# baekjoon 11723
import sys
input = sys.stdin.readline

M = int(input())
S = set()

for _ in range(M):
    a = input().rstrip().split()

    if a[0] == 'add':
        S.add(a[1])
    elif a[0] == 'remove':
        S.discard(a[1])
    elif a[0] == 'check':
        if a[1] in S:
            print('1')
        else:
            print('0')
    elif a[0] == 'toggle':
        if a[1] in S:
            S.discard(a[1])
        else:
            S.add(a[1])
    elif a[0] == 'all':
        S = set([str(x) for x in range(1, 21)])
    elif a[0] == 'empty':
        S = set({})