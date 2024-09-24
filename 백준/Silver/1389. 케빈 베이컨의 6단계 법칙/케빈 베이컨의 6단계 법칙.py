import sys
input = sys.stdin.readline

n, v = map(int, input().split())
INF = 9999999
result = [INF, 0]
graph = [[INF] * (n+1) for _ in range(n+1)]

for _ in range(v) :
    v1, v2 = map(int, input().split())
    graph[v1][v2] = 1
    graph[v2][v1] = 1
    
for i in range(1, n+1) :
    graph[i][i] = 0

for k in range(1, n+1) :
    for i in range(1, n+1) :
        for j in range(1, n+1) :
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
            
for i in range(1, n+1):
    tmp = 0
    for j in range(1, n+1):
        tmp += graph[i][j]
    if tmp < result[0]:
        result[0] = tmp
        result[1] = i

print(result[1])