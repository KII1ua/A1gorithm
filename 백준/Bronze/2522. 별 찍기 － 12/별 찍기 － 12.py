# baekjoon 2522
import sys
input = sys.stdin.readline

N = int(input())

for i in range(1, N):
    for j in range(N-i):
        print(" ", end = "")
    
    for k in range(i):
        print("*", end = "")
    print()

print("*" * N)

for i in range(1, N):
    for j in range(i):
        print(" ", end = "")
    
    for k in range(N-i):
        print("*", end = "")
    print()