# baekjoon 9935
import sys
input = sys.stdin.readline

N = input().rstrip()
M = list(input().rstrip())
res = []

for i in N:
    res.append(i)
    if res[len(res) - len(M):] == M:
        for j in range(len(M)):
            res.pop()

if len(res) != 0:
    for i in res:
        print(i, end = "")
else:
    print("FRULA")