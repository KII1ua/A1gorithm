# baekjoon 1018
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = [input().rstrip() for i in range(N)]
result = []

for i in range(N-7):
    for j in range(M-7):
        white = 0
        black = 0

        for a in range(i, i + 8):
            for b in range(j, j + 8):
                if(a + b) % 2 == 0:
                    if board[a][b] != 'B':
                        white += 1
                    if board[a][b] != 'W':
                        black += 1
                else:
                    if board[a][b] != 'W':
                        white += 1
                    if board[a][b] != 'B':
                        black += 1
                
        result.append(white)
        result.append(black)
    
print(min(result))