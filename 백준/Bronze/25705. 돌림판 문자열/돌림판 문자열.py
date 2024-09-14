#baekjoon 25705
import sys
input = sys.stdin.readline

N = int(input())
alpha = input().rstrip()
M = int(input())
S = input().rstrip()

cnt = N-1
idx = 0

for i in S:
    if i not in alpha:
        print(-1)
        sys.exit()

while True:
    cnt += 1
    if alpha[cnt % N] == S[idx]:
        idx += 1
        if idx == M:
            break

print(cnt - N + 1)