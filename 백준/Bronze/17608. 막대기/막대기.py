# baekjoon 17608
import sys
input = sys.stdin.readline

N = int(input())
result = []
cnt = 0
max = 0

for i in range(N):
    i = int(input())
    result.append(i)

while True:
    if len(result) == 0:
        break
    
    i = result.pop()
    if i > max:
        max = i
        cnt += 1

print(cnt)