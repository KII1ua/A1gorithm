import sys
input = sys.stdin.readline

N, Q = map(int, input().split())
akbo = []
count = 0
result = {}

for i in range(1, N+1):
    a = int(input())
    for j in range(a):
        akbo.append(i)

time = [int(input()) for x in range(Q)]


for i in time:
    print(akbo[i])