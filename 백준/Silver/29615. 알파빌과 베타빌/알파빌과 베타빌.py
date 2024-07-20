#baekjoon 29615
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
wait = list(map(int, input().split()))
friend = list(map(int, input().split()))
count = M

for i in range(M):
    for j in friend:
        if wait[i] == j:
            count -= 1
            break

print(count)