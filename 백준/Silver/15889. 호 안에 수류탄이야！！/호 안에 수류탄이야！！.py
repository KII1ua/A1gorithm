#baekjoon 15889
import sys
input = sys.stdin.readline

N = int(input())
graph = list(map(int, input().split()))

if N == 1:
    print("권병장님, 중대장님이 찾으십니다")
    sys.exit()
else:
    arr = list(map(int, input().split()))
    result = graph[0] + arr[0]
    for i in range(1, N-1):
        if graph[i] <= result < arr[i] + graph[i]:
            result = arr[i] + graph[i]
    if result >= graph[N-1]:
        print("권병장님, 중대장님이 찾으십니다")
    else:
        print("엄마 나 전역 늦어질 것 같아")