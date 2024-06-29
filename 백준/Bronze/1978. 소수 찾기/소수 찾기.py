#baekjoon 1978
import sys
input = sys.stdin.readline

N = int(input())
lst = list(map(int, input().split()))
count = 0

for i in lst:
    if i == 1:
        continue

    if i == 2:
        count += 1
        continue

    is_prime = True
    for j in range(2, i):
        if i % j == 0:
            is_prime = False
            break
    if is_prime:
        count += 1

print(count)