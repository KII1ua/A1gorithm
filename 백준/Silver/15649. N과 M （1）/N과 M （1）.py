# baekjoon 15649
import sys
from itertools import permutations
input = sys.stdin.readline

N, M = list(map(int, input().rstrip().split()))

per = [i for i in range(1, N+1)]

permute = permutations(per, M)          # 순열 permutation 사용

for i in permute:
    print(' '.join(map(str, i)))        # 튜플 형식을 공백 문자열로 출력하기 위함