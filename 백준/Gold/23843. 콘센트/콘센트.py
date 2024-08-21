# baekjoon 23843
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
t = list(map(int, input().split()))
totaltime = [0] * M

t.sort(reverse=True)

idx = 0
for i in range(len(t)):
    if idx == 0:  # 첫번째 콘센트에 충전
        totaltime[idx] += t[i]
        idx = (idx + 1) % M
        continue
    
    totaltime[idx] += t[i]
    if totaltime[idx] == totaltime[idx - 1]:        # 두 개의 충전 콘센트가 같아질 경우 M에 따라 다른 콘센트 사용
        idx = (idx + 1) % M
    
print(totaltime[0])