# baekjoon 11866
import sys
from collections import deque
input = sys.stdin.readline

N, K = list(map(int, input().split()))

q = deque([x for x in range(1, N + 1)])
result = []

while q:
    for i in range(K - 1):
        q.append(q.popleft())
    result.append(str(q.popleft()))

print("<" + ", ".join(result) + ">")