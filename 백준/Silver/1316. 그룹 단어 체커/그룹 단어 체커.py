# baekjoon 5585
import sys
input = sys.stdin.readline

N = int(input())
count = 0

for _ in range(N):
    a = input().rstrip()
    tmp = []
    for i in range(len(a)-1):
        if a[i] != a[i+1]:
            tmp.append(a[i])
            if a[i+1] in tmp:
                count += 1
                break
print(N - count)