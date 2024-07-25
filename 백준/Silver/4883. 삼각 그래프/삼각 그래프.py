# baekjoon 4883
import sys
input = sys.stdin.readline

K = 1

while True:
    N = int(input())
    graph = []
    if N == 0:
        break
    
    for i in range(N):
        i = list(map(int, input().split()))
        graph.append(i)
    
    graph[1][0] += graph[0][1]
    graph[1][1] += min(graph[0][1], graph[0][1] + graph[0][2], graph[1][0])
    graph[1][2] += min(graph[0][1], graph[0][1] + graph[0][2], graph[1][1])

    for i in range(2, N):
        graph[i][0] += min(graph[i-1][0], graph[i-1][1])
        graph[i][1] += min(graph[i][0], graph[i-1][0], graph[i-1][1], graph[i-1][2])
        graph[i][2] += min(graph[i][1], graph[i-1][1], graph[i-1][2])

    print("{}. {}".format(K, graph[N-1][1]))
    
    K += 1
