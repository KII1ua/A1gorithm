# baekjoon 1389
import sys
input = sys.stdin.readline

N = int(input())
lst = list(map(int, input().split()))
X = int(input())
cnt = 0

lst.append(X)
lst.sort()
tmp = lst[:lst.index(X)]

start = 0
end = len(tmp) - 1

while start < end:
    if tmp[start] + tmp[end] == X:
        cnt += 1
    if tmp[start] + tmp[end] <= X:
        start += 1
    else:
        end -= 1

print(cnt)