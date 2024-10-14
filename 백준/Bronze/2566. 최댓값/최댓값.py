#baekjoon 16928
import sys
input = sys.stdin.readline

arr = [list(map(int, input().split())) for _ in range(9)]

a = -1
tmp = [0, 0]

for i in range(9):
    for j in range(9):
        if arr[i][j] > a:
            a = arr[i][j]
            tmp = [i+1, j+1]

print(a)
print(*tmp)