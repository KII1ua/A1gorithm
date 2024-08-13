# baekjoon 1012
import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def dfs(y, x):
    if x < 0 or y < 0 or x >= N or y >= M:      # 현재 좌표가 인덱스 범위 에 있는지
        return False
    if graph[y][x] == 1:            # 배추가 있을 경우
        graph[y][x] = 0             # 0으로 만들어 방문체크
        dfs(y-1, x)     # 상
        dfs(y+1, x)     # 하
        dfs(y, x-1)     # 좌
        dfs(y, x+1)     # 우
        return True
    return False

T = int(input())

for _ in range(T):
    M, N, K = map(int, input().split())
    graph = [[0] * N for _ in range(M)]
    total = 0

    for a in range(K):
        y, x = map(int ,input().split())
        graph[y][x] = 1

    for i in range(M):
        for j in range(N):
            if dfs(i, j) == True:
                total += 1

    print(total)
