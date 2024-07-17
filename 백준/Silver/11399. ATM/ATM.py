# baekjoon 11399
import sys
input = sys.stdin.readline

N = int(input())
time = 0

bank = list(map(int, input().split()))

bank.sort()

for i in range(1, len(bank) + 1):
    time += sum(bank[:i])

print(time)