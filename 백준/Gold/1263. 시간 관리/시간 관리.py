# baekjoon 1263
import sys
input = sys.stdin.readline

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]

arr.sort(key = lambda x : (x[-1]), reverse=True)

time = arr[0][1] - arr[0][0]

for i in range(1, N):
    if time > arr[i][1]:
        time = arr[i][1] - arr[i][0]
    else:
        time -= arr[i][0]

if time < 0:
    print(-1)
    sys.exit()
else:
    print(time)