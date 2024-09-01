#baekjoon 1427
import sys
input = sys.stdin.readline

N = list(input().rstrip())
result = list(map(int, N))

for i in range(len(result)):        # 정렬 구현
    tmp = i     # 제일 큰 인덱스를 저장 하기 위함
    for j in range(i+1, len(result)):
        if result[tmp] < result[j]:      # 인덱스에 있는 값을 비교
            tmp = j
    num = result[i]
    result[i] = result[tmp]
    result[tmp] = num

print("".join(map(str, result)))