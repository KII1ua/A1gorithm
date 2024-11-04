# baekjoon 2446
import sys
input = sys.stdin.readline

N = int(input())
arr = [0]
result = []

for _ in range(N):
    arr.append(int(input()))

def dfs(n):
    if visited[n] == 0:
        visited[n] = 1
        up.add(n)
        down.add(arr[n])
        if up == down:
            result.extend(list(down))
            return
        dfs(arr[n])


for i in range(1, N+1):
    visited = [0] * (N+1)
    up = set()
    down = set()
    dfs(i)

result = set(result)
result = list(result)
result.sort()
print(len(result))
for i in result:
    print(i)