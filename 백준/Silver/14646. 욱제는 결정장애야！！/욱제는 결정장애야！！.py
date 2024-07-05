# baekjoon 14646
import sys
input = sys.stdin.readline

N = int(input())
sticker = list(map(int, input().split()))
visited = [False] * 100001
cnt = 0
max_cnt = 0

for i in sticker:
    if not visited[i]:
        cnt += 1
        visited[i] = True
    else:
        cnt -= 1
        visited[i] = False
    max_cnt = max(max_cnt, cnt)

print(max_cnt)