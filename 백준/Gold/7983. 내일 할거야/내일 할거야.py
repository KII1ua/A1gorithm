# baekjoon 7983
import sys
input = sys.stdin.readline

N = int(input())
arr = []

for _ in range(N):
    a = list(map(int, input().split()))
    a.insert(0, a[1] - a[0] + 1)
    arr.append(a)

arr.sort(reverse=True, key=lambda x : (x[2], x[1]))

now = arr[0][0] # 현재 숙제를 해야하는날

for i in range(1, N):
    start, dur, end = arr[i]

    if now > end:
        now = start
    else:
        now = now - dur

print(now-1)