#baekjoon 24460
import sys
input = sys.stdin.readline

def recursive(x, y, n):
    if n == 1:
        return graph[x][y]

    ori = recursive(x, y, n // 2)
    down = recursive(x + n // 2, y, n // 2)
    right = recursive(x, y + n // 2, n // 2)
    diag = recursive(x + n // 2, y + n // 2, n // 2)

    arr = [ori, down, right, diag]
    arr.sort()
    return arr[1]


N = int(input().strip())
graph = [list(map(int, input().split())) for _ in range(N)]

print(recursive(0, 0, N))