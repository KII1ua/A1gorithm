# baekjoon 2292
import sys
input = sys.stdin.readline

N = int(input())
cnt = 1     # 첫번째 방 하나 세주기
hexagon = 1

while N > hexagon:
    hexagon += 6 * cnt
    cnt += 1

print(cnt)