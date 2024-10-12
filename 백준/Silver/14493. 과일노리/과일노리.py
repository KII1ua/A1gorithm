# baekjoon 14493
import sys
input = sys.stdin.readline

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
time = 0

for i in range(N):
    tmp = time % (arr[i][0] + arr[i][1])

    if tmp < arr[i][1]:
        time += arr[i][1] - tmp
    
    time += 1

print(time)