# baekjoon 7568
import sys
input = sys.stdin.readline

N = int(input())

rank = []       # 등수를 저장할 리스트 
bmi = [list(map(int, input().split())) for x in range(N)]

for i in range(N):      # 무게와 키를 브루트포스 방식을 사용하여 모든 결과와 비교
    count = 0
    for j in range(N):
        if bmi[i][0] < bmi[j][0] and bmi[i][1] < bmi[j][1]:
            count += 1
    rank.append(count + 1)      # 실제 등수는 + 1

for i in rank:
    print(i, end=" ")