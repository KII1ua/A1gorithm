# baekjoon 2630
import sys
input = sys.stdin.readline

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
white = 0
blue = 0

def bt(x, y, n):
    global white, blue

    tmp = 0
    for i in range(x, x+n):
        for j in range(y, y+n):
            if graph[i][j] == 1:        # 파랑색의 개수를 셈
                tmp += 1
    
    if not tmp:     # 0일때는 흰색으로 채워져 있으니
        white += 1
    elif tmp == n ** 2:     # 파랑색으로 채워져 있으니
        blue += 1
    else:
        bt(x, y, n // 2)        # 1사분면
        bt(x, y + n // 2, n // 2)   # 2사분면
        bt(x + n // 2, y, n // 2)   # 3사분면
        bt(x + n // 2, y + n // 2, n // 2) # 4사분면
    return

bt(0, 0, N)
print(white)
print(blue)