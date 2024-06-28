# baekjoon 27160
import sys
input = sys.stdin.readline

N = int(input())
correct = [5]
result = {}

for i in range(N):
    a, b = list(input().rstrip().split())
    b = int(b)
    if a not in result:
        result[a] = b
    else:
        result[a] += b

for j in result.values():
    if j == 5:
        print("YES")
        sys.exit()

print("NO")