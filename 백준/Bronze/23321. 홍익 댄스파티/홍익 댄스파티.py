# baekjoon 23321
import sys
input = sys.stdin.readline

arr = [list(input().rstrip()) for _ in range(5)]
result = []

for i in range(len(arr[0])):
    tmp = ""
    for j in range(len(arr)):
        tmp += arr[j][i]
    if tmp == '.omln':
        tmp = 'owln.'
        for l in range(len(arr)):
            arr[l][i] = tmp[l]
    elif tmp == 'owln.':
        tmp = '.omln'
        for l in range(len(arr)):
            arr[l][i] = tmp[l]

for j in range(len(arr)):
    for i in range(len(arr[0])):
        print(arr[j][i], end='')
    print()