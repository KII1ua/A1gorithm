#baekjoon 29155
import sys
input = sys.stdin.readline

N = int(input())
level = list(map(int, input().split()))
ti = [list(map(int, input().split())) for _ in range(N)]

ti.sort()
cnt = 0
before_level = 1
before_time = 0
first_clear = True

for i, j in ti:
    if level[i-1] > 0:
        cnt += j
        level[i-1] -= 1

        if first_clear:
            first_clear = False
        elif before_level == i:
            cnt += (j - before_time)
        elif before_level != i:
            cnt += 60
        
        before_level = i
        before_time = j

print(cnt)