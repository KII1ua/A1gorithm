import sys
import math
input = sys.stdin.readline

N = int(input())

for i in range(N):
    lst = list(map(int, input().rstrip().split(" ")))
    answer = 0

    for j in range(len(lst)):
        for k in range(j+1, len(lst)):
            answer = max(answer, math.gcd(lst[j], lst[k]))
    
    print(answer)