# baekjoon 2231
import sys
input = sys.stdin.readline

N = int(input())

for i in range(1, N+1):     # 1, N까지 반복문을 사용하여 분해합 찾기
    tmp = sum((map(int, str(i)))) #각 자리수합
    tmp_sum = i + tmp  #각 자리수 합 + i
    if tmp_sum == N:
        print(i)
        sys.exit()      # 분해합을 발견했을경우 시스템 종료
print('0')