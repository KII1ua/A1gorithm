#baekjoon 2559
import sys
input = sys.stdin.readline

N, K = map(int, input().split())
degree = list(map(int, input().split()))
result = [sum(degree[:K])]

for i in range(N-K):
    result.append(result[i] - degree[i] + degree[i+K])

print(max(result))