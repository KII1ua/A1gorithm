# baekjoon 1072
import sys
input = sys.stdin.readline

X, Y = map(int, input().split())
Z = (100 * Y) // X

if Z >= 99:
    print(-1)
    sys.exit()

start = 0
end = X
result = 0

while start <= end:
    mid = (start + end) // 2 

    if (100 * (Y + mid) // (X + mid) > Z):
        end = mid - 1
        result = mid
    else:
        start = mid + 1

print(result)