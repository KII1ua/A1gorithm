# baekjoon 18110
import sys
input = sys.stdin.readline

N = int(input())
lst = [int(input()) for x in range(N)]

if N == 0:      # 의견이 없을시
    print("0")
    exit()

lst.sort()

# 반올림
def banup(solve):
    if solve - int(solve) >= 0.5:
        return int(solve) + 1
    else:
        return int(solve)

# 절사평균
tmp = banup(N * 0.15)
result = lst[tmp:len(lst)-tmp]
print(banup(sum(result) / len(result)))