#baekjoon 14563
import sys
input = sys.stdin.readline

graph = [list(input().rstrip()) for _ in range(8)]
move = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]
cnt = 0

def recursive(x, y):
    for a, b in move:
        nx = x
        ny = y
        for _ in range(7):
            nx += a
            ny += b
            if 0 <= nx < 8 and 0 <= ny < 8:
                if graph[nx][ny] == '*':
                    return True

for i in range(8):
    for j in range(8):
        if graph[i][j] == "*":
            if recursive(i, j) == True:
                print("invalid")
                sys.exit()
            cnt += 1

if cnt != 8:
    print("invalid")
else:
    print("valid")