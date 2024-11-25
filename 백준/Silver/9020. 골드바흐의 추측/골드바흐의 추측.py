#baekjoon 9020
import sys
input = sys.stdin.readline

N = int(input())

def is_prime(n):
    if n == 1:
        return False
    for j in range(2, n):
        if n % j == 0:
            return False
    return True

for i in range(N):
    a = int(input())

    left, right = a // 2, a // 2
    
    while left > 0:
        if is_prime(left) and is_prime(right):
            print(left, right)
            break
        else:
            left -= 1
            right += 1