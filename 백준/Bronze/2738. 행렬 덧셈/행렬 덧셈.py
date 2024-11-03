# baekjoon 2738
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
arr1 = [list(map(int, input().split())) for _ in range(N)]
result = [[] * M for _ in range(N)]

for i in range(N):
    for j in range(M):
        result[i].append(arr[i][j] + arr1[i][j])
    
for i in range(N):
    for j in range(M):
        print(result[i][j], end = ' ')
    print()