# baekjoon 1931
import sys
input = sys.stdin.readline

N = int(input())
meet = [list(map(int, input().split())) for _ in range(N)]

meet.sort(key = lambda x : (x[1], x[0]))
cnt = 1
end = meet[0][1]

for i in range(1, N):
    if end <= meet[i][0]:
        end = meet[i][1]
        cnt += 1

print(cnt)