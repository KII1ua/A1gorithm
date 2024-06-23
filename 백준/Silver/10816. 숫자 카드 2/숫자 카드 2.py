# baekjoon 10816
import sys
input = sys.stdin.readline

N = int(input().rstrip())        # 숫자 카드 개수
num = list(map(int, input().split()))   # 숫자 카드 정수

M = int(input().rstrip())
mnum = list(map(int, input().split()))

dict_card = {}       # 카드에 대응되는 딕셔너리 생성

for i in num:
    if i in dict_card:
        dict_card[i] += 1
    else:
        dict_card[i] = 1
    
for i in mnum:
    if i in dict_card:
        print(dict_card[i], end=' ')
    else:
        print(0, end=' ')
