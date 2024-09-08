# baekjoon 21736
import sys
from collections import deque
input = sys.stdin.readline

N =  int(input())   # 컴퓨터의 개수
cnt = int(input())  # 컴퓨터 연결 개수
graph = [[] * N for _ in range(N+1)]
lst = set()
visited = [False] * (N+1)

for i in range(cnt):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

q = deque()

q.append(1)

while q:

    x = q.popleft()
    visited[x] = True

    for i in graph[x]:
        if not visited[i]:
            q.append(i)
            lst.add(i)

print(len(lst))