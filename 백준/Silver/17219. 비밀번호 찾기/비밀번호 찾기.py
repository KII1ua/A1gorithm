# baekjoon 11399
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
password = {}

for i in range(N):
    a, b = input().rstrip().split()
    password[a] = b

for j in range(M):
    a = input().rstrip()
    print(password[a])
