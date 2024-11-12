#baekjoon 25400
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
tmp = 1
res = 0
result = 0
visited = False

for i in range(N):
    if arr[i] == tmp:
        visited = True
        tmp += 1
        result += res
        res = 0
    else:
        res += 1
result += res
    
if visited == False:
    print(N)
else:
    print(result)