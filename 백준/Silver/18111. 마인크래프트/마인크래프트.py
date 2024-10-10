# baekjoon 18111
import sys
input = sys.stdin.readline

N, M, B = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
time = float('inf')        # 시간
ground = 0                  # 높이

for _ in range(257):
    useblock = 0
    takeblock = 0
    for i in range(N):
        for j in range(M):
            if graph[i][j] > _:
                takeblock += graph[i][j] - _
            else:
                useblock += _ - graph[i][j]
    
    if useblock > takeblock + B:
        continue
    
    result = takeblock * 2 + useblock 

    if time >= result:
        time = result
        ground = _

print(time, ground)