# baekjoon 30960
import sys
import heapq
input = sys.stdin.readline

N, K = map(int, input().split())
visited = [float('inf')] * 100001
visited[N] = 0
hq = []

heapq.heappush(hq, (0,N))

while hq:
    w, z = heapq.heappop(hq)    # 가중치, 위치
    
    for nx in [(z+1, 1), (z-1, 1), (z * 2, 0)]:     # 이동한 위치, 가중치
        if 0 <= nx[0] < 100001 and visited[nx[0]] > w + nx[1]:
            visited[nx[0]] = w + nx[1]      # 방문노드에 가중치 삽입
            heapq.heappush(hq, (visited[nx[0]], nx[0]))     # 가중치, 위치
    
print(visited[K])