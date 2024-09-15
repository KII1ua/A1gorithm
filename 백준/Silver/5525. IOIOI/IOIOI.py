#baekjoon 5525
import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
S = input().rstrip()
result = ''
cnt = 0

for i in range((N + 1) + N):
    if i % 2 == 0:
        tmp = 'I'
    else:
        tmp = 'O'
    for j in range(1):
        result += tmp
    
for i in range(len(S)):
    if S[i:i+len(result)] == result:
        cnt += 1

print(cnt)