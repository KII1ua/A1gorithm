#baekjoon 1487
import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    box = [[] for _ in range(M)]
    for i in range(N):
        lst = list(map(int, input().split()))
        for j in range(M):
            box[j].append(lst[j])
    
    result = 0
    for i in range(M):
        boxcnt = box[i].count(1)
        floor = N - 1

        for j in range(N - 1, -1, -1):
            if box[i][j] == 1:
                result += floor - j
                floor -= 1

    print(result)