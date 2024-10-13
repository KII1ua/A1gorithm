#baekjoon 16928
import sys
input = sys.stdin.readline

arr = []
tp = 0
tmp = 0

for _ in range(5):
    a = list(input().rstrip())
    arr.append(a)
    if len(a) > tmp:
        tmp = len(a)

for i in range(5):
    for j in range(len(arr[i])):
        if len(arr[i]) != tmp:
            for k in range(len(arr[i]), tmp):
                arr[i].append(True)

for i in range(tmp):
    for j in range(5):
        if arr[j][i] != True:
            print(arr[j][i], end = '')