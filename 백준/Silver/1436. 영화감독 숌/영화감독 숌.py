# baekjoon 11723
import sys
input = sys.stdin.readline

N = int(input())
cnt = 0
start = 666

while True:
    if '666' in str(start):
        cnt += 1
    
    if cnt == N:
        break

    start += 1

print(start)