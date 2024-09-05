# baekjoon 17128
import sys
input = sys.stdin.readline

N, Q = map(int, input().split())
Ai = list(map(int, input().split()))
Qi = list(map(int, input().split()))
arr = [0] * N

for _ in range(N):
    arr[_] = Ai[_] * Ai[_-1] * Ai[_-2] * Ai[_-3]

arr_sum = sum(arr)

for i in Qi:
    for j in range(4):
        idx = (i - 1 + j) % N
        arr[idx] = -arr[idx]
        arr_sum += 2 * arr[idx]
    print(arr_sum)