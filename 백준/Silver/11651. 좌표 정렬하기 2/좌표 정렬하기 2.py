#baekjoon 11866
import sys
input = sys.stdin.readline

N = int(input())        # 정수개 입력

result = [list(map(int, input().split())) for _ in range(N)]    # 2차원 배열로 입력

result.sort(key = lambda x : (x[1], x[0]))      # y좌표 정렬 후 x좌표 정렬

for i, j in result:
    print(i, j)