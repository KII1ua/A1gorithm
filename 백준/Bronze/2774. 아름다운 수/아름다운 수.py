# baekjoon 4504
import sys
input = sys.stdin.readline

T = int(input())
arr = []

for _ in range(T):
    a = input().rstrip()
    arr.append(a)

for i in arr:
    cnt = 0
    dict = {}
    for j in i:
        if j not in dict:
            dict[j] = 1
            cnt += 1
        else:
            continue
    print(cnt)