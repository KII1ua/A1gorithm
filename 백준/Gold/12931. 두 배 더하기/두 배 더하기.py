# baekjoon 12931
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
cnt = 0

while True:
    for i in range(N):
        if arr[i] % 2:  # 홀수일 경우
            arr[i] -= 1
            cnt += 1
    
    if sum(arr) == 0:       # 모든 요소의 합이 0일 경우
        break

    for j in range(N):   # 위에서 홀수인 경우를 빼줬으니 짝수가 되어 나눔
        arr[j] = arr[j] / 2
    cnt += 1

print(cnt)