# baekjoon 4949
import sys
input = sys.stdin.readline

T = int(input())
count = 0

for _ in range(T):
    a, b, c = list(map(int, input().split()))
    
    for i in range(1, a+1):
        for j in range(1, b+1):
            for k in range(1, c+1):
                if i ** 2 == j * k and j ** 2 == i * k and k ** 2 == i * j:
                    count += 1
                else:
                    continue
    print(count)
    count = 0