# baekjoon 1138
import sys
input = sys.stdin.readline

N = int(input())

line = list(map(int, input().split()))
height = [_ for _ in range(1, N+1)]
result = []

x = -1
for i in range(N):
    result.insert(line[x], height[x])   # 키가 큰 사람부터 세움
    x -= 1

for j in range(N):
    print(result[j], end = ' ')